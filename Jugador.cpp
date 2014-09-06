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
   _arma = 1;
   _invencible = false;
   _reliquias = 0;

}
Jugador::getArmas(){
    return _armas;
}
Jugador::getInvencible(){
    return _invencible;
}
Jugador::getNombre(){
    return _nombre;
}
Jugador::getPosX(){
    return _posX;
}
Jugador::getPosY(){
    return _posY;
}
Jugador::getPuntaje(){
    return _puntaje;
}
Jugador::getReliquias(){
    return _reliquias;
}
Jugador::getVelocidad(){
    return _velocidad;
}
Jugador::getVidas(){
    return _vidas;
}
Jugador::setArmas(int armas){
    _armas = armas;
}
Jugador::setInvencible(bool invencible){
    _invencible = invencible;
}
Jugador::setNombre(string nombre){
    _nombre = nombre;
}
Jugador::setPosX(int posX){
    _posX = posX;
}
Jugador::setPosY(int posY){
    _posY = posY;
}
Jugador::setPuntaje(int puntaje){
    _puntaje = puntaje;
}
Jugador::setReliquias(int reliquias){
    _reliquias = reliquias;
}
Jugador::setVelocidad(int velocidad){
    _velocidad = velocidad;
}
Jugador::setVidas(int vidas){
    _vidas = vidas;
}












