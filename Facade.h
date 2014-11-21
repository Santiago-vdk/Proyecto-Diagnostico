#ifndef FACADE_H
#define FACADE_H
#include "Jugador.h"
#include "Obstaculo.h"
#include "Beneficio.h"
#include <string>
#include <Disparo.h>
#include <infomapa.h>

using namespace std;

class Facade
{
private:
    Jugador *_jugador;
    Obstaculo *_arrayObstaculos[100];
    Beneficio *_arrayBeneficios[50];
    Disparo *_arrayDisparos[100];
    //infoMapa *_infoMapa;

    int *_arrayObstaculosPorNivel;
    int *_arrayBeneficiosPorNivel;
    int _tiempo;

    int _cantObstaculos,_cantBeneficios,_cantDisparos,_nivel;
    bool cambioNivel;
    infoMapa *_infoMapa;

public:
    Facade();
    ~Facade();
    int jugadorPosX();
    int jugadorPosY();
    int getVidaJugador();
    Jugador *getJugador();
    void crearObstaculo(string tipo,int posX,int posY);

    void crearDisparo(string tipo,int posX,int posY);

    void borrarObstaculoEnPos(int indice);
    void borrarDisparoEnPos(int indice);
    void borrarBeneficioEnPos(int indice);
    int borrarObstaculoPorPuntero(Obstaculo *obstaculo);

    int borrarDisparoPorPuntero(Disparo *disparo);
    int borrarBeneficioPorPuntero(Beneficio *beneficio);
    void setVidasJugador(int i);
    int getCantObstaculos();
    int getCantBeneficios();
    int getNivel();
    int getSaludObstaculoEnPos(int indice);
    int getPosXObstaculoEnPos(int indice);
    int getPosYObstaculoEnPos(int indice);
    int getPosXDisparoEnPos(int indice);
    int getPosYDisparoEnPos(int indice);
    int getCantDisparos();
    int getValorObstaculoEnPos(int indice);
    Disparo *getDisparoEnPos(int indice);
    Beneficio *getBeneficioEnPos(int indice);
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
    bool colisionConDisparo(int pPosX, int pPosY);
    bool colisionConObstaculo(int pPosX,int pPosY);
    bool colisionConReliquia(int pPosX,int pPosY);
    void setCambioNivel(bool cambio);
    bool getCambioNivel();


    void nuevoNivel();
    int valorEnPosArrayObstaculosPorNivel(int i);
    int valorEnPosArrayBeneficiosPorNivel(int i);
    void setValorEnPosArrayObstaculosPorNivel(int i);
    void setValorEnPosArrayBeneficiosPorNivel(int i);
    int getTiempo();
    void setTiempo();



};

#endif // FACADE_H
