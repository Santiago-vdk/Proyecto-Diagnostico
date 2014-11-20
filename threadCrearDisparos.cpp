#include "threadCrearDisparos.h"
#include <Facade.h>
#include <guiPartida.h>
#include <QDebug>
#include <Disparo.h>

threadCrearDisparos::threadCrearDisparos(Facade *facade, guiPartida *partida)
{
    _facade = facade;
    _partida = partida;


}


threadCrearDisparos::~threadCrearDisparos(){

}

void threadCrearDisparos::process(){
    connect(this, SIGNAL(agregarObsLabel()), _partida, SLOT(agregarArregloLabels()));

    while(_facade->getVidaJugador() > 0){

        if(_partida->getquieroUnDisparo()){
            _partida->setquieroUnDisparo(false);

            _facade->crearDisparo("Disparo", _facade->jugadorPosX(),_facade->jugadorPosY());
            _partida->setLabelInfo("Disparo",_facade->jugadorPosX(),_facade->jugadorPosY());
            agregarObsLabel();

            Disparo *temp = _facade->getDisparoEnPos(_facade->getCantDisparos() - 1);
            encapsulaDisparo = new QThread;
            disparo = new threadDisparos(temp,_facade,_partida);
            disparo->moveToThread(encapsulaDisparo);
            connect(encapsulaDisparo, SIGNAL(started()), disparo, SLOT(process()));
            connect(disparo, SIGNAL(finished()), encapsulaDisparo, SLOT(quit()));
            connect(disparo, SIGNAL(finished()), disparo, SLOT(deleteLater()));
            connect(encapsulaDisparo, SIGNAL(finished()), encapsulaDisparo, SLOT(deleteLater()));
            encapsulaDisparo->start();
            QThread::msleep(500);
            qDebug() << "Fire";
        }

    }
    emit finished();

}
