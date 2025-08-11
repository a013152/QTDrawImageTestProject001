#include "QImageDetectFrame.h"

#include <QPaintEvent>
#include <QPainter>
#include <QQueue>
#include <QPen>
#include <QTime>
#include <QCoreApplication>
#include <QDebug>
#include <QMatrix>

//const char* IMAGE_FRAME_NAME = "imageframe";
const int INFO_POSITION_LEFT = 10;
const int INFO_POSITION_SPACING = 10;
const int PROMPT_POSITION_OFFSET = 10;

// In order to avoid the camera refresh too fast, causing aninvisible pass image;
const int OK_DELAY_SHOW_COUNT = 2;

QImageDetectFrame::QImageDetectFrame(QWidget* parent /*= nullptr*/)
	: QImageFrame(parent)
	, m_bShowed(false)
{
	//setObjectName(IMAGE_FRAME_NAME);
	m_pQImageQueue = new QQueue<QImage>();
	//m_pMapMarks = new QMap<QString, QRect>();
}

QImageDetectFrame::~QImageDetectFrame()
{
	
}


bool QImageDetectFrame::ShowImage(QString strImagePath, IMAGE_ROTATE_e eRotate/* = IMAGE_ROTATE_NORMAL*/)
{ 
	QImage imageObj;
	if (!imageObj.load(strImagePath))
	{
		return false;
	}
	if (eRotate == IMAGE_ROTATE_90) 
	{
		QMatrix matrix;
		matrix.rotate(90.0);
		imageObj = imageObj.transformed(matrix, Qt::FastTransformation);
	}
	else if(eRotate ==IMAGE_ROTATE_180) {
		imageObj = imageObj.mirrored(true, true);
	}
	else if (eRotate == IMAGE_ROTATE_270) {
		QMatrix matrix;
		matrix.rotate(-90.0);
		imageObj = imageObj.transformed(matrix, Qt::FastTransformation);
	}
	
	imageObj.scaled(QSize(width(), height()));
	m_pQImageQueue->push_back(imageObj);
	repaint();
	m_bShowed = true;
	return true;
}
//
bool QImageDetectFrame::ShowImage(QImage& imageObj, IImage const* pImageRef)
{
	QImageFrame::ShowImage(imageObj, pImageRef);

	//for DeNuo//20201013	
	if (imageObj.isNull() == false)
	{
		imageObj.scaled(QSize(width(), height()));
		m_pQImageQueue->push_back(imageObj);
		repaint();
		m_bShowed = true;
	}  
	
	return true;
}

bool QImageDetectFrame::ShowImageInThread(QImage& imageObj, IImage const* pImageRef)
{
	QImageFrame::ShowImage(imageObj, pImageRef);
	if (imageObj.isNull() == false)
	{
		imageObj.scaled(QSize(width(), height()));
		m_pQImageQueue->push_back(imageObj);
		emit SigShowImageInMainThread();
	}
	return true;
}

bool QImageDetectFrame::ClearImage()
{
	if (m_bShowed)
	{
		m_pixClone = m_pixClear;
		m_pixCanvas = m_pixClear;
		m_pQImageQueue->clear();
		m_bShowClone = true;
		m_pMapMarks->clear();
		//repaint();
		m_bShowed = false;
	}
	return true;
}

void QImageDetectFrame::ShowImageInMainThreadImpl()
{
	repaint();
	m_bShowed = true;
}

void QImageDetectFrame::paintEvent(QPaintEvent*)
{
	QPainter painter(this);

	if (m_pQImageQueue->size() == 0)
	{
		if (m_bShowClone)
		{
			painter.drawPixmap(m_ptCanvas.x(), m_ptCanvas.y(), m_pixClone);
		}
		DrawPrompt(&painter);
		return;
	}

	m_nLeftTopCount = 0;
	m_nLeftBottomCount = 0;

	QImage oImage = m_pQImageQueue->back(); 

	CalibCanvasArea(m_pixCanvas, oImage);

	QPainter Canvas(&m_pixCanvas);

	DrawImage(&Canvas, oImage);

	DrawImageSpecial(&Canvas, &oImage);

	DrawShape(&Canvas, oImage);

	DrawText(&Canvas, oImage);

	DrawCanvas(&painter, oImage);

	TightenImageQueue(oImage);

	//AdjustDisplayEffect(pImage);

	//DrawPrompt(&painter);
}

