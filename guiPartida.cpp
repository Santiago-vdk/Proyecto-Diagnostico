#include "guiPartida.h"
#include "ui_guiPartida.h"
#include <QLabel>
#include <QTime>
#include <QEventLoop>
#include <QPixmap>
#include <QDebug>

#include <QThread>
#include <miThread.h>


guiPartida::guiPartida(QWidget *parent):QMainWindow(parent),ui(new Ui::guiPartida)
{
    ui->setupUi(this);
    this->showFullScreen();
    QPixmap bkgnd(":/recursos/Afternoon.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    crearJugador();
    comenzarThread();

}


void guiPartida::comenzarThread(){

    Qhilo = new QThread;
    worker = new miThread();
    worker->moveToThread(Qhilo);
    //connect(worker, SIGNAL(error(QString)), worker, SLOT(errorString(QString)));
    connect(Qhilo, SIGNAL(started()), worker, SLOT(process()));
    connect(worker, SIGNAL(finished()), Qhilo, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(Qhilo, SIGNAL(finished()), Qhilo, SLOT(deleteLater()));
    Qhilo->start();




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
