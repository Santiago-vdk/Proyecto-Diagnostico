#include "Be_Reliquia.h"
#include <QDebug>

string Be_Reliquia::beneficio(){
    return "Reliquia";
}
Be_Reliquia::~Be_Reliquia(){
    qDebug()<<"mori reliquia";
}
