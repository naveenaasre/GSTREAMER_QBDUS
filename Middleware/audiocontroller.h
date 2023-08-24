#ifndef AUDIOCONTROLLER_H
#define AUDIOCONTROLLER_H

#include <QObject>
 #include <gst/gst.h>
//#include <QDBusAbstractAdaptor>
#include <audiocontroller.h>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QGraphicsObject>



class AudioController : public QObject
{
    Q_OBJECT

    Q_CLASSINFO("D-Bus Interface", "org.example.AudioControl")
public:

    explicit AudioController(QObject *parent = nullptr);
    QRectF boundingRect() const;

    // AudioPlayerAdaptor(AudioController *controller);
public slots:
    void play(QString song);
    void pause(QString song);
    void nextsong(QString song);
    void prevsong(QString song);
    void stop();
signals:

private:
    QMediaPlayer mediaPlayer;
    GstElement *pipeline = nullptr;
    GstElement *playbin = nullptr;
    gint64 playbackPosition = -1;
    int currentIndex;
    bool isPlaying = true;


};

#endif // AUDIOCONTROLLER_H
