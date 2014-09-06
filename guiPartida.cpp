#include "guiPartida.h"
#include "ui_guiPartida.h"
#include <QLabel>
#include <QTime>
#include <QEventLoop>
#include <QPixmap>


guiPartida::guiPartida(QWidget *parent):QMainWindow(parent),ui(new Ui::guiPartida)
{
    ui->setupUi(this);


    this->showFullScreen();
    QPixmap bkgnd(":/recursos/Afternoon.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);



    //crearObjetos()

}

void guiPartida::crearLabel(){


    label = new QLabel();
    label->setStyleSheet("background-image: url(:/recursos/nave.png);");
    label->move(100,200);
    label->show();
}

guiPartida::~guiPartida()
{
    delete ui;
}
