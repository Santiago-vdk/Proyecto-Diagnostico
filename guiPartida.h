#ifndef GUIPARTIDA_H
#define GUIPARTIDA_H
#include <QMainWindow>
#include <QLabel>
#include <QThread>
#include <QString>
#include <string>
#include <Facade.h>
#include <QKeyEvent>


using namespace std;

namespace Ui {
class guiPartida;

}

class guiPartida : public QMainWindow
{
    Q_OBJECT


public:
    explicit guiPartida(QWidget *parent = 0, Facade *facade = NULL);
    void crearJugador();

    void borrarLabelEnPos(int i);
    void borrarDisparoEnPos(int i);
    void borrarBeneficioEnPos(int i);
    int getTamanioVentanaX();
    int getTamanioVentanaY();
    void setTamanioVentana(int ptamanioX, int ptamanioY);
    void setLabelInfo(string pLabelNombre, int posLabelX, int posLabelY);

    void keyPressEvent(QKeyEvent* e);

    ~guiPartida();
    void setquieroUnDisparo(bool pBool);
    bool getquieroUnDisparo();

public slots:
    void agregarArregloLabels();
    void refrescarGUI();
    void destruirJugador();
    void colisionDisparo(int posX, int posY);
    void aumentarContadorPuntucion(int contado);
    void quitarJugadorVida();



signals:
    void disparar();


private:
    Ui::guiPartida *ui;
    QLabel *labelJugador;
    QLabel *labelObstaculo;
    int tamanioX;
    int tamanioY;
    Facade *_facade;
    QLabel *arregloLabels[100];
    QLabel *arregloDisparos[100];
    QLabel *arregloBeneficios[100];
    int contadorArregloLabels = 0;
    int contadorArregloDisparos = 0;
    int contadorArregloBeneficios = 0;
    string _LabelNombre;
    int _posLabelX;
    int _posLabelY;
    bool quieroUnDisparo;

};

#endif // GUIPARTIDA_H
