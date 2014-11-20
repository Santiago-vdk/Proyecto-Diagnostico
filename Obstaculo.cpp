#include "Obstaculo.h"
#include <QDebug>

Obstaculo::Obstaculo(int salud,int posX,int posY,int valor){
    _salud = salud;
    _posX = posX;
    _posY = posY;
    _valor = valor;
    matadoPorJugador = false;
}
Obstaculo::~Obstaculo(){
    qDebug()<<"mori obstaculo";
}

int Obstaculo::getPosX(){
    return _posX;

}
int Obstaculo::getPosY(){
    return _posY;
}
int Obstaculo::getSalud(){
    return _salud;
}
int Obstaculo::getValor(){
    return _valor;
}

bool Obstaculo::getMatadoPorJugador()
{
    return matadoPorJugador;
}

void Obstaculo::setMatadoPorJugador(bool pMatadoPorJugador)
{
    matadoPorJugador = pMatadoPorJugador;
}

void Obstaculo::setPosX(int posX){
    _posX=posX;
}
void Obstaculo::setPosY(int posY){
    _posY=posY;
}
void Obstaculo::setSalud(int salud){
    _salud=salud;
}
void Obstaculo::setValor(int valor){
    _valor=valor;
}

