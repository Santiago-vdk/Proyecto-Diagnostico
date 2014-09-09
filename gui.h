#ifndef GUI_H
#define GUI_H
#include <QMainWindow>
#include <QLabel>
#include <loading.h>
#include <QString>



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

private slots:



private:
    Ui::gui *ui;
    QString nombreUsuario;
};





#endif // GUI_H
