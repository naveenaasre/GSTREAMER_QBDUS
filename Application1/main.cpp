#include "application.h"

//#include <QtWidgets>
#include <QtDBus>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Application w;
    w.show();
    return a.exec();
}
