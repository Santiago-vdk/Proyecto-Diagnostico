#include "threadTiempo.h"
#include <Facade.h>
#include <guiPartida.h>
#include <QSound>

threadTiempo::threadTiempo(Facade *facade, guiPartida *partida)
{
    _facade = facade;
    _partida = partida;


}


threadTiempo::~threadTiempo(){

}

void threadTiempo::process(){
    connect(this, SIGNAL(reduzcoTiempo()), _partida, SLOT(reducirTiempo()));
    while (_facade->getVidaJugador() >= 0){
        if(_facade->getTiempo() <= 0){
            _facade->setVidasJugador(0);
        }
        reduzcoTiempo();
        _facade->setTiempo();
        QThread::sleep(1);
    }

    emit finished();

}
