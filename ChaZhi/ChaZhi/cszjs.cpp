#include "cszjs.h"
#include <QDebug>
#include <iostream>
#include <vector>

CSZJS::CSZJS()
{
    m_painter = new QPainter();

    m_xYD = 100;
    m_yYD = 900;
    m_kx = 50;
    m_ky = -2;

    m_scaleX = 10;
    m_scaleY = 300;

    m_points651.push_back(QPointF(1, 70));
    m_points651.push_back(QPointF(2, 122));
    m_points651.push_back(QPointF(3, 144));
    m_points651.push_back(QPointF(4, 152));
    m_points651.push_back(QPointF(5, 174));
    m_points651.push_back(QPointF(6, 196));
    m_points651.push_back(QPointF(7, 202));



    this->initSeries();
    this->InitDataOfNumericalIntegration();
    this->CountOfNumericalIntegration();

    this->CountAllRobot();

    this->initDataOfRungeKutta();
    this->countAllRungeKutta();
}

void CSZJS::PrintData()
{
    for (int i = 0; i < m_dataX1.size(); i++) {
        qDebug() << m_dataX1.at(i);
        qDebug() << m_dataY1.at(i);
        qDebug() <<"";
    }

    qDebug() << "-----------------------";

    for (int i = 0; i < m_dataX2.size(); i++) {
        qDebug() << m_dataX2.at(i);
        qDebug() << m_dataY2.at(i);
        qDebug() <<"";
    }

    qDebug() << "-----------------------";

    for (int i = 0; i < m_dataX3.size(); i++) {
        qDebug() << m_dataX3.at(i);
        qDebug() << m_dataY3.at(i);
        qDebug() <<"";
    }
}

void CSZJS::initSeries()
{
    m_series1 = new QSplineSeries();
    m_series2 = new QSplineSeries();
    m_series3 = new QSplineSeries();
    m_series1->setName("一次曲线");
    m_series2->setName("二次曲线");
    m_series3->setName("三次曲线");

    m_serInitData651 = new QScatterSeries();
    m_serInitData651->setName("原始数据");
    m_serInitData651->setMarkerShape(QScatterSeries::MarkerShapeCircle);  // 设置绘制的散点的样式为圆
    m_serInitData651->setMarkerSize(20);                                  // 设置绘制的点的大小

    m_seriesOne651 = new QSplineSeries();
    m_seriesTwo651 = new QSplineSeries();
    m_seriesThree651 = new QSplineSeries();
    m_seriesFour651 = new QSplineSeries();
    m_seriesFive651 = new QSplineSeries();
    m_seriesOne651->setName("一次曲线");
    m_seriesTwo651->setName("二次曲线");
    m_seriesThree651->setName("三次曲线");
    m_seriesFour651->setName("四次曲线");
    m_seriesFive651->setName("五次曲线");

    m_serRec = new QSplineSeries();
    m_serTra = new QSplineSeries();
    m_serSim = new QSplineSeries();
    m_serNew = new QSplineSeries();
    m_serCot = new QSplineSeries();

    m_serRec->setName("矩形法");
    m_serTra->setName("梯形法");
    m_serSim->setName("辛普森法");
    m_serNew->setName("牛顿法");
    m_serCot->setName("科特法");
}

void CSZJS::CountAll()
{
    m_series1->clear();
    m_series2->clear();
    m_series3->clear();

    this->CountByLagrangeFirstOrderCurve();
    this->CountByLagrangeQuadraticCurve();
    this->CountByLagrangeCubicCurve();

    m_seriesOne651->clear();
    m_seriesTwo651->clear();
    m_seriesThree651->clear();
    m_seriesFour651->clear();
    m_seriesFive651->clear();
    m_serInitData651->clear();

    this->SetInitData651();
    this->FitFirstOrderCurve();
    this->FitQuadraticCurves();
    this->FitCubicCurve();
    this->FitQuinticCurve();
    this->FitHexagonalCurve();
}

void CSZJS::SetInitData651()
{
    m_serInitData651->append(QPointF(1, 70));
    m_serInitData651->append(QPointF(2, 122));
    m_serInitData651->append(QPointF(3, 144));
    m_serInitData651->append(QPointF(4, 152));
    m_serInitData651->append(QPointF(5, 174));
    m_serInitData651->append(QPointF(6, 196));
    m_serInitData651->append(QPointF(7, 202));
}

