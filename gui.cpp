#include "gui.h"
#include "ui_gui.h"
#include <QMovie>
#include <QLabel>
#include "myLabel.h"
#include <QDebug>
#include <loading.h>
#include <QTime>
#include <string.h>
#include <guiPartida.h>
#include <QFile>
#include <QSound>







QString user;

gui::gui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gui)

{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    QPixmap bkgnd(":/recursos/bg1.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QMovie *movie = new QMovie(":/recursos/pyro.gif");
    myLabel *m_label = new myLabel("Test",this);
    m_label->setMovie(movie);
    movie->start();
    m_label->setGeometry(QRect(300, 250, 500, 350));
    connect(m_label, SIGNAL(clicked()), SLOT(closeWindow()));
    connect(m_label, SIGNAL(clicked()), SLOT(carga()));
    connect(m_label, SIGNAL(clicked()), SLOT(partida()));


}


void gui::closeWindow()
{
    this->close();
}


void gui::carga()
{
    loading *cargar = new loading();
    cargar->show();
    //Agregar ejecucion inicial
    QTime dieTime= QTime::currentTime().addSecs(1);
    while( QTime::currentTime() < dieTime ){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    cargar->close();
}


void gui::partida(){
    guiPartida *match = new guiPartida();
    match->show();
    match->showFullScreen();
    //match->setFixedSize(800,600);

    QPixmap bkgnd(":/recursos/Afternoon.png");
    bkgnd = bkgnd.scaled(match->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    match->setPalette(palette);

}

gui::~gui()
{
    delete ui;
}


