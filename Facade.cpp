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
    _jugador = new Jugador("");
    _nivel = 0;
    _cantObstaculos=0;
    _cantBeneficios=0;
    _cantDisparos=0;
    cambioNivel = false;
    _arrayObstaculosPorNivel = new int[5];
    _arrayBeneficiosPorNivel = new int[4];
    _infoMapa = new infoMapa(_nivel);
    nuevoNivel();


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
    int k = 0;
    while(k<_cantDisparos){
        delete _arrayDisparos[k];
        k++;
    }
    delete _jugador;
    qDebug()<<"mori facade";

}

int Facade::jugadorPosX(){
    return _jugador->getPosX();
}
int Facade::jugadorPosY(){
    return _jugador->getPosY();
}

int Facade::getVidaJugador()
{
    return _jugador->getVidas();
}

Jugador *Facade::getJugador()
{
    return _jugador;
}
void Facade::crearObstaculo(string tipo, int posX,int posY){
    if(_cantObstaculos<100){
        if (tipo=="Dinamico"){
            _arrayObstaculos[_cantObstaculos] = new Ob_Dinamico(15,posX,posY,10);//valores de salud y valor tentativos
            _cantObstaculos++;
        }
        if (tipo=="Estatico"){
            _arrayObstaculos[_cantObstaculos] = new Ob_Estatico(20,posX,posY,0);//valores de salud y valor tentativos
            _cantObstaculos++;
        }
        if (tipo=="Jefe"){
            _arrayObstaculos[_cantObstaculos] = new Ob_Jefe(40,posX,posY,200);//valores de salud y valor tentativos
            _cantObstaculos++;
        }
        if (tipo=="Rastrero"){
            _arrayObstaculos[_cantObstaculos] = new Ob_Rastrero(10,posX,posY,50);//valores de salud y valor tentativos
            _cantObstaculos++;
        }
        if (tipo=="Teledirigido"){
            _arrayObstaculos[_cantObstaculos] = new Ob_Teledirigido(10,posX,posY,50);//valores de salud y valor tentativos
            _cantObstaculos++;
        }
        if (tipo=="Volumen"){
            _arrayObstaculos[_cantObstaculos] = new Ob_Volumen(4,posX,posY,20);//valores de salud y valor tentativos
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

void Facade::crearDisparo(string tipo, int posX, int posY)
{
    if(_cantDisparos<100){
        if(tipo=="Disparo"){


            _arrayDisparos[_cantDisparos] = new Disparo(posX, posY);
            _cantDisparos++;



        }
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


void Facade::borrarDisparoEnPos(int indice)
{
    if (indice<_cantDisparos){
        delete _arrayDisparos[indice];
        _cantDisparos--;
        while(indice < _cantDisparos){
            _arrayDisparos[indice]=_arrayDisparos[indice+1];
            indice++;
        }
    }
}

void Facade::borrarBeneficioEnPos(int indice)
{
    if (indice<_cantBeneficios){
        delete _arrayBeneficios[indice];
        _cantBeneficios--;
        while(indice < _cantBeneficios){
            _arrayBeneficios[indice]=_arrayBeneficios[indice+1];
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
//##########################################################
int Facade::borrarDisparoPorPuntero(Disparo *disparo)
{
    int i = 0;
    int indice = -1;
    while(i<_cantDisparos){
        if(_arrayDisparos[i] == disparo){
            delete _arrayDisparos[i];
            _cantDisparos--;
            indice = i;
            while(i < _cantDisparos){
                _arrayDisparos[i]=_arrayDisparos[i+1];
                i++;
            }
        }
        else{
            i++;
        }
    }
    return indice;
}




int Facade::borrarBeneficioPorPuntero(Beneficio *beneficio)
{
    int i = 0;
    int indice = -1;
    while(i<_cantBeneficios){
        if(_arrayBeneficios[i] == beneficio){
            delete _arrayBeneficios[i];
            _cantBeneficios--;
            indice = i;
            while(i < _cantBeneficios){
                _arrayBeneficios[i]=_arrayBeneficios[i+1];
                i++;
            }
        }
        else{
            i++;
        }
    }
    return indice;
}

void Facade::setVidasJugador(int i)
{
    _jugador->setVidas(i);
}
//##########################################################

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
        return -1;
    }
}
int Facade::getPosYBeneficioEnPos(int indice){
    if (indice<_cantBeneficios){
        return _arrayBeneficios[indice]->getPosY();
    }
    else{
        return -1;
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
    else{

    }
}

Disparo *Facade::getDisparoEnPos(int indice)
{
    if (indice < _cantDisparos){
        return _arrayDisparos[indice];
    }
    else{

    }
}

Beneficio *Facade::getBeneficioEnPos(int indice)
{
    if (indice < _cantBeneficios){
        return _arrayBeneficios[indice];
    }
    else{

    }
}

void Facade::setJugadorNombre(string nombre)
{
    _jugador->setNombre(nombre);
}

void Facade::jugadorMoverMasX()
{
    if(_jugador->getPosX()+10<1300){
        _jugador->setPosX(_jugador->getPosX()+10);
    }
}
void Facade::jugadorMoverMasY()
{
    if(_jugador->getPosY()+10<550){
        _jugador->setPosY(_jugador->getPosY()+10);
    }
}
void Facade::jugadorMoverMenosX()
{
    if(_jugador->getPosX()-10>0){
        _jugador->setPosX(_jugador->getPosX()-10);
    }
}
void Facade::jugadorMoverMenosY()
{
    _jugador->setPosY(_jugador->getPosY()-10);
}

bool Facade::colisionConDisparo(int pPosX, int pPosY)
{
    for(int i = 0; i < _cantObstaculos; i++){
        if( ( pPosX + 40 >= _arrayObstaculos[i]->getPosX() && pPosX <= _arrayObstaculos[i]->getPosX() +65)
                && pPosY + 10 >= _arrayObstaculos[i]->getPosY() && pPosY <= _arrayObstaculos[i]->getPosY() +65 ){
            _arrayObstaculos[i]->setSalud(_arrayObstaculos[i]->getSalud()-_jugador->getArmas());
            if(_arrayObstaculos[i]->getSalud()<=0){
                _jugador->setPuntaje(_jugador->getPuntaje()+_arrayObstaculos[i]->getValor());
                _arrayObstaculos[i]->setMatadoPorJugador(true);
            }
            return true;
        }
    }
    return false;
}

bool Facade::colisionConObstaculo(int pPosX, int pPosY)
{
    for(int i = 0; i < _cantObstaculos; i++){
        if( ( pPosX + 65 >= _arrayObstaculos[i]->getPosX() && pPosX <= _arrayObstaculos[i]->getPosX() +65)
                && pPosY + 65 >= _arrayObstaculos[i]->getPosY() && pPosY <= _arrayObstaculos[i]->getPosY() +65 ){
            _arrayObstaculos[i]->setSalud(0);
            _jugador->setVidas(_jugador->getVidas() - 1);
            return true;
        }
    }
    return false;
}


bool Facade::colisionConReliquia(int pPosX, int pPosY){

    for(int i = 0; i < _cantBeneficios; i++){
        if( ( pPosX + 65 >= _arrayBeneficios[i]->getPosX() && pPosX <= _arrayBeneficios[i]->getPosX() +65)
                && pPosY + 65 >= _arrayBeneficios[i]->getPosY() && pPosY <= _arrayBeneficios[i]->getPosY() +65 ){
            _arrayBeneficios[i]->setAdquirido(true);
            if(_arrayBeneficios[i]->beneficio().compare("Arma") == 0){
                _jugador->setArmas(_jugador->getArmas() + 2);
            }
            if(_arrayBeneficios[i]->beneficio().compare("Vida") == 0 && _jugador->getVidas() < 5){

                _jugador->setVidas(_jugador->getVidas() + 1);

            }
            if(_arrayBeneficios[i]->beneficio().compare("Invencible") == 0){
                _jugador->setInvencible(true);
            }
            if(_arrayBeneficios[i]->beneficio().compare("Reliquia") == 0){
                _jugador->setReliquias(_jugador->getReliquias()-1);
                setValorEnPosArrayBeneficiosPorNivel(0);

//                if(_jugador->getReliquias() <= 0){
//                    qDebug("Gane cambio nivel");
//                    cambioNivel = true;
//                    _nivel += 1;
//                    nuevoNivel();
//                    //cambioNivel = false;
//                }
            }

            return true;
        }
    }
    return false;
}

void Facade::setCambioNivel(bool cambio)
{
    cambioNivel = cambio;
}

bool Facade::getCambioNivel()
{
    return cambioNivel;
}

void Facade::nuevoNivel()
{
    _nivel += 1;
    if(_nivel>=4){
        _jugador->setVidas(0);
    }
    else{
        _infoMapa->leer(_nivel);
        _arrayObstaculosPorNivel[0] = _infoMapa->getDinamico();
        _arrayObstaculosPorNivel[1] = _infoMapa->getEstatico();
        _arrayObstaculosPorNivel[2] = _infoMapa->getRastrero();
        _arrayObstaculosPorNivel[3] = _infoMapa->getTeledirigido();
        _arrayObstaculosPorNivel[4] = _infoMapa->getVolumen();

        _arrayBeneficiosPorNivel[0] = _infoMapa->getReliquias();
        _jugador->setReliquias(_infoMapa->getReliquias());
        _arrayBeneficiosPorNivel[1] = _infoMapa->getArma();
        _jugador->setArmas(_infoMapa->getArma());
        _arrayBeneficiosPorNivel[2] = _infoMapa->getInvencible();
        _arrayBeneficiosPorNivel[3] = _infoMapa->getVida();

        _tiempo = _infoMapa->getTiempo();
    }
}

int Facade::valorEnPosArrayObstaculosPorNivel(int i)
{
    return _arrayObstaculosPorNivel[i];

}

int Facade::valorEnPosArrayBeneficiosPorNivel(int i)
{
    return _arrayBeneficiosPorNivel[i];
}

void Facade::setValorEnPosArrayObstaculosPorNivel(int i)
{
    _arrayObstaculosPorNivel[i]-=1;
}

void Facade::setValorEnPosArrayBeneficiosPorNivel(int i)
{
    _arrayBeneficiosPorNivel[i]-=1;
}

int Facade::getTiempo()
{
    return _tiempo;
}

void Facade::setTiempo()
{
    _tiempo = _tiempo - 1;
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

//#########################################

int Facade::getPosXDisparoEnPos(int indice){
    if(indice < _cantDisparos){
        return _arrayDisparos[indice]->getPosX();
    }
    else{
        return -1; //lo estandarizamos como codigo de error ya que es posible la posicion 0
    }
}
int Facade::getPosYDisparoEnPos(int indice){
    if(indice < _cantDisparos){
        return _arrayDisparos[indice]->getPosY();
    }
    else{
        return -1; //lo estandarizamos como codigo de error ya que es posible la posicion 0
    }
}


int Facade::getCantDisparos()
{
    return _cantDisparos;
}

//#######################################




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
