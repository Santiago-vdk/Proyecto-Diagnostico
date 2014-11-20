#include "Disparo.h"

Disparo::Disparo(int pposX, int pposY)
{
    posX = pposX;
    posY = pposY;
    conPolvora = true;
}

int Disparo::getPosX()
{
    return posX;
}

int Disparo::getPosY()
{
    return posY;
}

void Disparo::setPosX(int pPosX)
{
    posX = pPosX;
}

void Disparo::setPosY(int pPosY)
{
    posY = pPosY;
}

bool Disparo::getbanderaConPolvora()
{
    return conPolvora;
}

void Disparo::setbanderaConPolvora(bool pFlag)
{
    conPolvora = pFlag;
}
