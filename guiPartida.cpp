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
#include <QMessageBox>

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

    labelJugador->move(_facade->jugadorPosX(),_facade->jugadorPosY());
    labelJugador->resize(QSize(80,80));
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

void guiPartida::keyPressEvent(QKeyEvent *e)
{
    if (e->text() == "s"){
        _facade->jugadorMoverMasY();
        labelJugador->move(_facade->jugadorPosX(),_facade->jugadorPosY());

    }

    if (e->text() == "w"){
        _facade->jugadorMoverMenosY();
        labelJugador->move(_facade->jugadorPosX(),_facade->jugadorPosY());

    }

}

void guiPartida::agregarArregloLabels()
{
    if (_LabelNombre == "Dinamico"){
        qDebug() << "label dinamico";
        QLabel *labelDinamico = new QLabel(this);
        QPixmap *pixmap = new QPixmap(":/recursos/obstaculo1.png");
        labelDinamico->setPixmap(*pixmap);
        labelDinamico->move(_posLabelX,_posLabelY);
        labelDinamico->resize(QSize(80,80));
        labelDinamico->show();
        arregloLabels[contadorArregloLabels] = labelDinamico;
        contadorArregloLabels++;
    }

    if (_LabelNombre == "Estatico"){
        qDebug() << "label estatico";
        QLabel *labelDinamico = new QLabel(this);
        QPixmap *pixmap = new QPixmap(":/recursos/Obstaculo4.png");
        labelDinamico->setPixmap(*pixmap);
        labelDinamico->move(_posLabelX,_posLabelY);
        labelDinamico->resize(QSize(80,80));
        labelDinamico->show();
        arregloLabels[contadorArregloLabels] = labelDinamico;
        contadorArregloLabels++;
    }

    if (_LabelNombre == "Rastrero"){
        qDebug() << "label rastrero";
        QLabel *labelDinamico = new QLabel(this);
        QPixmap *pixmap = new QPixmap(":/recursos/Obstaculo2.png");
        labelDinamico->setPixmap(*pixmap);
        labelDinamico->move(_posLabelX,_posLabelY);
        labelDinamico->resize(QSize(80,80));
        labelDinamico->show();
        arregloLabels[contadorArregloLabels] = labelDinamico;
        contadorArregloLabels++;
    }


    if (_LabelNombre == "Teledirigido"){
        qDebug() << "label teledirigido";
        QLabel *labelDinamico = new QLabel(this);
        QPixmap *pixmap = new QPixmap(":/recursos/obstaculo3.png");
        labelDinamico->setPixmap(*pixmap);
        labelDinamico->move(_posLabelX,_posLabelY);
        labelDinamico->resize(QSize(80,80));
        labelDinamico->show();
        arregloLabels[contadorArregloLabels] = labelDinamico;
        contadorArregloLabels++;
    }

    if (_LabelNombre == "Volumen"){
        qDebug() << "label volumen";
        QLabel *labelDinamico = new QLabel(this);
        QPixmap *pixmap = new QPixmap(":/recursos/obstaculo4.png");
        labelDinamico->setPixmap(*pixmap);
        labelDinamico->move(_posLabelX,_posLabelY);
        labelDinamico->resize(QSize(80,80));
        labelDinamico->show();
        arregloLabels[contadorArregloLabels] = labelDinamico;
        contadorArregloLabels++;
    }


    if (_LabelNombre == "Jefe"){
        qDebug() << "label Jefe";
        QLabel *labelDinamico = new QLabel(this);
        QPixmap *pixmap = new QPixmap(":/recursos/obstaculo3.png");
        labelDinamico->setPixmap(*pixmap);
        labelDinamico->move(_posLabelX,_posLabelY);
        labelDinamico->resize(QSize(80,80));
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
