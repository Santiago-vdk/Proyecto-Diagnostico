#include "threadRefrescaGui.h"
#include <Facade.h>
#include <guiPartida.h>

threadRefrescaGui::threadRefrescaGui(Facade *facade, guiPartida *partida)
{
    _facade = facade;
    _partida = partida;


}


threadRefrescaGui::~threadRefrescaGui(){

}

void threadRefrescaGui::process(){
    connect(this, SIGNAL(refresquemela()), _partida, SLOT(refrescarGUI()));
    while (_facade->getVidaJugador() > 0){
        QThread::msleep(50);
        refresquemela();
    }

    emit finished();

}
