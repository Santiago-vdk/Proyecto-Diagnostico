#ifndef GUI_H
#define GUI_H
#include <QMainWindow>
#include <QLabel>
#include <loading.h>
#include <QString>
#include <string>
#include <QThread>
#include <threadCrearObstaculo.h>
#include <Facade.h>



using namespace std;

namespace Ui {
class gui;
}

class gui : public QMainWindow
{
    Q_OBJECT

public:
    explicit gui(QWidget *parent = 0);
    ~gui();

public slots:
    void closeWindow();
    void carga();
    void partida();
    void CrearObstaculos();

private slots:



private:
    Ui::gui *ui;
    QString nombreUsuario;
    QThread* encapsulaThreadCrearObjetos;
    threadCrearObstaculos* ThreadCrearObjetos;
    Facade *_facade;
    guiPartida *match;
};





#endif // GUI_H
