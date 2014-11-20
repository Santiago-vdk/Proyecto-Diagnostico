#include "threadobstaculos.h"
#include <QDebug>
#include "gui.h"
#include "threadCrearObstaculo.h"
#include "Obstaculo.h"
#include <Facade.h>
#include "guiPartida.h"
#include <ctime>
#include <QSound>

threadObstaculos::threadObstaculos(Obstaculo *obs, Facade *facade, guiPartida *partida)
{
// you could copy data from constructor arguments to internal variables here.
    _obs = obs;
    _facade = facade;
    _partida = partida;


}

threadObstaculos::~threadObstaculos(){

}

void threadObstaculos::process(){

    connect(this, SIGNAL(aumentaPuntuacion(int)), _partida, SLOT(aumentarContadorPuntucion(int)));
    while ((*_obs).getSalud() > 0  ){
        (*_obs).mover();

        QThread::msleep(50);
    }

    if((*_obs).getMatadoPorJugador()){
        aumentaPuntuacion((*_obs).getValor());
    }

    int indice = _facade->borrarObstaculoPorPuntero(_obs);
    if(indice == -1){
        qDebug()<<"error obstaculo";
    }
    else{
        _partida->borrarLabelEnPos(indice);

    }
    emit finished();

}
