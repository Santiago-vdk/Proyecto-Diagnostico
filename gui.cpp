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
#include <string>
#include <QThread>
#include <threadCrearObstaculo.h>
#include <threadRefrescaGui.h>

using namespace std;

gui::gui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gui)

{
    _facade = new Facade();
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

void gui::refrescaGUI(){

    encapsulaThreadRefrescarGUI = new QThread;
    ThreadRefrescarGUI = new threadRefrescaGui(_facade, match);
    ThreadRefrescarGUI->moveToThread(encapsulaThreadRefrescarGUI);

    connect(encapsulaThreadRefrescarGUI, SIGNAL(started()), ThreadRefrescarGUI , SLOT(process()));
    connect(ThreadRefrescarGUI , SIGNAL(finished()), encapsulaThreadRefrescarGUI, SLOT(quit()));
    connect(ThreadRefrescarGUI , SIGNAL(finished()), ThreadRefrescarGUI , SLOT(deleteLater()));
    connect(encapsulaThreadRefrescarGUI, SIGNAL(finished()), encapsulaThreadRefrescarGUI, SLOT(deleteLater()));

    encapsulaThreadRefrescarGUI->start();

}

void gui::CrearObstaculos(){

    encapsulaThreadCrearObjetos = new QThread;
    ThreadCrearObjetos = new threadCrearObstaculos(_facade, match);
    ThreadCrearObjetos->moveToThread(encapsulaThreadCrearObjetos);
    connect(encapsulaThreadCrearObjetos, SIGNAL(started()), ThreadCrearObjetos, SLOT(process()));
    connect(ThreadCrearObjetos, SIGNAL(finished()), encapsulaThreadCrearObjetos, SLOT(quit()));
    connect(ThreadCrearObjetos, SIGNAL(finished()), ThreadCrearObjetos, SLOT(deleteLater()));
    connect(encapsulaThreadCrearObjetos, SIGNAL(finished()), encapsulaThreadCrearObjetos, SLOT(deleteLater()));
    encapsulaThreadCrearObjetos->start();

}


void gui::carga()
{
    nombreUsuario = ui->inputNombre->text();
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
    string current_locale_text = qPrintable(nombreUsuario);
    _facade->setJugadorNombre(current_locale_text);

    match = new guiPartida(this,_facade);
    match->show();
    CrearObstaculos();
    refrescaGUI();
}

gui::~gui()
{
    delete ui;
}




