#include "QImageFrame.h"
//#include "IImage.h"
//#include "..\AMSoft-HC-MBDD_ImageProcessor\Include\ImageManager\QImageManager.h"
//#include "QProductParamDef.h"
//#include "QProductResultDef.h"
//#include "QLogEmitterFactory.h"

#include <QPaintEvent>
#include <QPainter>
#include <QQueue>
#include <QPen>
#include <QTime>
#include <QCoreApplication>
#include <QDebug>
//#include "QFactoryManager.h"
//#include "IFactory.h"
//#include "IImage.h"

const char* IMAGE_FRAME_NAME = "imageframe";

const int INFO_POSITION_LEFT = 10;
const int INFO_POSITION_SPACING = 10;

const int PROMPT_POSITION_OFFSET = 20;

// In order to avoid the camera refresh too fast, causing aninvisible pass image;
const int OK_DELAY_SHOW_COUNT = 2;

QImageFrame::QImageFrame(QWidget* parent /*= nullptr*/)
	: QFrame(parent), 
	m_nLeftTopCount(0), 
	m_nLeftBottomCount(0),
	m_bShowClone(false),
	//m_eProcessMode(CAMERA_PROCESS_MODE_NONE),
	m_nOKDelayShowCount(0),
	m_bPromptAlarm(false),
	m_pMapMarks(nullptr)
	, m_pImageCurrentInfo(new IMAGE_SIMPLE_INFO_t(0,0,0,0))
	, m_eDrawAlign(ALIGN_UNKNOWN)
	
{
	setObjectName(IMAGE_FRAME_NAME);
	m_pImageQueue = new QQueue<IImage*>();
	m_pMarkNumberQueue = new QQueue<long>();
	m_pMapMarks = new QMap<QString, QRect>();
	QObject::connect(this, &QImageFrame::SigShowImageInMainThread, this, &QImageFrame::OnShowImageInMainThread);
}

QImageFrame::~QImageFrame()
{
	if (m_pImageQueue != nullptr)
	{
		delete m_pImageQueue;
		m_pImageQueue = nullptr;
		delete m_pMarkNumberQueue;
		m_pMarkNumberQueue = nullptr;
	}
	RemoveMarkAreas();
}

bool QImageFrame::ShowImage(IImage* pImage, const long lMarkNumber)
{
	if (pImage == nullptr)
	{
		return false;
	}

	m_pImageQueue->enqueue(pImage);
	m_pMarkNumberQueue->enqueue(lMarkNumber);
	if (m_nOKDelayShowCount != 0)
	{
		--m_nOKDelayShowCount;
		return true;
	}
	if (1/*pImage->Defects() >= DEFECT_FLAG_OK*/)
	{
		repaint();
	}
	else
	{
		update();
	}
	return true;
}

bool QImageFrame::ShowImage(QString strImagePath, IMAGE_ROTATE_e eRotate/* = IMAGE_ROTATE_NORMAL*/)
{
	if (!m_pixClone.load(strImagePath))
	{
		return false;
	}
	QSize qSize(width(), height());
	m_pixClone = m_pixClone.scaled(QSize(width(), height()));

	////for DeNuo//20201013
	//m_ptCanvas = QPoint(0,0);
	//m_bShowClone = true;

	repaint();
	return true;
}

bool QImageFrame::ShowImage(QImage& imageObj, IImage const* pImageRef)
{ 	
	m_pImageCurrentInfo->lModuleType = 4;
	m_pImageCurrentInfo->nCameraIndex = 0;
	m_pImageCurrentInfo->nWidth = 1920;
	m_pImageCurrentInfo->nHeight = 1200;
	
	//QImageDetectFrame::ShowImage();
	return true;
}

bool QImageFrame::ShowImageInThread(QImage& imageObj, IImage const* pImageRef)
{
	//QImageDetectFrame::ShowImageInThread;
	return true;
}

