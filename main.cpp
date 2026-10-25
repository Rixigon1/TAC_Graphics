#include <QApplication>
#include <QStyleFactory>

#include "mainWindow.h"



int main(int argc, char** argv) {
    QApplication app(argc, argv);
    mainWindow* mWin = new mainWindow();

    mWin->show();

    return app.exec();
}




























