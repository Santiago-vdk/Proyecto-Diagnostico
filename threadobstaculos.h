#ifndef THREADOBSTACULOS_H
#define THREADOBSTACULOS_H
#include <QString>
#include <QObject>
#include <Obstaculo.h>
#include "Facade.h"
#include "guiPartida.h"

class threadObstaculos : public QObject {
    Q_OBJECT

public:
    threadObstaculos(Obstaculo *obs, Facade *facade, guiPartida *partida);
    ~threadObstaculos();

public slots:
    void process();

signals:
    void finished();
    void aumentaPuntuacion(int cantidad);
    void terminoPartida();

private:
    Obstaculo *_obs;
    Facade *_facade;
    guiPartida *_partida;
};

#endif
