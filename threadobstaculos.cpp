#include "threadobstaculos.h"
#include <QDebug>
#include "gui.h"
#include "threadCrearObstaculo.h"
#include "Obstaculo.h"


threadObstaculos::threadObstaculos(Obstaculo *obs)
{
// you could copy data from constructor arguments to internal variables here.
    _obs = obs;
}

threadObstaculos::~threadObstaculos(){

}

void threadObstaculos::process(){
    //while (nave.getVida() > 0){

    while (true){
        //(*_obs).mover();
    }

    emit finished();

}
