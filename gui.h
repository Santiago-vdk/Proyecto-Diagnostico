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
#include <threadRefrescaGui.h>



using namespace std;

namespace Ui {
class gui;
}

class gui : public QMainWindow
{
    Q_OBJECT

public:
    explicit gui(QWidget *parent = 0);
    void refrescaGUI();
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

    QThread* encapsulaThreadRefrescarGUI;
    threadRefrescaGui* ThreadRefrescarGUI;

};





#endif // GUI_H
