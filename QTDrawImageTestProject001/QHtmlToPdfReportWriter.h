#ifndef _QHTMLTOPDFREPORTWRITER_H_
#define _QHTMLTOPDFREPORTWRITER_H_

#pragma once

#include "IHtmlReportWriter.h"

class IHtmlReportDataSource;
class wkhtmltopdf_global_settings;
class wkhtmltopdf_object_settings;
class wkhtmltopdf_converter;
class QLibrary;

class Q_DECL_EXPORT QHtmlToPdfReportWriter : public IHtmlReportWriter
{
public:
	QHtmlToPdfReportWriter();
	virtual ~QHtmlToPdfReportWriter();

public:
	static QString FileExtension();

	static QString DefaultPath();

	virtual void SetSavePath(QString strPath) override;

	virtual void SetDataSource(IHtmlReportDataSource* pReportDataSource) override;

	virtual bool Submit() override;

private:
	void InitConverter(QString strHtmlFile, QString strPdfFile);

private:
	QString m_strSavePath;
	IHtmlReportDataSource* m_pReportDataSource;
	QLibrary* m_pWkHtmlDll;
	wkhtmltopdf_global_settings* pGlobalSetting;
	wkhtmltopdf_object_settings* pObjectSetting;
	wkhtmltopdf_converter* m_pPdfConverter;
};

#endif