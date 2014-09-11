#include "Ob_Volumen.h"
#include <QDebug>
#include <ctime>
#include <random>

void Ob_Volumen::mover(){
    if (_posX-10 > 0){
        time_t  timev;
        qsrand(time(&timev));
        int num = rand()%6;

        if (num>2){
            _posX -= 5;
        }
        if (num==1){
            _posX += 5;
        }
        if ((num==2)&&(_posY-5>0)){
            _posY -= 5;
        }
        if ((num==0)&&(_posY+5<900)){
            _posY += 5;
        }
    }
    else{
        _salud = 0;
    }

}
Ob_Volumen::~Ob_Volumen(){
    qDebug()<<"mori Volumen";
}
