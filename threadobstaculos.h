#ifndef THREADOBSTACULOS_H
#define THREADOBSTACULOS_H
#include <QString>
#include <QObject>
#include <Obstaculo.h>

class threadObstaculos : public QObject {
    Q_OBJECT

public:
    threadObstaculos(Obstaculo *obs);
    ~threadObstaculos();


public slots:
    void process();

signals:
    void finished();
    //void error(QString err);


private:
    Obstaculo *_obs;

};

#endif
