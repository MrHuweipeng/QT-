#ifndef CSZJS_H
#define CSZJS_H

#include <QVector>
#include <QPainter>
#include <Eigen/Dense> // 导入Eigen库
#include <QtCharts>

typedef struct {
    float h;  // 步长
    float x;
    float y;
    float vx;
    float vy;
    float ax;
    float ay;
    QVector<float> xGJ;
    QVector<float> yGJ;
    QVector<float> vxGJ;
    QVector<float> vyGJ;
}SRungeKutta;

typedef struct  {
    std::vector<std::vector<double>> A; // 约束条件的系数矩阵
    std::vector<double> b; // 约束条件的右侧常数
    std::vector<double> c; // 目标函数的系数
}LinearProgram;

class CSZJS
{
public:
    CSZJS();

    void PrintData();

    void initSeries();

    void CountAll();

    // 拟合
    void SetInitData651();      // 原始数据散点图
    void FitFirstOrderCurve();  // 拟合一次曲线
    void FitQuadraticCurves();  // 拟合二次曲线
    void FitCubicCurve();       // 拟合三次曲线
    void FitQuinticCurve();     // 拟合四次曲线
    void FitHexagonalCurve();   // 拟合五次曲线

    // 插值
    void CountByLagrangeFirstOrderCurve();  // 一次曲线
    void CountByLagrangeQuadraticCurve();   // 二次曲线
    void CountByLagrangeCubicCurve();       // 三次曲线

    void Draw(QPainter* painter);
    void DrawAxis();       //画坐标轴
    void DrawCurve();      //画曲线
    void DrawPoint();      //画点

    // 数值积分
    float getFunctionResultOfNumericalIntegration(float x);   // 根据数值积分函数求结果
    void InitDataOfNumericalIntegration();            // 初始化数值积分数据
    void CountOfNumericalIntegration();               // 计算数值积分结果
    void MiddleRectangleMethod();  // 中矩形法
    void TrapezoidalMethod();      // 梯形法
    void SimpsonMethod();          // 辛普森
    void NewtonMethod();           // 牛顿
    void CotesMethod();            // 科特

    // 数值积分机器人例子
    void CountAllRobot();
    void FitRobotCurves();                   // 拟合机器人二次曲线
    float getResultOfRobotVelocity(float t); // 根据拟合曲线获取机器人任意时刻速度
    void CountRobotRec();
    void CountRobotTra();
    void CountRobotSim();
    void CountRobotNew();
    void CountRobotCot();

    // Runge-Kutta法解微分方程
    float fx(float x);
    float fy(float y);
    float fvx(float vx);
    float fvy(float vy);
    void initDataOfRungeKutta();  // 初始化数据
    void countAllRungeKutta();    // 计算所有变量变化轨迹
    void countXRungeKutta();      // 计算x变化轨迹
    void countYRungeKutta();      // 计算y变化轨迹
    void countVxRungeKutta();     // 计算vx变化轨迹
    void countVyRungeKutta();     // 计算vy变化轨迹

    //线性规划
    std::vector<double> simplex(LinearProgram& lp);
    void CountLP();

public:
    QPainter * m_painter;

    int m_xYD;
    int m_yYD;
    float m_kx;
    float m_ky;
    int m_scaleX;  // 刻度总数
    int m_scaleY;  // 刻度总数

    // Runge-Kutta法解微分方程
    SRungeKutta m_rungKutta;
    QSplineSeries * m_serRKX;
    QSplineSeries * m_serRKY;
    QSplineSeries * m_serRKVx;
    QSplineSeries * m_serRKVy;


    // 数值积分
    QVector<QPointF> m_points712;  // 已知数据点
    float m_resultRec;  // 矩形法
    float m_resultTra;  // 梯形法
    float m_resultSim;  // 辛普森
    float m_resultNew;  // 牛顿
    float m_resultCot;  // 科特

    // 数值积分机器人例子
    QVector<QPointF> m_potsRobVel; // 机器人每个时刻的速度
    QVector<float> m_transRec;
    QVector<float> m_transTra;
    QVector<float> m_transSim;
    QVector<float> m_transNew;
    QVector<float> m_transCot;
    float m_coefficient[3];   // 拟合函数的每一项系数，0：二次项系数，1：一次项系数，2：常数项
    QSplineSeries * m_serRec;
    QSplineSeries * m_serTra;
    QSplineSeries * m_serSim;
    QSplineSeries * m_serNew;
    QSplineSeries * m_serCot;



    // 拟合已知点
    QVector<QPointF> m_points651;
    QScatterSeries * m_serInitData651; // 散点图
    // 拟合曲线
    QSplineSeries * m_seriesOne651;
    QSplineSeries * m_seriesTwo651;
    QSplineSeries * m_seriesThree651;
    QSplineSeries * m_seriesFour651;
    QSplineSeries * m_seriesFive651;

    // 插值
    float m_result221;

    // 已知点
    QPointF m_dataKnown1[2];
    QPointF m_dataKnown2[3];
    QPointF m_dataKnown3[4];

    QVector<float> m_dataX1;
    QVector<float> m_dataY1;

    QVector<float> m_dataX2;
    QVector<float> m_dataY2;

    QVector<float> m_dataX3;
    QVector<float> m_dataY3;

    QSplineSeries * m_series1;
    QSplineSeries * m_series2;
    QSplineSeries * m_series3;
};

#endif // CSZJS_H
