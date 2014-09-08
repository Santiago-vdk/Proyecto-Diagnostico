#include "threadobstaculos.h"
#include <QDebug>
#include "gui.h"


threadObstaculos::threadObstaculos()
{
// you could copy data from constructor arguments to internal variables here.
}

threadObstaculos::~threadObstaculos(){

}

void threadObstaculos::process(){
    //correr();
    emit finished();

}
