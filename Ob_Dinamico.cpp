#include "Ob_Dinamico.h"
#include <QDebug>
#include <ctime>
#include <random>


void Ob_Dinamico::mover(){
    if ((_posX-10>0)){
        time_t  timev;
        qsrand(time(&timev));
        int num = rand()%10;

        if (num<5){
            _posX -= 5;
        }
        if (num>6){
            _posX += 5;
        }
        if ((num==5)&&(_posY-5>0)){
            _posY -= 5;
        }
        if ((num==6)&&(_posY+5<550)){
            _posY += 5;
        }

    }
    else{
        _salud = 0;
    }


}
Ob_Dinamico::~Ob_Dinamico(){
    qDebug()<<"mori dinamico";
}
