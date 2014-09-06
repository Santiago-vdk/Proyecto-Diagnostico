#ifndef BE_INVENCIBLE_H
#define BE_INVENCIBLE_H
#include <Beneficio.h>

class Be_Invencible: public Beneficio
{
public:
    Be_Invencible(int posX,int posY):Beneficio(posX,posY){}
    virtual string beneficio();
};

#endif // BE_INVENCIBLE_H
