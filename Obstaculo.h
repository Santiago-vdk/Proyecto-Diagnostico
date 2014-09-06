#ifndef OBSTACULO_H
#define OBSTACULO_H

class Obstaculo
{
public:
    Obstaculo(int salud,int posX,int posY,int valor);
    void setSalud(int salud);
    void setPosX(int posX);
    void setPosY(int posY);
    void setValor(int valor);

    int getSalud();
    int getPosX();
    int getPosY();
    int getValor();

    virtual void mover()=0;

protected:
    int _salud,_posX,_posY,_valor;
};

#endif // OBSTACULO_H
