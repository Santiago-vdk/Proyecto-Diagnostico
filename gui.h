#ifndef GUI_H
#define GUI_H
#include <QMainWindow>
#include <QLabel>


namespace Ui {
class gui;
}

class gui : public QMainWindow
{
    Q_OBJECT

public:
    explicit gui(QWidget *parent = 0);
    ~gui();

private:
    Ui::gui *ui;
};


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















#endif // GUI_H
