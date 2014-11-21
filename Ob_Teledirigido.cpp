#include "Ob_Teledirigido.h"
#include <QDebug>
void Ob_Teledirigido::mover(int pPosY){
    if (_posX-10 > 0){

       _posX -= 2;
       if(_posY < pPosY){
           _posY+=5;
       }
       if(_posY > pPosY){
           _posY-=5;
       }
    }
    else{
        _salud = 0;
    }
}
Ob_Teledirigido::~Ob_Teledirigido(){

}