void QImageDetectFrame::DrawImage(QPainter* const pPainter, const QImage& qImage)
{
	if (pPainter == nullptr )
	{
		return;
	}
	pPainter->drawPixmap(0, 0, m_pixCanvas.width(), m_pixCanvas.height(), QPixmap::fromImage(qImage));
}

void QImageDetectFrame::DrawShape(QPainter* const pPainter, const QImage& qImage)
{
	DrawImageRoi(pPainter, qImage);
	
	DrawMarkAreas(pPainter, qImage);
}

void QImageDetectFrame::DrawText(QPainter* const pPainter, const QImage& qImage)
{

}

void QImageDetectFrame::DrawCanvas(QPainter* const pPainter, const QImage& qImage)
{
	pPainter->drawPixmap(m_ptCanvas.x(), m_ptCanvas.y(), m_pixCanvas);
	if (1/*pImage->Defects() > DEFECT_FLAG_OK*/)
	{
		//emit SigCloneCanvas(&m_pixCanvas, m_ptCanvas);
	}
}

void QImageDetectFrame::DrawRoi(QPainter* const pPainter, const MARK_AREA_t& stArea, int nBorderWidth)
{
	if (stArea.rect.isEmpty())
	{
		return;
	}

	float fWidthRatio = m_pixCanvas.width() * 1.0f / stArea.imageWidth;
	float fHeightRatio = m_pixCanvas.height() * 1.0f / stArea.imageHeight;
	QRectF rcRoiRatio = QRectF(
		stArea.rect.x() * fWidthRatio,
		stArea.rect.y() * fHeightRatio,
		stArea.rect.width() * fWidthRatio,
		stArea.rect.height() * fHeightRatio
	);

	QPen oPen(Qt::SolidLine);
	//IWorkMode *pWorkMode = QFactoryManager::Instance()->CurrFactory()->WorkModeControl()->GetCurrentWorkMode();
	//Q_ASSERT(pWorkMode != nullptr);
	//if (pWorkMode->GetWorkModeType() == HUMAN_LEAD)
	//{
	//	oPen.setStyle(Qt::DashDotLine);
	//}

	oPen.setWidth(nBorderWidth);
	oPen.setColor(stArea.borderColor);
	pPainter->setPen(oPen);
	pPainter->drawRect(rcRoiRatio);

	if (stArea.content.isEmpty())
	{
		return;
	}

	oPen.setColor(stArea.contentColor);
	pPainter->setPen(oPen);

	QFont oFont = font();
	int nOldPointSize = oFont.pointSize();
	oFont.setPointSize(12);
	pPainter->setFont(oFont);

	pPainter->fontMetrics();
	int nTextWidth = pPainter->fontMetrics().width(stArea.content);
	int nTextHeight = pPainter->fontMetrics().height();

	pPainter->fillRect(
		rcRoiRatio.x(),
		rcRoiRatio.y() - nTextHeight - PROMPT_POSITION_OFFSET,
		nTextWidth + PROMPT_POSITION_OFFSET,
		nTextHeight + PROMPT_POSITION_OFFSET,
		stArea.backgroundColor
	);
	//pPainter->fillRect(
	//	stArea.rect.x(),
	//	stArea.rect.y() - nTextHeight - PROMPT_POSITION_OFFSET,
	//	nTextWidth + PROMPT_POSITION_OFFSET,
	//	nTextHeight + PROMPT_POSITION_OFFSET,
	//	stArea.backgroundColor
	//);

	pPainter->drawText(
		rcRoiRatio.x() + PROMPT_POSITION_OFFSET / 2,
		(rcRoiRatio.y() - PROMPT_POSITION_OFFSET / 2),
		stArea.content
	);
	//pPainter->drawText(
	//	stArea.rect.x() + PROMPT_POSITION_OFFSET / 2,
	//	(stArea.rect.y() - PROMPT_POSITION_OFFSET / 2),
	//	stArea.content
	//);

	oFont.setPointSize(nOldPointSize);
	pPainter->setFont(oFont);
}

