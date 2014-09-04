#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <QString>

class Thread : public QThread
{
    Q_OBJECT

public:
    Thread();

    void setMessage(const QString &message);
    void stop();
    void run();

protected:


private:
    QString messageStr;
    volatile bool stopped;

};

#endif // THREAD_H
