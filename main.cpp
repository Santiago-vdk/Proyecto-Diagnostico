#include <QApplication>
#include <gui.h>
#include <QSound>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSound sound(":/recursos/ACDCHighwayToHell.wav");
    sound.setLoops(-1); // will loops forever
    sound.play();
    gui w;
    w.show();
    return a.exec();
}
