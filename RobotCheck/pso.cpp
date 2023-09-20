#include "pso.h"

PSO::PSO()
{
    srand(time(nullptr));
    int i;
    for( i = 0; i < 30; i++)
    {
//            SWeiLi WL;
//            WL.x = rand()%1400 -700;
//            WL.y = rand()%650 -10;
//            WL.vx = 50;
//            WL.vy = 50;
//            WL.px = m_lz[i].x; //N个粒子当前的最好位置
//            WL.py = m_lz[i].y;
//            WL.ndBH = 0;//历史最大浓度
//            WL.ND = 0;
//            m_lz.push_back(WL);
            m_lz[i].x = rand()%1400 -700;
            m_lz[i].y = rand()%650 -10;
            m_lz[i].vx = 50;
            m_lz[i].vy = 50;
            m_lz[i].px = m_lz[i].x; //N个粒子当前的最好位置
            m_lz[i].py = m_lz[i].y;
            m_lz[i].ndBH = 0;//历史最大浓度
            m_lz[i].ND = 0;

    }

    m_pgx = m_lz[0].px;
    m_pgy = m_lz[0].py;//全局的最好位置

    c1 = 1.2;
    c2 = 1.2;
    r1 = 0.5;
    r2 = 0.5;//初始化

    m_times = 0;
    m_YD.setX(800);
    m_YD.setY(700);//原点初始值位置
    m_kx = 1900 / 1000.0;
    m_ky = - 950 / 1000.0;
    m_pgND = 0;
}

void PSO::UpDate()
{
    int i;
    int vMax = 26;
    for(i = 0; i < N; i++)
    {

            m_lz[i].vx =  m_lz[i].vx * 0.5 + c1*r1*(m_lz[i].px - m_lz[i].x) + c2*r2*(m_pgx - m_lz[i].x);//给定的公式
            m_lz[i].vy =  m_lz[i].vy * 0.5 + c1*r1*(m_lz[i].py - m_lz[i].y) + c2*r2*(m_pgy - m_lz[i].y);
            if( m_lz[i].vx > vMax )
                m_lz[i].vx = vMax;
            if( m_lz[i].vx < -vMax)
                m_lz[i].vx = -vMax;//限制范围
            if( m_lz[i].vy > vMax )
                m_lz[i].vy = vMax;
            if( m_lz[i].vy < -vMax)
                m_lz[i].vy = -vMax;//限制范围

            m_lz[i].x += m_lz[i].vx;//给定的公式
            m_lz[i].y += m_lz[i].vy;//给定的公式

            if(m_lz[i].ndBH < m_lz[i].ND)//当前位置是否比历史的最优位置要好
            {
                m_lz[i].px = m_lz[i].x;
                m_lz[i].py = m_lz[i].y;
                m_lz[i].ndBH = m_lz[i].ND;

            }
//            if(m_pgND < m_lz[i].m_ND)//当前位置是否比历史的最优位置要好
//            {


//            }
            if(m_pgND < m_lz[i].ND)
            {
                m_pgx = m_lz[i].px;
                m_pgy = m_lz[i].py;
                m_pgND = m_lz[i].ND;
            }

    }
//    m_lspg[0] = m_pg[0];
//    m_lspg[1] = m_pg[1];

    m_times++;

}

void PSO::Draw(QPainter *p)
{
    painter = p;
    DrawCanShu();

}

void PSO::DrawCanShu()
{
    QFont font("Arial", 12);
    painter->setFont(font);
    painter->setPen(Qt::black);

    QString str1 = QString("迭代次数：%1").arg(m_times);
    QString str2 = QString("全局最优值位置:（%1，%2）").arg(m_pgx).arg(m_pgy);
    painter->drawText(1700, 100, str1);
    painter->drawText(1700, 120, str2);
    int i;
    int x ,y,r;
    r = 5;//坐标原点半径
    x = m_YD.x();
    y = m_YD.y();
    painter->drawEllipse(x-r,y-r,2 * r,2 * r);
    QBrush brush(Qt::blue);  // 设置为蓝色
    painter->setBrush(brush);
    for(i = 0; i < N; i++)
    {
        x = m_YD.x() + m_lz[i].x * m_kx;
        y = m_YD.y() + m_lz[i].y * m_ky;
        r = 10;
        painter->drawEllipse(x-r,y-r,2 * r,2 * r);

    }

}
