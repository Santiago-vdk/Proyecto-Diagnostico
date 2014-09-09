#ifndef THREADOBSTACULOS_H
#define THREADOBSTACULOS_H
#include <QString>
#include <QObject>

class threadObstaculos : public QObject {
    Q_OBJECT

public:
    threadObstaculos();
    ~threadObstaculos();


public slots:
    void process();

signals:
    void finished();
    //void error(QString err);


private:

};

#endif
