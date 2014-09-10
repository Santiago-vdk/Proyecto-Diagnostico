#include "Ob_Rastrero.h"
#include <QDebug>

void Ob_Rastrero::mover(){
    if (_posX-10 > 0){

       _posX -= 5;
    }
    else{
        _salud = 0;
    }

}
Ob_Rastrero::~Ob_Rastrero(){
    qDebug()<<"mori rastrero";
}
