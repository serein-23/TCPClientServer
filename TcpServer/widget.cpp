#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("服务器");
    Server = new QTcpServer;

    // 初始化日志文件
    logFile.setFileName("server.log");  // 日志文件名
    if (logFile.open(QIODevice::Append | QIODevice::Text)) {
        logStream.setDevice(&logFile);
         qDebug() << "日志文件路径：" << logFile.fileName();
    } else {
        QMessageBox::critical(this, "错误", "无法打开日志文件");
    }

    //监听
    //Server->listen(QHostAddress::AnyIPv4,PORT);

    //客户端发起连接，Server发出信号
    //connect(Server,&QTcpServer::newConnection,this,&Widget::newClientHandler);

    ui->Stop->setEnabled(false);

    connect(ui->Start, &QPushButton::clicked, this, &Widget::on_Start_clicked);
    connect(ui->Stop, &QPushButton::clicked, this, &Widget::on_Stop_clicked);

    connect(Server, &QTcpServer::newConnection, this, &Widget::newClientHandler);
}

Widget::~Widget()
{
    if (logFile.isOpen()) {
        logFile.close();  // 关闭日志文件
    }
    delete ui;
}

void Widget::logMessage(const QString &message)
{
    if (logStream.device()) {
        QString logEntry = QString("%1 - %2\n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"), message);
        logStream << logEntry;
        logStream.flush();
    }
}

void Widget::on_Start_clicked()
{
    if (!Server->isListening())//服务器还未监听
    {
        if (Server->listen(QHostAddress::AnyIPv4, PORT))
        {
            ui->Start->setText("已启动");
            ui->Start->setEnabled(false);//禁用启动按钮
            ui->Stop->setEnabled(true);//启用终止按钮

            logMessage("服务器已启动，监听端口：" + QString::number(PORT));

        }
        else
        {
            QMessageBox::critical(this, "错误", "无法启动服务器：" + Server->errorString());
            logMessage("服务器启动失败：" + Server->errorString());
        }
    }
}

void Widget::newClientHandler()
{
    //建立TCP连接
    QTcpSocket *Socket = Server->nextPendingConnection();

//    Socket->peerAddress();
//    Socket->peerPort();

    ui->PlineEdit->setText(Socket->peerAddress().toString());
    ui->PortlineEdit->setText(QString::number(Socket->peerPort()));

    //connect(Socket,&QTcpSocket::readyRead,this,&Widget::clientsendinfo);

    logMessage("客户端已连接：" + Socket->peerAddress().toString() + ":" + QString::number(Socket->peerPort()));

    Thread *thread = new Thread(Socket);
    thread->run();
    connect(thread,&Thread::sendsignal,this,&Widget::ThreadReceive);
}

void Widget::ThreadReceive(QString s)
{
    ui->textEdit->setText(s);
     logMessage("收到客户端消息：" + s);
}

void Widget::on_Stop_clicked()
{
    if (Server->isListening())  // 检查服务器是否正在监听
        {
            // 关闭服务器监听
            Server->close();

            // 更新按钮状态
            ui->Start->setText("启动");
            ui->Start->setEnabled(true);  // 重新启用启动按钮
            ui->Stop->setEnabled(false);  // 禁用终止按钮
            logMessage("服务器已停止监听");

            QMessageBox::information(this, "服务器已停止", "服务器已成功停止监听");
        }
}
