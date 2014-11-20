#ifndef THREADARDUINO_H
#define THREADARDUINO_H

#include <QString>
#include <QObject>
#include <Facade.h>
#include <guiPartida.h>
#include <QString>
#include <QtSerialPort/qserialport.h>
#include <QSerialport>
#include <QSerialPortInfo>

class threadArduino : public QObject {
    Q_OBJECT

public:
    threadArduino(Facade *facade, guiPartida *partida);
    ~threadArduino();
    void habilitar();
    bool cerrar();

public slots:
    void process();

signals:
    void finished();
    void envioCaracter(QString pCaracter);

private:
    Facade *_facade;
    guiPartida *_partida;
    QSerialPort * Port;


};

#endif
