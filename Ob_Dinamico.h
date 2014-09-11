#ifndef OB_DINAMICO_H
#define OB_DINAMICO_H
#include <Obstaculo.h>
class Ob_Dinamico: public Obstaculo
{
public:
    Ob_Dinamico(int salud,int posX,int posY,int valor):Obstaculo(salud,posX,posY,valor){
    }
    virtual void mover();
    ~Ob_Dinamico();
};

#endif // OB_DINAMICO_H
