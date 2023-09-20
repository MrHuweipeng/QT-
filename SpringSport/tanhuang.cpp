#include "tanhuang.h"

TanHuang::TanHuang()
{
    m_YD.setX(400);
    m_YD.setY(50);
    m_k = 200;
    m_TLK = 20;
    m_InitL = 0.2;
    m_l = 0.5;
    m_Upl = 0.2;
    m_Downl = 0.1;
    m_m = 1.0;
    m_ZN = 0.96;
    m_v = 1;
    m_WY = 0;
    m_w = 0.2;
    m_r = 0.05;
    m_detatl = 0.1;
    m_nvQX = 0;
    m_naQX= 0;
    m_nfQX = 0;
    m_nwyQX = 0;



}

void TanHuang::Draw(QPainter* p)
{
    painter = p;
    DrawSpring();
    DrawQuXian(700,200,"速度曲线",m_vQX,m_nvQX);
    DrawQuXian(1200,200,"加速度曲线",m_aQX,m_naQX);
    DrawQuXian(700,600,"力曲线",m_fQX,m_nfQX);
    DrawQuXian(1200,600,"位移曲线",m_wyQX,m_nwyQX);


}

void TanHuang::DrawSpring()
{
    int x,y,w,h,x1,y1;
    int r = m_r * m_k;

    //画弹簧上面的部分
    x = m_YD.x() - 60;
    y = m_YD.y();
    x1 = m_YD.x() + 60;
    painter->drawLine(x,y,x1,y);

    x = m_YD.x();
    y = m_YD.y();
    y1 = m_YD.y() + m_Upl * m_k;
    painter->drawLine(x,y,x,y1);

    //画弹簧
    x = m_YD.x() - 20;
    y = y1;
    w = m_w * m_k;
    h = m_l * m_k;
    painter->drawRect(x,y,w,h);

    //画弹簧与重物之间的线
    x = m_YD.x();
    y = y1 + h;
    y1 = y + m_Downl * m_k;
    painter->drawLine(x,y,x,y1);

    //画小球
    x -= r;
    y = y1;
    w = 2 * r;
    painter->drawEllipse(x,y,w,w);

}

void TanHuang::Move()
{
    m_f = m_m * 9.8 - m_TLK * (m_l - m_InitL);
    m_a = m_f / m_m;
    m_v += m_a * m_detatl;
    m_v *= m_ZN;
    m_WY = m_v * m_detatl;
    m_l += m_WY;

    //保存数据
    m_vQX[m_nvQX] = m_v;
    m_nvQX++;
    m_aQX[m_naQX] = m_a;
    m_naQX++;
    m_fQX[m_nfQX] = m_f;
    m_nfQX++;
    m_wyQX[m_nwyQX] = m_WY;
    m_nwyQX++;

}

void TanHuang::DrawQuXian(int x,int y,QString str,float arr[],int n)
{
    //坐标
    int i,JG = 0;
    int initX = x;
    int initY = y;

    painter->drawLine(initX, initY,initX + 450, initY);
    painter->drawLine(initX, initY,initX, initY - 150);
    painter->drawLine(initX, initY,initX, initY + 150);
    painter->drawText(initX + 100, initY + 150 + 10, str);

    painter->drawText(initX - 15, initY - 2, "0");
    for (i = 0; i < 6; i++)
    {
        JG += 20;
        painter->drawLine(initX, initY + JG,initX + 5, initY + JG);

    }
    JG = 0;
    for (i = 0; i < 6; i++)
    {
        JG += 20;
        painter->drawLine(initX, initY - JG,initX + 5, initY - JG);
    }
    JG = 0;
    for (i = 0; i < 20; i++)
    {
        JG += 20;
        painter->drawLine(initX + JG, initY,initX + JG, initY - 5);
    }

    //刻度值
    JG = 0;
    for (i = 1; i < 7; i++)
    {
        JG += 20;
        QString str = QString::number((int)i, 'd', 1); // 将浮点数转换为字符串
        painter->setFont(QFont("宋体", 10)); // 设置字体和大小
        painter->drawText(initX - 25, initY + JG + 5, str); // 绘制文本
    }

    JG = 0;
    for (i = 1; i < 7; i++)
    {
        JG += 20;
        QString str = QString::number((int)i, 'd', 1); // 将浮点数转换为字符串
        painter->setFont(QFont("宋体", 10)); // 设置字体和大小
        painter->drawText(initX - 25, initY - JG, str); // 绘制文本
    }
    JG = 0;
    for (i = 1; i < 21; i++)
    {
        JG += 20;
        QString str = QString::number((float)i / 10.0, 'f', 1); // 将浮点数转换为字符串
        painter->setFont(QFont("宋体", 10)); // 设置字体和大小
        painter->drawText(initX + JG - 10, initY + 15, str); // 绘制文本

    }
    //曲线

    for (i = 1; i < n; i++)
    {
        painter->drawLine(initX, initY + arr[i-1] * 20,initX + 2,initY + arr[i] * 20);
        initX += 2;
    }
}

