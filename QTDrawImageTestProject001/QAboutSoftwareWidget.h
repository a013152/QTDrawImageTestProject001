#ifndef _Q_ABOUT_SOFTWARE_WIDGET_H_
#define _Q_ABOUT_SOFTWARE_WIDGET_H_

#pragma once

/**
 * Copyright(c) 2018 ATOM, All Rights Reserved.
 *
 * Filename: QAboutSoftwareWidget.h
 *
 * Spec: show the software version
 *
 * @author       ChenLin
 * @version      1.01         Date: 2022-8-8
 */

#include <QWidget>
class QLabel;

class QAboutSoftwareWidget : public QWidget
{
	Q_OBJECT
public:
	explicit QAboutSoftwareWidget(QWidget *parent = nullptr);
	virtual ~QAboutSoftwareWidget();

public:
	void InitLayout();
	void CreateMember();

protected:
	QLabel* m_pLabLogo;
	QLabel* m_pLabSoftware;
	QLabel* m_pLabCompany;

};
#endif