#include "Ob_Estatico.h"
#include <QDebug>
void Ob_Estatico::mover(){
    if (_posX-10 > 0){

       _posX -= 5;
    }
    else{
        _salud = 0;
    }

}
Ob_Estatico::~Ob_Estatico(){
    qDebug()<<"mori estatico";
}
