#include "QMono8ImageWidget.h"
#include <QLayout>
#include <QPushButton>
#include "QImageDetectFrame.h"
#include <QFileInfo>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QtGui\QPainter>
#include <QPixmap>

const int DEFECT_INFO_OFFSET = 20;
#define ROI_FONT_SIZE 12
#define ROI_PEN_WIDTH 6

QString strImagePath = QString(".\\BFSImage\\No.2_1_115201.589.bmp");
QMono8ImageWidget::QMono8ImageWidget()
{
    m_pTempImage = new QImage();
    m_pImageFrame = new QImageDetectFrame(this);  
    
    QPushButton* pBtnLoadImage = new QPushButton("Load Mono8 Image");
    QPushButton* pBtnDrawImage = new QPushButton("Draw ROI");
    QPushButton* pBtnSaveImage = new QPushButton("Save to Local");

    auto setBtnWH = [](QWidget* pWidget, int nFixedWidth, int nFixedHeight) {
        pWidget->setFixedSize(nFixedWidth, nFixedHeight);
    };
    auto setBtnClear = [](QPushButton* pButton) {
        pButton->setIconSize(QSize(0, 0));
        QString str = pButton->text();
        pButton->setToolTip(str);
        pButton->setText(QString(""));
    };
    m_pImageFrame->setFixedHeight(450);
    QHBoxLayout* pHLayout_Btn = new QHBoxLayout();
    pHLayout_Btn->addWidget(pBtnLoadImage);
    pHLayout_Btn->addWidget(pBtnDrawImage);
    pHLayout_Btn->addWidget(pBtnSaveImage);

    QWidget* pWidgetBtn = new QWidget(this);
    pWidgetBtn->setLayout(pHLayout_Btn);

    QVBoxLayout* pMainLayout = new QVBoxLayout();
    pMainLayout->setSpacing(1);
    pMainLayout->setMargin(1);
    pMainLayout->addWidget(m_pImageFrame);
    pMainLayout->addStretch(1);
    pMainLayout->addWidget(pWidgetBtn);
    pMainLayout->addStretch(1);

    this->setLayout(pMainLayout);
    
    QObject::connect(pBtnLoadImage, &QPushButton::clicked, this, &QMono8ImageWidget::OnClickLoadImage);
    QObject::connect(pBtnDrawImage, &QPushButton::clicked, this, &QMono8ImageWidget::OnClickDrawImage);
    QObject::connect(pBtnSaveImage, &QPushButton::clicked, this, &QMono8ImageWidget::OnClickSaveImage);

}

void QMono8ImageWidget::OnClickLoadImage()
{
    m_pImageFrame->ShowImage(strImagePath);
}

void QMono8ImageWidget::OnClickDrawImage()
{
    if(!m_pTempImage->load(strImagePath))
        return ;
    if (m_pTempImage->format() == QImage::Format_Indexed8
        || m_pTempImage->format() == QImage::Format_Grayscale8)
        (*m_pTempImage) = m_pTempImage->convertToFormat(QImage::Format_RGB888);


    //画一点缺陷
    QVector<DEFECT_RESULT_t> pVtDefect;
    DEFECT_RESULT_t defect;
    defect.flag = DETECT_FLAG_NG;
    defect.patternName = "TestDefect";
    defect.data.region = QRect(50, 50, 300, 400);
    pVtDefect.append(defect);
    bool bOkImage = false;

    AddSaveTime(m_pTempImage);

    AddMarkInfo(&pVtDefect, m_pTempImage, bOkImage);

    //显示
    m_pImageFrame->ShowImage(*m_pTempImage, nullptr);
}

void QMono8ImageWidget::OnClickSaveImage()
{
    QString strSavePath = ".\\BFSImage\\TestSaveImage.jpg";
    QFile file(strSavePath);
    if (file.exists())
    {
        file.remove();
    }

    //转化
    const QImage* pImage = m_pImageFrame->GetCurrentImage();
    QImage oImage;
    if (pImage->format() == QImage::Format_Indexed8)
    {
        oImage = pImage->convertToFormat(QImage::Format_RGB888);  // mono8 image can't convert
        //oImage = pImage->convertToFormat(QImage::Format_Grayscale8);
        //
        // *m_pixCanvas = QPixmap::fromImage(qImage);
    }
    else
    {
        oImage = pImage->copy();
    }

    //画一点缺陷
    QVector<DEFECT_RESULT_t> pVtDefect;
    DEFECT_RESULT_t defect;
    defect.flag = DETECT_FLAG_NG;
    defect.patternName = "TestDefect";
    defect.data.region = QRect(50, 50, 300, 400);
    pVtDefect.append(defect);
    bool bOkImage = false;
    AddSaveTime(&oImage);
    AddMarkInfo(&pVtDefect, &oImage, bOkImage);

    //存图
    QFileInfo oFileInfo(strSavePath);
    QDir oDir;
    oDir.mkpath(oFileInfo.path());

    oImage.save(strSavePath);
}

