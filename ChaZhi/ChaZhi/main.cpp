#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


//    // 定义数据点
//    QVector<QPointF> points = {
//        {1, 70},
//        {2, 122},
//        {3, 144},
//        {4, 152},
//        {5, 174},
//        {6, 196},
//        {7, 202}
//    };

//    // 执行一次拟合
//    float aa, bb;
//    CSZJS linearFitting;
//    linearFitting.FitFirstOrderCurve(aa, bb);
//    qDebug() << "一次拟合: aa =" << aa << ", bb =" << bb;

//    // 执行二次拟合
//    float c;
//    CSZJS quadraticFitting;
//    quadraticFitting.FitQuadraticCurves(aa, bb, c);
//    qDebug() << "二次拟合: aa =" << aa << ", bb =" << bb << ", c =" << c;

//    // 执行三次拟合
//    float d;
//    CSZJS cubicFitting;
//    cubicFitting.FitCubicCurve(aa, bb, c, d);
//    qDebug() << "三次拟合: aa =" << aa << ", bb =" << bb << ", c =" << c << ", d =" << d;



    w.show();
    return a.exec();
}
