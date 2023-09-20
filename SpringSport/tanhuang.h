#ifndef TANHUANG_H
#define TANHUANG_H
#include<QPainter>
#include<QPoint>
#include <QPaintEvent>


class TanHuang
{
public:
    TanHuang();
    void Draw(QPainter* p);
    void DrawSpring();
    void Move();
    void DrawQuXian(int x,int y,QString str,float arr[],int n);
    QPainter *painter;
    QPoint m_YD;
    float m_k;
    float m_InitL,m_l,m_Upl,m_Downl;
    float m_TLK;
    float m_m,m_v,m_r,m_a,m_WY,m_f,m_w;
    float m_ZN;
    float m_detatl;
    float m_vQX[1000];
    float m_aQX[1000];
    float m_fQX[1000];
    float m_wyQX[1000];

    int m_nvQX,m_naQX;
    int m_nfQX,m_nwyQX;

};

#endif // TANHUANG_H
