#ifndef PSO_H
#define PSO_H
#include <random>
#include <QPainter>
#include <QDebug>
#include <QVector>
#define N 30
typedef struct
{
    float x;
    float y;//微粒位置
    float vx;//微粒速度
    float vy;
    float px;//曾经经历过的最好位置
    float py;
    float ND;
    float ndBH;
}SWeiLi;//用结构体表示微粒
class PSO
{
public:
    PSO();

    void UpDate();
    void Draw(QPainter* p);
    void DrawCanShu();

    QPainter *painter;
//    QVector<SWeiLi>m_lz;
    SWeiLi m_lz[N];//定义微粒数组
    float m_pgx,m_pgy;//全局的最优
    float c1,c2;//c1是调节微粒自身最好位置，c2是全局最好位置。
    float r1,r2;//r1,r2
    int m_times;//迭代次数
    float m_pgND;
    QPoint m_YD;
    float m_kx,m_ky;
};

#endif // PSO_H