void CSZJS::FitFirstOrderCurve()
{
    int n = m_points651.size();
    Eigen::MatrixXd A(n, 2); // 创建 n x 2 的矩阵 A
    Eigen::VectorXd bVec(n); // 创建长度为 n 的向量 b

    for (int i = 0; i < n; ++i) {
        float x = m_points651[i].x();
        float y = m_points651[i].y();
        A(i, 0) = x; // 第 i 行第一列为 x
        A(i, 1) = 1; // 第 i 行第二列为 1
        bVec(i) = y; // 向量 b 的第 i 个元素为 y
    }

    // 解线性方程组 Ax = b，得到拟合参数 x
    Eigen::VectorXd x = A.colPivHouseholderQr().solve(bVec);

    // 保存数据到曲线中
    for (int i = 0; i < m_scaleX; i++) {
        m_seriesOne651->append(QPointF(i, x(0) * i + x(1)));
    }
}

void CSZJS::FitQuadraticCurves()
{
    int n = m_points651.size();
    Eigen::MatrixXd A(n, 3); // 创建 n x 3 的矩阵 A
    Eigen::VectorXd bVec(n); // 创建长度为 n 的向量 b

    for (int i = 0; i < n; ++i) {
        float x = m_points651[i].x();
        float y = m_points651[i].y();
        A(i, 0) = x * x; // 第 i 行第一列为 x^2
        A(i, 1) = x;     // 第 i 行第二列为 x
        A(i, 2) = 1;     // 第 i 行第三列为 1
        bVec(i) = y;     // 向量 b 的第 i 个元素为 y
    }

    // 解线性方程组 Ax = b，得到拟合参数 x
    Eigen::VectorXd x = A.colPivHouseholderQr().solve(bVec);

    // 保存数据到曲线中
    for (int i = 0; i < m_scaleX; i++) {
        m_seriesTwo651->append(QPointF(i, x(0) * i * i + x(1) * i + x(2)));
    }
}

void CSZJS::FitCubicCurve()
{
    int n = m_points651.size();
    Eigen::MatrixXd A(n, 4); // 创建 n x 4 的矩阵 A
    Eigen::VectorXd bVec(n); // 创建长度为 n 的向量 b

    for (int i = 0; i < n; ++i) {
        float x = m_points651[i].x();
        float y = m_points651[i].y();
        A(i, 0) = x * x * x; // 第 i 行第一列为 x^3
        A(i, 1) = x * x;     // 第 i 行第二列为 x^2
        A(i, 2) = x;         // 第 i 行第三列为 x
        A(i, 3) = 1;         // 第 i 行第四列为 1
        bVec(i) = y;         // 向量 b 的第 i 个元素为 y
    }

    // 解线性方程组 Ax = b，得到拟合参数 x
    Eigen::VectorXd x = A.colPivHouseholderQr().solve(bVec);

    for (int i = 0; i < m_scaleX; i++) {
        m_seriesThree651->append(QPointF(i, x(0) * i * i * i + x(1) * i * i + x(2) * i + x(3)));
    }
}

void CSZJS::FitQuinticCurve()
{
    int n = m_points651.size(); // 获取数据点数量
    Eigen::MatrixXd A(n, 5); // 创建 n x 5 的矩阵 A
    Eigen::VectorXd bVec(n); // 创建长度为 n 的向量 b

    // 构建矩阵 A 和向量 b
    for (int i = 0; i < n; ++i) {
        float x = m_points651[i].x();
        float y = m_points651[i].y();
        A(i, 0) = x * x * x * x; // 第 i 行第一列为 x^4
        A(i, 1) = x * x * x;     // 第 i 行第二列为 x^3
        A(i, 2) = x * x;         // 第 i 行第三列为 x^2
        A(i, 3) = x;             // 第 i 行第四列为 x
        A(i, 4) = 1;             // 第 i 行第五列为 1
        bVec(i) = y;             // 向量 b 的第 i 个元素为 y
    }

    // 解线性方程组 Ax = b，得到拟合参数 x
    Eigen::VectorXd x = A.colPivHouseholderQr().solve(bVec);

    for (int i = 0; i < m_scaleX; i++) {
        m_seriesFour651->append(QPointF(i, x(0) * i * i * i * i + x(1) * i * i * i + x(2) * i * i + x(3) * i + x(4)));
    }
}

