#include "Ob_Rastrero.h"
#include <QDebug>
#include <ctime>
#include <random>

void Ob_Rastrero::mover(){
    if (_posX-10 > 0){
        time_t  timev;
        qsrand(time(&timev));
        int num = rand()%10;

        if (num<=6){
            _posX -= 5;
        }
        if (num>6){
            _posX += 5;
        }
    }
    else{
        _salud = 0;
    }

}
Ob_Rastrero::~Ob_Rastrero(){
    qDebug()<<"mori rastrero";
}
