#ifndef BENEFICIO_H
#define BENEFICIO_H
#include <string>
using namespace std;

class Beneficio
{
private:
    int _posX, _posY;

public:
    int getPosX();
    int getPosY();
    void setPosX(int posX);
    void setPosY(int posY);
    virtual string beneficio()=0;
};

#endif // BENEFICIO_H
