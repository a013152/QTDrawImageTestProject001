#ifndef _IHTMLREPORTDATASOCURE_H_
#define _IHTMLREPORTDATASOCURE_H_

#pragma once

#include <QString>

class IHtmlReportDataSource
{
public:
	virtual ~IHtmlReportDataSource() {};

	virtual QString Organize() = 0;
};

#endif