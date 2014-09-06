#ifndef THREAD_H
#define THREAD_H

#include <QString>
#include <QObject>

class miThread : public QObject {
    Q_OBJECT

public:
    miThread();
    ~miThread();


public slots:
    void process();

signals:
    void finished();
    //void error(QString err);


private:
    int vida;

};












#endif // THREAD_H
