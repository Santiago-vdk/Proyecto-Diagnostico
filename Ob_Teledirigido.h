#ifndef OB_TELEDIRIGIDO_H
#define OB_TELEDIRIGIDO_H
#include <Obstaculo.h>
class Ob_Teledirigido: public Obstaculo
{
public:
    Ob_Teledirigido(int salud,int posX,int posY,int valor):Obstaculo(salud,posX,posY,valor){}
    virtual void mover(int pPosY);
    ~Ob_Teledirigido();
};

#endif // OB_TELEDIRIGIDO_H
