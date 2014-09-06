#include "Obstaculo.h"

Obstaculo::getPosX(){
    return _posX;

}
Obstaculo::getPosY(){
    return _posY;
}
Obstaculo::getSalud(){
    return _salud;
}
Obstaculo::getValor(){
    return _valor;
}

Obstaculo::setPosX(int posX){
    _posX=posX;
}
Obstaculo::setPosY(int posY){
    _posY=posY;
}
Obstaculo::setSalud(inst salud){
    _salud=salud;
}
Obstaculo::setValor(int valor){
    _valor=valor;
}

