#ifndef RECEIVE_H
#define RECEIVE_H

#include <QWidget>

namespace Ui {
class Receive;
}

class Receive : public QWidget
{
    Q_OBJECT

public:
    explicit Receive(QWidget *parent = nullptr);
    ~Receive();

private:
    Ui::Receive *ui;
};

#endif // RECEIVE_H
