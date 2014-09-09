#include "Ob_Dinamico.h"
#include <QDebug>

void Ob_Dinamico::mover(){
    qDebug()<<"mover clase Ob_Dinamico";
    _posX -= 10;
}
Ob_Dinamico::~Ob_Dinamico(){
    qDebug()<<"mori dinamico";
}
