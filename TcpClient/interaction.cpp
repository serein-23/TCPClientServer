#include "interaction.h"
#include "ui_interaction.h"

Interaction::Interaction(QTcpSocket *sock,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Interaction)
{
    ui->setupUi(this);
    socket=sock;
}

Interaction::~Interaction()
{
    delete ui;
}

void Interaction::on_Clear_clicked()
{
    ui->lineEdit->clear();
}

void Interaction::on_Send_clicked()
{
    QString information = ui->lineEdit->text();
    socket->write(information.toLatin1());
}
