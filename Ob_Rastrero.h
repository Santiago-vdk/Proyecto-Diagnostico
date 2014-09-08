#ifndef OB_RASTRERO_H
#define OB_RASTRERO_H

#include <Obstaculo.h>
class Ob_Rastrero: public Obstaculo
{
public:
    Ob_Rastrero(int salud,int posX,int posY,int valor):Obstaculo(salud,posX,posY,valor){}
    virtual void mover();
    ~Ob_Rastrero();
};

#endif // OB_RASTRERO_H
