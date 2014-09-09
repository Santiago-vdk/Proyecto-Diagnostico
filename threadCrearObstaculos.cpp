#include "threadCrearObstaculo.h"
#include <QDebug>
#include "gui.h"
#include <random>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Facade.h"

using namespace std;

threadCrearObstaculos::threadCrearObstaculos()
{
// you could copy data from constructor arguments to internal variables here.
}
threadCrearObstaculos::~threadCrearObstaculos(){

}

int threadCrearObstaculos::obstaculoRandom(){
    std::srand(time (NULL));
    int v1 = std::rand() % 7;
    return v1;
}

void threadCrearObstaculos::process(){
    //Facade facade = new Facade("test");


    i = 0;
    int numeroObstaculo;
    while (i <= 10){
        numeroObstaculo = obstaculoRandom();
        if (numeroObstaculo == 0){
            //facade.crearObstaculo("Dinamico", guiPartida.getTamanioVentanaX + 50, guiPartida.getTamanioY//2)
        }
        encapsulaObstaculo = new QThread;
        obstaculo = new threadObstaculos();
        obstaculo->moveToThread(encapsulaObstaculo);
        connect(encapsulaObstaculo, SIGNAL(started()), obstaculo, SLOT(process()));
        connect(obstaculo, SIGNAL(finished()), encapsulaObstaculo, SLOT(quit()));
        connect(obstaculo, SIGNAL(finished()), obstaculo, SLOT(deleteLater()));
        connect(encapsulaObstaculo, SIGNAL(finished()), encapsulaObstaculo, SLOT(deleteLater()));
        encapsulaObstaculo->start();
        qDebug() << "He Creado obstaculo #" << i << "Thread #" << i << "Corriendo";
        i ++;
    }
    qDebug() << "Destruyendo threadCrearObstaculos";
    //while (facade.getReliquias() =! 0)
    //random
    //facade.obstaculo("", rango de posicin)
    //facade.getUltimoobstaculo
    //Encapsulo en thread, hacer que el obstaculo sea de tipo threadObstaculo
    //sleep(random int)
    //qDebug("threadObstaculos Vivo");
    emit finished();

}
