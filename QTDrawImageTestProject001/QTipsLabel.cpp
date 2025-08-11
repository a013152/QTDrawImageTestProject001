#include "QTipsLabel.h"

QTipsLabel::QTipsLabel(QWidget *parent)
{
	this->setMouseTracking(true);
}

void QTipsLabel::enterEvent(QEvent * event)
{
	emit show();
}

void QTipsLabel::leaveEvent(QEvent * event)
{
	emit hide();
}