//void QImageFrame::DrawInfoFromLeftTop(QPainter* const pPainter, QString strInfo)
//{
//	pPainter->drawText(INFO_POSITION_LEFT, INFO_POSITION_SPACING * ++m_nLeftTopCount, strInfo);
//}

//void QImageFrame::DrawInfoFromLeftBottom(QPainter* const pPainter, QString strInfo)
//{
//	pPainter->drawText(INFO_POSITION_LEFT, height() - INFO_POSITION_SPACING * ++m_nLeftBottomCount, strInfo);
//}

void QImageDetectFrame::TightenImageQueue(const QImage& qImage)
{
	QImage imageFront;
	while (m_pQImageQueue->size() > 1)
	{
		imageFront = m_pQImageQueue->dequeue();
		//if (pImageFront != nullptr)
		//{
		//	pImageFront->SetShown();
		//	//pImageFront->ImageManager()->Revoke(pImageFront, pImageFront == pImage);
		//}
		if (imageFront == qImage)
		{
			return;
		}
	}
}

//void QImageFrame::AdjustDisplayEffect(IImage* const pImage)
//{
//	if (m_eProcessMode == CAMERA_PROCESS_MODE_BLOCK /*&& pImage->Defects() == DEFECT_FLAG_OK*/)
//	{
//		m_nOKDelayShowCount = OK_DELAY_SHOW_COUNT;
//	}
//}
//
//void QImageDetectFrame::DrawRoi(QPainter* const pPainter, const MARK_AREA_t& stArea, int nBorderWidth)
//{
//	if (stArea.rect.isEmpty())
//	{
//		return;
//	}
//
//	float fWidthRatio = m_pixCanvas.width() * 1.0f / stArea.imageWidth;
//	float fHeightRatio = m_pixCanvas.height() * 1.0f / stArea.imageHeight;
//	QRectF rcRoiRatio = QRectF(
//		stArea.rect.x() * fWidthRatio, 
//		stArea.rect.y() * fHeightRatio,
//		stArea.rect.width() * fWidthRatio, 
//		stArea.rect.height() * fHeightRatio
//	);
//
//	QPen oPen(Qt::SolidLine);
//	oPen.setWidth(nBorderWidth);
//	oPen.setColor(stArea.borderColor);
//	pPainter->setPen(oPen);
//	pPainter->drawRect(rcRoiRatio);
//
//	if (stArea.content.isEmpty())
//	{
//		return;
//	}
//
//	oPen.setColor(stArea.contentColor);
//	pPainter->setPen(oPen);
//
//	QFont oFont = font();
//	int nOldPointSize = oFont.pointSize();
//	oFont.setPointSize(14);
//	pPainter->setFont(oFont);
//
//	pPainter->fontMetrics();
//	int nTextWidth = pPainter->fontMetrics().width(stArea.content);
//	int nTextHeight = pPainter->fontMetrics().height();
//
//	pPainter->fillRect(
//		rcRoiRatio.x(),
//		rcRoiRatio.y() - nTextHeight - PROMPT_POSITION_OFFSET,
//		nTextWidth + PROMPT_POSITION_OFFSET,
//		nTextHeight + PROMPT_POSITION_OFFSET,
//		stArea.backgroundColor
//	);
//
//	pPainter->drawText(
//		rcRoiRatio.x() + PROMPT_POSITION_OFFSET / 2, 
//		(rcRoiRatio.y() - PROMPT_POSITION_OFFSET / 2), 
//		stArea.content
//	);
//
//	oFont.setPointSize(nOldPointSize);
//	pPainter->setFont(oFont);
//}
//
//void QImageFrame::DrawPrompt(QPainter* const pPainter)
//{
//	Q_ASSERT(pPainter != nullptr);
//	if (m_strPrompt.isEmpty())
//	{
//		return;
//	}
//
//	const QPen oldPen = pPainter->pen();
//	QPen oPen(QBrush(QColor(m_bPromptAlarm ? Qt::red : Qt::gray)), 3, Qt::SolidLine);
//	pPainter->setPen(oPen);
//
//	QFont oFont = font();
//	int nOldPointSize = oFont.pointSize();
//	oFont.setPointSize(18);
//	oFont.setBold(true);
//	pPainter->setFont(oFont);
//
//	QRect rcFrame = this->geometry();
//	int nTextWidth = pPainter->fontMetrics().width(m_strPrompt);
//	int nTextHeight = pPainter->fontMetrics().height();
//	int nTextLeft = (rcFrame.width() - nTextWidth) / 2;
//	int nTextTop = (rcFrame.height() - nTextHeight) / 2;
//
//	pPainter->drawText(nTextLeft, nTextTop, m_strPrompt);
//	
//	pPainter->setPen(oldPen);
//	oFont.setPointSize(nOldPointSize);
//	pPainter->setFont(oFont);
//}
//
//void QImageFrame::SetPrompt(QString strInfo, bool bPromptAlarm /*= false*/)
//{
//	m_strPrompt = strInfo;
//	m_bPromptAlarm = bPromptAlarm;
//	update();
//}
//
//void QImageFrame::ClearPrompt()
//{
//	m_strPrompt.clear();
//	m_bPromptAlarm = false;
//}

