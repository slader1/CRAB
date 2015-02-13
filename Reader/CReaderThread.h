#ifndef CREADERTHREAD_H
#define CREADERTHREAD_H

#include <QtCore/QThread>

class CReaderThread : public QThread
{
    Q_OBJECT

public:
    explicit CReaderThread(QThread *parent = 0);
    
signals:
    void NewCardNumber(const QString& p_CardNumber);
    
public slots:
    
private:
    void run();

};

#endif // CREADERTHREAD_H
