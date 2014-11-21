#include "threadCrearObstaculo.h"
#include <QDebug>
#include "gui.h"
#include <random>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include "Facade.h"
#include <iostream>
#include "Obstaculo.h"
#include "guiPartida.h"


using namespace std;

threadCrearObstaculos::threadCrearObstaculos(Facade *facade, guiPartida *partida)
{
    // you could copy data from constructor arguments to internal variables here.
    _facade = facade;
    _partida = partida;
    _tamanioX = _partida->getTamanioVentanaX();
    _tamanioY = _partida->getTamanioVentanaY();

}
threadCrearObstaculos::~threadCrearObstaculos(){

}

int threadCrearObstaculos::obstaculoRandom(){
    std::srand(time (NULL));
    int v1 = std::rand() % 6;
    return v1;
}


int threadCrearObstaculos::randomPosY(){
    time_t  timev;
    qsrand(time(&timev));
    int v2 = rand()%6;
    return v2*100;

}

void threadCrearObstaculos::process(){

    bool _jefe=false;

    int numeroObstaculo;
    connect(this, SIGNAL(agregarObsLabel()), _partida, SLOT(agregarArregloLabels()));

    while (_facade->getVidaJugador() > 0){
        QThread::sleep(3);
        numeroObstaculo = obstaculoRandom();
        if(!_facade->getCambioNivel()){
            if (numeroObstaculo == 0 && _facade->valorEnPosArrayObstaculosPorNivel(0)>0){
                int x = _tamanioX + 50;
                int y = randomPosY();
                _facade->crearObstaculo("Dinamico", x, y);
                _partida->setLabelInfo("Dinamico", x, y);
                agregarObsLabel();
                _facade->setValorEnPosArrayObstaculosPorNivel(0);

            }
            if (numeroObstaculo == 1 && _facade->valorEnPosArrayObstaculosPorNivel(1)>0){
                int x = _tamanioX + 50;
                int y = randomPosY();
                _facade->crearObstaculo("Estatico", x, y);
                _partida->setLabelInfo("Estatico", x, y);
                agregarObsLabel();
                _facade->setValorEnPosArrayObstaculosPorNivel(1);
            }
            if (numeroObstaculo == 2 && _facade->valorEnPosArrayObstaculosPorNivel(2)>0){
                int x = _tamanioX + 50;
                //int y = randomPosY();
                _facade->crearObstaculo("Rastrero", x,550);
                _partida->setLabelInfo("Rastrero", x,550);
                agregarObsLabel();
                _facade->setValorEnPosArrayObstaculosPorNivel(2);
            }
            if (numeroObstaculo == 3 && _facade->valorEnPosArrayObstaculosPorNivel(3)>0){
                int x = _tamanioX + 50;
                int y = randomPosY();
                _facade->crearObstaculo("Teledirigido", x, y);
                _partida->setLabelInfo("Teledirigido", x, y);
                agregarObsLabel();
                _facade->setValorEnPosArrayObstaculosPorNivel(3);
            }
            if (numeroObstaculo == 4 && _facade->valorEnPosArrayObstaculosPorNivel(4)>0){
                int x = _tamanioX + 50;
                int y = randomPosY();
                _facade->crearObstaculo("Volumen", x, y);
                _partida->setLabelInfo("Volumen", x, y);
                agregarObsLabel();
                _facade->setValorEnPosArrayObstaculosPorNivel(4);
            }
            if (numeroObstaculo == 5 && !_jefe){
                int x = _tamanioX - 100;
                int y = randomPosY();
                _facade->crearObstaculo("Jefe", x, y);
                _partida->setLabelInfo("Jefe", x, y);
                agregarObsLabel();
                _jefe = true;
            }

            Obstaculo *temp = _facade->getObstaculoEnPos(_facade->getCantObstaculos() - 1);
            encapsulaObstaculo = new QThread;
            obstaculo = new threadObstaculos(temp,_facade, _partida);
            obstaculo->moveToThread(encapsulaObstaculo);
            connect(encapsulaObstaculo, SIGNAL(started()), obstaculo, SLOT(process()));
            connect(obstaculo, SIGNAL(finished()), encapsulaObstaculo, SLOT(quit()));
            connect(obstaculo, SIGNAL(finished()), obstaculo, SLOT(deleteLater()));
            connect(encapsulaObstaculo, SIGNAL(finished()), encapsulaObstaculo, SLOT(deleteLater()));
            encapsulaObstaculo->start();
        }

        //QThread::sleep(2);
    }
    qDebug()<<"numero de reliquias al morir: "<<_facade->jugadorReliquias();
    emit finished();
}
