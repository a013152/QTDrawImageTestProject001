#ifndef Q_TIPS_LABEL_H
#define Q_TIPS_LABEL_H

#include <QObject>
#include <QLabel>

class QTipsLabel : public QLabel
{
	Q_OBJECT
public:
	explicit QTipsLabel(QWidget *parent = nullptr);

signals:
	void show();
	void hide();

public slots:

private:
	void enterEvent(QEvent * event);
	void leaveEvent(QEvent * event);


};

#endif // Q_TIPS_LABEL_H


