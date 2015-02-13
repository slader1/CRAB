#include "CReaderThread.h"

#include <QtCore/QFile>

CReaderThread::CReaderThread(QThread *parent) :
    QThread(parent)
{
}

void CReaderThread::run()
{
    while(1)
    {
        qDebug("Thread loop");
        QFile l_File("CardNumber");
        QString l_CardNumber = l_File.readAll();
        l_File.remove();
        emit NewCardNumber(l_CardNumber);
        sleep(10000);
    }
}
