#include "guiPartida.h"
#include "ui_guiPartida.h"

guiPartida::guiPartida(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::guiPartida)
{
    ui->setupUi(this);
}

guiPartida::~guiPartida()
{
    delete ui;
}
