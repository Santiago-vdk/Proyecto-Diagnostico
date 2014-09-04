#include "guiPartida.h"
#include "ui_guiPartida.h"
#include <QLabel>
#include <QTime>
#include <QEventLoop>
#include <Thread.h>





guiPartida::guiPartida(QWidget *parent):QMainWindow(parent),ui(new Ui::guiPartida)

{

    ui->setupUi(this);
    crearLabel();
    moverLabel();





}

void guiPartida::moverLabel(){
    int paso = 0;
    int x = 0;
    int y = 0;

    while (paso < 2){
        label->move(x,y);
        label->update();
        x += 100;
        y += 100;
        paso ++;
    }
}

void guiPartida::crearLabel(){
    label = new QLabel();
    label->setParent(this);
    label->move(100,200);
    label->show();
}

guiPartida::~guiPartida()
{
    delete ui;
}
