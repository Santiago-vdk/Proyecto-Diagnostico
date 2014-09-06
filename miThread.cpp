#include "miThread.h"
#include <QDebug>
#include "gui.h"


miThread::miThread()
{
// you could copy data from constructor arguments to internal variables here.
}

miThread::~miThread(){

}

void miThread::process(){
    vida = 50;
    while (vida>0){
        qDebug("Vivo");
        vida --;
    }
    qDebug("Muerto");
    emit finished();
}
