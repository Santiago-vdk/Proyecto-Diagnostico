#ifndef BE_RELIQUIA_H
#define BE_RELIQUIA_H
#include <Beneficio.h>

class Be_Reliquia: public Beneficio
{
public:
    Be_Reliquia(int posX,int posY):Beneficio(posX,posY){}
    virtual string beneficio();
    ~Be_Reliquia();
};

#endif // BE_RELIQUIA_H