void QImageDetectFrame::CalibCanvasArea(QPixmap& pixCanvas, const QImage& qImage)
{
	//if (!m_pixCanvas.isNull())   //delete 20210113//
	//{
	//	return;
	//}
	int nMaxWidth = width();
	int nMaxHeight = height();
	int nSrcWidth = qImage.width();
	int nSrcHeight = qImage.height();
	int nX_ = 0;
	int nY_ = 0;
	int nDestWidth = nSrcWidth;
	int nDestHeight = nSrcHeight;

	float fRatioW = nSrcWidth * 1.0f / nMaxWidth;
	float fRatioH = nSrcHeight * 1.0f / nMaxHeight;

	if (fRatioW > 1.0f && fRatioW > fRatioH)
	{
		//scaling-down by width's ratio
		nDestWidth = nMaxWidth;
		nDestHeight = nSrcHeight / fRatioW;
		nY_ = (nMaxHeight - nDestHeight) / 2;
	}
	else if (fRatioH > 1.0f && fRatioH > fRatioW)
	{
		//scaling-down by height's ratio
		nDestHeight = nMaxHeight;
		nDestWidth = nSrcWidth / fRatioH;
		nX_ = (nMaxWidth - nDestWidth) / 2;
	}	
	else if (fRatioH < 1.0f && fRatioW < 1.0f )
	{
		nX_ = (nMaxWidth - nDestWidth) / 2;
		nY_ = (nMaxHeight - nDestHeight) / 2;
	}
	
	if (m_eDrawAlign == ALIGN_LEFT_TOP)
	{
		nX_ = 0; nY_ = 0;
	}
	else if (m_eDrawAlign == ALIGN_LEFT_BOTTOM)
	{
		nX_ = 0;
		nY_ = nMaxHeight - nDestHeight;
	}
	else if (m_eDrawAlign == ALIGN_RIGHT_TOP)
	{
		nX_ = nMaxWidth - nDestWidth;
		nY_ = 0;
	}
	else if (m_eDrawAlign == ALIGN_RIGHT_BOTTOM)
	{
		nX_ = nMaxWidth - nDestWidth;
		nY_ = nMaxHeight - nDestHeight;
	}



	m_ptCanvas.setX(nX_);
	m_ptCanvas.setY(nY_);
	m_pixCanvas = QPixmap(nDestWidth, nDestHeight);


	//if (this->width() * 1.0f / this->height() >= 2.0f * qImage.width() / qImage.height())
	//{
	//	int nLongSide = std::max(qImage.width(), qImage.height());
	//	int nShortSide = std::min(qImage.width(), qImage.height());
	//	int nWidth = nLongSide * height() * 1.0f / nShortSide;
	//	int x_ = (width() - nWidth) / 2;
	//	m_ptCanvas.setX(x_);
	//	m_ptCanvas.setY(0);
	//	m_pixCanvas = QPixmap(nWidth, height());
	//}
	//else
	//{
	//	m_ptCanvas.setX(0);
	//	m_ptCanvas.setY(0);
	//	m_pixCanvas = QPixmap(this->width(), this->height());
	//}
}

