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
    connect(this,SIGNAL(jugadorPierdeVida()),_partida,SLOT(quitarJugadorVida()));
    connect(this,SIGNAL(jugadorGanaReliquia()),_partida,SLOT(jugadorSumaReliquia()));
    connect(this,SIGNAL(jugadorGanaArma()),_partida,SLOT(jugadorGanaArma()));
    while (!_beneficio->adquirido && _beneficio->getPosX() > 0){
        _beneficio->setPosX(_beneficio->getPosX() - 10);
        QThread::msleep(50);
    }

    if(_beneficio->adquirido && _beneficio->beneficio().compare("Vida") == 0){
        jugadorPierdeVida();
    }
    if(_beneficio->adquirido && _beneficio->beneficio().compare("Reliquia") == 0){
        jugadorGanaReliquia();
    }
    if(_beneficio->adquirido && _beneficio->beneficio().compare("Arma") == 0){
        jugadorGanaArma();
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