void CSZJS::FitHexagonalCurve()
{
    int n = m_points651.size(); // 获取数据点数量
    Eigen::MatrixXd A(n, 6); // 创建 n x 6 的矩阵 A
    Eigen::VectorXd bVec(n); // 创建长度为 n 的向量 b

    // 构建矩阵 A 和向量 b
    for (int i = 0; i < n; ++i) {
        float x = m_points651[i].x();
        float y = m_points651[i].y();
        A(i, 0) = x * x * x * x * x; // 第 i 行第一列为 x^5
        A(i, 1) = x * x * x * x;     // 第 i 行第二列为 x^4
        A(i, 2) = x * x * x;         // 第 i 行第三列为 x^3
        A(i, 3) = x * x;             // 第 i 行第四列为 x^2
        A(i, 4) = x;                 // 第 i 行第五列为 x
        A(i, 5) = 1;                 // 第 i 行第六列为 1
        bVec(i) = y;                 // 向量 b 的第 i 个元素为 y
    }

    // 解线性方程组 Ax = b，得到拟合参数 x
    Eigen::VectorXd x = A.colPivHouseholderQr().solve(bVec);

    for (int i = 0; i < m_scaleX; i++) {
        m_seriesFive651->append(QPointF(i, x(0) * i * i * i * i * i + x(1) * i * i * i * i + x(2) * i * i * i + x(3) * i * i + x(4) * i + x(5)));
    }

}

// 一次曲线  y=x
void CSZJS::CountByLagrangeFirstOrderCurve()
{
    m_dataX1.clear();
    m_dataY1.clear();

    // 数据准备
    m_dataX1.push_back(m_dataKnown1[0].x());
    m_dataY1.push_back(m_dataKnown1[0].y());
    m_dataX1.push_back(m_dataKnown1[1].x());
    m_dataY1.push_back(m_dataKnown1[1].y());

    m_series1->append(QPointF(m_dataKnown1[0].x(), m_dataKnown1[0].y()));
    m_series1->append(QPointF(m_dataKnown1[1].x(), m_dataKnown1[1].y()));

    // 插值到10
    for (int i = 0; i <= 10 - 2; i++) {
        float x = i + 2;
        float y = (x - m_dataX1.at(1)) / (m_dataX1.at(0) - m_dataX1.at(1)) * m_dataY1.at(0)
                  + (x - m_dataX1.at(0)) / (m_dataX1.at(1) - m_dataX1.at(0)) * m_dataY1.at(1);
        m_dataX1.push_back(x);
        m_dataY1.push_back(y);

        m_series1->append(QPointF(x, y));
    }
}

// 二次曲线  y=x^2
void CSZJS::CountByLagrangeQuadraticCurve()
{
    m_dataX2.clear();
    m_dataY2.clear();

    // 数据准备
    m_dataX2.push_back(m_dataKnown2[0].x());
    m_dataY2.push_back(m_dataKnown2[0].y());
    m_dataX2.push_back(m_dataKnown2[1].x());
    m_dataY2.push_back(m_dataKnown2[1].y());
    m_dataX2.push_back(m_dataKnown2[2].x());
    m_dataY2.push_back(m_dataKnown2[2].y());

    m_series2->append(QPointF(m_dataKnown2[0].x(), m_dataKnown2[0].y()));
    m_series2->append(QPointF(m_dataKnown2[1].x(), m_dataKnown2[1].y()));
    m_series2->append(QPointF(m_dataKnown2[2].x(), m_dataKnown2[2].y()));

    // 插值到10
    for (int i = 0; i <= 10 - 3; i++) {
        float x = i + 3;
        float y = (x - m_dataX2.at(1)) * (x - m_dataX2.at(2))
                      / (m_dataX2.at(0) - m_dataX2.at(1)) / (m_dataX2.at(0) - m_dataX2.at(2)) * m_dataY2.at(0)
                  + (x - m_dataX2.at(0)) * (x - m_dataX2.at(2))
                        / (m_dataX2.at(1) - m_dataX2.at(0)) / (m_dataX2.at(1) - m_dataX2.at(2)) * m_dataY2.at(1)
                  + (x - m_dataX2.at(0)) * (x - m_dataX2.at(1))
                        / (m_dataX2.at(2) - m_dataX2.at(0)) / (m_dataX2.at(2) - m_dataX2.at(1)) * m_dataY2.at(2);
        m_dataX2.push_back(x);
        m_dataY2.push_back(y);

        m_series2->append(QPointF(x, y));
    }

    m_result221 = (2.8 - m_dataX2.at(1)) * (2.8 - m_dataX2.at(2))
                      / (m_dataX2.at(0) - m_dataX2.at(1)) / (m_dataX2.at(0) - m_dataX2.at(2)) * m_dataY2.at(0)
                  + (2.8 - m_dataX2.at(0)) * (2.8 - m_dataX2.at(2))
                        / (m_dataX2.at(1) - m_dataX2.at(0)) / (m_dataX2.at(1) - m_dataX2.at(2)) * m_dataY2.at(1)
                  + (2.8 - m_dataX2.at(0)) * (2.8 - m_dataX2.at(1))
                        / (m_dataX2.at(2) - m_dataX2.at(0)) / (m_dataX2.at(2) - m_dataX2.at(1)) * m_dataY2.at(2);
}

