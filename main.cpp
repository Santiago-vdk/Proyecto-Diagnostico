#include "mainwindow.h"
#include <QApplication>
#include <gui.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gui w;
    w.show();
//David estuvo aqui
    return a.exec();
}

