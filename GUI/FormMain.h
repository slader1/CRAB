#ifndef FORMMAIN_H
#define FORMMAIN_H

#include <QWidget>

#include "../Database/CCRABDB.h"
#include "../Reader/CReaderThread.h"
#include "../Sound/CSoundPlayer.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_ButtonGong_clicked();

    void NewCardNumber(const QString& p_CardNumber);

private:
    Ui::Widget *ui;

    CCRABDB m_CRABDB;
    CReaderThread m_ReaderThread;
    CSoundPlayer m_SoundPlayer;

};

#endif // FORMMAIN_H
