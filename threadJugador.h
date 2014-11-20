#ifndef THREADJUGADOR_H
#define THREADJUGADOR_H
#include <QString>
#include <QObject>
#include "Facade.h"
#include "guiPartida.h"
#include <Jugador.h>

class threadJugador : public QObject {
    Q_OBJECT

public:
    threadJugador(Jugador *jugador, Facade *facade, guiPartida *partida);
    ~threadJugador();

public slots:
    void process();

signals:
    void finished();
    void jugadorMuerto();
    void jugadorPierdeVida();

private:
    Jugador *_jugador;
    Facade *_facade;
    guiPartida *_partida;
};

#endif
