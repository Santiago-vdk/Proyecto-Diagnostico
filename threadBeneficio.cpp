#include "threadBeneficio.h"
#include <QDebug>
#include "gui.h"
#include "threadCrearObstaculo.h"
#include "Obstaculo.h"
#include <Facade.h>
#include "guiPartida.h"
#include <ctime>


threadBeneficio::threadBeneficio(Beneficio *beneficio, Facade *facade, guiPartida *partida)
{
// you could copy data from constructor arguments to internal variables here.
    _beneficio = beneficio;
    _facade = facade;
    _partida = partida;


}

threadBeneficio::~threadBeneficio(){

}

void threadBeneficio::process(){

    while (!_beneficio->adquirido && _beneficio->getPosX() > 0){
        _beneficio->setPosX(_beneficio->getPosX() - 10);
        QThread::msleep(50);
    }

    int indice = _facade->borrarBeneficioPorPuntero(_beneficio);
    if(indice == -1){
        qDebug()<<"error beneficio";
    }
    else{
        _partida->borrarBeneficioEnPos(indice);
    }
    emit finished();

}
