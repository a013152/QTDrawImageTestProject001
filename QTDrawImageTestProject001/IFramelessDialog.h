#ifndef _IFRAMELESSDLG_H_
#define _IFRAMELESSDLG_H_

#pragma once

#include <QDialog>
#include "IFramelessWidget.h"

class IFramelessDialog : public IFramelessWidget<QDialog>
{
	Q_OBJECT
public:
	IFramelessDialog(QWidget* parent = Q_NULLPTR);
	virtual ~IFramelessDialog();

	void AddCloseButton();

protected slots:
	virtual void OnClickBtnExit();

protected:
	void InitLayout(QString strBackgroundName = "") override;
};

#endif