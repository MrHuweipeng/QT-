#include "car_pso.h"
#include <QObject>

Car_PSO::Car_PSO()
{
    srand(time(NULL));

    m_kx = 1900 / 1000.0;
    m_ky = - 950 / 1000.0;
    m_YD.setX(700);
    m_YD.setY(850);

    // 初始化小车位置，速度
    for (int i = 0; i < m_numCar; i++)
    {
        SMyCar car;
        car.nd = 0;
        car.ndBestHistory = 0;
        car.pos.setX(rand() % (477 + 310 + 1) - 310);
        car.pos.setY(rand() % (686 + 100 + 1) - 100);
        car.v.x = 50;
        car.v.y = 50;
        car.posBestHistory.setX(car.pos.x());
        car.posBestHistory.setY(car.pos.y());

        m_carPSO.push_back(car);
    }

    // 初始化全局最优位置
    this->m_posGlobalBest.setX(m_carPSO[0].pos.x());
    this->m_posGlobalBest.setY(m_carPSO[0].pos.y());
    this->m_ndPosGlobalBest = m_carPSO[0].nd;

    r1 = 0.5;
    r2 = 0.5;
}

void Car_PSO::Move()
{
    int i;
    int vMax = 100;
    for(i = 0; i < m_carPSO.count(); i++)
    {
        m_carPSO[i].v.x = w * m_carPSO[i].v.x +
                          c1 * r1 * (m_carPSO[i].posBestHistory.x() - m_carPSO[i].pos.x()) +
                          c2 * r2 * (m_posGlobalBest.x() - m_carPSO[i].pos.x());
        m_carPSO[i].v.y = w * m_carPSO[i].v.y +
                          c1 * r1 * (m_carPSO[i].posBestHistory.y() - m_carPSO[i].pos.y()) +
                          c2 * r2 * (m_posGlobalBest.y() - m_carPSO[i].pos.y());

        if (m_carPSO[i].v.x > vMax)
            m_carPSO[i].v.x = vMax;
        if (m_carPSO[i].v.x < -vMax)
            m_carPSO[i].v.x = -vMax;
        if (m_carPSO[i].v.y > vMax)
            m_carPSO[i].v.y = vMax;
        if (m_carPSO[i].v.y < -vMax)
            m_carPSO[i].v.y = -vMax;

        m_carPSO[i].pos.setX(m_carPSO[i].pos.x() + m_carPSO[i].v.x);
        m_carPSO[i].pos.setY(m_carPSO[i].pos.y() + m_carPSO[i].v.y);

        // 更新最优位置
        if (m_carPSO[i].nd > m_carPSO[i].ndBestHistory)
        {
            m_carPSO[i].posBestHistory.setX(m_carPSO[i].pos.x());
            m_carPSO[i].posBestHistory.setY(m_carPSO[i].pos.y());
            m_carPSO[i].ndBestHistory = m_carPSO[i].nd;
        }

        // 更新全局最优位置及其浓度
        if (m_ndPosGlobalBest < m_carPSO[i].nd)
        {
            m_posGlobalBest.setX(m_carPSO[i].pos.x());
            m_posGlobalBest.setY(m_carPSO[i].pos.y());
            m_ndPosGlobalBest = m_carPSO[i].nd;
        }
    }

    m_times++;
}

void Car_PSO::Draw(QPainter *p)
{
    m_painter = p;

    // 画小车
    m_painter->setBrush(QColor(255, 0, 0));

    for (int i = 0; i < m_carPSO.count(); i++)
    {
        m_painter->drawEllipse(
            QPoint(m_YD.x() + m_kx * m_carPSO[i].pos.x(), m_YD.y() + m_ky * m_carPSO[i].pos.y()),
            10, 10);
    }

    // 数据
    m_painter->drawText(10, 50, QString("迭代次数：%1").arg(m_times));
    m_painter->drawText(10, 80, QString("历史最好位置：%1, %2")
                .arg(m_posGlobalBest.x()).arg(m_posGlobalBest.y()));
}
