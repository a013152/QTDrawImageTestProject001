
/**
 * Copyright(c) 2018 ATOM, All Rights Reserved.
 *
 * Filename: QLogReportDataSource.h
 *
 * Spec: check log file.
 *
 * @author       ChenLin
 * @version      1.01         Date: 2022-08-16
 */
#pragma once

#include "IHtmlReportDataSource.h"
struct LOG_INFO_st 
{
	QString dateTime;
	QString type;
	QString account;
	QString content; 
};
template<typename T>
class QList;

class Q_DECL_EXPORT QLogReportDataSource : public IHtmlReportDataSource
{
public:
	explicit QLogReportDataSource(const QString strlogPath);
	virtual ~QLogReportDataSource();
	virtual QString Organize() override;

private:
	bool ReadLogFile(const QString strLogPath);

	bool ReadHtmlTemplateFile(QString strTemplateFile, QString& strHtml);

	bool UpdateTemplateFile(QString strTemplateFile, QString& strHtml, QString& strHtmlFile);

	bool UpdateData(QString& strHtml);

	void UpdateLogInfoList(QString& strHtml);

	void ParseOneLineLogInfo(const QString& strLineLog);

	void GetLogTypeCN(const QString& strTypeEN, LOG_INFO_st& oLogInfo);
private:
	QString m_strUpdateHtmlFile;
	QString m_strLogSource;

	QList<LOG_INFO_st>* m_pListLogInfos;
};

