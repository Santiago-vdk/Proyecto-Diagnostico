#include "loading.h"
#include "ui_loading.h"
#include <QLabel>
#include <QMovie>

loading::loading(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loading)
{
    ui->setupUi(this);


    this->setFixedSize(800,600);
    this->setStyleSheet("background-color: black;");

//    QPixmap bkgnd(":/recursos/bg2.png");
//    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
//    QPalette palette;
//    palette.setBrush(QPalette::Background, bkgnd);
//    this->setPalette(palette);



    QMovie *movie = new QMovie(":/recursos/loading.gif");
    QLabel *loading = new QLabel("Test",this);
    loading->setMovie(movie);
    movie->start();
    loading->setGeometry(QRect(250, 50, 500, 350));


}

loading::~loading()
{
    delete ui;
}
