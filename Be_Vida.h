#ifndef BE_VIDA_H
#define BE_VIDA_H
#include <Beneficio.h>

class Be_Vida: public Beneficio
{
public:
    Be_Vida(int posX,int posY):Beneficio(posX,posY){}
    virtual string beneficio();
};

#endif // BE_VIDA_H
