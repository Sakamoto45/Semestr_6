#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    char* buf=new char[10];
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
