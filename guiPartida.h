#ifndef GUIPARTIDA_H
#define GUIPARTIDA_H

#include <QMainWindow>
#include <QLabel>

#include "threadCrearObstaculo.h"
#include <QThread>


namespace Ui {
class guiPartida;

}

class guiPartida : public QMainWindow
{
    Q_OBJECT


public:
    explicit guiPartida(QWidget *parent = 0);
    void crearJugador();
    void CrearObstaculos();
    ~guiPartida();

private:
    Ui::guiPartida *ui;
    QLabel *labelJugador;
    QThread* Qhilo;
    threadCrearObstaculos* worker;

};

#endif // GUIPARTIDA_H
