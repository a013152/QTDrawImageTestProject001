#ifndef _Q_IMAGE_DETECT_FRAME_H_
#define _Q_IMAGE_DETECT_FRAME_H_

/**
 * Copyright(c) 2018 ATOM, All Rights Reserved.
 *
 * Filename: QImageDetectFrame.h
 *
 * Spec: The frame use for show detect image .
 *
 * @author       ChenLin
 * @version      1.01         Date: 2020-10-21
 */

#pragma once

//#include "QStatusDef.h"
#include "QImageFrame.h" 

class QPainter; 
class QRect;
template<typename Key, typename T>
class QMap;

template<typename T>
class QQueue;
class IImage;

class QImageDetectFrame : public QImageFrame
{
	Q_OBJECT
public:
	QImageDetectFrame(QWidget* parent = nullptr);
	virtual ~QImageDetectFrame(); 

	virtual bool ShowImage(QString strImagePath, IMAGE_ROTATE_e eRotate = IMAGE_ROTATE_NORMAL) override;

	virtual bool ShowImage(QImage& imageObj, IImage const* pImageRef) override;  //for show Denuo //add 20201020

	virtual bool ShowImageInThread(QImage& imageObj, IImage const* pImageRef) override;  //add 20210124

	virtual bool ClearImage();  //clear Pixmap, //add 202021013 
   
	virtual void AddMarkAreas(QString strContent, QRect rect);

    const QImage* GetCurrentImage();

protected:
	virtual void ShowImageInMainThreadImpl() override;

protected:
	virtual void paintEvent(QPaintEvent*) override;

	virtual void DrawImage(QPainter* const pPainter, const QImage& qImage);

	virtual void DrawShape(QPainter* const pPainter, const QImage& qImage);

	virtual void DrawText(QPainter* const pPainter, const QImage& qImage);
	
	virtual void DrawCanvas(QPainter* const pPainter, const QImage& qImage);

	virtual void DrawRoi(QPainter* const pPainter, const MARK_AREA_t& stArea, int nBorderWidth);

	//void DrawInfoFromLeftTop(QPainter* const pPainter, QString strInfo);

	//void DrawInfoFromLeftBottom(QPainter* const pPainter, QString strInfo);

	void TightenImageQueue(const QImage& qImage);

	//void AdjustDisplayEffect(IImage* const pImage);

	//void DrawRoi(QPainter* const pPainter, const MARK_AREA_t& stArea, int nBorderWidth);

	//void DrawPrompt(QPainter* const pPainter);

	//void SetPrompt(QString strInfo, bool bPromptAlarm = false);

	//void ClearPrompt(); 
	

protected:
	void CalibCanvasArea(QPixmap& pixCanvas, const QImage& qImage);

	void DrawImageRoi(QPainter* const pPainter, const QImage& qImage);

	void DrawMarkAreas(QPainter* const pPainter, const QImage& qImage);

	bool FillImageRoi(const QImage& qImage, MARK_AREA_t& stArea);

	bool FillMarkArea(const QString& strContent, const QRect& rect, MARK_AREA_t& stArea);	 

protected:
	QQueue<QImage>* m_pQImageQueue;

	bool m_bShowed;
	//int m_nLeftTopCount;
	//int m_nLeftBottomCount;

	//QPixmap m_pixCanvas;
	//QPixmap m_pixClone;
	//QPixmap m_pixClear;
	//bool m_bShowClone;

	//CAMERA_PROCESS_MODE_e m_eProcessMode;
	//int m_nOKDelayShowCount;

	//QString m_strPrompt;
	//bool m_bPromptAlarm;

	//QPoint m_ptCanvas;

	//QMap<QString, QRect>* m_pMapMarks;

};
#endif