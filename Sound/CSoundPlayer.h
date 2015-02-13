#ifndef CSOUNDPLAYER_H
#define CSOUNDPLAYER_H

#include <QObject>

class QMediaPlayer;

class CSoundPlayer : public QObject
{
    Q_OBJECT
public:
    explicit CSoundPlayer(QObject *parent = 0);
    ~CSoundPlayer();

    void PlayMP3(const QString &p_Filename);
    
signals:
    
public slots:

private:
    QMediaPlayer *m_MediaPlayer;
    
};

#endif // CSOUNDPLAYER_H
