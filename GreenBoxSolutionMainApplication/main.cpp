#include "mainwindow.h"

#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWindow;
    //mainWindow.set(MainWindow::ScreenOrientationAuto);

    //mainWindow.setSizeIncrement(601,530);

    int WIDTH = 600;
    int HEIGHT = 600;

    int screenWidth;
    int screenHeight;

    int x, y;


    QDesktopWidget *desktop = QApplication::desktop();

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - WIDTH) / 2;
    y = (screenHeight - HEIGHT) / 2;

    mainWindow.resize(WIDTH, HEIGHT);
    mainWindow.move( x, y );

    mainWindow.show();
    return a.exec();
}
