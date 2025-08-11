#include "QExportLogDialog.h"
#include <QLabel>
#include <QProgressBar>
#include <QDebug>
#include <QDateTimeEdit>
#include <QFileDialog>
#include "QHtmlToPdfReportWriter.h"
#include "QLogReportDataSource.h"
#include <QThread>
#include <QTime>

#pragma execution_character_set("utf-8")

const char* const SZ_DIALOG_CAPTION = "操作记录导出";
const char* const SZ_BEGIN_DATE = "开始日期";
const char* const SZ_END_DATE = "结束日期";
const char* const SZ_BEGIN_EXPORT = "\r\n开始\r\n\r\n导出\r\n";
const char* const SZ_END_EXPORT = "\r\n结束\r\n\r\n导出\r\n";
const char* const SZ_EXPORT_DATE_ERROR = "选择日期错误，日期范围只能大于1天且小于10天";
const char* const SZ_EXPORT_DATE_INTERVAL = "导出记录的日期间隔%1天";
const char* const SZ_EXPORT_NO_LOG_FILES = "日期间隔内未找到日志文件";

const char* const ACT_EXPORT_LOG_REPORT = "开始对操作记录生成报告..";
const char* const MSG_LOG_REPORT_SAVE_DIALOG_NAME = "请选择保存报告的路径";
const char* const MSG_LOG_REPORT_SAVE_RESULT_SUCCEED = "导出完成!!总耗时%2ms 路径：%1 ";
const char* const ERR_LOG_REPORT_SAVE_RESULT_FAILURE = "生产记录报告保存失败!!";
const char* const MSG_EXPORT_PROGRESS = "导出进度(%1/%2), 导出%3文件已完成，耗时%4ms";
const char* const ERR_EXPORT_PROGRESS = "导出进度(%1/%2), 导出%3文件错误，导出终止.";

QExportLogDialog::QExportLogDialog()
	: IFramelessDialog(),
	m_pExportProgress(nullptr)
	,m_pBtnExport(nullptr)
	,m_pDteEndTime(nullptr)
	,m_pDteStartTime(nullptr)
	,m_pLblPrompt(nullptr)

{
	IFramelessDialog::InitLayout("popupdlgbackground");
	SetupTitleBar(QString(SZ_DIALOG_CAPTION), "popupdlgtitle", "popupdlgcaption");
	AddCloseButton();
	SetMoveEnable(true);
	SetScaleEnable(false);

	CreateMember();
	InitLayout("popupdlgcontent");

	ConnectMember();
	m_pExportWork->moveToThread(m_pExportThread);
	m_pExportThread->start();
}

QExportLogDialog::~QExportLogDialog()
{
	if (m_pExportThread != nullptr&&
		m_pExportThread->isRunning())
	{
		m_pExportThread->quit();
		m_pExportThread->wait();
	}
	if (m_pExportWork) {
		delete m_pExportWork; m_pExportWork = nullptr;
	}
}

void QExportLogDialog::CreateMember()
{
	//member
	m_pVtLogFiles = new QVector<QFileInfo>();
	m_pExportWork = new QExportLogWorker();
	m_pExportThread = new QThread();

	//ui
	m_pDteStartTime = new QDateTimeEdit(QDateTime::currentDateTime().addDays(-1));
	m_pDteEndTime = new QDateTimeEdit(QDateTime::currentDateTime());
	m_pBtnExport = new QPushButton(QString(SZ_BEGIN_EXPORT));
	m_pExportProgress = new QProgressBar();
	m_pLblPrompt = new QLabel("Tip:");

}

void QExportLogDialog::ConnectMember()
{
	// connect ui
	QObject::connect(m_pDteStartTime, &QDateTimeEdit::dateChanged, this, &QExportLogDialog::OnBeginDateChanged);
	QObject::connect(m_pDteEndTime, &QDateTimeEdit::dateChanged, this, &QExportLogDialog::OnBeginDateChanged);
	//QObject::connect(this, &QExportLogDialog::SigExportProgressChanged, this, &QExportLogDialog::OnExportProgress);
	//QObject::connect(this, &QExportLogDialog::SigExportProgressChanged, this, &QExportLogDialog::OnExportProgress);
	QObject::connect(m_pBtnExport, &QPushButton::clicked, this, &QExportLogDialog::OnCLickedBtnReport);

	//connect member
	QObject::connect(m_pExportWork, &QExportLogWorker::SigExportProgress, this, &QExportLogDialog::OnUpdateExportProgress);
}

