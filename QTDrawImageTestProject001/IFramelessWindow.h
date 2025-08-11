#ifndef _IFRAMELESSWINDOW_H_
#define _IFRAMELESSWINDOW_H_

#pragma once

#include <QFrame>
#include "IFramelessWidget.h"
#include "QMainFormDef.h"

class IFramelessWindow : public IFramelessWidget<QFrame>
{
	Q_OBJECT
public:
	IFramelessWindow(FORM_TYPE_e eFormType = FORM_TYPE_NONE, QWidget* parent = Q_NULLPTR);
	virtual ~IFramelessWindow();

	void AddCloseButton();

	FORM_TYPE_e Mode();

	void SetDeleteLater();

signals:
	void SigWindowClosed(FORM_TYPE_e eForm);

protected slots:
	virtual void OnClickBtnExit();

protected:
	void InitLayout(QString strBackgroundName = "") override;

	virtual bool DoBeforeClose();

	virtual void Dump();

protected:
	bool m_bDeleteLater;
	FORM_TYPE_e m_eFormType;
};

#endif