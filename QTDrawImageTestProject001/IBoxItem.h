#ifndef _IBOXITEM_H_
#define _IBOXITEM_H_

#pragma once

#include <QFrame>
#include <QString>

static const char* BOX_CAPTION_DEFAULT = "boxcaption";

class IBoxItem : public QFrame
{
public:
	virtual ~IBoxItem() = default;

	virtual void SetCaption(QString strCaption, QString strCaptionName = BOX_CAPTION_DEFAULT) = 0;

	virtual void AppendWidget(QWidget* pWidget, Qt::Alignment alignment = Qt::AlignLeft) = 0;

	virtual QWidget* GetWidget(int nIndex) = 0;

protected:
	virtual void InitLayout(QString strBackgroundName = "") = 0;

};
#endif