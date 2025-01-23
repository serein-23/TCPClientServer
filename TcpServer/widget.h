#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <thread.h>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>

#define PORT 8000

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void newClientHandler();
    //void clientsendinfo();
    void ThreadReceive(QString s);

    void on_Start_clicked();

    void on_Stop_clicked();

    void logMessage(const QString &message);

private:
    Ui::Widget *ui;
    QTcpServer *Server;

    QFile logFile;  // 日志文件
    QTextStream logStream;  // 日志流
};

#endif // WIDGET_H
