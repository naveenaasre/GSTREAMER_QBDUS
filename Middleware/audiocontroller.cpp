#include "audiocontroller.h"
#include <qdebug.h>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusInterface>
#include <qaudiooutput.h>
#include <qmediaplayer.h>
#include <QMediaPlayer>
#include <gst/gst.h>

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
    if (!pipeline) {
        pipeline = gst_parse_launch("playbin uri=file://" + song.toUtf8(), 0);

        gst_element_set_state(pipeline, GST_STATE_PLAYING);
    } else {
        GstState state;
        gst_element_get_state(pipeline, &state, nullptr, GST_CLOCK_TIME_NONE);

        if (state != GST_STATE_PLAYING) {
            gst_element_set_state(pipeline, GST_STATE_PLAYING);
        }
    }
}

void AudioController::pause(QString song)
{
    if (pipeline) {
        GstState state;
        gst_element_get_state(pipeline, &state, nullptr, GST_CLOCK_TIME_NONE);
        if (state == GST_STATE_PLAYING) {
            gst_element_set_state(pipeline, GST_STATE_PAUSED);

            qDebug() << "string get from pause"<<state;
        }else if (state == GST_STATE_PAUSED || state == GST_STATE_NULL) {
            gst_element_set_state(pipeline, GST_STATE_PLAYING);
            qDebug() << "Resumed / Playing";
        }
    }
}

void AudioController::nextsong(QString song)
{
    if (pipeline) {
        gst_element_set_state(pipeline, GST_STATE_NULL);
        gst_object_unref(pipeline);
        pipeline = nullptr;
    }
    GError *error = nullptr;
    pipeline = gst_parse_launch("playbin uri=file://" + song.toUtf8(), &error);
    gst_element_set_state(pipeline, GST_STATE_PLAYING);
    qDebug() << "Playing next song"<<pipeline;
}

void AudioController::prevsong(QString song)
{
    if (pipeline) {
        gst_element_set_state(pipeline, GST_STATE_NULL);
        gst_object_unref(pipeline);
        pipeline = nullptr;
    }
    GError *error = nullptr;
    pipeline = gst_parse_launch("playbin uri=file://" + song.toUtf8(), &error);
    gst_element_set_state(pipeline, GST_STATE_PLAYING);
    qDebug() << "Playing previous song";
}

void AudioController::stop()
{
    if (pipeline) {
        gst_element_set_state(pipeline, GST_STATE_NULL);
        gst_object_unref(pipeline);
        pipeline = nullptr;
        qDebug() << "stop previous song";
    }
}