void QImageFrame::AddMarkAreas(QString strContent, QRect rect)
{
	//QImageDetectFrame::AddMarkAreas
}

void QImageFrame::SetDrawAlign(ALIGN_FRAME_BORDER_e eAlign)
{
	m_eDrawAlign = eAlign;
}

bool QImageFrame::ClearImage()
{
	//QImageDetectFrame::ClearImage
	return true;
}

void QImageFrame::OnCloneCanvas(QPixmap* pPix, QPoint& pt)
{
	m_pixClone = *pPix;
	m_ptCanvas = pt;
	m_bShowClone = true;
	update();
}

//void QImageFrame::OnVideoProcessModeChanged(CAMERA_PROCESS_MODE_e eMode)
//{
//	m_eProcessMode = eMode;
//}

void QImageFrame::OnShowImageInMainThread()
{
	ShowImageInMainThreadImpl();
}

void QImageFrame::ShowImageInMainThreadImpl()
{
	//Go QImageDetectFrame::ShowImageInMainThreadImpl()
}

void QImageFrame::paintEvent(QPaintEvent*)
{
	QPainter painter(this);

	if (m_pImageQueue->size() == 0)
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

	IImage* pImage = m_pImageQueue->back();

	CalibCanvasArea(m_pixCanvas, pImage);

	QPainter Canvas(&m_pixCanvas);

	DrawImage(&Canvas, pImage);

	DrawImageSpecial(&Canvas, pImage);

	DrawShape(&Canvas, pImage);

	DrawText(&Canvas, pImage);

	DrawCanvas(&painter, pImage);

	TightenImageQueue(pImage);

	AdjustDisplayEffect(pImage);

	DrawPrompt(&painter);
}

void QImageFrame::DrawImage(QPainter* const pPainter, const IImage* const pImage)
{
	if (pPainter == nullptr || pImage == nullptr)
	{
		return;
	}

	pPainter->drawPixmap(0, 0, m_pixCanvas.width(), m_pixCanvas.height(), QPixmap::fromImage(QImage(".\\InfusionBagImage\\001_Top_Left.bmp")));
}

void QImageFrame::DrawShape(QPainter* const pPainter, const IImage* const pImage)
{
	DrawImageRoi(pPainter, pImage);
	
	DrawMarkAreas(pPainter, pImage);
}

void QImageFrame::DrawText(QPainter* const pPainter, const IImage* const pImage)
{

}

void QImageFrame::DrawCanvas(QPainter* const pPainter, const IImage* const pImage)
{
	pPainter->drawPixmap(m_ptCanvas.x(), m_ptCanvas.y(), m_pixCanvas);
	if (1/*pImage->Defects() > DEFECT_FLAG_OK*/)
	{
		emit SigCloneCanvas(&m_pixCanvas, m_ptCanvas);
	}
}

void QImageFrame::DrawInfoFromLeftTop(QPainter* const pPainter, QString strInfo)
{
	pPainter->drawText(INFO_POSITION_LEFT, INFO_POSITION_SPACING * ++m_nLeftTopCount, strInfo);
}

void QImageFrame::DrawInfoFromLeftBottom(QPainter* const pPainter, QString strInfo)
{
	pPainter->drawText(INFO_POSITION_LEFT, height() - INFO_POSITION_SPACING * ++m_nLeftBottomCount, strInfo);
}

void QImageFrame::TightenImageQueue(IImage* const pImage)
{
	IImage* pImageFront = nullptr;
	long lMarkNumber = -1;
	while (pImage != nullptr)
	{
		pImageFront = m_pImageQueue->dequeue();
		lMarkNumber = m_pMarkNumberQueue->dequeue();
		if (pImageFront != nullptr)
		{
			//pImageFront->SetShown(lMarkNumber);
			//pImageFront->ImageManager()->Revoke(pImageFront, pImageFront == pImage);
		}
		if (pImageFront == pImage)
		{
			return;
		}
	}
}

