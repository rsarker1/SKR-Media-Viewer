#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // QApplication::setApplicationName("SKR Media Viewer");
    MainWindow w;
    w.show();
    return app.exec();
}
