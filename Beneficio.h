#ifndef BENEFICIO_H
#define BENEFICIO_H
#include <string>
using namespace std;

class Beneficio
{
protected:
    int _posX, _posY;

public:
    Beneficio(int posX,int posY);
    virtual ~Beneficio();
    int getPosX();
    int getPosY();
    void setPosX(int posX);
    void setPosY(int posY);
    virtual string beneficio()=0;
    bool adquirido;
    bool getAdquirido();
    void setAdquirido(bool pCondicion);
};

#endif // BENEFICIO_H
