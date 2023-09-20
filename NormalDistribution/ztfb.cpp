#include "ztfb.h"

ZTFB::ZTFB()
{
    for(int i = 0;i < 2;i++)
    {
        m_n0ZY[i] = 0;
        m_n1ZY[i] = 0;
        m_n2ZY[i] = 0;
        m_n3ZY[i] = 0;
        m_nF1ZY[i] = 0;
        m_nF2ZY[i] = 0;
        m_nF3ZY[i] = 0;

    }
    CreateRandomNumber();
    generate_normal_random();
    m_YD.setX(500);
    m_YD.setY(600);


}

void ZTFB::Draw(QPainter *p)
{
    painter = p;
    DrawZB();
    DrawQX();

}

void ZTFB::DrawZB()
{
    painter->drawLine(m_YD.x(),m_YD.y(),m_YD.x() + 400,m_YD.y());
    painter->drawLine(m_YD.x(),m_YD.y(),m_YD.x() - 400,m_YD.y());
    painter->drawLine(m_YD.x(),m_YD.y(),m_YD.x(),m_YD.y() - 500);
    int i,JG = 0;
    for (i = 0; i < 6; i++)
    {
        JG += 40;
        painter->drawLine(m_YD.x() + JG, m_YD.y(),m_YD.x() + JG, m_YD.y() - 5);

    }
    JG = 0;
    for (i = 0; i < 6; i++)
    {
        JG -= 40;
        painter->drawLine(m_YD.x() + JG, m_YD.y(),m_YD.x() + JG, m_YD.y() - 5);

    }

    JG = 0;
    for (i = 1; i < 7; i++)
    {
        JG += 40;
        QString str = QString::number((int)i, 'd', 0); // 将浮点数转换为字符串
        painter->setFont(QFont("宋体", 10)); // 设置字体和大小
        painter->drawText(m_YD.x() + JG + 2, m_YD.y() + 25, str); // 绘制文本
    }
    JG = 0;
    for (i = 1; i < 7; i++)
    {
        JG += 40;
        QString str = QString::number((int)-i, 'd', 0); // 将浮点数转换为字符串
        painter->setFont(QFont("宋体", 10)); // 设置字体和大小
        painter->drawText(m_YD.x() - JG - 5, m_YD.y() + 25, str); // 绘制文本
    }
    painter->drawText(m_YD.x(), m_YD.y() + 25, "0"); // 绘制文本
    JG = 0;
    for (i = 1; i < 5; i++)
    {
        JG += 100;
        QString str = QString::number((int)i * 100, 'd', 0); // 将浮点数转换为字符串
        painter->setFont(QFont("宋体", 10)); // 设置字体和大小
        painter->drawText(m_YD.x() - 40, m_YD.y() - JG, str); // 绘制文本
    }
    JG = 0;
    for (i = 0; i < 4; i++)
    {
        JG += 100;
        painter->drawLine(m_YD.x(), m_YD.y() - JG - 5, m_YD.x() + 8, m_YD.y() - JG - 5);

    }

    QString str = QString::number((int)m_nY[0], 'd', 0);
    painter->drawText(80, 100, "Y1:"); // 绘制文本
    painter->drawText(100, 100, str); // 绘制文本
    str = QString::number((int)m_nY[1], 'd', 0);
    painter->drawText(80, 120, "Y2:"); // 绘制文本
    painter->drawText(100, 120, str); // 绘制文本
    str = QString::number((int)(m_BL[0] * 100), 'd', 0).append("%");
    painter->drawText(60, 140, "Y13σ:"); // 绘制文本
    painter->drawText(100, 140, str); // 绘制文本
    str = QString::number((int)(m_BL[1] * 100), 'd', 0).append("%");
    painter->drawText(60, 160, "Y23σ:"); // 绘制文本
    painter->drawText(100, 160, str); // 绘制文本

}