void QImageFrame::AdjustDisplayEffect(IImage* const pImage)
{
	//if (m_eProcessMode == CAMERA_PROCESS_MODE_BLOCK /*&& pImage->Defects() == DEFECT_FLAG_OK*/)
	{
		m_nOKDelayShowCount = OK_DELAY_SHOW_COUNT;
	}
}

void QImageFrame::DrawRoi(QPainter* const pPainter, const MARK_AREA_t& stArea, int nBorderWidth)
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
	oFont.setPointSize(16);
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

	pPainter->drawText(
		rcRoiRatio.x() + PROMPT_POSITION_OFFSET / 2,
		(rcRoiRatio.y() - PROMPT_POSITION_OFFSET / 2),
		stArea.content
	);

	oFont.setPointSize(nOldPointSize);
	pPainter->setFont(oFont);
}

void QImageFrame::DrawPrompt(QPainter* const pPainter)
{
	Q_ASSERT(pPainter != nullptr);
	if (m_strPrompt.isEmpty())
	{
		return;
	}

	const QPen oldPen = pPainter->pen();
	QPen oPen(QBrush(QColor(m_bPromptAlarm ? Qt::red : Qt::gray)), 3, Qt::SolidLine);
	pPainter->setPen(oPen);

	QFont oFont = font();
	int nOldPointSize = oFont.pointSize();
	oFont.setPointSize(18);
	oFont.setBold(true);
	pPainter->setFont(oFont);

	QRect rcFrame = this->geometry();
	int nTextWidth = pPainter->fontMetrics().width(m_strPrompt);
	int nTextHeight = pPainter->fontMetrics().height();
	int nTextLeft = (rcFrame.width() - nTextWidth) / 2;
	int nTextTop = (rcFrame.height() - nTextHeight) / 2;

	pPainter->drawText(nTextLeft, nTextTop, m_strPrompt);
	
	pPainter->setPen(oldPen);
	oFont.setPointSize(nOldPointSize);
	pPainter->setFont(oFont);
}

void QImageFrame::SetPrompt(QString strInfo, bool bPromptAlarm /*= false*/)
{
	m_strPrompt = strInfo;
	m_bPromptAlarm = bPromptAlarm;
	update();
}

void QImageFrame::ClearPrompt()
{
	m_strPrompt.clear();
	m_bPromptAlarm = false;
}

void QImageFrame::CalibCanvasArea(QPixmap& pixCanvas, const IImage* const pImage)
{
	if (!m_pixCanvas.isNull())
	{
		return;
	}

	if (width() * 1.0f / height() >= 2.0f * 1920 / 1200)
	{
		int nLongSide = std::max(1920, 1200);
		int nShortSide = std::min(1920, 1200);
		int nWidth = nLongSide * height() * 1.0f / nShortSide;
		m_ptCanvas.setX((width() - nWidth) / 2);
		m_ptCanvas.setY(0);
		m_pixCanvas = QPixmap(nWidth, height());
	}
	else
	{
		m_ptCanvas.setX(0);
		m_ptCanvas.setY(0);
		m_pixCanvas = QPixmap(width(), height());
	}
}

void QImageFrame::DrawImageRoi(QPainter* const pPainter, const IImage* const pImage)
{
	//draw image spacial tip. //add 20210907
	float fWidthRatio = m_pixCanvas.width() * 1.0f / 1920;
	float fHeightRatio = m_pixCanvas.height() * 1.0f / 1200;
	//QFactoryManager::Instance()->CurrFactory()->DrawSpecialImage(pPainter, m_pImageCurrentInfo, fWidthRatio, fHeightRatio);
	//add end

	MARK_AREA_t stArea;
	if (FillImageRoi(pImage, stArea))
	{
		DrawRoi(pPainter, stArea, 3);
	}
}

