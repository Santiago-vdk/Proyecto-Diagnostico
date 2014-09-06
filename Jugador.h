#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
using namespace std;

class Jugador
{
private:
    int _puntaje,_vidas,_posX,_posY,_velocidad,_armas,_reliquias;
    string _nombre;
    bool _invencible;
public:
    Jugador(string nombre);
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


};

#endif // JUGADOR_H