// 三次曲线  y=x^3
void CSZJS::CountByLagrangeCubicCurve()
{
    m_dataX3.clear();
    m_dataY3.clear();

    // 数据准备
    m_dataX3.push_back(m_dataKnown3[0].x());
    m_dataY3.push_back(m_dataKnown3[0].y());
    m_dataX3.push_back(m_dataKnown3[1].x());
    m_dataY3.push_back(m_dataKnown3[1].y());
    m_dataX3.push_back(m_dataKnown3[2].x());
    m_dataY3.push_back(m_dataKnown3[2].y());
    m_dataX3.push_back(m_dataKnown3[3].x());
    m_dataY3.push_back(m_dataKnown3[3].y());

    m_series3->append(QPointF(m_dataKnown3[0].x(), m_dataKnown3[0].y()));
    m_series3->append(QPointF(m_dataKnown3[1].x(), m_dataKnown3[1].y()));
    m_series3->append(QPointF(m_dataKnown3[2].x(), m_dataKnown3[2].y()));
    m_series3->append(QPointF(m_dataKnown3[3].x(), m_dataKnown3[3].y()));


    // 插值到10
    for (int i = 0; i <= 10 - 4; i++) {
        float x = i + 3;
        float y = (x - m_dataX3.at(1)) * (x - m_dataX3.at(2)) * (x - m_dataX3.at(3))
                        / (m_dataX3.at(0) - m_dataX3.at(1)) / (m_dataX3.at(0) - m_dataX3.at(2)) / (m_dataX3.at(0) - m_dataX3.at(3))
                        * m_dataY3.at(0)
                  + (x - m_dataX3.at(0)) * (x - m_dataX3.at(2)) * (x - m_dataX3.at(3))
                        / (m_dataX3.at(1) - m_dataX3.at(0)) / (m_dataX3.at(1) - m_dataX3.at(2)) / (m_dataX3.at(1) - m_dataX3.at(3))
                        * m_dataY3.at(1)
                  + (x - m_dataX3.at(0)) * (x - m_dataX3.at(1)) * (x - m_dataX3.at(3))
                        / (m_dataX3.at(2) - m_dataX3.at(0)) / (m_dataX3.at(2) - m_dataX3.at(1)) / (m_dataX3.at(2) - m_dataX3.at(3))
                        * m_dataY3.at(2)
                  + (x - m_dataX3.at(0)) * (x - m_dataX3.at(1)) * (x - m_dataX3.at(2))
                        / (m_dataX3.at(3) - m_dataX3.at(0)) / (m_dataX3.at(3) - m_dataX3.at(1)) / (m_dataX3.at(3) - m_dataX3.at(2))
                        * m_dataY3.at(3);;
        m_dataX3.push_back(x);
        m_dataY3.push_back(y);

        m_series3->append(QPointF(x, y));
    }
}

void CSZJS::Draw(QPainter * painter)
{
    m_painter = painter;

    DrawAxis();
    DrawCurve();

    DrawPoint();
}

void CSZJS::DrawAxis()
{
    int i, x1, y1, x2, y2;
    QString str;

    m_painter->drawLine(m_xYD, m_yYD, m_xYD + m_scaleX * m_kx, m_yYD); // X轴
    m_painter->drawLine(m_xYD, m_yYD, m_xYD, m_yYD + m_scaleY * m_ky); // Y轴

    // Y轴刻度
    for (i = 1; i <= m_scaleY; i++)
    {
        x1 = m_xYD;
        y1 = m_yYD + i * m_ky;
        x2 = x1 + 10;
        y2 = y1;
        m_painter->drawLine(x1, y1, x2, y2);

        x1 = m_xYD - 25;
        y1 += m_ky;

        if (i % 20 == 0)
        {
            str = QString::number(i);
            m_painter->drawText(x1, y1, str);
        }
    }
    // X轴刻度
    for (i = 1; i <= m_scaleX; i++)
    {
        x1 = m_xYD + i *  m_kx;
        y1 = m_yYD;
        x2 = x1;
        y2 = y1 - 10;
        m_painter->drawLine(x1, y1, x2, y2);
        str = QString::number(i);
        x2 -= 3;
        y2 += 25;
        m_painter->drawText(x2, y2, str);
    }
}

