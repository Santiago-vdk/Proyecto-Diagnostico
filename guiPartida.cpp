#include "guiPartida.h"
#include "ui_guiPartida.h"
#include <QLabel>
#include <QTime>
#include <QEventLoop>
#include <QPixmap>
#include <QDebug>

#include <QThread>
#include <threadCrearObstaculo.h>


guiPartida::guiPartida(QWidget *parent):QMainWindow(parent),ui(new Ui::guiPartida)
{
    ui->setupUi(this);
    this->showFullScreen();
    QPixmap bkgnd(":/recursos/Afternoon.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    crearJugador(); //Obtener parametros del facade
    CrearObstaculos(); //Comenzar thread para obstaculos


}


void guiPartida::CrearObstaculos(){

//    encapsulaThread = new QThread;
//    worker = new threadCrearObstaculos();
//    worker->moveToThread(Qhilo);
//    connect(Qhilo, SIGNAL(started()), worker, SLOT(process()));
//    connect(worker, SIGNAL(finished()), Qhilo, SLOT(quit()));
//    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
//    connect(Qhilo, SIGNAL(finished()), Qhilo, SLOT(deleteLater()));
//    Qhilo->start();

}

void guiPartida::crearJugador(){
    //Pinta el label del jugador
    labelJugador = new QLabel(this);
    QPixmap *pixmap=new QPixmap(":/recursos/nave.png");
    labelJugador->setPixmap(*pixmap);
    labelJugador->move(100,200);
    labelJugador->resize(QSize(100,100));
    labelJugador->show();
}

guiPartida::~guiPartida()
{
    delete ui;
}
