#pragma once

#include <QComboBox>

class Q_DECL_EXPORT QNoWheelComboBox : public QComboBox
{
public:
    explicit QNoWheelComboBox(QWidget *parent = nullptr);
    virtual ~QNoWheelComboBox();

protected:
    void wheelEvent(QWheelEvent* event);
};
