#ifndef THREADTiempo_H
#define THREADTiempo_H

#include <QString>
#include <QObject>
#include <Facade.h>
#include <guiPartida.h>

class threadTiempo : public QObject {
    Q_OBJECT

public:
    threadTiempo(Facade *facade, guiPartida *partida);
    ~threadTiempo();

public slots:
    void process();

signals:
    void finished();
    void reduzcoTiempo();

private:
    Facade *_facade;
    guiPartida *_partida;


};

#endif
