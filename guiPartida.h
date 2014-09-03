#ifndef GUIPARTIDA_H
#define GUIPARTIDA_H

#include <QMainWindow>

namespace Ui {
class guiPartida;
}

class guiPartida : public QMainWindow
{
    Q_OBJECT

public:
    explicit guiPartida(QWidget *parent = 0);
    ~guiPartida();

private:
    Ui::guiPartida *ui;
};

#endif // GUIPARTIDA_H
