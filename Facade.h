#ifndef FACADE_H
#define FACADE_H
#include "Jugador.h"
#include "Obstaculo.h"
#include "Beneficio.h"
#include <string>

using namespace std;

class Facade
{
private:
    Jugador *_jugador;
    Obstaculo *_arrayObstaculos[100];
    Beneficio *_arrayBeneficios[20];
    int _cantObstaculos,_cantBeneficios,_nivel;

public:
    Facade(string nombre);
    int jugadorPosX();
    int jugadorPosY();
};

#endif // FACADE_H
