#include "Be_Invecible.h"
#include <QDebug>

string Be_Invencible::beneficio(){
    return "Invencible";
}
Be_Invencible::~Be_Invencible(){
    qDebug()<<"mori Invencible";
}