void CSZJS::DrawCurve()
{
//    for (int i = 0; i < m_dataY1.size() - 1; i++)
//    {
//        m_painter->drawLine(m_xYD + m_dataX1.at(i) * m_kx, m_yYD + m_dataY1.at(i) * m_ky,
//                            m_xYD + m_dataX1.at(i + 1) * m_kx, m_yYD + m_dataY1.at(i + 1) * m_ky);
//    }

//    for (int i = 0; i < m_dataY2.size() - 1; i++)
//    {
//        m_painter->drawLine(m_xYD + m_dataX2.at(i) * m_kx, m_yYD + m_dataY2.at(i) * m_ky,
//                            m_xYD + m_dataX2.at(i + 1) * m_kx, m_yYD + m_dataY2.at(i + 1) * m_ky);
//    }

//    for (int i = 0; i < m_dataY3.size() - 1; i++)
//    {
//        m_painter->drawLine(m_xYD + m_dataX3.at(i) * m_kx, m_yYD + m_dataY3.at(i) * m_ky,
//                            m_xYD + m_dataX3.at(i + 1) * m_kx, m_yYD + m_dataY3.at(i + 1) * m_ky);
//    }

//    for (int i = 0; i < m_line651X.size() - 1; i++)
//    {
//        m_painter->drawLine(m_xYD + m_line651X.at(i) * m_kx, m_yYD + m_line651Y.at(i) * m_ky,
//                            m_xYD + m_line651X.at(i + 1) * m_kx, m_yYD + m_line651Y.at(i + 1) * m_ky);
//    }
}

void CSZJS::DrawPoint()
{
    for (int i = 0; i < m_points651.size(); i++) {
        m_painter->drawEllipse(QPoint(m_xYD + m_points651.at(i).x() * m_kx, m_yYD + m_points651.at(i).y() * m_ky),
                               2, 2);
    }


}

float CSZJS::getFunctionResultOfNumericalIntegration(float x)
{
    return x * x + 3;
}

void CSZJS::InitDataOfNumericalIntegration()
{
    for (int i = 0; i <= 10; i++) {
        m_points712.push_back(QPointF(i, getFunctionResultOfNumericalIntegration(i)));
    }
}

void CSZJS::CountOfNumericalIntegration()
{
    MiddleRectangleMethod();
    TrapezoidalMethod();
    SimpsonMethod();
    NewtonMethod();
    CotesMethod();

//    qDebug() << m_resultRec;
//    qDebug() << m_resultTra;
//    qDebug() << m_resultSim;
//    qDebug() << m_resultNew;
//    qDebug() << m_resultCot;
}

void CSZJS::MiddleRectangleMethod()
{
    m_resultRec = 0;

    for (int i = 0; i < m_points712.size() - 1; i++) {
        float res = (m_points712.at(i + 1).x() - m_points712.at(i).x()) * getFunctionResultOfNumericalIntegration((i + i + 1) / 2);
        m_resultRec += res;
    }
}

void CSZJS::TrapezoidalMethod()
{
    m_resultTra = 0;

    for (int i = 0; i < m_points712.size() - 1; i++) {
        float res = (m_points712.at(i).y() + m_points712.at(i + 1).y()) / 2 * (i + 1 - i);
        m_resultTra += res;
    }
}

void CSZJS::SimpsonMethod()
{
    m_resultSim = 0;

    for (int i = 0; i < m_points712.size() - 1; i++) {
        float res = (i + 1 - i) / 6.0 * (m_points712.at(i).y() + m_points712.at(i + 1).y() + 4 * getFunctionResultOfNumericalIntegration((i + i + 1) / 2.0));
        m_resultSim += res;
    }
}

void CSZJS::NewtonMethod()
{
    m_resultNew = 0;

    for (int i = 0; i < m_points712.size() - 1; i++) {
        float res = (i + 1 - i) / 8.0 * (m_points712.at(i).y() + 3 * getFunctionResultOfNumericalIntegration(i + 1 / 3.0) + 3 * getFunctionResultOfNumericalIntegration(i + 2 / 3.0) + m_points712.at(i + 1).y());
        m_resultNew += res;
    }
}

void CSZJS::CotesMethod()
{
    m_resultCot = 0;

    for (int i = 0; i < m_points712.size() - 1; i++) {
        float res = (i + 1 - i) / 90.0 * (7 * m_points712.at(i).y() + 32 * getFunctionResultOfNumericalIntegration(i + 1 / 4.0) + 12 * getFunctionResultOfNumericalIntegration(i + 2 / 4.0) + 32 * getFunctionResultOfNumericalIntegration(i + 3 / 4.0) + 7 * m_points712.at(i + 1).y());
        m_resultCot += res;
    }
}

