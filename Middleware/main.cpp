#include <QCoreApplication>
#include <QtDBus/QDBusConnection>
#include <audiocontroller.h>
#include <QtDBus/QDBusConnection>
#include "application_adaptor.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>
#include <qdebug.h>
#include <QLabel>
#include <QFrame>

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);

    QWidget window;
    window.setGeometry(100, 100, 400, 300);

    QFrame rectangle(&window);
    rectangle.setGeometry(50, 50, 300, 200);
    rectangle.setStyleSheet("background-color: lightgray;");

    QLabel label("Enjoy the Music", &window);
    label.setGeometry(100, 100, 200, 50);
    label.setAlignment(Qt::AlignCenter);
    //    QGraphicsScene scene;
    //    scene.setSceneRect(-500, -500, 1000, 1000);
    //    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    AudioController *audioController=new AudioController();
    // scene.addItem(audioController);

    new AppInterfaceAdaptor(audioController);
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.registerObject("/App", audioController);
    connection.registerService("org.example.AppExample");

    window.show();
    return a.exec();
}
