#include "application.h"
#include "ui_application.h"
#include "application.h"
#include "application_interface.h"

Application::Application(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Application)
{
    ui->setupUi(this);

    songPath <<
        "/home/navii/song.mp3"
        << "/home/navii/song2.mp3"
        << "/home/navii/song3.mp3"
        << "/home/navii/song4.mp3"
        << "/home/navii/song5.mp3";
    currentIndex = 0;

    app = new org::example::Examples::AppInterface("org.example.AppExample", "/App",
                                                   QDBusConnection::sessionBus(), this);

}

Application::~Application()
{
    delete ui;
}


void Application::on_play_clicked()
{
    song = songPath[currentIndex];
    if (currentIndex >= 0 && currentIndex < songPath.size()){
    app->play(song);
    }
    qDebug()<<"Play button clicked"<<song;
}


void Application::on_pause_clicked()
{

    app->pause();

}

void Application::on_nextsong_clicked()
{

    currentIndex = (currentIndex + 1) % song.size();
    app->nextsong(songPath[currentIndex]);
    qDebug()<<"Play button clicked"<<song;
}


void Application::on_prevsong_clicked()
{
    currentIndex = (currentIndex - 1 + song.size()) % song.size();
    app->prevsong(songPath[currentIndex]);
    qDebug()<<"Play button clicked"<<song;
}


void Application::on_stop_clicked()
{

    if (currentIndex >= 0 && currentIndex < song.size())
    {
    app->stop();
    }
    qDebug()<<"stop button clicked";

}


