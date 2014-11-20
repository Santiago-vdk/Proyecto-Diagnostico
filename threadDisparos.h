#ifndef THREADDISPAROS_H
#define THREADDISPAROS_H
#include <QString>
#include <QObject>
#include <Disparo.h>
#include "Facade.h"
#include "guiPartida.h"

class threadDisparos : public QObject {
    Q_OBJECT

public:
    threadDisparos(Disparo *disparo, Facade *facade, guiPartida *partida);
    ~threadDisparos();

public slots:
    void process();

signals:
    void finished();
        void agregarObsLabel();
    void estallidoDisparo(int posX, int posY);

private:
    Disparo *_disparo;
    Facade *_facade;
    guiPartida *_partida;
};
#endif
