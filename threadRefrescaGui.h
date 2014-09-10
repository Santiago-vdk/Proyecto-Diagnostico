#ifndef THREADREFRESCAGUI_H
#define THREADREFRESCAGUI_H

#include <QString>
#include <QObject>
#include <Facade.h>
#include <guiPartida.h>

class threadRefrescaGui : public QObject {
    Q_OBJECT

public:
    threadRefrescaGui(Facade *facade, guiPartida *partida);
    ~threadRefrescaGui();


public slots:
    void process();

signals:
    void finished();
    void refresquemela();
    //void error(QString err);


private:
    Facade *_facade;
    guiPartida *_partida;


};

#endif
