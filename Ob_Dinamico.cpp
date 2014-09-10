#include "Ob_Dinamico.h"
#include <QDebug>

void Ob_Dinamico::mover(){
    if (_posX-10 > 0){

       _posX -= 5;
    }
    else{
        _salud = 0;
    }


}
Ob_Dinamico::~Ob_Dinamico(){
    qDebug()<<"mori dinamico";
}
