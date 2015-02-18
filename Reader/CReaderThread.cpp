#include "CReaderThread.h"

#include <QtCore/QFile>

CReaderThread::CReaderThread(QThread *parent) :
    QThread(parent)
{
}

void CReaderThread::run()
{
    forever
    {
        qDebug("Thread loop");
        emit NewCardNumber("0");
        QThread::msleep(10000);
    }
}
