#include "threadCrearObstaculo.h"
#include <QDebug>
#include "gui.h"


threadCrearObstaculos::threadCrearObstaculos()
{
// you could copy data from constructor arguments to internal variables here.
}
threadCrearObstaculos::~threadCrearObstaculos(){

}

void threadCrearObstaculos::process(){
    //while (facade.getReliquias() =! 0)
    //random
    //facade.obstaculo("", rango de posicin)
    //facade.getUltimoobstaculo
    //Encapsulo en thread, hacer que el obstaculo sea de tipo threadObstaculo
//    encapsulaThread = new QThread;
//    worker = new threadCrearObstaculos();
//    worker->moveToThread(Qhilo);
//    connect(Qhilo, SIGNAL(started()), worker, SLOT(process()));
//    connect(worker, SIGNAL(finished()), Qhilo, SLOT(quit()));
//    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
//    connect(Qhilo, SIGNAL(finished()), Qhilo, SLOT(deleteLater()));
//    Qhilo->start();





    //sleep(random int)
    //qDebug("threadObstaculos Vivo");
    emit finished();

}
