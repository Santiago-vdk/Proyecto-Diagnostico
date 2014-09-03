#include "myLabel.h"
#include <QDebug>
#include <gui.h>
#include "MainWindow.h"



myLabel::myLabel( const QString & text, QWidget * parent )
:QLabel(parent)
{
    connect( this, SIGNAL( clicked() ), this, SLOT( slotClicked() ) );


}

void myLabel::slotClicked()
{
    qDebug()<<"Clicked";
}





void myLabel::mousePressEvent ( QMouseEvent * event )
{
    emit clicked();
}