void CSZJS::CountAllRobot()
{
    // 初始化
    m_potsRobVel.push_back(QPointF(0, 0));
    m_potsRobVel.push_back(QPointF(1, 3));
    m_potsRobVel.push_back(QPointF(2, 5));
    m_potsRobVel.push_back(QPointF(3, 6));
    m_potsRobVel.push_back(QPointF(4, 4));
    m_potsRobVel.push_back(QPointF(5, 2));
    m_potsRobVel.push_back(QPointF(6, 0));
    m_potsRobVel.push_back(QPointF(7, -2));
    m_potsRobVel.push_back(QPointF(8, -4));
    m_potsRobVel.push_back(QPointF(9, -6));
    m_potsRobVel.push_back(QPointF(10, -8));

    // 拟合
    FitRobotCurves();

    // 计算
    this->CountRobotRec();
    this->CountRobotTra();
    this->CountRobotSim();
    this->CountRobotNew();
    this->CountRobotCot();
}

void CSZJS::FitRobotCurves()
{
    int n = m_potsRobVel.size();
    Eigen::MatrixXd A(n, 3); // 创建 n x 3 的矩阵 A
    Eigen::VectorXd bVec(n); // 创建长度为 n 的向量 b

    for (int i = 0; i < n; ++i) {
        float x = m_potsRobVel[i].x();
        float y = m_potsRobVel[i].y();
        A(i, 0) = x * x; // 第 i 行第一列为 x^2
        A(i, 1) = x;     // 第 i 行第二列为 x
        A(i, 2) = 1;     // 第 i 行第三列为 1
        bVec(i) = y;     // 向量 b 的第 i 个元素为 y
    }

    // 解线性方程组 Ax = b，得到拟合参数 x
    Eigen::VectorXd x = A.colPivHouseholderQr().solve(bVec);

    // 保存系数
    m_coefficient[0] = x(0);
    m_coefficient[1] = x(1);
    m_coefficient[2] = x(2);
}

float CSZJS::getResultOfRobotVelocity(float t)
{
    return m_coefficient[0] * t * t + m_coefficient[1] * t + m_coefficient[2];
}

void CSZJS::CountRobotRec()
{
    float res = 0;
    m_transRec.push_back(res);
    m_serRec->append(QPointF(0, res));

    for (int i = 0; i < m_potsRobVel.size() - 1; i++) {
        float a = m_potsRobVel.at(i).x();
        float b = m_potsRobVel.at(i + 1).x();
        float fab2 = getResultOfRobotVelocity((a + b) / 2.0);

        res += (b - a) * fab2;
        m_transRec.push_back(res);

        m_serRec->append(QPointF(i + 1, res));
    }
}

void CSZJS::CountRobotTra()
{
    float res = 0;
    m_transTra.push_back(res);
    m_serTra->append(QPointF(0, res));

    for (int i = 0; i < m_potsRobVel.size() - 1; i++) {
        float a = m_potsRobVel.at(i).x();
        float b = m_potsRobVel.at(i + 1).x();
        float fa = m_potsRobVel.at(i).y();
        float fb = m_potsRobVel.at(i + 1).y();

        res += (fa + fb) / 2.0 * (b - a);
        m_transTra.push_back(res);

        m_serTra->append(QPointF(i + 1, res));
    }
}

void CSZJS::CountRobotSim()
{
    float res = 0;
    m_transSim.push_back(res);
    m_serSim->append(QPointF(0, res));

    for (int i = 0; i < m_potsRobVel.size() - 1; i++) {
        float a = m_potsRobVel.at(i).x();
        float b = m_potsRobVel.at(i + 1).x();
        float fa = m_potsRobVel.at(i).y();
        float fb = m_potsRobVel.at(i + 1).y();
        float fab2 = getResultOfRobotVelocity((a + b) / 2.0);

        res += (b - a) / 6.0 * (fa + 4 * fab2 + fb);
        m_transSim.push_back(res);

        m_serSim->append(QPointF(i + 1, res));
    }
}

void CSZJS::CountRobotNew()
{
    float res = 0;
    m_transNew.push_back(res);
    m_serNew->append(QPointF(0, res));

    for (int i = 0; i < m_potsRobVel.size() - 1; i++) {
        float a = m_potsRobVel.at(i).x();
        float b = m_potsRobVel.at(i + 1).x();
        float fx0 = m_potsRobVel.at(i).y();
        float fx1 = getResultOfRobotVelocity(a + (b - a) / 3.0);
        float fx2 = getResultOfRobotVelocity(a + 2 * (b - a) / 3.0);
        float fx3 = m_potsRobVel.at(i + 1).y();

        res += (b - a) / 8.0 * (fx0 + 3 * fx1 + 3 * fx2 + fx3);
        m_transNew.push_back(res);

        m_serNew->append(QPointF(i + 1, res));
    }
}

