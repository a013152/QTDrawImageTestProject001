#ifndef _Q_THREAD_TEST_H_
#define _Q_THREAD_TEST_H_

#pragma once
 
#include <QThread>
#include <QWaitCondition>
#include <QMutex>


class QThreadTest1 : public QThread
{
public:
	QThreadTest1();
	~QThreadTest1() = default;
	QWaitCondition* GetWaitCondition();
	QMutex* GetMutex();

public:
	void run() override;

protected:
	QWaitCondition* m_pWaitCondition;
	QMutex* m_pMutex;

};


class QThreadTest2 : public QThread
{
public:
	QThreadTest2();
	~QThreadTest2() = default;
	void SetWaitCondition(QWaitCondition*);
	void SetMutex(QMutex*);

public:
	void run() override;

protected:
	QWaitCondition* m_pWaitCondition;
	QMutex* m_pMutex;

};

#endif