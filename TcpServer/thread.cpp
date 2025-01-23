#include "thread.h"

Thread::Thread(QTcpSocket *s, QObject *parent) : QObject(parent)
{
    socket=s;
}

void Thread::run()
{
    connect(socket,&QTcpSocket::readyRead,this,&Thread::clientsendinfo);
}

void Thread::clientsendinfo()
{
    QString info = QString(socket->readAll());
    //发送信号
    emit sendsignal(info);
}
