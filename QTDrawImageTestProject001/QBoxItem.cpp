#include "QBoxItem.h"

#include <QHBoxLayout>
#include <QLabel>

const char* BOX_ITEM_BACKGROUND_NAME = "boxitembg";

QBoxItem::QBoxItem()
	: m_pLayout(nullptr)
{
	InitLayout(BOX_ITEM_BACKGROUND_NAME);
}

QBoxItem::QBoxItem(QString strCaption, QWidget* pWidget, QString strCaptionName /*= BOX_CAPTION_DEFAULT*/, Qt::Alignment alignment /*= Qt::AlignLeft*/)
{
	InitLayout(BOX_ITEM_BACKGROUND_NAME);
	SetCaption(strCaption, strCaptionName);
	AppendWidget(pWidget, alignment);
}

QBoxItem::~QBoxItem()
{

}

void QBoxItem::SetCaption(QString strCaption, QString strCaptionName /*= BOX_CAPTION_DEFAULT*/)
{
	QLabel* pLblCaption = new QLabel(strCaption);
	pLblCaption->setObjectName(strCaptionName);
	m_pLayout->insertWidget(0, pLblCaption);
}

void QBoxItem::AppendWidget(QWidget* pWidget, Qt::Alignment alignment /*= Qt::AlignLeft*/)
{
	m_pLayout->insertWidget(m_pLayout->count() - 1, pWidget, alignment);
}

QWidget* QBoxItem::GetWidget(int nIndex)
{
	if (nIndex >= m_pLayout->count() - 1)
	{
		return nullptr;
	}
	return m_pLayout->itemAt(nIndex + 1)->widget();
}

void QBoxItem::InitLayout(QString strBackgroundName /*= ""*/)
{
	setObjectName(strBackgroundName);
	m_pLayout = new QHBoxLayout();
	m_pLayout->setContentsMargins(0, 0, 10, 0);
	m_pLayout->addStretch();
	setLayout(m_pLayout);
}

void QBoxItem::enterEvent(QEvent * event)
{
	emit SigEnterEvent();
}

void QBoxItem::leaveEvent(QEvent * event)
{
	emit SigLeaveEvent();
}
