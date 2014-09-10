#ifndef THREADCREAROBSTACULO_H
#define THREADCREAROBSTACULO_H
#include <QString>
#include <QObject>
#include <QThread>
#include "threadObstaculos.h"
#include <QString>
#include <string>
#include <Facade.h>
#include "guiPartida.h"

using namespace std;

class threadCrearObstaculos : public QObject {
    Q_OBJECT

public:
    threadCrearObstaculos(Facade *facade, guiPartida *partida);
    ~threadCrearObstaculos();


public slots:
    void process();
    int obstaculoRandom();
    int randomPosY();

signals:
    void finished();
    void agregarObsLabel();

    //void error(QString err);


private:
    QThread* encapsulaObstaculo;
    threadObstaculos* obstaculo;
    int i;
    int _tamanioX;
    int _tamanioY;
    Facade *_facade;
    guiPartida *_partida;

};
#endif // THREADCREAROBSTACULO_H