void QExportLogDialog::InitLayout(QString strBackgroundName /*= ""*/)
{
	resize(400, 300);
	QVBoxLayout* pMainLayout = new QVBoxLayout();
	QGridLayout* pOperaterLayout = new QGridLayout();

	m_pDteStartTime->setCalendarPopup(true);
	m_pDteEndTime->setCalendarPopup(true);

	m_pExportProgress->setValue(0);
	m_pExportProgress->setAlignment(Qt::AlignCenter);

	pOperaterLayout->addWidget(new QLabel(QString(SZ_BEGIN_DATE)), 0, 0);
	pOperaterLayout->addWidget(m_pDteStartTime, 0, 1);
	pOperaterLayout->addWidget(new QLabel(QString(SZ_END_DATE)), 1, 0);
	pOperaterLayout->addWidget(m_pDteEndTime, 1, 1);
	pOperaterLayout->addWidget(m_pBtnExport, 0, 2, 2, 1);
	pOperaterLayout->setMargin(24);
	pOperaterLayout->setSpacing(8);

	QWidget* pOperWidget = new QWidget();
	pOperWidget->setLayout(pOperaterLayout);

	pMainLayout->addWidget(pOperWidget);
	pMainLayout->addWidget(m_pExportProgress);
	pMainLayout->addWidget(m_pLblPrompt);

	pMainLayout->setStretch(0, 2);
	pMainLayout->setStretch(1, 1);
	pMainLayout->setStretch(2, 1);
	//pMainLayout->setRowStretch(3, 1);

	QFrame* pContentFrame = new QFrame();

	pContentFrame->setObjectName(strBackgroundName);
	pContentFrame->setLayout(pMainLayout);
	AppendWidget(pContentFrame);

}
void QExportLogDialog::OnExportProgress(int nStep)
{
	m_pExportProgress->setValue(nStep);
}

void QExportLogDialog::OnBeginDateChanged(const QDate &date)
{
	QDate dateBegin = m_pDteStartTime->date();

	QDate dateEnd = m_pDteEndTime->date();

	int days = dateBegin.daysTo(dateEnd);

	qDebug() << "time2 - time1=" << days;
	if (days > 10 || days < 1)
		ShowPrompt(QString(SZ_EXPORT_DATE_ERROR), true);
	else
		ShowPrompt(QString(SZ_EXPORT_DATE_INTERVAL).arg(days));
	//emit emit SigExportProgressChanged(10);
}

void QExportLogDialog::OnEndDateChanged(const QDate &date)
{


}


void QExportLogDialog::OnCLickedBtnReport()
{
	//UI_LOG_ACT1(ACT_EXPORT_LOG_REPORT);
	QDate dateBegin = m_pDteStartTime->date();
	QDate dateEnd = m_pDteEndTime->date();
	int days = dateBegin.daysTo(dateEnd);
	if (days > 10 || days < 1)
	{
		ShowPrompt(QString(SZ_EXPORT_DATE_ERROR), true);
		return;
	}

	//select directory to export
	QFileDialog fileDialog;
	m_strExportDir = fileDialog.getExistingDirectory(this,\
		QString(MSG_LOG_REPORT_SAVE_DIALOG_NAME),"D:/");
	if (m_strExportDir.isEmpty())
		return;

	if (m_strExportDir.isEmpty())
	{
		return;
	}	

	//get log files list
	if (GetLogFileList(dateBegin, dateEnd, m_pVtLogFiles) == false)
	{
		return ;
	}
	if (m_pVtLogFiles->isEmpty())
	{
		ShowPrompt(QString(SZ_EXPORT_NO_LOG_FILES), false);
		return;
	}

	//start to export
	m_pExportWork->SetLogFiles(m_pVtLogFiles, m_strExportDir);
	m_pExportWork->StartExport();

	//lock ui
	m_pBtnExport->setEnabled(false);

}

void QExportLogDialog::OnUpdateExportProgress(int nStep, QString strTip, bool bError)
{	
	OnExportProgress(nStep);
	ShowPrompt(strTip, bError);
	if (nStep == 100 || bError == true)
	{
		m_pBtnExport->setEnabled(true);		
	}
}


void QExportLogDialog::ShowPrompt(QString strText /*= ""*/, bool bAlarm /*= false*/)
{
	if (!strText.isEmpty())
	{
		//UI_LOG_WRN1(strText);
	}
	m_pLblPrompt->setText(strText);
	if (bAlarm)
	{
		m_pLblPrompt->setStyleSheet("color: red;");
	}
	else
	{
		m_pLblPrompt->setStyleSheet("color: rgb(255,214,100);");
	}
}

