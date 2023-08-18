#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>
#include "ui_application.h"
#include "application_adaptor.h"
#include "application_interface.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Application; }
QT_END_NAMESPACE

class Application : public QMainWindow
{
    Q_OBJECT

public:
    Application(QWidget *parent = nullptr);
    ~Application();

private slots:
    void on_play_clicked();
    void on_pause_clicked();
    void on_nextsong_clicked();
    void on_prevsong_clicked();
    void on_stop_clicked();

private:
    QStringList songPath;
    QString song;
    int currentIndex;
    Ui::Application *ui;
    org::example::Examples::AppInterface *app;
};
#endif // APPLICATION_H
