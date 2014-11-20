#ifndef THREADTiempoAudio_H
#define THREADTiempoAudio_H

#include <QString>
#include <QObject>
#include <Facade.h>
#include <guiPartida.h>

class threadTiempoAudio : public QObject {
    Q_OBJECT

public:
    threadTiempoAudio(Facade *facade, guiPartida *partida);
    ~threadTiempoAudio();


public slots:
    void process();

signals:
    void finished();
    void reproducirSonido(QString tipo);
    //void error(QString err);


private:
    Facade *_facade;
    guiPartida *_partida;


};

#endif
