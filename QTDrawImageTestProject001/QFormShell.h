#ifndef _QFORMSHELL_H_
#define _QFORMSHELL_H_

#pragma once

#include "IFormShell.h"
#include "QIconPathDef.h"

#include <QWidget>
#include <QPushButton>
#include <QVariant>
#include <QFile>

template <typename T>
class QFormShell : public T, public IFormShell
{
public:
	QFormShell(QWidget* parent = Q_NULLPTR):T(parent){};
	virtual ~QFormShell() {};

public:
	virtual QPushButton* CreateUIButton(const QIcon &icon, const char* text, const char* slotMember, int nFixedHeight = -1, int nFixedWidth = -1, QString strToolTip = "") override
	{
		QPushButton* pButton = new QPushButton(icon, text);
		pButton->setFlat(true);
		if (nFixedHeight > 0)
		{
			pButton->setFixedHeight(nFixedHeight);
		}
		if (nFixedWidth > 0)
		{
			pButton->setFixedWidth(nFixedWidth);
		}
		if (!strToolTip.isEmpty())
		{
			pButton->setToolTip(strToolTip);
		}
		if (slotMember != nullptr)
		{
			QObject::connect(pButton, SIGNAL(clicked()), this, slotMember);
		}
		return pButton;
	}

	virtual QPushButton* CreateUIExitButton(const QIcon &icon, const char* text, const char* slotMember, int nFixedHeight = -1, int nFixedWidth = -1, QString strToolTip = "") override
	{
		QPushButton* pButton = nullptr;
		if (icon.isNull() && QFile::exists(ICON_BUTTON_CLOSE_PATH))
		{
			pButton = CreateUIButton(QIcon(ICON_BUTTON_CLOSE_PATH), "", slotMember, nFixedHeight, nFixedWidth, strToolTip);
		}
		else
		{
			pButton = CreateUIButton(icon, text, slotMember, nFixedHeight, nFixedWidth, strToolTip);
		}
		pButton->setProperty("behavior", "exit");
		return pButton;
	}

	virtual QPushButton* CreateUIOkButton(const QIcon &icon, const char* text, const char* slotMember, int nFixedHeight = -1, int nFixedWidth = -1, QString strToolTip = "") override
	{
		QPushButton* pButton = CreateUIButton(icon, text, slotMember, nFixedHeight, nFixedWidth, strToolTip);
		pButton->setProperty("behavior", "apply");
		return pButton;
	}

	virtual QPushButton* CreateUICancelButton(const QIcon &icon, const char* text, const char* slotMember, int nFixedHeight = -1, int nFixedWidth = -1, QString strToolTip = "") override
	{
		QPushButton* pButton = CreateUIButton(icon, text, slotMember, nFixedHeight, nFixedWidth, strToolTip);
		pButton->setProperty("behavior", "cancel");
		return pButton;
	}
};
#endif
