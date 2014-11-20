#ifndef THREADBENEFICIO_H
#define THREADBENEFICIO_H
#include <QString>
#include <QObject>
#include <Beneficio.h>
#include "Facade.h"
#include "guiPartida.h"

class threadBeneficio : public QObject {
    Q_OBJECT

public:
    threadBeneficio(Beneficio *beneficio, Facade *facade, guiPartida *partida);
    ~threadBeneficio();

public slots:
    void process();

signals:
    void finished();
    void jugadorPierdeVida();
    void jugadorNoPuedeMorir();
    void jugadorGanaReliquia();
    void jugadorGanaArma();

private:
    Beneficio *_beneficio;
    Facade *_facade;
    guiPartida *_partida;
};

#endif