void QMono8ImageWidget::AddSaveTime(QImage* pQImage)
{
    QPainter painter(pQImage);
    QFont oFont("Microsoft YaHei", 8, QFont::Normal);
    int nOldPointSize = oFont.pointSize();
    oFont.setPointSize(8);
    painter.setFont(oFont);
    painter.setPen(QColor(139, 139, 139));
    QString strPrompt = QDateTime::currentDateTime().toString("yyyy:MM:dd hh:mm:ss");
    QFontMetrics fontMetrics(oFont);
    int nTextWidth = fontMetrics.width(strPrompt);
    int nTextHeight = fontMetrics.height();
    painter.drawText(pQImage->width() - nTextWidth - DEFECT_INFO_OFFSET / 2, (pQImage->height() - nTextHeight - DEFECT_INFO_OFFSET / 2), strPrompt);
    oFont.setPointSize(nOldPointSize);
    painter.setFont(oFont);
}

void QMono8ImageWidget::AddMarkInfo(const QVector<DEFECT_RESULT_t>* const pVtDefect, QImage* pQImage, bool bOkImage)
{
    QPainter painter(pQImage);

    QColor foreColor = bOkImage ? QColor(0, 255, 0) : QColor(255, 0, 0);
    for (int nIndex = 0, nSize = pVtDefect->size(); nIndex < nSize; ++nIndex)
    {
        const DEFECT_RESULT_t* pDefect = &(pVtDefect->at(nIndex));
        QColor defectColor;
        switch (pDefect->flag)
        {
        case DETECT_FLAG_OK:
            defectColor = QColor(0, 255, 0);
            break;
        case DETECT_FLAG_NG:
            defectColor = QColor(255, 0, 0);
            break;
        default:
            continue;
        }
        DrawMarkInfo(
            &painter,
            ROI_PEN_WIDTH,
            ROI_FONT_SIZE + 8,
            foreColor,
            pDefect->data.region,
            //QString("B-%1. %2").arg(pVTagetDetectParam->predict.base.number)
            QString("%1").arg(pDefect->patternName)
        );
    }
}
void QMono8ImageWidget::DrawMarkInfo(QPainter* const pPainter, const int nPenWidth, const int nFontSize, const QColor& foreColor, const QRect& rcRoi, const QString& strPrompt, Qt::PenStyle penStyle /*= Qt::SolidLine*/)
{
    QPen oPen(penStyle);  //add 20210112 // for draw dash not line when HumanLead work mode.
//QPen oPen(Qt::SolidLine);
    oPen.setWidth(nPenWidth);
    oPen.setColor(foreColor);
    pPainter->setPen(oPen);
    pPainter->drawRect(rcRoi);

    //oPen.setColor(QColor(0, 0, 0));
    pPainter->setPen(oPen);

    QFont oFont("Microsoft YaHei", nFontSize, QFont::Normal);
    pPainter->setFont(oFont);
    QFontMetrics fontMetrics(oFont);
    int nTextHeight = fontMetrics.height();
    int nTextWidth = fontMetrics.width(strPrompt);

    bool bDrawTop = (rcRoi.y() - nTextHeight - DEFECT_INFO_OFFSET) > 0;
    int nYRect = bDrawTop ? (rcRoi.y() - nTextHeight - DEFECT_INFO_OFFSET)
        : (rcRoi.y() + rcRoi.height());
    int nYText = bDrawTop ? (rcRoi.y() - DEFECT_INFO_OFFSET / 2)
        : (rcRoi.y() + rcRoi.height() + nTextHeight + (DEFECT_INFO_OFFSET / 2));

    pPainter->fillRect(rcRoi.x(),
        nYRect,
        nTextWidth + DEFECT_INFO_OFFSET,
        nTextHeight + DEFECT_INFO_OFFSET,
        foreColor
    );
    pPainter->drawRect(rcRoi);
    oPen.setColor(QColor(0, 0, 0));
    pPainter->setPen(oPen);
    pPainter->drawText(rcRoi.x() + DEFECT_INFO_OFFSET / 2, nYText, strPrompt);
}