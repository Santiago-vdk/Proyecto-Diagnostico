#include "infomapa.h"

infoMapa::infoMapa(int Nivel)
{

    if (Nivel==1){

        QString json = readFile("C://Mapa1.json");


        bool ok;
        JsonObject result = QtJson::parse(json, ok).toMap();

        JsonObject indent = result["Mapa"].toMap();
        Dinamico=indent["Dinamico"].toInt();
        Volumen= indent["Tiempo"].toInt();
        Estatico= indent["Estatico"].toInt();
        Jefe= indent["Jefe"].toInt();
        Rastrero= indent["Rastrero"].toInt();
        Teledirigido= indent["Teledirigido"].toInt();
        Invencible= indent["Invencible"].toInt();
        Vida= indent["Vida"].toInt();
        Tiempo= indent["Tiempo"].toInt();
        Jefe= indent["Jefe"].toInt();
        Reliquias=indent["Reliquias"].toInt();
        Arma=indent["Arma"].toInt();
    }
    if (Nivel==2){

        QString json = readFile("C://Mapa2.json");

        bool ok;
        JsonObject result = QtJson::parse(json, ok).toMap();

        JsonObject indent = result["Mapa"].toMap();
        Dinamico= indent["Dinamico"].toInt();
        Volumen= indent["Tiempo"].toInt();
        Estatico= indent["Estatico"].toInt();
        Jefe= indent["Jefe"].toInt();
        Rastrero= indent["Rastrero"].toInt();
        Teledirigido= indent["Teledirigido"].toInt();
        Invencible= indent["Invencible"].toInt();
        Vida= indent["Vida"].toInt();
        Tiempo= indent["Tiempo"].toInt();
        Jefe= indent["Jefe"].toInt();
        Reliquias=indent["Reliquias"].toInt();
    }
    if (Nivel==3){
        QString json = readFile("C://Mapa3.json");


        bool ok;
        JsonObject result = QtJson::parse(json, ok).toMap();

        JsonObject indent = result["Mapa"].toMap();
        Dinamico= indent["Dinamico"].toInt();
        Volumen= indent["Tiempo"].toInt();
        Estatico= indent["Estatico"].toInt();
        Jefe= indent["Jefe"].toInt();
        Rastrero= indent["Rastrero"].toInt();
        Teledirigido= indent["Teledirigido"].toInt();
        Invencible= indent["Invencible"].toInt();
        Vida= indent["Vida"].toInt();
        Tiempo= indent["Tiempo"].toInt();
        Jefe= indent["Jefe"].toInt();
        Reliquias=indent["Reliquias"].toInt();
    }
}

QString infoMapa::readFile(const QString &filename) {
    QFile f(filename);
    if (!f.open(QFile::ReadOnly | QFile::Text)) {
        return QString();
    } else {
        QTextStream in(&f);
        return in.readAll();
    }
}

void infoMapa::leer(int Nivel)
{
    if (Nivel==1){

        QString json = readFile("C://Mapa1.json");


        bool ok;
        JsonObject result = QtJson::parse(json, ok).toMap();

        JsonObject indent = result["Mapa"].toMap();
        Dinamico=indent["Dinamico"].toInt();
        Volumen= indent["Tiempo"].toInt();
        Estatico= indent["Estatico"].toInt();
        Jefe= indent["Jefe"].toInt();
        Rastrero= indent["Rastrero"].toInt();
        Teledirigido= indent["Teledirigido"].toInt();
        Invencible= indent["Invencible"].toInt();
        Vida= indent["Vida"].toInt();
        Tiempo= indent["Tiempo"].toInt();
        Jefe= indent["Jefe"].toInt();
        Reliquias=indent["Reliquias"].toInt();
        Arma=indent["Arma"].toInt();
    }
    if (Nivel==2){

        QString json = readFile("C://Mapa2.json");

        bool ok;
        JsonObject result = QtJson::parse(json, ok).toMap();

        JsonObject indent = result["Mapa"].toMap();
        Dinamico= indent["Dinamico"].toInt();
        Volumen= indent["Tiempo"].toInt();
        Estatico= indent["Estatico"].toInt();
        Jefe= indent["Jefe"].toInt();
        Rastrero= indent["Rastrero"].toInt();
        Teledirigido= indent["Teledirigido"].toInt();
        Invencible= indent["Invencible"].toInt();
        Vida= indent["Vida"].toInt();
        Tiempo= indent["Tiempo"].toInt();
        Jefe= indent["Jefe"].toInt();
        Reliquias=indent["Reliquias"].toInt();
    }
    if (Nivel==3){
        QString json = readFile("C://Mapa3.json");


        bool ok;
        JsonObject result = QtJson::parse(json, ok).toMap();

        JsonObject indent = result["Mapa"].toMap();
        Dinamico= indent["Dinamico"].toInt();
        Volumen= indent["Tiempo"].toInt();
        Estatico= indent["Estatico"].toInt();
        Jefe= indent["Jefe"].toInt();
        Rastrero= indent["Rastrero"].toInt();
        Teledirigido= indent["Teledirigido"].toInt();
        Invencible= indent["Invencible"].toInt();
        Vida= indent["Vida"].toInt();
        Tiempo= indent["Tiempo"].toInt();
        Jefe= indent["Jefe"].toInt();
        Reliquias=indent["Reliquias"].toInt();
    }
}


int infoMapa::getArma(){
    return Arma;
}

int infoMapa::getDinamico(){
    return Dinamico;
}

int infoMapa::getEstatico(){
    return Estatico;
}

int infoMapa::getInvencible(){
    return Invencible;
}

int infoMapa::getJefe(){
    return Jefe;
}

int infoMapa::getRastrero(){
    return Rastrero;
}

int infoMapa::getReliquias(){
    return Reliquias;
}

int infoMapa::getTeledirigido(){
    return Teledirigido;
}

int infoMapa::getTiempo(){
    return Tiempo;
}

int infoMapa::getVida(){
    return Vida;
}

int infoMapa::getVolumen(){
    return Volumen;
}
