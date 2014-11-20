#ifndef THREADCREARDISPAROS_H
#define THREADCREARDISPAROS_H

#include <QString>
#include <QObject>
#include <Facade.h>
#include <guiPartida.h>
#include <QThread>
#include <threadDisparos.h>

class threadCrearDisparos : public QObject {
    Q_OBJECT

public:
    threadCrearDisparos(Facade *facade, guiPartida *partida);
    ~threadCrearDisparos();


public slots:
    void process();

signals:
    void finished();
    void agregarObsLabel();
    //void refresquemela();
    //void error(QString err);


private:
    Facade *_facade;
    guiPartida *_partida;
    QThread* encapsulaDisparo;
    threadDisparos* disparo;


};

#endif
