#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    Dialog startMenu;

    startMenu.show();
    QObject::connect(&startMenu, SIGNAL(start()), &w, SLOT(start()));
    QObject::connect(&startMenu, SIGNAL(leave()), &w, SLOT(leave()));
    QObject::connect(&startMenu, SIGNAL(emitLevel(int)), &w, SLOT(setLevel(int)));
    QObject::connect(&w, SIGNAL(backToStart()), &startMenu, SLOT(open()));

    return app.exec();
}