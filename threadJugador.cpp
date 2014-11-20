#include "threadJugador.h"
#include <QDebug>
#include "gui.h"
#include <Facade.h>
#include "guiPartida.h"
#include <Jugador.h>


threadJugador::threadJugador(Jugador *jugador, Facade *facade, guiPartida *partida)
{
// you could copy data from constructor arguments to internal variables here.
    _jugador = jugador;
    _facade = facade;
    _partida = partida;
}
threadJugador::~threadJugador(){

}

void threadJugador::process(){
    connect(this, SIGNAL(jugadorMuerto()), _partida, SLOT(destruirJugador()));
    connect(this,SIGNAL(jugadorPierdeVida()),_partida,SLOT(quitarJugadorVida()));
    while (_facade->getVidaJugador() > 0){
        if(_jugador->getPosY()<0){
            _jugador->setVidas(_jugador->getVidas()-1);
            //respawn
            _jugador->setPosX(100);
            _jugador->setPosY(550);
            jugadorPierdeVida();

        }
        if(_facade->colisionConObstaculo(_jugador->getPosX(), _jugador->getPosY())){
            qDebug() << "Colision obstaculo, menos vida";
            _jugador->setInvencible(true);
            //respawn
            _jugador->setPosX(100);
            _jugador->setPosY(550);
            jugadorPierdeVida();

        }
        if(_jugador->getInvencible()){
            QThread::msleep(2000);
            _jugador->setInvencible(false);
        }

        if(_facade->colisionConReliquia(_jugador->getPosX(), _jugador->getPosY())){
            //Cambios visuales

        }
        //desenso x gravedad
        if(_jugador->getPosY()<550){
            _jugador->setPosY(_jugador->getPosY()+2);
        }
        QThread::msleep(50);

    }
    jugadorMuerto();
    qDebug() << "mori";
    emit finished();

}
