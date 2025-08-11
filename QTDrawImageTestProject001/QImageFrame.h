#ifndef _QIMAGEFRAME_H_
#define _QIMAGEFRAME_H_

#pragma once

//#include "QStatusDef.h"

#include <QFrame>
#include <QPixmap>

class QPainter;
class QImage;
class IImage;
class QRect;
template<typename Key, typename T>
class QMap;

template<typename T>
class QQueue;
class IImage
{

};
struct IMAGE_SIMPLE_INFO_t
{
	long lModuleType;
	int nCameraIndex;
	int nWidth;
	int nHeight;
	IMAGE_SIMPLE_INFO_t(long moduleType, int cameraIndex, int width, int height)
	{
		lModuleType = moduleType;
		nCameraIndex = cameraIndex;
		nWidth = width;
		nHeight = height;
	}
};

enum ALIGN_FRAME_BORDER_e
{
	ALIGN_UNKNOWN = -1,
	ALIGN_LEFT_TOP = 0,
	ALIGN_RIGHT_TOP = 1,
	ALIGN_RIGHT_BOTTOM = 2,
	ALIGN_LEFT_BOTTOM = 3,
};

enum IMAGE_ROTATE_e
{
	IMAGE_ROTATE_NORMAL= 0,
	IMAGE_ROTATE_90,
	IMAGE_ROTATE_180,
	IMAGE_ROTATE_270,
};

class QImageFrame : public QFrame
{
	Q_OBJECT
public:
	QImageFrame(QWidget* parent = nullptr);
	virtual ~QImageFrame();

	virtual bool ShowImage(IImage* pImage, const long lMarkNumber);

	virtual bool ShowImage(QString strImagePath, IMAGE_ROTATE_e eRotate = IMAGE_ROTATE_NORMAL);

	virtual bool ClearImage();  //clear Pixmap, //add 202021013

	virtual bool ShowImage(QImage& imageObj, IImage const* pImageRef);  //for show Denuo //add 20201020

	virtual bool ShowImageInThread(QImage& imageObj, IImage const* pImageRef);  //add 20210124

	virtual void AddMarkAreas(QString strContent, QRect rect);

	virtual void SetDrawAlign(ALIGN_FRAME_BORDER_e eAlign);

signals:
	void SigCloneCanvas(QPixmap* pPix, QPoint& pt);

	void SigShowImageInMainThread();

public slots:
	void OnCloneCanvas(QPixmap* pPix, QPoint& pt);
	//void OnVideoProcessModeChanged(CAMERA_PROCESS_MODE_e eMode);

	void OnShowImageInMainThread();
protected:
	virtual void ShowImageInMainThreadImpl();
	
protected:
	struct MARK_AREA_t
	{
		QRect rect;
		QString content;
		QColor borderColor;
		QColor backgroundColor;
		QColor contentColor;
		int imageWidth;
		int imageHeight;
	};

protected:
	void paintEvent(QPaintEvent*) override;

	virtual void DrawImage(QPainter* const pPainter, const IImage* const pImage);

	virtual void DrawShape(QPainter* const pPainter, const IImage* const pImage);

	virtual void DrawText(QPainter* const pPainter, const IImage* const pImage);
	
	virtual void DrawCanvas(QPainter* const pPainter, const IImage* const pImage);

	void DrawInfoFromLeftTop(QPainter* const pPainter, QString strInfo);

	void DrawInfoFromLeftBottom(QPainter* const pPainter, QString strInfo);

	void TightenImageQueue(IImage* const pImage);

	void AdjustDisplayEffect(IImage* const pImage);

	virtual void DrawRoi(QPainter* const pPainter, const MARK_AREA_t& stArea, int nBorderWidth);

	void DrawPrompt(QPainter* const pPainter);

	void SetPrompt(QString strInfo, bool bPromptAlarm = false);

	void ClearPrompt();

	void ChangeMarkAreas(QString strContent, QRect rect);

	void DrawImageSpecial(QPainter* const pPainter, QImage* pImage); //add 20210915 // for C6-01 project draw special

	void DrawImageSpecial(QPainter* const pPainter, IImage* pImage); //modify 20220303 // for C031-0003 project draw special

private:
	void CalibCanvasArea(QPixmap& pixCanvas, const IImage* const pImage);

	void DrawImageRoi(QPainter* const pPainter, const IImage* const pImage);

	void DrawMarkAreas(QPainter* const pPainter, const IImage* const pImage);

	bool FillImageRoi(const IImage* const pImage, MARK_AREA_t& stArea);

	bool FillMarkArea(const QString& strContent, const QRect& rect, MARK_AREA_t& stArea);

	void RemoveMarkAreas();

protected:
	QQueue<IImage*>* m_pImageQueue;
	QQueue<long>* m_pMarkNumberQueue;

	int m_nLeftTopCount;
	int m_nLeftBottomCount;

	QPixmap m_pixCanvas;
	QPixmap m_pixClone;
	QPixmap m_pixClear;
	bool m_bShowClone;

	//CAMERA_PROCESS_MODE_e m_eProcessMode;
	int m_nOKDelayShowCount;

	QString m_strPrompt;
	bool m_bPromptAlarm;

	QPoint m_ptCanvas;

	QMap<QString, QRect>* m_pMapMarks;

	//IImage* m_pImageCur; //add 20210915
	IMAGE_SIMPLE_INFO_t* m_pImageCurrentInfo;

	ALIGN_FRAME_BORDER_e m_eDrawAlign;

};
#endif