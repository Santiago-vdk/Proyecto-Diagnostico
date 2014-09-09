#ifndef GUIPARTIDA_H
#define GUIPARTIDA_H
#include <QMainWindow>
#include <QLabel>
#include <QThread>
#include <QString>
#include <string>
#include <Facade.h>

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
    //void CrearObstaculos();
    int getTamanioVentanaX();
    int getTamanioVentanaY();
    void setTamanioVentana(int ptamanioX, int ptamanioY);

    ~guiPartida();


public slots:
    void crearObstaculoLabel();


private:
    Ui::guiPartida *ui;
    QLabel *labelJugador;
    QLabel *labelObstaculo;
//    QThread* encapsulaThreadCrearObjetos;
//    threadCrearObstaculos* ThreadCrearObjetos;
    int tamanioX;
    int tamanioY;
//    string _nombreUsuario;
    Facade *_facade;


};

#endif // GUIPARTIDA_H
