#include <QDebug>
#include "gui.h"
#include <random>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include "Facade.h"
#include <iostream>
#include "guiPartida.h"


using namespace std;

threadCrearBeneficios::threadCrearBeneficios(Facade *facade, guiPartida *partida)
{
    // you could copy data from constructor arguments to internal variables here.
    _facade = facade;
    _partida = partida;
    _tamanioX = _partida->getTamanioVentanaX();
    _tamanioY = _partida->getTamanioVentanaY();

}
threadCrearBeneficios::~threadCrearBeneficios(){

}

int threadCrearBeneficios::beneficioRandom(){
    std::srand(time (NULL));
    int v1 = std::rand() % 4;
    return v1;
}


int threadCrearBeneficios::randomPosY(){
    time_t  timev;
    qsrand(time(&timev));
    int v2 = rand()%6;
    return v2*100;
}



void threadCrearBeneficios::process(){



    int numeroBeneficio;
    connect(this, SIGNAL(agregarBeneficioLabel()), _partida, SLOT(agregarArregloLabels()));
    while ( _facade->getJugador()->getVidas() > 0){
        QThread::sleep(7);
        numeroBeneficio = beneficioRandom();

        if (numeroBeneficio == 0){
            int x = _tamanioX + 50;
            int y = randomPosY();
            _facade->crearBeneficio("Vida", x, y);
            _partida->setLabelInfo("Vida", x, y);
            agregarBeneficioLabel();

        }
        if (numeroBeneficio == 1){
            int x = _tamanioX + 50;
            int y = randomPosY();
            _facade->crearBeneficio("Arma", x, y);
            _partida->setLabelInfo("Arma", x, y);
            agregarBeneficioLabel();
        }
        if (numeroBeneficio == 2){
            int x = _tamanioX + 50;
            int y = randomPosY();
            _facade->crearBeneficio("Invencible", x, y);
            _partida->setLabelInfo("Invencible", x, y);
            agregarBeneficioLabel();
        }
        if (numeroBeneficio == 3){
            int x = _tamanioX + 50;
            int y = randomPosY();
            _facade->crearBeneficio("Reliquia", x, y);
            _partida->setLabelInfo("Reliquia", x, y);
            agregarBeneficioLabel();
        }


        Beneficio *temp = _facade->getBeneficioEnPos(_facade->getCantBeneficios() - 1);
        encapsulaBeneficio = new QThread;
        beneficio = new threadBeneficio(temp,_facade, _partida);
        beneficio->moveToThread(encapsulaBeneficio);
        connect(encapsulaBeneficio, SIGNAL(started()), beneficio, SLOT(process()));
        connect(beneficio, SIGNAL(finished()), encapsulaBeneficio, SLOT(quit()));
        connect(beneficio, SIGNAL(finished()), beneficio, SLOT(deleteLater()));
        connect(encapsulaBeneficio, SIGNAL(finished()), encapsulaBeneficio, SLOT(deleteLater()));
        encapsulaBeneficio->start();
        qDebug() << "Nuevo Beneficio";



        QThread::sleep(7);


    }
    emit finished();
}