void ZTFB::DrawQX()
{
    int JG = 40;
    painter->drawLine(m_YD.x(),m_YD.y() - m_n0ZY[0],m_YD.x() + JG,m_YD.y() - m_n1ZY[0]);
    painter->drawLine(m_YD.x() + JG,m_YD.y() - m_n1ZY[0],m_YD.x() + JG*2,m_YD.y() - m_n2ZY[0]);
    painter->drawLine(m_YD.x() + JG*2,m_YD.y() - m_n2ZY[0],m_YD.x() + JG*3,m_YD.y() - m_n3ZY[0]);
    JG = 40;
    painter->drawLine(m_YD.x(),m_YD.y() - m_n0ZY[0],m_YD.x() - JG,m_YD.y() - m_nF1ZY[0]);
    painter->drawLine(m_YD.x() - JG,m_YD.y() - m_nF1ZY[0],m_YD.x() - JG*2,m_YD.y() - m_nF2ZY[0]);
    painter->drawLine(m_YD.x() - JG*2,m_YD.y() - m_nF2ZY[0],m_YD.x() - JG*3,m_YD.y() - m_nF3ZY[0]);
    QBrush *b = new QBrush;//创建画刷对象

    b->setColor(Qt::red);//给画刷设置颜色
    b->setStyle(Qt::SolidPattern);//设置填充风格
    painter->setBrush(*b);//将画刷交给画家
    painter->drawEllipse(m_YD.x() - 2,m_YD.y() - m_n0ZY[0] - 2,4,4);
    QString str = QString::number((int)m_n0ZY[0], 'd', 0); // 将浮点数转换为字符串
    painter->setFont(QFont("宋体", 10)); // 设置字体和大小
    painter->drawText(m_YD.x() + 5, m_YD.y() - m_n0ZY[0], str); // 绘制文本

    painter->drawEllipse(m_YD.x() - 2 + JG,m_YD.y() - m_n1ZY[0] - 2,4,4);
    str = QString::number((int)m_n1ZY[0], 'd', 0); // 将浮点数转换为字符串
    painter->setFont(QFont("宋体", 10)); // 设置字体和大小
    painter->drawText(m_YD.x() + 5 + JG, m_YD.y() - m_n1ZY[0], str); // 绘制文本
    painter->drawEllipse(m_YD.x() - 2 + JG*2,m_YD.y() - m_n2ZY[0] - 2,4,4);
    str = QString::number((int)m_n2ZY[0], 'd', 0); // 将浮点数转换为字符串
    painter->setFont(QFont("宋体", 10)); // 设置字体和大小
    painter->drawText(m_YD.x() + 5 + JG*2, m_YD.y() - m_n2ZY[0], str); // 绘制文本
    painter->drawEllipse(m_YD.x() - 2 + JG*3,m_YD.y() - m_n3ZY[0] - 2,4,4);
    str = QString::number((int)m_n3ZY[0], 'd', 0); // 将浮点数转换为字符串
    painter->setFont(QFont("宋体", 10)); // 设置字体和大小
    painter->drawText(m_YD.x() + 5 + JG*3, m_YD.y() - m_n3ZY[0], str); // 绘制文本
    painter->drawEllipse(m_YD.x() - 2 - JG,m_YD.y() - m_nF1ZY[0] - 2,4,4);
    str = QString::number((int)m_nF1ZY[0], 'd', 0); // 将浮点数转换为字符串
    painter->setFont(QFont("宋体", 10)); // 设置字体和大小
    painter->drawText(m_YD.x() + 5  - JG, m_YD.y() - m_nF1ZY[0], str); // 绘制文本
    painter->drawEllipse(m_YD.x() - 2 - 2 * JG,m_YD.y() - m_nF2ZY[0] - 2,4,4);
    str = QString::number((int)m_nF2ZY[0], 'd', 0); // 将浮点数转换为字符串
    painter->setFont(QFont("宋体", 10)); // 设置字体和大小
    painter->drawText(m_YD.x() + 5 - 2 * JG, m_YD.y() - m_nF2ZY[0], str); // 绘制文本
    painter->drawEllipse(m_YD.x() - 2 - 3 * JG,m_YD.y() - m_nF3ZY[0] - 2,4,4);
    str = QString::number((int)m_nF3ZY[0], 'd', 0); // 将浮点数转换为字符串
    painter->setFont(QFont("宋体", 10)); // 设置字体和大小
    painter->drawText(m_YD.x() + 5 - 3 * JG, m_YD.y() - m_nF3ZY[0], str); // 绘制文本

    QPen *pen = new QPen;//创建画笔对象
    pen->setColor(Qt::blue);//设置颜色
    pen->setStyle(Qt::SolidLine);//设置风格
    painter->setPen(*pen);//将画笔交给画家

    JG = 40;
    painter->drawLine(m_YD.x(),m_YD.y() - m_n0ZY[1],m_YD.x() + JG,m_YD.y() - m_n1ZY[1]);
    painter->drawLine(m_YD.x() + JG,m_YD.y() - m_n1ZY[1],m_YD.x() + JG*2,m_YD.y() - m_n2ZY[1]);
    painter->drawLine(m_YD.x() + JG*2,m_YD.y() - m_n2ZY[1],m_YD.x() + JG*3,m_YD.y() - m_n3ZY[1]);
    JG = 40;
    painter->drawLine(m_YD.x(),m_YD.y() - m_n0ZY[1],m_YD.x() - JG,m_YD.y() - m_nF1ZY[1]);
    painter->drawLine(m_YD.x() - JG,m_YD.y() - m_nF1ZY[1],m_YD.x() - JG*2,m_YD.y() - m_nF2ZY[1]);
    painter->drawLine(m_YD.x() - JG*2,m_YD.y() - m_nF2ZY[1],m_YD.x() - JG*3,m_YD.y() - m_nF3ZY[1]);


    painter->setBrush(*b);//将画刷交给画家
    painter->drawEllipse(m_YD.x() - 2,m_YD.y() - m_n0ZY[1] - 2,4,4);
    str = QString::number((int)m_n0ZY[1], 'd', 0); // 将浮点数转换为字符串
    painter->setFont(QFont("宋体", 10)); // 设置字体和大小
    painter->drawText(m_YD.x() + 5, m_YD.y() - m_n0ZY[1], str); // 绘制文本

    painter->drawEllipse(m_YD.x() - 2 + JG,m_YD.y() - m_n1ZY[1] - 2,4,4);
    str = QString::number((int)m_n1ZY[1], 'd', 0); // 将浮点数转换为字符串
    painter->setFont(QFont("宋体", 10)); // 设置字体和大小
    painter->drawText(m_YD.x() + 5 + JG, m_YD.y() - m_n1ZY[1], str); // 绘制文本
    painter->drawEllipse(m_YD.x() - 2 + JG*2,m_YD.y() - m_n2ZY[1] - 2,4,4);
    str = QString::number((int)m_n2ZY[1], 'd', 0); // 将浮点数转换为字符串
    painter->setFont(QFont("宋体", 10)); // 设置字体和大小
    painter->drawText(m_YD.x() + 5 + JG*2, m_YD.y() - m_n2ZY[1], str); // 绘制文本
    painter->drawEllipse(m_YD.x() - 2 + JG*3,m_YD.y() - m_n3ZY[1] - 2,4,4);
    str = QString::number((int)m_n3ZY[1], 'd', 0); // 将浮点数转换为字符串
    painter->setFont(QFont("宋体", 10)); // 设置字体和大小
    painter->drawText(m_YD.x() + 5 + JG*3, m_YD.y() - m_n3ZY[1], str); // 绘制文本
    painter->drawEllipse(m_YD.x() - 2 - JG,m_YD.y() - m_nF1ZY[1] - 2,4,4);
    str = QString::number((int)m_nF1ZY[1], 'd', 0); // 将浮点数转换为字符串
    painter->setFont(QFont("宋体", 10)); // 设置字体和大小
    painter->drawText(m_YD.x() + 5  - JG, m_YD.y() - m_nF1ZY[1], str); // 绘制文本
    painter->drawEllipse(m_YD.x() - 2 - 2 * JG,m_YD.y() - m_nF2ZY[1] - 2,4,4);
    str = QString::number((int)m_nF2ZY[1], 'd', 0); // 将浮点数转换为字符串
    painter->setFont(QFont("宋体", 10)); // 设置字体和大小
    painter->drawText(m_YD.x() + 5 - 2 * JG, m_YD.y() - m_nF2ZY[1], str); // 绘制文本
    painter->drawEllipse(m_YD.x() - 2 - 3 * JG,m_YD.y() - m_nF3ZY[1] - 2,4,4);
    str = QString::number((int)m_nF3ZY[1], 'd', 0); // 将浮点数转换为字符串
    painter->setFont(QFont("宋体", 10)); // 设置字体和大小
    painter->drawText(m_YD.x() + 5 - 3 * JG, m_YD.y() - m_nF3ZY[1], str); // 绘制文本


}

