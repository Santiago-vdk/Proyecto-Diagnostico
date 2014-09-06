#include "Beneficio.h"

Beneficio::Beneficio(int posX,int posY){
    _posX = posX;
    _posY = posY;
}

int Beneficio::getPosX(){
    return _posX;
}
int Beneficio::getPosY(){
    return _posY;
}
void Beneficio::setPosX(int posX){
    _posX = posX;
}
void Beneficio::setPosY(int posY){
    _posY = posY;
}
