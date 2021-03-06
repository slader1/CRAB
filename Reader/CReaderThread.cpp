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
        QThread::msleep(2000);
        qDebug("Thread loop");
        QString l_CardNumber = GetCardNumberFromReader();
        if(l_CardNumber.isEmpty() == false)
        {
            emit NewCardNumber(l_CardNumber);
        }
        QThread::msleep(8000);
    }
}

QString CReaderThread::GetCardNumberFromReader()
{
    return "0";
}
