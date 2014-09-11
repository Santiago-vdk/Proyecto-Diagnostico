#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
using namespace std;

class Jugador
{

public:
    Jugador(string nombre);
    ~Jugador();
    void setPuntaje(int puntaje);
    void setVidas(int vidas);
    void setPosX(int posX);
    void setPosY(int posY);
    void setVelocidad(int velocidad);
    void setArmas(int armas);
    void setReliquias(int reliquias);
    void setNombre(string nombre);
    void setInvencible(bool invencible);

    int getPuntaje();
    int getVidas();
    int getPosX();
    int getPosY();
    int getVelocidad();
    int getArmas();
    int getReliquias();
    string getNombre();
    bool getInvencible();


private:
    //int _puntaje,_vidas,_posX,_posY,_velocidad,_armas,_reliquias;
    int _puntaje;
    int _vidas;
    int _posX = 0;
    int _posY = 0;
    int _velocidad;
    int  _armas;
    int _reliquias;

    string _nombre;
    bool _invencible;


};

#endif // JUGADOR_H
