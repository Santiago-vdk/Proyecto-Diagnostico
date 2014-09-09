#ifndef THREADCREAROBSTACULO_H
#define THREADCREAROBSTACULO_H
#include <QString>
#include <QObject>
#include <QThread>
#include "threadObstaculos.h"

class threadCrearObstaculos : public QObject {
    Q_OBJECT

public:
    threadCrearObstaculos();
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

};
#endif // THREADCREAROBSTACULO_H
