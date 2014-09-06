#ifndef MYLABEL_H
#define MYLABEL_H
#include <QLabel>
#include <QMouseEvent>
#include <gui.h>
#include <QWidget>
#include <QString>



class myLabel : public QLabel
{
    Q_OBJECT
public:

    myLabel( const QString & text, QWidget * parent = 0 );
    ~myLabel(){}

signals:
    void clicked();

public slots:
    void slotClicked();


protected:
    void mousePressEvent ( QMouseEvent * event ) ;

};
#endif

