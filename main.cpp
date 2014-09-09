#include <QApplication>
#include <gui.h>
#include <QDebug>
#include "Facade.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //gui w;
    //.show();
    Facade *facade = new Facade("rafa");
    (*facade).crearObstaculo("Dinamico",5,5);
    (*facade).crearObstaculo("Jefe",10,10);
    (*facade).crearObstaculo("Estatico",5,5);
    (*facade).crearObstaculo("Teledirigido",10,10);
    (*facade).crearObstaculo("Rastrero",5,5);
    (*facade).crearObstaculo("Volumen",10,10);
    qDebug()<<(*facade).getCantObstaculos();
    (*facade).borrarObstaculoEnPos(2);
    qDebug()<<(*facade).getCantObstaculos();
    qDebug()<<(*facade).getPosXObstaculoEnPos(2);
    delete facade;

    return a.exec();
}

