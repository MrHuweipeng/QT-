#ifndef CDITU_H
#define CDITU_H
#include "math.h"
#include <QPainter>
typedef struct QPainter CDC;
typedef struct
{
    int x,y;
}CPoint;

typedef struct
{
    float dd[4][2];
    float name_wz[2];
    char name[30];

}SJianZhu;

typedef struct
{
    float dd1[10][2];
    float dd2[10][2];
    int n;
    char name[30];

}SLuMian;

typedef struct
{
    float x,y;
    float vx,vy;
    float T;
    float t;
}SLiZi;

class CDiTu
{
public:
    CDiTu();
    void InitLXD();
    float QiuND(float x,float y);
    void InitialJianZhu();
    void DrawJianZhu();
    void Draw(CDC *p);
    void DrawLuMian();
    void InitialLuMian();
    void DrawLiZi();
    void MoveLiZi();
    void CreateLiZi();
    CDC *pDC;
    CPoint m_YD;
    //比例尺
    float m_kx,m_ky;
    //建筑物
    SJianZhu m_JZ[100];
    int m_nJZ;
    SLuMian m_LM[100];
    int m_nLM;
    SLiZi m_LZ[60000];
    int m_nLZ;
    float m_xXLD,m_yXLD;
    float m_r;
    float m_ND,m_R;//浓度和以小车为圆心的半径
};

#endif // CDITU_H
