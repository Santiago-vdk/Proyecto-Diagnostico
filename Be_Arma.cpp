#include "Be_Arma.h"
#include <QDebug>

string Be_Arma::beneficio(){
    return "Arma";
}
Be_Arma::~Be_Arma(){
    qDebug()<<"mori Arma";
}
