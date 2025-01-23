#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class Thread : public QObject
{
    Q_OBJECT
public:
    explicit Thread(QTcpSocket *s,QObject *parent = nullptr);
    void run();

signals:
    void sendsignal(QString mm);

private:
    QTcpSocket *socket;

public slots:
    void clientsendinfo();
};

#endif // THREAD_H
