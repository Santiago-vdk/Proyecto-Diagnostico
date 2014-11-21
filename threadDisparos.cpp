#include "threadDisparos.h"
#include <QDebug>
#include "gui.h"
#include "threadCrearObstaculo.h"
#include "Obstaculo.h"
#include <Facade.h>
#include "guiPartida.h"
#include <ctime>
#include <Disparo.h>


threadDisparos::threadDisparos(Disparo *disparo, Facade *facade, guiPartida *partida)
{
// you could copy data from constructor arguments to internal variables here.
    _disparo = disparo;
    _facade = facade;
    _partida = partida;
}

threadDisparos::~threadDisparos(){

}

void threadDisparos::process(){
    int i = 5;
    connect(this,SIGNAL(estallidoDisparo(int,int)), _partida, SLOT(colisionDisparo(int,int)));
            connect(this,SIGNAL(terminoPartida()),_partida,SLOT(borrarDisparos()));
    while (_disparo->getPosX() < _partida->getTamanioVentanaX() && _disparo->getbanderaConPolvora() && !_facade->getCambioNivel()){
        _disparo->setPosX(_disparo->getPosX()+i);

        if(_facade->colisionConDisparo(_disparo->getPosX(),_disparo->getPosY())){

            estallidoDisparo(_disparo->getPosX(),_disparo->getPosY());
            _disparo->setbanderaConPolvora(false);


        }
        QThread::msleep(10);
    }

//    if(_facade->getCambioNivel()){
//        qDebug("mato disparos");
//        terminoPartida();
//    }
    if(!_facade->getCambioNivel()){
        int indice = _facade->borrarDisparoPorPuntero(_disparo);
        if(indice == -1){
            qDebug()<<"error disparo";
        }
        else{

            //aqui cambiar imagen de disparo a imagen de explosion
            _partida->borrarDisparoEnPos(indice);
        }
    }
    emit finished();

}
