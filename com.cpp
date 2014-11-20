#include "com.h"

com::com()
{
    Port = new QSerialPort();
    Port->setPortName("COM4");
}

void com::habilitar(){
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

bool com::cerrar(){
    Port->close();
}



QString com::leer()
{
    qDebug()<<"Antes de leer";
    while (1) {
        int numBytes= Port->bytesAvailable();
        Port->waitForReadyRead(50);
        if (numBytes>0){
            qDebug()<<Port->readAll();

        }
    }
}
