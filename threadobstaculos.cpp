#include "threadobstaculos.h"
#include <QDebug>
#include "gui.h"
#include "threadCrearObstaculo.h"


threadObstaculos::threadObstaculos()
{
// you could copy data from constructor arguments to internal variables here.
}

threadObstaculos::~threadObstaculos(){

}

void threadObstaculos::process(){
    //while (nave.getVida() > 0){
    qDebug() << "Thread de Obstaculo creado";
    while (true){

    }

    emit finished();

}
