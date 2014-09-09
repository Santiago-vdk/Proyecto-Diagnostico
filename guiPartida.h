#ifndef GUIPARTIDA_H
#define GUIPARTIDA_H
#include <QMainWindow>
#include <QLabel>
#include "threadCrearObstaculo.h"
#include <QThread>
#include <QString>

namespace Ui {
class guiPartida;

}

class guiPartida : public QMainWindow
{
    Q_OBJECT


public:
    explicit guiPartida(QWidget *parent = 0, QString nombreUsuario = "");
    void crearJugador();
    void CrearObstaculos();
    int getTamanioVentanaX();
    int getTamanioVentanaY();
    void setTamanioVentana(int ptamanioX, int ptamanioY);
    ~guiPartida();

private:
    Ui::guiPartida *ui;
    QLabel *labelJugador;
    QThread* encapsulaThreadCrearObjetos;
    threadCrearObstaculos* ThreadCrearObjetos;
    int tamanioX;
    int tamanioY;
    QString _nombreUsuario;


};

#endif // GUIPARTIDA_H
