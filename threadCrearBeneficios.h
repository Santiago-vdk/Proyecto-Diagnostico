#ifndef THREADCREARBENEFICIOS_H
#define THREADCREARBENEFICIOSO_H
#include <QString>
#include <QObject>
#include <QThread>
#include "threadBeneficio.h"
#include <QString>
#include <string>
#include <Facade.h>
#include "guiPartida.h"

using namespace std;

class threadCrearBeneficios : public QObject {
    Q_OBJECT

public:
    threadCrearBeneficios(Facade *facade, guiPartida *partida);
    ~threadCrearBeneficios();


public slots:
    void process();
    int beneficioRandom();
    int randomPosY();

signals:
    void finished();
    void agregarBeneficioLabel();
    void genodicio();




private:
    QThread* encapsulaBeneficio;
    threadBeneficio* beneficio;
    int i;
    int _tamanioX;
    int _tamanioY;
    Facade *_facade;
    guiPartida *_partida;

};
#endif // THREADCREARBENEFICIO_H

