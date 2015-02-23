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

    /*! Should return an empty string if no card is present at the reader.
     * If an error occurs an exception shall be thrown. */
    QString GetCardNumberFromReader();
};

#endif // CREADERTHREAD_H