void CSZJS::CountRobotCot()
{
    float res = 0;
    m_transCot.push_back(res);
    m_serCot->append(QPointF(0, res));

    for (int i = 0; i < m_potsRobVel.size() - 1; i++) {
        float a = m_potsRobVel.at(i).x();
        float b = m_potsRobVel.at(i + 1).x();
        float fx0 = m_potsRobVel.at(i).y();
        float fx1 = getResultOfRobotVelocity(a + (b - a) / 4.0);
        float fx2 = getResultOfRobotVelocity(a + 2 * (b - a) / 4.0);
        float fx3 = getResultOfRobotVelocity(a + 3 * (b - a) / 4.0);
        float fx4 = m_potsRobVel.at(i + 1).y();

        res += (b - a) / 90.0 * (7 * fx0 + 32 * fx1 + 12 * fx2 + 32 * fx3 + 7 * fx4);
        m_transCot.push_back(res);

        m_serCot->append(QPointF(i + 1, res));
    }
}

float CSZJS::fx(float x)
{
    return x;
}

float CSZJS::fy(float y)
{
    return y;
}

float CSZJS::fvx(float vx)
{
    return vx;
}

float CSZJS::fvy(float vy)
{
    return vy;
}

void CSZJS::initDataOfRungeKutta()
{
    m_rungKutta.h = 0.1;

    m_rungKutta.x = 0;
    m_rungKutta.y = 0.2;
    m_rungKutta.vx = 5.0;
    m_rungKutta.vy = 2.0;
    m_rungKutta.ax = 0;
    m_rungKutta.ay = 9.8;

    m_rungKutta.xGJ.push_back(m_rungKutta.x);
    m_rungKutta.yGJ.push_back(m_rungKutta.y);
    m_rungKutta.vxGJ.push_back(m_rungKutta.vx);
    m_rungKutta.vyGJ.push_back(m_rungKutta.vy);

    m_serRKX = new QSplineSeries();
    m_serRKY = new QSplineSeries();
    m_serRKVx = new QSplineSeries();
    m_serRKVy = new QSplineSeries();
    m_serRKX->setName("x方向位移变化轨迹");
    m_serRKY->setName("y方向位移变化轨迹");
    m_serRKVx->setName("x方向速度变化轨迹");
    m_serRKVy->setName("y方向速度变化轨迹");

    m_serRKX->append(QPointF(0, m_rungKutta.x));
    m_serRKY->append(QPointF(0, m_rungKutta.y));
    m_serRKVx->append(QPointF(0, m_rungKutta.vx));
    m_serRKVy->append(QPointF(0, m_rungKutta.vy));
}

void CSZJS::countAllRungeKutta()
{
    qDebug() << m_rungKutta.x;
    qDebug() << m_rungKutta.y;
    qDebug() << m_rungKutta.vx;
    qDebug() << m_rungKutta.vy;
    qDebug() << "-------------";

    for (int i = 0; i < 10; i++) {
        countXRungeKutta();
        countYRungeKutta();
        countVxRungeKutta();
        countVyRungeKutta();

        m_serRKX->append(QPointF(0.1 * (i + 1), m_rungKutta.x));
        m_serRKY->append(QPointF(0.1 * (i + 1), m_rungKutta.y));
        m_serRKVx->append(QPointF(0.1 * (i + 1), m_rungKutta.vx));
        m_serRKVy->append(QPointF(0.1 * (i + 1), m_rungKutta.vy));

        qDebug() << m_rungKutta.x;
        qDebug() << m_rungKutta.y;
        qDebug() << m_rungKutta.vx;
        qDebug() << m_rungKutta.vy;
        qDebug() << "-------------";
    }
}

void CSZJS::countXRungeKutta()
{
    float K1 = fx(m_rungKutta.vx);
    float K2 = fx(m_rungKutta.vx);
    float K3 = fx(m_rungKutta.vx);
    float K4 = fx(m_rungKutta.vx);
    float yk = m_rungKutta.xGJ.at(m_rungKutta.xGJ.size() - 1);

    m_rungKutta.x = yk + m_rungKutta.h / 6.0 * (K1 + 2 * K2 + 2 * K3 + K4);
    m_rungKutta.xGJ.push_back(m_rungKutta.x);
}

