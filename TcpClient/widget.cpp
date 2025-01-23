#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket = new QTcpSocket;
    setWindowTitle("客户端");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Cancel_clicked()
{
    this->close();
}

void Widget::on_Connect_clicked()
{
    //获取ip地址和端口号
    QString ip = ui->PlineEdit->text();
    QString portStr = ui->PortlineEdit->text();

    // 将端口号字符串转换为无符号短整型
    quint16 port = portStr.toUShort();

    // 检查 IP 地址和端口号是否有效
    if (ip.isEmpty() || port == 0)
    {
        QMessageBox::warning(this, tr("警告"), tr("IP 地址或端口号无效！"));
        return;
    }
    //连接服务器
    socket->connectToHost(QHostAddress(ip), port);
    connect(socket, &QTcpSocket::connected, this, &Widget::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &Widget::onSocketError);

}

void Widget::onConnected()
{
    QMessageBox::information(this, tr("连接成功"), tr("已成功连接到服务器！"));
    //this->hide();
    Interaction *info = new Interaction(socket);

    info->show();
}

void Widget::onSocketError()
{
    QMessageBox::warning(this, tr("连接失败"), tr("无法连接到服务器：") + socket->errorString());
}
