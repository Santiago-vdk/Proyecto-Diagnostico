#include "Jugador.h"

#include <string>
using namespace std;

Jugador::Jugador(string nombre)
{
   _puntaje = 0;
   _vidas = 3;
   _nombre = nombre;
   _posX = 500;
   _posY = 0;
   _velocidad = 0;
   _armas = 1;
   _invencible = false;
   _reliquias = 0;

}
int Jugador::getArmas(){
    return _armas;
}
bool Jugador::getInvencible(){
    return _invencible;
}
string Jugador::getNombre(){
    return _nombre;
}
int Jugador::getPosX(){
    return _posX;
}
int Jugador::getPosY(){
    return _posY;
}
int Jugador::getPuntaje(){
    return _puntaje;
}
int Jugador::getReliquias(){
    return _reliquias;
}
int Jugador::getVelocidad(){
    return _velocidad;
}
int Jugador::getVidas(){
    return _vidas;
}
void Jugador::setArmas(int armas){
    _armas = armas;
}
void Jugador::setInvencible(bool invencible){
    _invencible = invencible;
}
void Jugador::setNombre(string nombre){
    _nombre = nombre;
}
void Jugador::setPosX(int posX){
    _posX = posX;
}
void Jugador::setPosY(int posY){
    _posY = posY;
}
void Jugador::setPuntaje(int puntaje){
    _puntaje = puntaje;
}
void Jugador::setReliquias(int reliquias){
    _reliquias = reliquias;
}
void Jugador::setVelocidad(int velocidad){
    _velocidad = velocidad;
}
void Jugador::setVidas(int vidas){
    _vidas = vidas;
}