void ZTFB::CreateRandomNumber()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    // 创建随机数引擎，并设置种子
    std::default_random_engine e(seed);

    // 创建均匀分布的随机整数分布对象
    std::uniform_int_distribution<int> u(0, 100);
    std::uniform_int_distribution<int> y(0, 100);

    for(int i = 0;i < 1000;++i)
    {
       x1[i] = u(e)/100.0;
       x2[i] = y(e)/100.0;
    }


}

void ZTFB::generate_normal_random()
{
    int i;
    for(i=0;i<1000;i+=2)
    {
        y1[i] = sqrt( -2.0*log(x1[i]) ) * cos(2*PI*x2[i+1]);
        y1[i+1] = sqrt( -2.0*log(x1[i]) ) * sin(2*PI*x2[i+1]);
        y2[i] = sqrt( -2.0*log(x2[i]) ) * cos(2*PI*x1[i+1]);
        y2[i+1] = sqrt( -2.0*log(x2[i]) ) * sin(2*PI*x1[i+1]);
    }
    JiLuGeShu();
}

void ZTFB::JiLuGeShu()
{
    int i,GS0ZY = 0,GS1ZY = 0,GS2ZY = 0,GS3ZY = 0,GSF1ZY = 0,GSF2ZY = 0,GSF3ZY = 0;
    for(i=0;i<1000;i++)
    {
       if(y1[i] > -0.5 && y1[i] < 0.5)
           GS0ZY++;
       if(y1[i] > 0.5 && y1[i] < 1.5)
           GS1ZY++;
       if(y1[i] > 1.5 && y1[i] < 2.5)
           GS2ZY++;
       if(y1[i] > 2.5 && y1[i] < 3.5)
           GS3ZY++;
       if(y1[i] > -1.5 && y1[i] < -0.5)
           GSF1ZY++;
       if(y1[i] > -2.5 && y1[i] < -1.5)
           GSF2ZY++;
       if(y1[i] > -3.5 && y1[i] < -2.5)
           GSF3ZY++;
    }
    m_n0ZY[0] = GS0ZY;
    m_n1ZY[0] = GS1ZY;
    m_n2ZY[0] = GS2ZY;
    m_n3ZY[0] = GS3ZY;
    m_nF1ZY[0] = GSF1ZY;
    m_nF2ZY[0] = GSF2ZY;
    m_nF3ZY[0] = GSF3ZY;
    m_nY[0] = m_n0ZY[0]+m_n1ZY[0]+m_n2ZY[0]+m_n3ZY[0]+m_nF1ZY[0]+m_nF2ZY[0]+m_nF3ZY[0];
    m_BL[0] = m_nY[0] / 1000.0;
    qDebug()<<m_n0ZY[0];
    qDebug()<<m_n1ZY[0];
    qDebug()<<m_n2ZY[0];
    qDebug()<<m_n3ZY[0];
    qDebug()<<m_nF1ZY[0];
    qDebug()<<m_nF2ZY[0];
    qDebug()<<m_nF3ZY[0];

    GS0ZY = 0,GS1ZY = 0,GS2ZY = 0,GS3ZY = 0,GSF1ZY = 0,GSF2ZY = 0,GSF3ZY = 0;
    for(i=0;i<1000;i++)
    {
       if(y2[i] > -0.5 && y2[i] < 0.5)
           GS0ZY++;
       if(y2[i] > 0.5 && y2[i] < 1.5)
           GS1ZY++;
       if(y2[i] > 1.5 && y2[i] < 2.5)
           GS2ZY++;
       if(y2[i] > 2.5 && y2[i] < 3.5)
           GS3ZY++;
       if(y2[i] > -1.5 && y2[i] < -0.5)
           GSF1ZY++;
       if(y2[i] > -2.5 && y2[i] < -1.5)
           GSF2ZY++;
       if(y2[i] > -3.5 && y2[i] < -2.5)
           GSF3ZY++;
    }

    m_n0ZY[1] = GS0ZY;
    m_n1ZY[1] = GS1ZY;
    m_n2ZY[1] = GS2ZY;
    m_n3ZY[1] = GS3ZY;
    m_nF1ZY[1] = GSF1ZY;
    m_nF2ZY[1] = GSF2ZY;
    m_nF3ZY[1] = GSF3ZY;
    m_nY[1] = m_n0ZY[1]+m_n1ZY[1]+m_n2ZY[1]+m_n3ZY[1]+m_nF1ZY[1]+m_nF2ZY[1]+m_nF3ZY[1];
    m_BL[1] = m_nY[1] / 1000.0;
    qDebug()<<m_n0ZY[1];
    qDebug()<<m_n1ZY[1];
    qDebug()<<m_n2ZY[1];
    qDebug()<<m_n3ZY[1];
    qDebug()<<m_nF1ZY[1];
    qDebug()<<m_nF2ZY[1];
    qDebug()<<m_nF3ZY[1];



}
