#include "QThreadTest.h"

#include <QDebug>
#include <QDateTime>
#include <QCoreApplication>

QThreadTest1::QThreadTest1()
{
	m_pWaitCondition = new QWaitCondition();
	m_pMutex = new QMutex();
}

QWaitCondition* QThreadTest1::GetWaitCondition()
{
	return m_pWaitCondition;
}

QMutex* QThreadTest1::GetMutex()
{
	return m_pMutex;
}

void QThreadTest1::run()
{
	for (int nIndex = 0; nIndex < 1; nIndex++)
	{
		
		qDebug() << nIndex << QDateTime::currentDateTime().toString(" hh:mm:ss.zzz") << " TheadTest1 lock mutex";
		m_pMutex->lock();
		qDebug() << nIndex << QDateTime::currentDateTime().toString(" hh:mm:ss.zzz")<< " TheadTest1 waiting condition";
		m_pWaitCondition->wait(m_pMutex);
		qDebug() << nIndex << QDateTime::currentDateTime().toString(" hh:mm:ss.zzz") << " TheadTest1 already waited condition, to do work ";
		m_pMutex->unlock();
		QThread::usleep(10);
		//QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
	}
}

QThreadTest2::QThreadTest2()
{
	m_pWaitCondition = nullptr;
	m_pMutex = nullptr;
}

void QThreadTest2::SetWaitCondition(QWaitCondition* p)
{
	m_pWaitCondition = p;
}

void QThreadTest2::SetMutex(QMutex* p)
{
	m_pMutex = p;
}

void QThreadTest2::run()
{
	if (!m_pMutex || !m_pWaitCondition)
		return;

	m_pMutex->lock();
	qDebug() << QDateTime::currentDateTime().toString(" hh:mm:ss.zzz") << " TheadTest2 wakeAll";
	m_pWaitCondition->wakeAll();
	m_pMutex->unlock();

}
