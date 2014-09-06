#ifndef OB_VOLUMEN_H
#define OB_VOLUMEN_H
#include <Obstaculo.h>
class Ob_Volumen: public Obstaculo
{
public:
    Ob_Volumen(int salud,int posX,int posY,int valor):Obstaculo(salud,posX,posY,valor){}
    virtual void mover();
};

#endif // OB_VOLUMEN_H
