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
    int v1 = std::rand() % 7;
    return v1;
}

void threadCrearObstaculos::process(){

    int i = 1;
    int numeroObstaculo;
    while (i <= 1){//facade->jugadorReliquias()){
        numeroObstaculo = 0;//obstaculoRandom();
        if (numeroObstaculo == 0){
            _facade->crearObstaculo("Dinamico", _tamanioX + 100, _tamanioY/2);
            qDebug() << "aqui";
            //_partida->crearObstaculoLabel();
            connect(this, SIGNAL(crearObs()), _partida, SLOT(crearObstaculoLabel()));
            crearObs();
        }
        Obstaculo *temp = _facade->getObstaculoEnPos(_facade->getCantObstaculos() - 1);
        encapsulaObstaculo = new QThread;
        obstaculo = new threadObstaculos(temp);
        obstaculo->moveToThread(encapsulaObstaculo);
        connect(encapsulaObstaculo, SIGNAL(started()), obstaculo, SLOT(process()));
        connect(obstaculo, SIGNAL(finished()), encapsulaObstaculo, SLOT(quit()));
        connect(obstaculo, SIGNAL(finished()), obstaculo, SLOT(deleteLater()));
        connect(encapsulaObstaculo, SIGNAL(finished()), encapsulaObstaculo, SLOT(deleteLater()));
        encapsulaObstaculo->start();
        qDebug() << "He Creado obstaculo #" << i << "Thread #" << i << "Corriendo";

        i ++;
    }
    emit finished();
}
