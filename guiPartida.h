#ifndef GUIPARTIDA_H
#define GUIPARTIDA_H

#include <QMainWindow>
#include <QLabel>

#include "Thread.h"

namespace Ui {
class guiPartida;

}

class guiPartida : public QMainWindow
{
    Q_OBJECT


public:
    explicit guiPartida(QWidget *parent = 0);
    void crearLabel();
    void moverLabel();
    ~guiPartida();

private:
    Ui::guiPartida *ui;
    QLabel *label;
};

#endif // GUIPARTIDA_H
