#ifndef FORMMAIN_H
#define FORMMAIN_H

#include <QWidget>
#include <QTimer>

#include "../Database/CCRABDB.h"
#include "../Reader/CReaderThread.h"
#include "../Sound/CSoundPlayer.h"

namespace Ui {
class FormMain;
}

class FormMain : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormMain(QWidget *parent = 0);
    ~FormMain();
    
private slots:
    void on_ButtonGong_clicked();

    void NewCardNumber(const QString& p_CardNumber);

    void on_pushButton_clicked();

private:
    Ui::FormMain *ui;

    /*!
     * \brief m_CRABDB Database access.
     */
    CCRABDB m_CRABDB;

    /*!
     * \brief m_ReaderThread Polls the card reader in a separate thread and sends qt events to this form.
     */
    CReaderThread m_ReaderThread;

    /*!
     * \brief m_SoundPlayer Used to play sounds (gong!).
     */
    CSoundPlayer m_SoundPlayer;

    /*!
     * \brief m_AnimationTimer Is used to display an order and discard any new card numbers from the reader while in the animation.
     */
    QTimer m_AnimationTimer;

};

#endif // FORMMAIN_H