bool QExportLogDialog::GetLogFileList(const QDate& beginDate, const QDate& endDate, QVector<QFileInfo>* pVtFiles)
{
	if (pVtFiles == nullptr)
		return false;
	QString strLogDir = QString("%1/Log").arg(QDir::currentPath());
	QDir dir(strLogDir);
	if (!dir.exists())
		return false;
	dir.setFilter(QDir::Dirs | QDir::Files);
	dir.setSorting(QDir::DirsFirst);
	QFileInfoList list = dir.entryInfoList();
	int nIndexFile = 0;
	pVtFiles->clear();
	do {
		QFileInfo fileInfo = list.at(nIndexFile);
		QString strFileName = fileInfo.fileName();
		if (strFileName == "." | strFileName == "..")
		{
			nIndexFile++;
			continue;
		}
		bool bisDir = fileInfo.isDir();
		if (bisDir)
		{
			nIndexFile++;
			continue;
		}
		QDateTime oFileDate = QDateTime::fromString(fileInfo.baseName().left(8), "yyyyMMdd");
		int days1 = beginDate.daysTo(oFileDate.date());
		int days2 = oFileDate.date().daysTo(endDate);
		if (days1 >= 0 && days2 >=0)
		{
			pVtFiles->append(fileInfo);
		}		
		nIndexFile++;
	} while (nIndexFile < list.size());
	return pVtFiles->size() > 0;
}

QExportLogWorker::QExportLogWorker()
	:QObject()
	,m_pVtLogFiles(nullptr)
	, m_bExporting(false)
{
	QObject::connect(this, &QExportLogWorker::SigStartExport, this, &QExportLogWorker::OnStartExport);
}

QExportLogWorker::~QExportLogWorker()
{

}

void QExportLogWorker::SetLogFiles(QVector<QFileInfo>* pVtFiles, QString strExportDir)
{
	m_pVtLogFiles = pVtFiles;
	m_strExportDir = strExportDir;
}

void QExportLogWorker::StartExport()
{
	emit SigStartExport();
}

bool QExportLogWorker::IsExporting()
{
	return m_bExporting;
}

void QExportLogWorker::OnStartExport()
{
	if (m_pVtLogFiles == nullptr
		&& m_pVtLogFiles->isEmpty())
		return;
	m_bExporting = true;

	QTime oTime1; oTime1.start();
	QTime oTime2;
	//loop export
	bool bError = false;
	int nSize = m_pVtLogFiles->size();
	for (int nIndex = 0; nIndex < nSize; nIndex++)
	{
		oTime2.start();
		QString strFirstLogPath = m_pVtLogFiles->at(nIndex).absoluteFilePath();
		QString strSavePath = QString("%1%2.%3").arg(m_strExportDir)\
			.arg(m_pVtLogFiles->at(nIndex).baseName())\
			.arg(QHtmlToPdfReportWriter::FileExtension());
		QFileInfo ofiletemp(strSavePath);
		if (ofiletemp.exists() == true)
		{
			ofiletemp.dir().remove(ofiletemp.fileName());
		}

		QHtmlToPdfReportWriter oPdfReportWriter;
		oPdfReportWriter.SetSavePath(strSavePath);
		oPdfReportWriter.SetDataSource(new QLogReportDataSource(strFirstLogPath));
		if (oPdfReportWriter.Submit())
		{
			// success
			int nProgress = (int)((((nIndex + 1)*1.0) / nSize) * 100);
			QString strTip = QString(MSG_EXPORT_PROGRESS)\
				.arg(nIndex).arg(nSize).arg(strSavePath).arg(oTime2.elapsed());
			emit SigExportProgress(nProgress, strTip, bError);
		}
		else
		{
			// failed
			bError = true;
			int nProgress = (int)((((nIndex + 1)*1.0) / nSize) * 100);
			QString strTip = QString(ERR_EXPORT_PROGRESS).arg(nIndex).arg(nSize).arg(strSavePath);
			emit SigExportProgress(nProgress, strTip, bError);
			break;
		}
	}
	if (bError == false)
	{
		QString strTip = QString(MSG_LOG_REPORT_SAVE_RESULT_SUCCEED)\
			.arg(m_strExportDir).arg(oTime1.elapsed());
		emit SigExportProgress(100, strTip, bError);
	}


	m_bExporting = false;
}
