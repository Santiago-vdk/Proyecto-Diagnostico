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
#include <QSound>

using namespace std;

guiPartida::guiPartida(QWidget *parent, Facade *facade):QMainWindow(parent)
  ,ui(new Ui::guiPartida)
{

    _facade = facade;
    quieroUnDisparo = false;
    ui->setupUi(this);
    this->showFullScreen();
    QPixmap bkgnd(":/recursos/Afternoon.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    setTamanioVentana(this->size().width(),this->size().height());
    crearJugador();
    ui->labelReliquias->setText(QString::number(_facade->getJugador()->getReliquias()));
    ui->labelArma->setText(QString::number(_facade->getJugador()->getArmas()));


}


void guiPartida::crearJugador(){
    //Pinta el label del jugador
    labelJugador = new QLabel(this);
    QPixmap *pixmap=new QPixmap(":/recursos/nave.png");
    labelJugador->setPixmap(*pixmap);

    labelJugador->move(_facade->jugadorPosX(),_facade->jugadorPosY());
    labelJugador->resize(QSize(65,65));
    labelJugador->show();
}


void guiPartida::destruirJugador(){
    labelJugador->hide();
}

void guiPartida::colisionDisparo(int posX, int posY)
{
    //Cambio imagen
    qDebug() << "Cambio";
    for(int i = 0; i < contadorArregloDisparos; i++){
        qDebug() << "x1 " << posX << "," << "x2 " << arregloDisparos[i]->x();


        if(arregloDisparos[i]->x()+5 == posX +20 || arregloDisparos[i]->x()+5 == posX - 20 ){
            qDebug() << "Boom";
            QPixmap *boom = new QPixmap(":/recursos/explosion.png");
            arregloDisparos[i]->setPixmap(*boom);
        }
    }

}

void guiPartida::aumentarContadorPuntucion(int contado)
{
    int marcadorTemp;
    marcadorTemp = ui->intPuntuacion->text().toInt();
    marcadorTemp = marcadorTemp + contado;
    QString numero = QString::number(marcadorTemp);
    ui->intPuntuacion->setText(numero);

}

void guiPartida::quitarJugadorVida()
{
    int vidas = _facade->getVidaJugador();
    if(vidas == 5){ //Si tiene 5 vidas le pongo cuatro visuales
        QPixmap *vida = new QPixmap(":/recursos/5vidas.png");
        ui->labelVidas->setPixmap(*vida);
    }
    if(vidas == 4){
        QPixmap *vida = new QPixmap(":/recursos/4vidas.png");
        ui->labelVidas->setPixmap(*vida);
    }
    if(vidas == 3){
        QPixmap *vida = new QPixmap(":/recursos/3vidas.png");
        ui->labelVidas->setPixmap(*vida);
    }
    if(vidas == 2){
        QPixmap *vida = new QPixmap(":/recursos/2vidas.png");
        ui->labelVidas->setPixmap(*vida);
    }
    if(vidas == 1){
        QPixmap *vida = new QPixmap(":/recursos/1vidas.png");
        ui->labelVidas->setPixmap(*vida);
    }


}

void guiPartida::iniciarSonido(QString sonido)
{

    if(sonido.compare("Piu") == 0){

            QSound sound("c:/piu.wav");
            sound.play();
    }

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

void guiPartida::borrarDisparoEnPos(int i){
    if (i < contadorArregloDisparos){
        arregloDisparos[i]->deleteLater();
        contadorArregloDisparos --;
        while(i < contadorArregloDisparos){
            arregloDisparos[i]=arregloDisparos[i+1];
            i++;
        }
    }
}

void guiPartida::borrarBeneficioEnPos(int i){
    if (i < contadorArregloBeneficios){
        arregloBeneficios[i]->deleteLater();
        contadorArregloBeneficios --;
        while(i < contadorArregloBeneficios){
            arregloBeneficios[i]=arregloBeneficios[i+1];
            i++;
        }
    }
}

void guiPartida::refrescarGUI()
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < contadorArregloLabels || j < contadorArregloDisparos || k < contadorArregloBeneficios){
        if(j < contadorArregloDisparos){
            arregloDisparos[j]->move(_facade->getPosXDisparoEnPos(j),_facade->getPosYDisparoEnPos(j));
        }
        if(i < contadorArregloLabels ){
            arregloLabels[i]->move(_facade->getPosXObstaculoEnPos(i),_facade->getPosYObstaculoEnPos(i));
        }
        if(k < contadorArregloBeneficios ){
            arregloBeneficios[k]->move(_facade->getPosXBeneficioEnPos(k),_facade->getPosYBeneficioEnPos(k));
        }
        labelJugador->move(_facade->jugadorPosX(),_facade->jugadorPosY());

        j++;
        i ++;
        k++;
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
    if (e->text() == "w"){
        _facade->jugadorMoverMenosY();
        labelJugador->move(_facade->jugadorPosX(),_facade->jugadorPosY());
    }
    if (e->text() == "s"){
        _facade->jugadorMoverMasY();
        labelJugador->move(_facade->jugadorPosX(),_facade->jugadorPosY());

    }
    if (e->text() == "d"){
        _facade->jugadorMoverMasX();
        labelJugador->move(_facade->jugadorPosX(),_facade->jugadorPosY());
    }

    if (e->text() == "a"){
        _facade->jugadorMoverMenosX();
        labelJugador->move(_facade->jugadorPosX(),_facade->jugadorPosY());
    }
    if (e->text() == " "){

        quieroUnDisparo = true;
    }
}


void guiPartida::lecturaArduino(QString pCaracter)
{
    if (pCaracter == "W"){
        _facade->jugadorMoverMenosY();
        labelJugador->move(_facade->jugadorPosX(),_facade->jugadorPosY());
    }
    if (pCaracter == "S"){
        _facade->jugadorMoverMasY();
        labelJugador->move(_facade->jugadorPosX(),_facade->jugadorPosY());

    }
    if (pCaracter == "D"){
        _facade->jugadorMoverMasX();
        labelJugador->move(_facade->jugadorPosX(),_facade->jugadorPosY());
    }

    if (pCaracter == "A"){
        _facade->jugadorMoverMenosX();
        labelJugador->move(_facade->jugadorPosX(),_facade->jugadorPosY());
    }
    if (pCaracter == " "){

        quieroUnDisparo = true;
    }
}

void guiPartida::reducirTiempo()
{
    int tmp = ui->labelTiempo->text().toInt();
    tmp = tmp -1;
    QString temporal = QString::number(tmp);
    ui->labelTiempo->setText(temporal);
}

void guiPartida::jugadorInvencible()
{
    QPixmap *pixmap=new QPixmap(":/recursos/invencible.png");
    labelJugador->setPixmap(*pixmap);
    labelJugador->resize(QSize(65,65));
    labelJugador->show();

}

void guiPartida::jugadorNormal()
{
    QPixmap *pixmap=new QPixmap(":/recursos/nave.png");
    labelJugador->setPixmap(*pixmap);
    labelJugador->resize(QSize(65,65));
    labelJugador->show();

}

void guiPartida::jugadorSumaReliquia()
{
    int reliquias = _facade->getJugador()->getReliquias();
    ui->labelReliquias->setText(QString::number(reliquias));

}

void guiPartida::jugadorGanaArma()
{
    int armas = _facade->getJugador()->getArmas();
    ui->labelReliquias->setText(QString::number(armas));
}

void guiPartida::agregarArregloLabels()
{
    if (_LabelNombre == "Dinamico"){
        qDebug() << "label dinamico";
        QLabel *labelDinamico = new QLabel(this);
        QPixmap *pixmap = new QPixmap(":/recursos/Obstaculo1.png");
        labelDinamico->setPixmap(*pixmap);
        labelDinamico->move(_posLabelX,_posLabelY);
        labelDinamico->resize(QSize(65,65));
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
        labelDinamico->resize(QSize(65,65));
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
        labelDinamico->resize(QSize(65,65));
        labelDinamico->show();
        arregloLabels[contadorArregloLabels] = labelDinamico;
        contadorArregloLabels++;
    }


    if (_LabelNombre == "Teledirigido"){
        qDebug() << "label teledirigido";
        QLabel *labelDinamico = new QLabel(this);
        QPixmap *pixmap = new QPixmap(":/recursos/Obstaculo3.png");
        labelDinamico->setPixmap(*pixmap);
        labelDinamico->move(_posLabelX,_posLabelY);
        labelDinamico->resize(QSize(65,65));
        labelDinamico->show();
        arregloLabels[contadorArregloLabels] = labelDinamico;
        contadorArregloLabels++;
    }

    if (_LabelNombre == "Volumen"){
        qDebug() << "label volumen";
        QLabel *labelDinamico = new QLabel(this);
        QPixmap *pixmap = new QPixmap(":/recursos/Obstaculo4.png");
        labelDinamico->setPixmap(*pixmap);
        labelDinamico->move(_posLabelX,_posLabelY);
        labelDinamico->resize(QSize(65,65));
        labelDinamico->show();
        arregloLabels[contadorArregloLabels] = labelDinamico;
        contadorArregloLabels++;
    }


    if (_LabelNombre == "Jefe"){
        qDebug() << "label Jefe";
        QLabel *labelDinamico = new QLabel(this);
        QPixmap *pixmap = new QPixmap(":/recursos/Obstaculo3.png");
        labelDinamico->setPixmap(*pixmap);
        labelDinamico->move(_posLabelX,_posLabelY);
        labelDinamico->resize(QSize(65,65));
        labelDinamico->show();
        arregloLabels[contadorArregloLabels] = labelDinamico;
        contadorArregloLabels++;
    }


    //Disparos
    if(_LabelNombre == "Disparo"){
        qDebug() << "label Disparo";
        QLabel *bala = new QLabel(this);
        QPixmap *pixmap=new QPixmap(":/recursos/disparo.png");
        bala->setPixmap(*pixmap);
        bala->move(_posLabelX,_posLabelY);
        bala->resize(QSize(40,10));
        bala->show();
        arregloDisparos[contadorArregloDisparos] = bala;
        contadorArregloDisparos++;
        quieroUnDisparo = false;
    }


    //Beneficios
    if(_LabelNombre == "Vida"){
        QLabel *vida = new QLabel(this);
        QPixmap *pixmap=new QPixmap(":/recursos/vida.png");
        vida->setPixmap(*pixmap);
        vida->move(_posLabelX,_posLabelY);
        vida->resize(QSize(65,65));
        vida->show();
        arregloBeneficios[contadorArregloBeneficios] = vida;
        contadorArregloBeneficios++;

    }

    if(_LabelNombre == "Arma"){
        QLabel *arma = new QLabel(this);
        QPixmap *pixmap=new QPixmap(":/recursos/arma.png");
        arma->setPixmap(*pixmap);
        arma->move(_posLabelX,_posLabelY);
        arma->resize(QSize(65,65));
        arma->show();
        arregloBeneficios[contadorArregloBeneficios] = arma;
        contadorArregloBeneficios++;

    }


    if(_LabelNombre == "Invencible"){
        QLabel *invencible = new QLabel(this);
        QPixmap *pixmap=new QPixmap(":/recursos/invencible.png");
        invencible->setPixmap(*pixmap);
        invencible->move(_posLabelX,_posLabelY);
        invencible->resize(QSize(65,65));
        invencible->show();
        arregloBeneficios[contadorArregloBeneficios] = invencible;
        contadorArregloBeneficios++;
    }

    if(_LabelNombre == "Reliquia"){
        QLabel *reliquia = new QLabel(this);
        QPixmap *pixmap=new QPixmap(":/recursos/reliquia.png");
        reliquia->setPixmap(*pixmap);
        reliquia->move(_posLabelX,_posLabelY);
        reliquia->resize(QSize(65,65));
        reliquia->show();
        arregloBeneficios[contadorArregloBeneficios] = reliquia;
        contadorArregloBeneficios++;
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

void guiPartida::setquieroUnDisparo(bool pBool)
{
    quieroUnDisparo = pBool;
}

bool guiPartida::getquieroUnDisparo()
{
    return quieroUnDisparo;
}
