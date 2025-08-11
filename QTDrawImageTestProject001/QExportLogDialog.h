#ifndef _Q_EXPORT_LOG_DIALOG_H_
#define _Q_EXPORT_LOG_DIALOG_H_

/**
 * Copyright(c) 2018 ATOM, All Rights Reserved.
 *
 * ClassName: QExportLogDialog
 *
 * Spec: The dialog use for select date before export log.
 *
 * @author       ChenLin
 * @version      1.01         Date: 2022-08-16
 */

#pragma once

#include "IFramelessDialog.h"
#include <QDate>
#include <QFileInfo>

class QProgressBar;
class QLabel;
class QPushButton;
class QDateTimeEdit;
template<typename T>
class QVector;
class QExportLogWorker;
class QExportLogDialog:public IFramelessDialog
{
	Q_OBJECT
public:
	QExportLogDialog();
	virtual ~QExportLogDialog();
Q_SIGNALS:
	void SigExportProgressChanged(int nStep);

protected slots:
	void OnExportProgress(int nStep);
	void OnBeginDateChanged(const QDate &date);
	void OnEndDateChanged(const QDate &date);
	void OnCLickedBtnReport();
	void OnUpdateExportProgress(int nStep, QString strTip, bool bError);


protected:
	void CreateMember();	
	void ConnectMember();
	void InitLayout(QString strBackgroundName = "") override;
	void ShowPrompt(QString strText = "", bool bAlarm = false);
	
private:
	bool GetLogFileList(const QDate& beginDate, const QDate& endDate, QVector<QFileInfo>* pVtFiles  );

private:
	QPushButton* m_pBtnExport;
	QLabel* m_pLblPrompt;
	QDateTimeEdit* m_pDteStartTime;
	QDateTimeEdit* m_pDteEndTime;
	QProgressBar* m_pExportProgress;

	QVector<QFileInfo>* m_pVtLogFiles;

	QExportLogWorker* m_pExportWork;
	QThread* m_pExportThread;

	QString m_strExportDir;

};


/**
 * Copyright(c) 2018 ATOM, All Rights Reserved.
 *
 * ClassName: QExportLogWorker.h
 *
 * Spec: The exporting log in thread.
 *
 * @author       ChenLin
 * @version      1.01         Date: 2022-08-18
 */

class QExportLogWorker :public QObject
{
	Q_OBJECT
public:
	explicit QExportLogWorker();
	virtual ~QExportLogWorker();
	void SetLogFiles(QVector<QFileInfo>* pVtFiles, QString strExportDir);
	void StartExport();
	bool IsExporting();
Q_SIGNALS:
	void SigStartExport();
	void SigExportProgress(int nStep, QString strTip, bool bError);
protected slots:
	void OnStartExport();
private:
	QVector<QFileInfo>* m_pVtLogFiles;
	bool m_bExporting;
	QString m_strExportDir;
};

#endif
