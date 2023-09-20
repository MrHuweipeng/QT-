#include "cditu.h"

CDiTu::CDiTu()
{
    m_kx = 1900 / 1000.0;
    m_ky = - 950 / 1000.0;

    m_YD.x = 800;
    m_YD.y = 700;

    m_nJZ = 0;
    m_nLM = 0;
    m_nLZ = 0;

    InitialLuMian();
    InitialJianZhu();

    InitLXD();
    m_r = 2;//2m
    m_R = 40.0;
    m_ND = 0;

}
void CDiTu::Draw(CDC *p)
{
    pDC = p;
    int x,y,r;
    r = 4;

    DrawJianZhu();
    DrawLuMian();
    DrawLiZi();
    //原点
    x = m_YD.x;
    y = m_YD.y;
    pDC->drawEllipse(x - r,y - r,2 * r,2 * r);

}

void CDiTu::DrawLuMian()
{
    int i,j;
    float x,y,x1,y1;
    for (i = 0; i < m_nLM; i++)
    {
        x = m_YD.x + m_LM[i].dd1[0][0] * m_kx;
        y = m_YD.y + m_LM[i].dd1[0][1] * m_ky;

        for (j = 0; j < m_LM[i].n; j++)
        {
            x1 = m_YD.x + m_LM[i].dd1[j][0] * m_kx;
            y1 = m_YD.y + m_LM[i].dd1[j][1] * m_ky;
            pDC->drawLine(x,y,x1,y1);
            x = x1;
            y = y1;

        }
    }
    for (i = 0; i < m_nLM; i++)
    {
        x = m_YD.x + m_LM[i].dd2[0][0] * m_kx;
        y = m_YD.y + m_LM[i].dd2[0][1] * m_ky;
        for (j = 0; j < m_LM[i].n; j++)
        {
            x1 = m_YD.x + m_LM[i].dd2[j][0] * m_kx;
            y1 = m_YD.y + m_LM[i].dd2[j][1] * m_ky;
            pDC->drawLine(x,y,x1,y1);
            x = x1;
            y = y1;
        }
    }
}

void CDiTu::DrawJianZhu()
{
    QPoint dd[4];
    int i,j;
    float x,y;

    for (i = 0; i < m_nJZ; i++)
    {
        for (j = 0; j < 4; j++)
        {
            dd[j].setX(m_YD.x + m_JZ[i].dd[j][0] * m_kx);
            dd[j].setY(m_YD.y + m_JZ[i].dd[j][1] * m_ky);
        }
        pDC->drawPolygon(dd, 4);
        x = m_YD.x + m_JZ[i].name_wz[0] * m_kx;
        y = m_YD.y + m_JZ[i].name_wz[1] * m_ky;
        pDC->drawText(x, y, m_JZ[i].name);
    }
}

void CDiTu::InitialJianZhu()
{
    FILE *fp = fopen("F:\\QTproject\\RobotCheck\\JianZhu.txt", "r");
    while(!feof(fp))//光标位置判断后面是否有字符
    {
        fscanf(fp, "%s %f %f %f %f %f %f %f %f %f %f\n",
            m_JZ[m_nJZ].name,
            &(m_JZ[m_nJZ].dd[0][0]), &(m_JZ[m_nJZ].dd[0][1]),
            &(m_JZ[m_nJZ].dd[1][0]), &(m_JZ[m_nJZ].dd[1][1]),
            &(m_JZ[m_nJZ].dd[2][0]), &(m_JZ[m_nJZ].dd[2][1]),
            &(m_JZ[m_nJZ].dd[3][0]), &(m_JZ[m_nJZ].dd[3][1]),
            &(m_JZ[m_nJZ].name_wz[0]), &(m_JZ[m_nJZ].name_wz[1]));
        m_nJZ++;
    }
    fclose(fp);
}

void CDiTu::InitialLuMian()
{
    FILE *fp = fopen("F:\\QTproject\\RobotCheck\\LuMian.txt", "r");
    int i;
    while(!feof(fp))//光标位置判断后面是否有字符
    {

        fscanf(fp,"%s %d\n",m_LM[m_nLM].name,&m_LM[m_nLM].n);
        for(i=0;i<m_LM[m_nLM].n;i++)
        {
            fscanf(fp,"%f %f\n",&m_LM[m_nLM].dd1[i][0],&m_LM[m_nLM].dd1[i][1]);
        }
        for(i=0;i<m_LM[m_nLM].n;i++)
        {
            fscanf(fp,"%f %f \n",&m_LM[m_nLM].dd2[i][0],&m_LM[m_nLM].dd2[i][1]);
        }
        m_nLM++;

    }
    fclose(fp);
}

void CDiTu::CreateLiZi()
{
    int i;
    for(i=0;i<30;i++)
    {
        m_LZ[m_nLZ].x = m_xXLD;
        m_LZ[m_nLZ].y = m_yXLD;
        m_LZ[m_nLZ].vx = rand()%101 - 50;
        m_LZ[m_nLZ].vy = rand()%101 - 50;

        m_LZ[m_nLZ].T = 80 + rand()%21;
        m_LZ[m_nLZ].t = 0;

        m_nLZ++;

    }
}

void CDiTu::MoveLiZi()
{
    int i;
    float deltaT = 0.1;
    for(i=0;i<m_nLZ;i++)
    {
        m_LZ[i].x += m_LZ[i].vx * deltaT;
        m_LZ[i].y += m_LZ[i].vy * deltaT;
        m_LZ[i].t += deltaT;

        if(m_LZ[i].t>m_LZ[i].T)
        {
            m_LZ[i] = m_LZ[m_nLZ-1];
            m_nLZ--;
        }
    }

}

void CDiTu::DrawLiZi()
{
    int i;
    int x,y,r;
    for(i=0;i<m_nLZ;i++)
    {
        x = m_YD.x + m_LZ[i].x * m_kx;
        y = m_YD.y + m_LZ[i].y * m_ky;
        r = m_r * m_kx;
        pDC->drawEllipse(x-r,y-r,2 * r,2 * r);
    }
}
void CDiTu::InitLXD()
{
    int i;
    srand((int)time(NULL));
    i = rand() % 38;
    m_xXLD = m_JZ[i].dd[0][0];
    m_yXLD = m_JZ[i].dd[0][1];

}


float CDiTu::QiuND(float x,float y)
{
    int i,j = 0;
    float d;
    for(i=0;i<m_nLZ;i++)
    {
        d = sqrt((m_LZ[i].x - x) * (m_LZ[i].x - x) + (m_LZ[i].y - y) * (m_LZ[i].y - y));
        if(d <= m_R)
        {
            j++;
        }
    }
    m_ND = j;
    return m_ND;
}
