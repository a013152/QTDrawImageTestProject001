#ifndef _IHTMLREPORTWRITER_H_
#define	_IHTMLREPORTWRITER_H_

#pragma once

#include <QString>

class IHtmlReportDataSource;

class IHtmlReportWriter
{
public:
	virtual ~IHtmlReportWriter() {};

	virtual void SetSavePath(QString strPath) = 0;

	virtual void SetDataSource(IHtmlReportDataSource* pReportDataSource) = 0;

	virtual bool Submit() = 0;
};

#endif