#include "Thread.h"
#include <QDebug>


Thread::Thread()
{

    stopped = false;

}

void Thread::run(){
    while (!stopped)
        qDebug() << "gilo";
    stopped = false;

}

void Thread::stop(){
    stopped = true;
}
