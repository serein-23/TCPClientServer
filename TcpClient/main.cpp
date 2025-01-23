#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //自动适应高分辨率
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
