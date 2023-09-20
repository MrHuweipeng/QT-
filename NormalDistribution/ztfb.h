#ifndef ZTFB_H
#define ZTFB_H
#include <random>
#include <QPaintEvent>
#define PI 3.1415926
#include <QDebug>
#include <QPainter>
#include <QPoint>
#include <QPen>
class ZTFB
{
public:
    ZTFB();
    void Draw(QPainter* p);
    void DrawZB();
    void DrawQX();
    void CreateRandomNumber();
    void generate_normal_random();
    void JiLuGeShu();
    double x1[1000],x2[1000],y1[1000],y2[1000];
    int m_n0ZY[2],m_n1ZY[2],m_n2ZY[2],m_n3ZY[2],m_nF1ZY[2],m_nF2ZY[2],m_nF3ZY[2];
    int m_nY[2];
    float m_BL[2];
    QPainter *painter;
    QPoint m_YD;


};

#endif // ZTFB_H