void CSZJS::countYRungeKutta()
{
    float K1 = fy(m_rungKutta.vy);
    float K2 = fy(m_rungKutta.vy);
    float K3 = fy(m_rungKutta.vy);
    float K4 = fy(m_rungKutta.vy);
    float yk = m_rungKutta.yGJ.at(m_rungKutta.yGJ.size() - 1);

    m_rungKutta.y = yk + m_rungKutta.h / 6.0 * (K1 + 2 * K2 + 2 * K3 + K4);
    m_rungKutta.yGJ.push_back(m_rungKutta.y);
}

void CSZJS::countVxRungeKutta()
{
    float K1 = fvx(m_rungKutta.ax);
    float K2 = fvx(m_rungKutta.ax);
    float K3 = fvx(m_rungKutta.ax);
    float K4 = fvx(m_rungKutta.ax);
    float yk = m_rungKutta.vxGJ.at(m_rungKutta.vxGJ.size() - 1);

    m_rungKutta.vx = yk + m_rungKutta.h / 6.0 * (K1 + 2 * K2 + 2 * K3 + K4);
    m_rungKutta.vxGJ.push_back(m_rungKutta.vx);
}

void CSZJS::countVyRungeKutta()
{
    float K1 = fvy(m_rungKutta.ay);
    float K2 = fvy(m_rungKutta.ay);
    float K3 = fvy(m_rungKutta.ay);
    float K4 = fvy(m_rungKutta.ay);
    float yk = m_rungKutta.vyGJ.at(m_rungKutta.vyGJ.size() - 1);

    m_rungKutta.vy = yk + (-m_rungKutta.h / 6.0 * (K1 + 2 * K2 + 2 * K3 + K4));
    m_rungKutta.vyGJ.push_back(m_rungKutta.vy);
}

std::vector<double> CSZJS::simplex(LinearProgram &lp)
{

    // 创建单纯形表
    std::vector<std::vector<double>> tableau(lp.A.size() + 1, std::vector<double>(lp.c.size() + 1));

    // 初始化单纯形表
    for (size_t i = 0; i < lp.A.size(); ++i) {
        tableau[i] = lp.A[i];
        tableau[i].push_back(lp.b[i]);
    }
    tableau[lp.A.size()] = lp.c;
    tableau[lp.A.size()].push_back(0);

    // 单纯形法迭代
    while (true) {
        // 寻找入基变量（pivot column）
        int pivot_col = std::min_element(tableau.back().begin(), tableau.back().end() - 1) - tableau.back().begin();
        if (tableau.back()[pivot_col] >= 0) {
            break; // 所有系数均非负，达到最优解
        }

        // 寻找出基变量（pivot row）
        int pivot_row = -1;
        double min_ratio = std::numeric_limits<double>::max();
        for (size_t i = 0; i < tableau.size() - 1; ++i) {
            if (tableau[i][pivot_col] > 0 && tableau[i][tableau[i].size() - 1] / tableau[i][pivot_col] < min_ratio) {
                pivot_row = i;
                min_ratio = tableau[i][tableau[i].size() - 1] / tableau[i][pivot_col];
            }
        }
        if (pivot_row == -1) {
            throw std::runtime_error("线性规划问题无界或无解");
        }

        // 进行主元消去
        double pivot_element = tableau[pivot_row][pivot_col];
        for (size_t i = 0; i < tableau.size(); ++i) {
            if (i != pivot_row) {
                double multiplier = tableau[i][pivot_col] / pivot_element;
                for (size_t j = 0; j < tableau[i].size(); ++j) {
                    tableau[i][j] -= multiplier * tableau[pivot_row][j];
                }
            }
        }
    }

    // 提取解
    std::vector<double> solution(lp.c.size(), 0);
    for (size_t i = 0; i < lp.A.size(); ++i) {
        int pivot_col = std::find(lp.c.begin(), lp.c.end(), 1) - lp.c.begin();
        if (pivot_col < lp.c.size() && tableau[i][pivot_col] == 1 && std::count(tableau[i].begin(), tableau[i].end(), 0) == tableau[i].size() - 1) {
            solution[pivot_col] = tableau[i][tableau[i].size() - 1];
        }
    }

    return solution;
}

void CSZJS::CountLP()
{
    LinearProgram lp;
    lp.A = {{5, 4}, {3, 5}};
    lp.b = {20, 15};
    lp.c = {6, 7};

    std::vector<double> solution = simplex(lp);

    qDebug() << "最优解";
    qDebug() << "x1 = " << solution.at(0);
    qDebug() << "x2 = " << solution.at(1);


}
