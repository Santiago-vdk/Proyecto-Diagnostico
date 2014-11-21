#ifndef INFOMAPA_H
#define INFOMAPA_H
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "json.h"
using QtJson::JsonObject;
using QtJson::JsonArray;
class infoMapa
{
public:
    infoMapa(int Nivel);
    int getDinamico();
    int getEstatico();
    int getJefe();
    int getTeledirigido();
    int getRastrero();
    int getVolumen();
    int getReliquias();
    int getInvencible();
    int getVida();
    int getArma();
    int getTiempo();
    QString readFile(const QString &filename);
    void leer(int Nivel);

private:
    const QString Mapa1;
    const QString Mapa2;
    const QString Mapa3;
    int Dinamico;
    int Estatico;
    int Jefe;
    int Teledirigido;
    int Rastrero;
    int Volumen;
    int Reliquias;
    int Invencible;
    int Vida;
    int Arma;
    int Tiempo;
};



#endif // INFOMAPA_H
