#include "threadTiempoAudio.h"
#include <Facade.h>
#include <guiPartida.h>
#include <QSound>

threadTiempoAudio::threadTiempoAudio(Facade *facade, guiPartida *partida)
{
    _facade = facade;
    _partida = partida;


}


threadTiempoAudio::~threadTiempoAudio(){

}

void threadTiempoAudio::process(){
    connect(this, SIGNAL(reproducirSonido(QString)), _partida, SLOT(iniciarSonido(QString)));

    while (true){
        if(_partida->getquieroUnDisparo()){
            qDebug("Audio");
            //reproducirSonido("Piu");

//            QSound sound("C:\\piu.wav");
//            sound.play();



        }


    }


    emit finished();

}
