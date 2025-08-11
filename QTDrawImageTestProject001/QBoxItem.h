#ifndef _QBOXITEM_H_
#define _QBOXITEM_H_

#pragma once

#include "IBoxItem.h"

class QHBoxLayout;
class QLabel;

class QBoxItem : public IBoxItem
{
	Q_OBJECT
public:
	QBoxItem();
	QBoxItem(QString strCaption, QWidget* pWidget, QString strCaptionName = BOX_CAPTION_DEFAULT, Qt::Alignment alignment = Qt::AlignLeft);
	virtual ~QBoxItem();

	virtual void SetCaption(QString strCaption, QString strCaptionName = BOX_CAPTION_DEFAULT) override;

	virtual void AppendWidget(QWidget* pWidget, Qt::Alignment alignment = Qt::AlignLeft) override;

	virtual QWidget* GetWidget(int nIndex) override;

signals:
	void SigEnterEvent();
	void SigLeaveEvent();

protected:
	virtual void InitLayout(QString strBackgroundName = "") override;

private:
	virtual void enterEvent(QEvent * event) override;
	virtual void leaveEvent(QEvent * event) override;

private:
	QHBoxLayout* m_pLayout;
};

#endif