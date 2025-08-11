#include "QNoWheelComboBox.h"

QNoWheelComboBox::QNoWheelComboBox(QWidget * parent)
    : QComboBox(parent)
{
}

QNoWheelComboBox::~QNoWheelComboBox()
{
}

void QNoWheelComboBox::wheelEvent(QWheelEvent * event)
{
}