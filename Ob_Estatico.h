#ifndef OB_ESTATICO_H
#define OB_ESTATICO_H
#include "Obstaculo.h"

class Ob_Estatico: public Obstaculo
{
public:
    Ob_Estatico(int salud,int posX,int posY,int valor):Obstaculo(salud,posX,posY,valor){}
    virtual void mover(int pPosY);
    ~Ob_Estatico();
};

#endif // OB_ESTATICO_H
