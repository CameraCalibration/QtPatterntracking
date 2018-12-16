#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.resize(1044, 800);
    w.setMinimumSize(1044, 800);
    w.move(20, 20);
    w.show();

    return a.exec();
}
