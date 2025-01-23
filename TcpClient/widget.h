#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <interaction.h>
#include <QProcess>
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
    void on_Cancel_clicked();

    void on_Connect_clicked();
    void onConnected();  // 处理连接成功
    void onSocketError();

private:
    Ui::Widget *ui;
    QTcpSocket *socket;

};

#endif // WIDGET_H
