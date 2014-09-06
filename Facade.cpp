#include "Facade.h"
#include "Jugador.h"
#include <string>

using namespace std;

Facade::Facade(string nombre){
    Jugador jugador(nombre);
    _jugador = &jugador;
    _nivel = 1;
}
int Facade::jugadorPosX(){
    return (*_jugador).getPosX();
}
int Facade::jugadorPosY(){
    return (*_jugador).getPosY();
}