void QImageDetectFrame::DrawImageRoi(QPainter* const pPainter, const QImage& qImage)
{
	MARK_AREA_t stArea;
	if (FillImageRoi(qImage, stArea))
	{
		DrawRoi(pPainter, stArea, 6);
	}
}

void QImageDetectFrame::DrawMarkAreas(QPainter* const pPainter, const QImage& qImage)
{
	if (m_pMapMarks == nullptr || m_pMapMarks->size() == 0)
	{
		return;
	}

	MARK_AREA_t stArea;
	stArea.imageWidth = qImage.width();
	stArea.imageHeight = qImage.height();
	QMap<QString, QRect>::iterator iter = m_pMapMarks->begin();
	while (iter != m_pMapMarks->end())
	{
		if (FillMarkArea(iter.key(), iter.value(), stArea))
		{
			DrawRoi(pPainter, stArea, 3);
		}
		++iter;
	}
}

bool QImageDetectFrame::FillImageRoi(const QImage& qImage, MARK_AREA_t& stArea)
{

	//stArea.rect = pImage->PostRoi(); 
	//if (m_eProcessMode == CAMERA_PROCESS_MODE_ALIGNMENT)
	//{
	//	//stArea.content = QString("F-%1. %2").arg(QString::number(pImage->Confidence(), 'f', 2)).arg(VIAL_PLUG_GAP_PATTERN_NAME[pImage->Pattern()]);
	//}
	//else
	//{
	//	//stArea.content = QString("B-%1. %2").arg(pImage->Id()).arg(pImage->DefectName());
	//}
	//stArea.borderColor = pImage->Defects() == DEFECT_FLAG_OK ? QColor(0, 255, 0) : QColor(255, 0, 0);
	stArea.backgroundColor = stArea.borderColor;
	stArea.contentColor = QColor(0, 0, 0);
	stArea.imageWidth = qImage.width();
	stArea.imageHeight = qImage.height();
	return true;
}

bool QImageDetectFrame::FillMarkArea(const QString& strContent, const QRect& rect, MARK_AREA_t& stArea)
{
	if (strContent.isEmpty() || rect.isEmpty())
	{
		return false;
	}
	stArea.rect = rect;
	stArea.content = strContent.mid(2, strContent.length());
	stArea.borderColor = QColor(255, 0, 0);
	stArea.backgroundColor = stArea.borderColor;
	stArea.contentColor = QColor(0, 0, 0);
	return true;
}

void QImageDetectFrame::AddMarkAreas(QString strContent, QRect rect)
{
	if (!rect.isEmpty())
	{
		QString str = QString("%1.%2").arg(m_pMapMarks->size()).arg(strContent);
		m_pMapMarks->insert(str, rect);
	}
	//else
	//{
	//	if (m_pMapMarks->contains(strContent) && rect.isEmpty())
	//	{
	//		m_pMapMarks->remove(strContent);
	//	}
	//}
}


const QImage* QImageDetectFrame::GetCurrentImage()
{
    QImage* pImage = nullptr;
    if (!m_pQImageQueue->isEmpty())
        pImage = &(*m_pQImageQueue)[0];
    return pImage;
}

//void QImageFrame::RemoveMarkAreas()
//{
//	if (m_pMapMarks != nullptr)
//	{
//		m_pMapMarks->clear();
//		delete m_pMapMarks;
//		m_pMapMarks = nullptr;
//	}
//}
