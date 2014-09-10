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
#include <QApplication>
#include <QMovie>
#include <myLabel.h>

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
    crearJugador();

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

void guiPartida::borrarLabelEnPos(int i){
    if (i < contadorArregloLabels){
        arregloLabels[i]->deleteLater();
        contadorArregloLabels --;
        while(i < contadorArregloLabels){
            arregloLabels[i]=arregloLabels[i+1];
            i++;
        }
    }
}

void guiPartida::refrescarGUI()
{
    int i = 0;
    while (i < contadorArregloLabels){
        arregloLabels[i]->move(_facade->getPosXObstaculoEnPos(i),_facade->getPosYObstaculoEnPos(i));
        i ++;
    }
}



void guiPartida::setTamanioVentana(int ptamanioX, int ptamanioY){
    tamanioX = ptamanioX;
    tamanioY = ptamanioY;
}

void guiPartida::setLabelInfo(string pLabelNombre, int posLabelX, int posLabelY)
{
    _LabelNombre = pLabelNombre;
    _posLabelX = posLabelX;
    _posLabelY = posLabelY;
}

void guiPartida::agregarArregloLabels()
{
    if (_LabelNombre == "Dinamico"){
        QLabel *labelDinamico = new QLabel(this);
        QPixmap *pixmap = new QPixmap(":/recursos/obstaculo1.png");
        labelDinamico->setPixmap(*pixmap);
        labelDinamico->move(_posLabelX,_posLabelY);
        labelDinamico->resize(QSize(100,100));
        labelDinamico->show();
        arregloLabels[contadorArregloLabels] = labelDinamico;
        contadorArregloLabels++;
    }

    if (_LabelNombre == "Estatico"){
        QLabel *labelDinamico = new QLabel(this);
        QPixmap *pixmap = new QPixmap(":/recursos/obstaculo1.png");
        labelDinamico->setPixmap(*pixmap);
        labelDinamico->move(_posLabelX,_posLabelY);
        labelDinamico->resize(QSize(100,100));
        labelDinamico->show();
        arregloLabels[contadorArregloLabels] = labelDinamico;
        contadorArregloLabels++;
    }

    if (_LabelNombre == "Rastrero"){
        QLabel *labelDinamico = new QLabel(this);
        QPixmap *pixmap = new QPixmap(":/recursos/obstaculo1.png");
        labelDinamico->setPixmap(*pixmap);
        labelDinamico->move(_posLabelX,_posLabelY);
        labelDinamico->resize(QSize(100,100));
        labelDinamico->show();
        arregloLabels[contadorArregloLabels] = labelDinamico;
        contadorArregloLabels++;
    }
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
