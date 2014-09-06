#ifndef OB_JEFE_H
#define OB_JEFE_H

#include <Obstaculo.h>
class Ob_Jefe: public Obstaculo
{
public:
    Ob_Jefe(int salud,int posX,int posY,int valor):Obstaculo(salud,posX,posY,valor){}
    virtual void mover();
};

#endif // OB_JEFE_H
