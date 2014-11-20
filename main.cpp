#include <QApplication>
#include <gui.h>
#include <QDebug>
#include <QSound>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gui w;
    w.show();
    //    QFileInfo checkFile(":/recursos/test.wav");
    //      // check if file exists and if yes: Is it really a file and no directory?
    //      if (checkFile.exists() && checkFile.isFile()) {
    //          qDebug()<< true;
    //      } else {
    //          qDebug()<< false;
    //      }
    //    QSound sound(":/recursos/test.wav");
    //       sound.play();
    return a.exec();
}

