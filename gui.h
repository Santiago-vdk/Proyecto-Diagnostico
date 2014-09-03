#ifndef GUI_H
#define GUI_H
#include <QMainWindow>
#include <QLabel>
#include <loading.h>


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

private:
    Ui::gui *ui;
};



#endif // GUI_H
