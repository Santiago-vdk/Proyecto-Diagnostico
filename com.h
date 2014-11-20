#ifndef COM_H
#define COM_H
#include <QString>
#include <QtSerialPort/qserialport.h>
#include <QSerialport>
#include <QSerialPortInfo>
#include <QDebug>
class com
{
public:
    com();
    void habilitar();
    bool cerrar();
    QString leer();

private:
    QSerialPort * Port;
};

#endif // COM_H
