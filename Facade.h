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
    Beneficio *_arrayBeneficios[50];
    int _cantObstaculos,_cantBeneficios,_nivel;

public:
    Facade();
    ~Facade();
    int jugadorPosX();
    int jugadorPosY();
    void crearObstaculo(string tipo,int posX,int posY);
    void borrarObstaculoEnPos(int indice);
    int borrarObstaculoPorPuntero(Obstaculo *obstaculo);
    int getCantObstaculos();
    int getCantBeneficios();
    int getNivel();
    int getSaludObstaculoEnPos(int indice);
    int getPosXObstaculoEnPos(int indice);
    int getPosYObstaculoEnPos(int indice);
    int getValorObstaculoEnPos(int indice);
    //Agregados por Santiago-vdk
    void crearBeneficio(string tipo, int posX, int posY);
    int getPosXBeneficioEnPos(int indice);
    int getPosYBeneficioEnPos(int indice);
    int jugadorReliquias();
    Obstaculo* getObstaculoEnPos(int indice);
    void setJugadorNombre(string nombre);
    void jugadorMoverMasX();
    void jugadorMoverMasY();
    void jugadorMoverMenosX();
    void jugadorMoverMenosY();
};

#endif // FACADE_H
