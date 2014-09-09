#include "guiPartida.h"
#include "ui_guiPartida.h"
#include <QLabel>
#include <QTime>
#include <QEventLoop>
#include <QPixmap>
#include <QDebug>
#include <QThread>
#include <string>
#include <Facade.h>

using namespace std;

guiPartida::guiPartida(QWidget *parent, Facade *facade):QMainWindow(parent)
  ,ui(new Ui::guiPartida)
{

    _facade = facade;
    ui->setupUi(this);
    this->showFullScreen();
    QPixmap bkgnd(":/recursos/Afternoon.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    setTamanioVentana(this->size().width(),this->size().height());
    crearJugador(); //Obtener parametros del facade
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



void guiPartida::crearObstaculoLabel(){
    //Pinta el label del jugador
    qDebug() << "en guu";
    labelObstaculo = new QLabel(this);
    QPixmap *pixmap = new QPixmap(":/recursos/obstaculo1.png");
    labelObstaculo->setPixmap(*pixmap);
    labelObstaculo->move(300,400);
    labelObstaculo->show();
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
