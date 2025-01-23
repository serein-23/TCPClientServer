#ifndef INTERACTION_H
#define INTERACTION_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class Interaction;
}

class Interaction : public QWidget
{
    Q_OBJECT

public:
    explicit Interaction(QTcpSocket *sock,QWidget *parent = nullptr);
    ~Interaction();

private slots:
    void on_Clear_clicked();

    void on_Send_clicked();

private:
    Ui::Interaction *ui;
    QTcpSocket *socket;
};

#endif // INTERACTION_H
