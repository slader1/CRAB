#include "CSoundPlayer.h"

#include <QMediaPlayer>
#include <QMediaObject>
#include <QMediaPlaylist>

CSoundPlayer::CSoundPlayer(QObject *parent) :
    QObject(parent)
{
    m_MediaPlayer = new QMediaPlayer;
}

CSoundPlayer::~CSoundPlayer()
{
    delete m_MediaPlayer;
}

void CSoundPlayer::PlayMP3(const QString &p_Filename)
{    
    /*
    QMediaPlaylist* playlist = new QMediaPlaylist;
    QMediaObject* mo = new QMediaObject(QUrl("C:\\mp3.mp3"));
    playlist->addMedia(mo);
    playlist->setCurrentIndex(0);

    m_MediaPlayer->setPlaylist(playlist);

    m_MediaPlayer->setVolume(100);
    m_MediaPlayer->play();
    qDebug("Played");    
    */
}
