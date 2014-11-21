#include "threadArduino.h"
#include <Facade.h>
#include <guiPartida.h>
#include <QSound>
#include <QDebug>

threadArduino::threadArduino(Facade *facade, guiPartida *partida)
{
    _facade = facade;
    _partida = partida;
    Port = new QSerialPort();
    Port->setPortName("COM8");
    habilitar();


}


void threadArduino::habilitar(){
    if(Port->open(QIODevice::ReadWrite))
        {
            Port->setBaudRate(QSerialPort::Baud9600);
            Port->setDataBits(QSerialPort::Data8);
            Port->setParity(QSerialPort::NoParity);
            Port->setStopBits(QSerialPort::OneStop);
            Port->setFlowControl(QSerialPort::NoFlowControl);
            qDebug()<<"Puerto habilitado";
        }
    else{
       qDebug()<<"Error al habilitar el puerto";
    }
}

bool threadArduino::cerrar(){
    Port->close();
}

threadArduino::~threadArduino(){

}

void threadArduino::process(){
    connect(this,SIGNAL(envioCaracter(QString)), _partida, SLOT(lecturaArduino(QString)));
    while (1) {
        int numBytes= Port->bytesAvailable();
        Port->waitForReadyRead(1);
        if (numBytes>0){

            QString temp = QString::fromUtf8(Port->readAll());
            envioCaracter(temp);
        }
    }
    emit finished();

}
