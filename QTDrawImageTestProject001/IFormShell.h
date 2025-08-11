#ifndef _IFORMSHELL_H_
#define _IFORMSHELL_H_

#pragma once

#include <QWidget>

class QPushButton;

class IFormShell
{
public:
	virtual ~IFormShell() = default;

	virtual QPushButton* CreateUIButton(const QIcon &icon, const char* text, const char *slotMember, int nFixedHeight = -1, int nFixedWidth = -1, QString strToolTip = "") = 0;
	
	virtual QPushButton* CreateUIExitButton(const QIcon &icon, const char* text, const char *slotMember, int nFixedHeight = -1, int nFixedWidth = -1, QString strToolTip = "") = 0;
	
	virtual QPushButton* CreateUIOkButton(const QIcon &icon, const char* text, const char *slotMember, int nFixedHeight = -1, int nFixedWidth = -1, QString strToolTip = "") = 0;
	
	virtual QPushButton* CreateUICancelButton(const QIcon &icon, const char* text, const char *slotMember, int nFixedHeight = -1, int nFixedWidth = -1, QString strToolTip = "") = 0;

protected:
	virtual void InitLayout(QString strBackgroundName = "") = 0;
};
#endif



