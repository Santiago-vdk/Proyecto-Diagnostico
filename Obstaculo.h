#ifndef OBSTACULO_H
#define OBSTACULO_H

class Obstaculo
{
public:
    Obstaculo(int salud,int posX,int posY,int valor);
    virtual ~Obstaculo();
    void setSalud(int salud);
    void setPosX(int posX);
    void setPosY(int posY);
    void setValor(int valor);

    int getSalud();
    int getPosX();
    int getPosY();
    int getValor();

    virtual void mover(int pPosY)=0;

    bool matadoPorJugador;
    bool getMatadoPorJugador();
    void setMatadoPorJugador(bool pMatadoPorJugador);

protected:
    int _salud,_posX,_posY,_valor;
};

#endif // OBSTACULO_H
