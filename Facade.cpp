#include "Facade.h"
#include "Jugador.h"
#include <string>
#include "Obstaculo.h"
#include"Ob_Dinamico.h"
#include"Ob_Estatico.h"
#include"Ob_Jefe.h"
#include"Ob_Rastrero.h"
#include"Ob_Teledirigido.h"
#include"Ob_Volumen.h"
#include <QDebug>
#include "Beneficio.h"
#include "Be_Arma.h"
#include "Be_Invecible.h"
#include"Be_Reliquia.h"
#include "Be_Vida.h"
using namespace std;

Facade::Facade(){
    Jugador jugador("");
    _jugador = &jugador;
    _nivel = 1;
    _cantObstaculos=0;
    _cantBeneficios=0;
}
Facade::~Facade(){
    int i = 0;
    while(i<_cantObstaculos){
        delete _arrayObstaculos[i];
        i++;
    }
    int w =0;
    while(w<_cantBeneficios){
        delete _arrayBeneficios[w];
        w++;
    }
    qDebug()<<"mori facade";

}


int Facade::jugadorPosX(){
    return (*_jugador).getPosX();
}
int Facade::jugadorPosY(){
    return (*_jugador).getPosY();
}
void Facade::crearObstaculo(string tipo, int posX,int posY){
    if(_cantObstaculos<100){
        if (tipo=="Dinamico"){
            _arrayObstaculos[_cantObstaculos] = new Ob_Dinamico(10,posX,posY,10);//valores de salud y valor tentativos
            _cantObstaculos++;
        }
        if (tipo=="Estatico"){
            _arrayObstaculos[_cantObstaculos] = new Ob_Estatico(10,posX,posY,10);//valores de salud y valor tentativos
            _cantObstaculos++;
        }
        if (tipo=="Jefe"){
            _arrayObstaculos[_cantObstaculos] = new Ob_Jefe(20,posX,posY,20);//valores de salud y valor tentativos
            _cantObstaculos++;
        }
        if (tipo=="Rastrero"){
            _arrayObstaculos[_cantObstaculos] = new Ob_Rastrero(15,posX,posY,15);//valores de salud y valor tentativos
            _cantObstaculos++;
        }
        if (tipo=="Teledirigido"){
            _arrayObstaculos[_cantObstaculos] = new Ob_Teledirigido(5,posX,posY,5);//valores de salud y valor tentativos
            _cantObstaculos++;
        }
        if (tipo=="Volumen"){
            _arrayObstaculos[_cantObstaculos] = new Ob_Volumen(2,posX,posY,2);//valores de salud y valor tentativos
            _cantObstaculos++;
        }
        else{
            //solo entraria aqui si hay un error en el llamado que hara la GUI de esta funcion
        }

    }
    else{
        //entraria aqui cuando se llene el arreglo, se debe definir que procedera en este caso
    }
}

void Facade::borrarObstaculoEnPos(int indice){
    if (indice<_cantObstaculos){
        delete _arrayObstaculos[indice];
        _cantObstaculos--;
        while(indice < _cantObstaculos){
            _arrayObstaculos[indice]=_arrayObstaculos[indice+1];
            indice++;
        }
    }
}

int Facade::borrarObstaculoPorPuntero(Obstaculo *obstaculo)
{
    int i = 0;
    int indice = -1;
    while(i<_cantObstaculos){
        if(_arrayObstaculos[i] == obstaculo){
            delete _arrayObstaculos[i];
            _cantObstaculos--;
            indice = i;
            while(i < _cantObstaculos){
                _arrayObstaculos[i]=_arrayObstaculos[i+1];
                i++;
            }

        }
        else{
            i++;
        }
    }
    return indice;
}


void Facade::crearBeneficio(string tipo, int posX,int posY){
    if(_cantBeneficios<100){
        if (tipo=="Arma"){
            _arrayBeneficios[_cantBeneficios] = new Be_Arma(posX,posY);
            _cantBeneficios++;
        }
        if (tipo=="Invencible"){
            _arrayBeneficios[_cantBeneficios] = new Be_Invencible(posX,posY);
            _cantBeneficios++;
        }
        if (tipo=="Reliquia"){
            _arrayBeneficios[_cantBeneficios] = new Be_Reliquia(posX,posY);
            _cantBeneficios++;
        }
        if (tipo=="Vida"){
            _arrayBeneficios[_cantBeneficios] = new Be_Vida(posX,posY);
            _cantBeneficios++;
        }
        else{

        }

    }
    else{

        }

}

int Facade::getPosXBeneficioEnPos(int indice){
    if (indice<_cantBeneficios){
        return _arrayBeneficios[indice]->getPosX();
    }
    else{

    }
}
int Facade::getPosYBeneficioEnPos(int indice){
    if (indice<_cantBeneficios){
        return _arrayBeneficios[indice]->getPosY();
    }
    else{

    }
}

int Facade::jugadorReliquias()
{
    return _jugador->getReliquias();
}

Obstaculo *Facade::getObstaculoEnPos(int indice)
{
    if (indice < _cantObstaculos){
        return _arrayObstaculos[indice];
    }
}

void Facade::setJugadorNombre(string nombre)
{
    _jugador->setNombre(nombre);
}

int Facade::getCantBeneficios(){
    return _cantBeneficios;
}
int Facade::getCantObstaculos(){
    return _cantObstaculos;
}
int Facade::getNivel(){
    return _nivel;
}
int Facade::getPosXObstaculoEnPos(int indice){
    if(indice < _cantObstaculos){
        return _arrayObstaculos[indice]->getPosX();
    }
    else{
        return -1; //lo estandarizamos como codigo de error ya que es posible la posicion 0
    }
}
int Facade::getPosYObstaculoEnPos(int indice){
    if(indice < _cantObstaculos){
        return _arrayObstaculos[indice]->getPosY();
    }
    else{
        return -1; //lo estandarizamos como codigo de error ya que es posible la posicion 0
    }
}
int Facade::getSaludObstaculoEnPos(int indice){
    if(indice < _cantObstaculos){
        return _arrayObstaculos[indice]->getSalud();
    }
    else{
        return -1; //lo estandarizamos como codigo de error ya que es posible la posicion 0
    }
}
int Facade::getValorObstaculoEnPos(int indice){
    if(indice < _cantObstaculos){
        return _arrayObstaculos[indice]->getValor();
    }
    else{
        return -1; //lo estandarizamos como codigo de error ya que es posible la posicion 0
    }
}
