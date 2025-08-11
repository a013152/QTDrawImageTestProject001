#include "QHtmlToPdfReportWriter.h"
#include "IHtmlReportDataSource.h"
#include "wkhtmltox\pdf.h"

#include <QLibrary>
#include <QDir>

const char* const REPORT_FORMAT_PDF = "pdf";

typedef int* (*dll_wkhtmltopdf_init)(int);
typedef wkhtmltopdf_global_settings* (*dll_wkhtmltopdf_create_global_settings)();
typedef int (*dll_wkhtmltopdf_set_global_setting)(wkhtmltopdf_global_settings *, const char *, const char *);
typedef wkhtmltopdf_object_settings* (*dll_wkhtmltopdf_create_object_settings)();
typedef int (*dll_wkhtmltopdf_set_object_setting)(wkhtmltopdf_object_settings *, const char *, const char *);
typedef wkhtmltopdf_converter* (*dll_wkhtmltopdf_create_converter)(wkhtmltopdf_global_settings *);
typedef void (*dll_wkhtmltopdf_add_object)(wkhtmltopdf_converter *, wkhtmltopdf_object_settings *, const char *);
typedef int (*dll_wkhtmltopdf_convert)(wkhtmltopdf_converter *);
typedef void (*dll_wkhtmltopdf_destroy_converter)(wkhtmltopdf_converter *);
typedef int (*dll_wkhtmltopdf_deinit)();

QHtmlToPdfReportWriter::QHtmlToPdfReportWriter()
	: m_pReportDataSource(nullptr),
	m_pWkHtmlDll(nullptr),
	pGlobalSetting(nullptr),
	pObjectSetting(nullptr),
	m_pPdfConverter(nullptr)
{
	m_pWkHtmlDll = new QLibrary("wkhtmltox.dll");
	Q_ASSERT(m_pWkHtmlDll != nullptr);
	bool bSucceed = m_pWkHtmlDll->load();
	Q_ASSERT(bSucceed == true);
}

QHtmlToPdfReportWriter::~QHtmlToPdfReportWriter()
{
	if (m_pReportDataSource != nullptr)
	{
		delete m_pReportDataSource;
		m_pReportDataSource = nullptr;
	}
	if (m_pWkHtmlDll != nullptr)
	{
		if (m_pPdfConverter != nullptr)
		{
			((dll_wkhtmltopdf_destroy_converter)m_pWkHtmlDll->resolve("wkhtmltopdf_destroy_converter"))(m_pPdfConverter);
			((dll_wkhtmltopdf_deinit)m_pWkHtmlDll->resolve("wkhtmltopdf_deinit"))();
			m_pPdfConverter = nullptr;
		}
		m_pWkHtmlDll->unload();
		delete m_pWkHtmlDll;
		m_pWkHtmlDll = nullptr;
	}
}

QString QHtmlToPdfReportWriter::FileExtension()
{
	return REPORT_FORMAT_PDF;
}

QString QHtmlToPdfReportWriter::DefaultPath()
{
	return QString("%1/Report/").arg(QDir::currentPath());
}

void QHtmlToPdfReportWriter::SetSavePath(QString strPath)
{
	m_strSavePath = strPath;
}

void QHtmlToPdfReportWriter::SetDataSource(IHtmlReportDataSource* pReportDataSource)
{
	Q_ASSERT(!m_strSavePath.isEmpty());
	m_pReportDataSource = pReportDataSource;
	InitConverter(pReportDataSource->Organize(), m_strSavePath);
}

bool QHtmlToPdfReportWriter::Submit()
{
	Q_ASSERT(m_pPdfConverter != nullptr);

	dll_wkhtmltopdf_convert pFuncConvert = (dll_wkhtmltopdf_convert)m_pWkHtmlDll->resolve("wkhtmltopdf_convert");
	if (!pFuncConvert(m_pPdfConverter))
	{
		return false;
	}
	return true;
}

void QHtmlToPdfReportWriter::InitConverter(QString strHtmlFile, QString strPdfFile)
{
	dll_wkhtmltopdf_init pFuncInit = (dll_wkhtmltopdf_init)m_pWkHtmlDll->resolve("wkhtmltopdf_init");
	pFuncInit(false);

	dll_wkhtmltopdf_create_global_settings pFuncCreateGlobalSetting = (dll_wkhtmltopdf_create_global_settings)m_pWkHtmlDll->resolve("wkhtmltopdf_create_global_settings");
	pGlobalSetting = pFuncCreateGlobalSetting();

	dll_wkhtmltopdf_set_global_setting pFuncSetGlobalSetting = (dll_wkhtmltopdf_set_global_setting)m_pWkHtmlDll->resolve("wkhtmltopdf_set_global_setting");
	pFuncSetGlobalSetting(pGlobalSetting, "out", strPdfFile.toUtf8());

	dll_wkhtmltopdf_create_object_settings pFuncCreateObjectSetting = (dll_wkhtmltopdf_create_object_settings)m_pWkHtmlDll->resolve("wkhtmltopdf_create_object_settings");
	pObjectSetting = pFuncCreateObjectSetting();

	dll_wkhtmltopdf_set_object_setting pFuncSetObjectSetting = (dll_wkhtmltopdf_set_object_setting)m_pWkHtmlDll->resolve("wkhtmltopdf_set_object_setting");
	pFuncSetObjectSetting(pObjectSetting, "page", strHtmlFile.toUtf8());

	dll_wkhtmltopdf_create_converter pFuncCreateConverter = (dll_wkhtmltopdf_create_converter)m_pWkHtmlDll->resolve("wkhtmltopdf_create_converter");
	m_pPdfConverter = pFuncCreateConverter(pGlobalSetting);

	dll_wkhtmltopdf_add_object pFuncAddObject = (dll_wkhtmltopdf_add_object)m_pWkHtmlDll->resolve("wkhtmltopdf_add_object");
	pFuncAddObject(m_pPdfConverter, pObjectSetting, NULL);
}
