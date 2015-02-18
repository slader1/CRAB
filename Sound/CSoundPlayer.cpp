#include "CSoundPlayer.h"

#include <QMediaPlayer>
#include <QMediaObject>
#include <QMediaPlaylist>

CSoundPlayer::CSoundPlayer(QObject *parent) :
    QObject(parent)
{
    m_MediaPlayer = new QMediaPlayer(this);
}

CSoundPlayer::~CSoundPlayer()
{
    delete m_MediaPlayer;
}

void CSoundPlayer::PlayMP3(const QString &p_Filename)
{    
    m_MediaPlayer->setVolume(100);
    m_MediaPlayer->setMedia(QUrl::fromLocalFile(p_Filename));
    m_MediaPlayer->play();
}
