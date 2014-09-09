#include "Be_Vida.h"
#include <QDebug>

string Be_Vida::beneficio(){
    return "Vida";
}
Be_Vida::~Be_Vida(){
    qDebug()<<"mori vida";
}
