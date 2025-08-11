#pragma once
#include <QWidget>
#include <QtGui\QColor>
#include <QtGui\QImage>
#include <QRect>
#include "QDefectDataDef.h"
class QImageDetectFrame;
class QImage;
class QPainter;

class QMono8ImageWidget :
    public QWidget
{

    Q_OBJECT

public:
    QMono8ImageWidget();
    ~QMono8ImageWidget() = default;

public slots:
    void OnClickLoadImage();
    void OnClickDrawImage();
    void OnClickSaveImage();

protected:
    void AddSaveTime(QImage* pQImage);

    void AddMarkInfo(const QVector<DEFECT_RESULT_t>* const pVtDefect, QImage* pQImage, bool bOkImage);

    void DrawMarkInfo(QPainter* const pPainter, const int nPenWidth, const int nFontSize, const QColor& foreColor, const QRect& rcRoi, const QString& strPrompt, Qt::PenStyle penStyle = Qt::SolidLine);

private:
    QImageDetectFrame* m_pImageFrame;

    QImage* m_pTempImage;
};

