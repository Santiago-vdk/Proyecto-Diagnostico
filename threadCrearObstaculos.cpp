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
    int v1 = std::rand() % 2;
    return v1;
}


int threadCrearObstaculos::randomPosY(){
    time_t  timev;
    qsrand(time(&timev));
    int v2 = rand()%10;
    return v2*(_tamanioY/10);
}



void threadCrearObstaculos::process(){

    int i = 1;
    int numeroObstaculo;
    connect(this, SIGNAL(agregarObsLabel()), _partida, SLOT(agregarArregloLabels()));
    while (i <= _facade->jugadorReliquias()){

        numeroObstaculo = obstaculoRandom();
        if (numeroObstaculo == 0){
            int x = _tamanioX + 100;
            int y = randomPosY();
            _facade->crearObstaculo("Dinamico", x, y);
            _partida->setLabelInfo("Dinamico", x, y);
            agregarObsLabel();


        }
        if (numeroObstaculo == 1){
            int x = _tamanioX + 100;
            int y = randomPosY();
            _facade->crearObstaculo("Estatico", x, y);
            _partida->setLabelInfo("Estatico", x, y);
            agregarObsLabel();
        }
        if (numeroObstaculo == 1){
            int x = _tamanioX + 100;
            int y = randomPosY();
            _facade->crearObstaculo("Rastrero", x, y);
            _partida->setLabelInfo("Rastrero", x, y);
            agregarObsLabel();
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

        i ++;
        QThread::sleep(5);
    }
    emit finished();
}
