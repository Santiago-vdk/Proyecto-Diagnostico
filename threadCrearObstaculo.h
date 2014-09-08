#ifndef THREADCREAROBSTACULO_H
#define THREADCREAROBSTACULO_H
#include <QString>
#include <QObject>

class threadCrearObstaculos : public QObject {
    Q_OBJECT

public:
    threadCrearObstaculos();
    ~threadCrearObstaculos();


public slots:
    void process();

signals:
    void finished();
    //void error(QString err);


private:

};
#endif // THREADCREAROBSTACULO_H
