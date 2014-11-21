#include "Ob_Jefe.h"
#include <QDebug>
#include <ctime>
#include <random>
#include <ctime>
void Ob_Jefe::mover(int pPosY){
        time_t  timev;
        qsrand(time(&timev));
        int num = rand()%10;

        if (((num==4)or(num==5)) && _posX>700){
            _posX -= 5;
        }
        if ((num<4)&&(_posY-5>0)){
            _posY -= 5;
        }
        if ((num>5)&&(_posY+5<550)){
            _posY += 5;
        }
    }
Ob_Jefe::~Ob_Jefe(){

}
