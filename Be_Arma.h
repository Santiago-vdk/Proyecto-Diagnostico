#ifndef BE_ARMA_H
#define BE_ARMA_H
#include <Beneficio.h>

class Be_Arma: public Beneficio
{
public:
    Be_Arma(int posX,int posY):Beneficio(posX,posY){}
    virtual string beneficio();
    ~Be_Arma();
};

#endif // BE_ARMA_H
