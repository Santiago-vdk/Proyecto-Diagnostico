#ifndef THREADCREAROBSTACULO_H
#define THREADCREAROBSTACULO_H
#include <QString>
#include <QObject>
#include <QThread>
#include "threadObstaculos.h"
#include <QString>
#include <string>

using namespace std;

class threadCrearObstaculos : public QObject {
    Q_OBJECT

public:
    threadCrearObstaculos(string _nombreUsuario);
    ~threadCrearObstaculos();


public slots:
    void process();
    int obstaculoRandom();

signals:
    void finished();
    //void error(QString err);


private:
    QThread* encapsulaObstaculo;
    threadObstaculos* obstaculo;
    int i;
    string _nombreUsuario;

};
#endif // THREADCREAROBSTACULO_H
