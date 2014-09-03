#include "gui.h"
#include "ui_gui.h"
#include <QMovie>
#include <QLabel>
#include "myLabel.h"
#include <QDebug>
#include <loading.h>
#include <QTime>
#include <string.h>



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

    ui->inputNombre->setText("Prueba ");

    //connect(m_label, SIGNAL(clicked()), SLOT(partida(user)));

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

    QTime dieTime= QTime::currentTime().addSecs(5);
    while( QTime::currentTime() < dieTime ){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    cargar->close();

}


QString gui::partida(QString usuario){

    return usuario;
}

gui::~gui()
{
    delete ui;
}


