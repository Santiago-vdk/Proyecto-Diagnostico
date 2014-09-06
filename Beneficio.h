#ifndef BENEFICIO_H
#define BENEFICIO_H

class Beneficio
{
private:
    int _posX, _posY;

public:
    int getPosX();
    int getPosY();
    void setPosX(int posX);
    void setPosY(int posY);
    virtual beneficio()=0;
};

#endif // BENEFICIO_H