void QImageFrame::DrawMarkAreas(QPainter* const pPainter, const IImage* const pImage)
{
	if (m_pMapMarks == nullptr || m_pMapMarks->size() == 0)
	{
		return;
	}

	MARK_AREA_t stArea;
	stArea.imageWidth = 1920;
	stArea.imageHeight = 1200;
	QMap<QString, QRect>::iterator iter = m_pMapMarks->begin();
	while (iter != m_pMapMarks->end())
	{
		if (FillMarkArea(iter.key(), iter.value(), stArea))
		{
			DrawRoi(pPainter, stArea, 1);
		}
		++iter;
	}
}

bool QImageFrame::FillImageRoi(const IImage* const pImage, MARK_AREA_t& stArea)
{
	//if (pImage->PostRoi().isEmpty())
	//{
	//	return false;
	//}
	//stArea.rect = pImage->PostRoi(); 
	//if (m_eProcessMode == CAMERA_PROCESS_MODE_ALIGNMENT)
	//{
	//	//stArea.content = QString("F-%1. %2").arg(QString::number(pImage->Confidence(), 'f', 2)).arg(VIAL_PLUG_GAP_PATTERN_NAME[pImage->Pattern()]);
	//}
	//else
	//{
	//	stArea.content = QString("B-%1. %2").arg(pImage->Id()).arg("pImage->DefectName()");
	//}
	////stArea.borderColor = pImage->Defects() == DEFECT_FLAG_OK ? QColor(0, 255, 0) : QColor(255, 0, 0);
	//stArea.backgroundColor = stArea.borderColor;
	//stArea.contentColor = QColor(0, 0, 0);
	//stArea.imageWidth = pImage->Width();
	//stArea.imageHeight = pImage->Height();
	return true;
}

bool QImageFrame::FillMarkArea(const QString& strContent, const QRect& rect, MARK_AREA_t& stArea)
{
	if (strContent.isEmpty() || rect.isEmpty())
	{
		return false;
	}
	stArea.rect = rect;
	stArea.content = strContent;
	stArea.borderColor = QColor(255, 215, 0);
	stArea.backgroundColor = stArea.borderColor;
	stArea.contentColor = QColor(0, 0, 0);
	return true;
}

void QImageFrame::ChangeMarkAreas(QString strContent, QRect rect)
{
	if (!rect.isEmpty())
	{
		m_pMapMarks->insert(strContent, rect);
	}
	else
	{
		if (m_pMapMarks->contains(strContent) && rect.isEmpty())
		{
			m_pMapMarks->remove(strContent);
		}
	}
}

void QImageFrame::DrawImageSpecial(QPainter* const pPainter, QImage*pImage)
{
	if (pPainter == nullptr || pImage == nullptr)
		return;
	//draw image spacial tip. //add 20210915

	float fWidthRatio = m_pixCanvas.width() * 1.0f / pImage->width();
	float fHeightRatio = m_pixCanvas.height() * 1.0f / pImage->height();
	//QFactoryManager::Instance()->CurrFactory()->DrawSpecialImage(pPainter, m_pImageCurrentInfo, fWidthRatio, fHeightRatio);
	//add end
}

void QImageFrame::DrawImageSpecial(QPainter* const pPainter, IImage* pImage)
{
	if (pPainter == nullptr || pImage == nullptr)
		return;
	float fWidthRatio = m_pixCanvas.width() * 1.0f / 1920;
	float fHeightRatio = m_pixCanvas.height() * 1.0f / 1200;
	//QFactoryManager::Instance()->CurrFactory()->DrawSpecialImage(pPainter, m_pImageCurrentInfo, fWidthRatio, fHeightRatio);
}

void QImageFrame::RemoveMarkAreas()
{
	if (m_pMapMarks != nullptr)
	{
		m_pMapMarks->clear();
		delete m_pMapMarks;
		m_pMapMarks = nullptr;
	}
}
