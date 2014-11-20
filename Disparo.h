#ifndef DISPARO_H
#define DISPARO_H

class Disparo
{
public:
    Disparo(int posX, int posY);
    int getPosX();
    int getPosY();
    void setPosX(int pPosX);
    void setPosY(int pPosY);
    bool conPolvora;

    bool getbanderaConPolvora();
    void setbanderaConPolvora(bool pFlag);



private:
    int posX;
    int posY;
};

#endif // DISPARO_H
