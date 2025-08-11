#ifndef Q_FAILURE_COUNT_FLOAT_PAN_H
#define Q_FAILURE_COUNT_FLOAT_PAN_H

#include "IFramelessWindow.h"

/**
 * Copyright(c) 2018 ATOM, All Rights Reserved.
 *
 * Filename: QFailureCountFloatPan.h
 * Spec: use for show defect detail
 *
 * @author       ChenLin
 * @version      1.01         Date: 2022-06-15
 */
class QTableWidget;
class QLineEdit;
class IDetectParam;
struct DEFECT_STATISTIC_t;
class QFailureCountFloatPan : public IFramelessWindow
{
public:
	explicit QFailureCountFloatPan(QWidget *parent = Q_NULLPTR, QString text = "default");
	~QFailureCountFloatPan();

	void UpdateFailureInfo();

protected:
	void InitLayout();

private:
	QLineEdit* m_pEdtDefectProductTotal;
	QLineEdit* m_pEdtFailureTotal;
	QTableWidget* m_pTwDefectInfo;
	IDetectParam* m_pDetectParam;

public:
	DEFECT_STATISTIC_t * m_pStatistic;
};
#endif // Q_FLOAT_PAN_H

