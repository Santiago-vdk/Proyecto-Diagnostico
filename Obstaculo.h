#ifndef OBSTACULO_H
#define OBSTACULO_H

class Obstaculo
{
public:
    void setSalud(int salud);
    void setPosX(int posX);
    void setPosY(int posY);
    void setValor(int valor);

    int getSalud();
    int getPosX();
    int getPosY();
    int getValor();

    virtual mover()=0;

private:
int _salud,_posX,_posY,_valor;
};

#endif // OBSTACULO_H
