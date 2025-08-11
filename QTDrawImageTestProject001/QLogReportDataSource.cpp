#include "QLogReportDataSource.h"
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDateTime>

const int LOG_INFO_LEAST_COUNT = 10;

const char* const TEMPLATE_FILE_NAME = "logtemplatereport.html";
const char* const TEMPORARY_FILE_NAME = "logReportDataSoruce.html";

const char* const LOGO_PATH_NAME = "@logopath";
const char* const DEVICE_NUMBER_NAME = "@devicenumber";
const char* const PRINT_TIME_NAME = "@printtime";

const char* const LOG_INFO_LIST_NAME = "@loginfolist";
const char* const LOG_TYPE_NAME_CN[]{
"人员操作","系统消息","系统错误","系统警告","系统调试"
};

QLogReportDataSource::QLogReportDataSource(const QString strlogPath)
	:m_pListLogInfos(nullptr)
{
	m_pListLogInfos = new QList<LOG_INFO_st>();
	if (ReadLogFile(strlogPath) == true)
	{
		
	}
}

QLogReportDataSource::~QLogReportDataSource()
{
	if (m_pListLogInfos) {
		delete m_pListLogInfos;
		m_pListLogInfos = nullptr;
	}
}

QString QLogReportDataSource::Organize()
{
	QString strHtml;
	QString strTemplatePath = QString("%1/Report/Template/").arg(QDir::currentPath());
	QDir dir;
	dir.mkpath(strTemplatePath);
	QString strTemplateFile = strTemplatePath + TEMPLATE_FILE_NAME;
	if (!ReadHtmlTemplateFile(strTemplateFile, strHtml))
	{
		return "";
	}

	if (!UpdateTemplateFile(strTemplateFile, strHtml, m_strUpdateHtmlFile))
	{
		return "";
	}
	return m_strUpdateHtmlFile;
}

bool QLogReportDataSource::ReadLogFile(const QString strLogPath)
{
	QFile oFile(strLogPath);
	if (!oFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return false;
	}
	while (!oFile.atEnd())
	{
		QByteArray line = oFile.readLine();
		QString strSource = QString::fromLocal8Bit(line);
		ParseOneLineLogInfo(strSource);
	}
	oFile.close();
	return true;
}

bool QLogReportDataSource::ReadHtmlTemplateFile(QString strTemplateFile, QString& strHtml)
{
	QFile oFile(strTemplateFile);
	if (!oFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return false;
	}
	strHtml = oFile.readAll();
	oFile.close();
	return strHtml.size() != 0;
}

bool QLogReportDataSource::UpdateTemplateFile(QString strTemplateFile, QString& strHtml, QString& strHtmlFile)
{
	if (!UpdateData(strHtml))
	{
		return false;
	}
	QFileInfo fi(strTemplateFile);
	strHtmlFile = fi.absolutePath() + "//" + TEMPORARY_FILE_NAME;
	QFileInfo ofiletemp(strHtmlFile);
	if (ofiletemp.exists() == true)
	{
		ofiletemp.dir().remove(ofiletemp.fileName());
	}
	QFile oFile(strHtmlFile);
	if (!oFile.open(QIODevice::WriteOnly))
	{
		return false;
	}
	QTextStream out(&oFile);
	out.setCodec("UTF-8");
	out << strHtml;
	oFile.close();
	return true;
}

bool QLogReportDataSource::UpdateData(QString& strHtml)
{
	if (m_pListLogInfos->isEmpty())
		return false;
	strHtml.replace(DEVICE_NUMBER_NAME, "DTC")\
		//.replace(PRINT_TIME_NAME, QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
		.replace(PRINT_TIME_NAME, QString("2021-11-04 22:24:20"));
	
	UpdateLogInfoList(strHtml);
	return true;
}

void QLogReportDataSource::UpdateLogInfoList(QString& strHtml)
{
	if (m_pListLogInfos->isEmpty())
		return;
	QString strDetectInfoList;
	int nLoopCount = std::max(m_pListLogInfos->size(), LOG_INFO_LEAST_COUNT);
	int nLoopIndex = -1;
	while (++nLoopIndex < nLoopCount)
	{
		if (nLoopIndex < m_pListLogInfos->size())
		{
			strDetectInfoList += QString("<tr><td>%1</td><td>%2</td><td>%3</td><td>%4</td></tr>\n")				
				.arg(m_pListLogInfos->at(nLoopIndex).dateTime)
				.arg(m_pListLogInfos->at(nLoopIndex).type)
				.arg(m_pListLogInfos->at(nLoopIndex).account)
				.arg(m_pListLogInfos->at(nLoopIndex).content);
		}
		else
		{
			strDetectInfoList += QString("<tr><td></td><td></td><td></td><td></td></tr>\n");
		}
	}
	strHtml.replace(LOG_INFO_LIST_NAME, strDetectInfoList);
}

void QLogReportDataSource::ParseOneLineLogInfo(const QString& strLineLog)
{
	//20220815 14:38:37.418 [UI          ]pid@13820 (Message)>System:------------ App End   ------------
	LOG_INFO_st oLogInfo;
	int nPos1 = strLineLog.indexOf('[');
	int nPos2 = strLineLog.indexOf('(', nPos1);
	int nPos3 = strLineLog.indexOf('>', nPos2);
	int nPos4 = strLineLog.indexOf(':', nPos3);

	oLogInfo.dateTime = strLineLog.left(nPos1);
	QString strTypeEN = strLineLog.mid(nPos2 + 1, nPos3 - 1 - nPos2 - 1);
	GetLogTypeCN(strTypeEN, oLogInfo);
	oLogInfo.account = strLineLog.mid(nPos3 + 1, nPos4 - 1 - nPos3);
	oLogInfo.content = strLineLog.mid(nPos4 + 1 );
	m_pListLogInfos->append(oLogInfo);
}

void QLogReportDataSource::GetLogTypeCN(const QString& strTypeEN, LOG_INFO_st& oLogInfo)
{
	/*const char* const LOG_TYPE_NAME_CN[]{
"人员操作","系统消息","系统错误","系统警告","系统调试"
};*/
	if (strTypeEN.contains("Action"))
	{
		oLogInfo.type = QString::fromLocal8Bit(LOG_TYPE_NAME_CN[0]);
	}
	else if(strTypeEN.contains("Message"))
	{
		oLogInfo.type = QString::fromLocal8Bit(LOG_TYPE_NAME_CN[1]);
	}
	else if (strTypeEN.contains("Error"))
	{
		oLogInfo.type = QString::fromLocal8Bit(LOG_TYPE_NAME_CN[2]);
	}
	else if (strTypeEN.contains("Debug"))
	{
		oLogInfo.type = QString::fromLocal8Bit(LOG_TYPE_NAME_CN[3]);
	}
	else
	{
		oLogInfo.type = strTypeEN;
	}
}
