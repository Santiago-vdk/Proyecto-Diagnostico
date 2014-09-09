#include "guiPartida.h"
#include "ui_guiPartida.h"
#include <QLabel>
#include <QTime>
#include <QEventLoop>
#include <QPixmap>
#include <QDebug>
#include <QThread>
#include <threadCrearObstaculo.h>

guiPartida::guiPartida(QWidget *parent, QString nombreUsuario):QMainWindow(parent)
  ,ui(new Ui::guiPartida)
{

    ui->setupUi(this);
    _nombreUsuario = nombreUsuario;
    qDebug() << _nombreUsuario;
    this->showFullScreen();
    QPixmap bkgnd(":/recursos/Afternoon.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    setTamanioVentana(this->size().width(),this->size().height());
    crearJugador(); //Obtener parametros del facade
    CrearObstaculos(); //Comenzar thread para obstaculos
}

void guiPartida::CrearObstaculos(){

    encapsulaThreadCrearObjetos = new QThread;
    ThreadCrearObjetos = new threadCrearObstaculos();
    ThreadCrearObjetos->moveToThread(encapsulaThreadCrearObjetos);
    connect(encapsulaThreadCrearObjetos, SIGNAL(started()), ThreadCrearObjetos, SLOT(process()));
    connect(ThreadCrearObjetos, SIGNAL(finished()), encapsulaThreadCrearObjetos, SLOT(quit()));
    connect(ThreadCrearObjetos, SIGNAL(finished()), ThreadCrearObjetos, SLOT(deleteLater()));
    connect(encapsulaThreadCrearObjetos, SIGNAL(finished()), encapsulaThreadCrearObjetos, SLOT(deleteLater()));
    encapsulaThreadCrearObjetos->start();

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

void guiPartida::setTamanioVentana(int ptamanioX, int ptamanioY){
    tamanioX = ptamanioX;
    tamanioY = ptamanioY;
}

int guiPartida::getTamanioVentanaX(){
    return tamanioX;
}

int guiPartida::getTamanioVentanaY(){
    return tamanioY;
}


guiPartida::~guiPartida()
{
    delete ui;
}
