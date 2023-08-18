#include "audiocontroller.h"
#include <qdebug.h>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusInterface>
#include <qaudiooutput.h>
#include <qmediaplayer.h>
#include <QMediaPlayer>

AudioController::AudioController(QObject *parent)
    : QObject{parent}
{
    QDBusConnection::sessionBus().registerObject("/audio", this, QDBusConnection::ExportAllSlots);
    qDebug()<<"AudioController initialized";
    currentIndex = 0;
}

void AudioController::play(QString song)
{
    qDebug()<<"string get from play"<<song;
    if (mediaPlayer.state() == QMediaPlayer::PausedState) {
        mediaPlayer.play();
    } else {
        mediaPlayer.setMedia(QUrl::fromLocalFile(song));
        mediaPlayer.play();
    }
}

void AudioController::pause()
{
    if (mediaPlayer.state() == QMediaPlayer::PlayingState) {
        mediaPlayer.pause();
    }
    qDebug()<<"string get from pause";

}

void AudioController::nextsong(QString song)
{
    mediaPlayer.setMedia(QUrl::fromLocalFile(song));
    if (!song.isEmpty())
    {

        mediaPlayer.play();
    }
    qDebug() << "Playing next song";
}

void AudioController::prevsong(QString song)
{
        mediaPlayer.setMedia(QUrl::fromLocalFile(song));
        if (!song.isEmpty())
        {

            mediaPlayer.play();
        }
        qDebug() << "Playing previous song";
}

void AudioController::stop()
{

    mediaPlayer.stop();
    qDebug() << "stop previous song";
}
