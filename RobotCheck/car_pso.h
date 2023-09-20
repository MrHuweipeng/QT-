#ifndef CAR_PSO_H
#define CAR_PSO_H

#include <QPoint>
#include <QVector>
#include <QPainter>


typedef struct
{
    float x;
    float y;
}SSpeed;

typedef struct
{
    QPoint pos;   // 小车位置
    QPoint posBestHistory;   // 历史最好位置
    SSpeed v;  // 速度
    int nd;    // 浓度
    int ndBestHistory; // 历史最好位置浓度
}SMyCar;


class Car_PSO
{
public:
    Car_PSO();

    void Move();
    void Draw(QPainter * p);

    QVector<SMyCar> m_carPSO;
    int m_numCar = 30;

    QPainter * m_painter;
    QPoint m_posGlobalBest;//全局的最优位置
    int m_ndPosGlobalBest; // 全局最优位置的浓度
    const float c1 = 1.4;  // c1个体学习因子
    const float c2 = 1.4;  // c2群体学习因子
    float r1,r2;  // 区间[0,1]内的随机数，增加搜索的随机性
    const float w = 0.5;  // 惯性权重
    int m_times = 0;  //迭代次数
    QPoint m_YD;  //原点
    float m_kx,m_ky;

};

#endif // CAR_PSO_H
