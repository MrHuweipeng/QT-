#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("贪吃蛇大战");
    w.setWindowIcon(QIcon(":/Image/R-C.jpg"));//设置应用图标
    w.show();
    return a.exec();
}
