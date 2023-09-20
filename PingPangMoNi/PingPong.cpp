// PingPong.cpp: implementation of the CPingPong class.
//
//////////////////////////////////////////////////////////////////////


#include "PingPong.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPingPong::CPingPong()
{
	m_kx = 150;//1m = 150像素
	m_ky = 150;


	//侧视图中原点在画布中的像素位置
    m_YDCST.setX(100);
    m_YDCST.setY(150);

	//俯视图中原点在画布中的像素位置
    m_YDFST.setX(190);
    m_YDFST.setY(650);

	
	//球桌的长和宽（米）
	m_TableLength = 2.74;
	m_TableWidth = 1.525;
	//球网高度（米）
	m_NetHeight = 0.1525;

	//T0时刻击球点位置(米)，相对于实际原点
	m_x = 0.7;
	m_y = 0;
	m_z = 0.6;

	//t0时刻的位移存入数组
	m_xGJ[0] = m_x;
	m_yGJ[0] = m_y;
	m_zGJ[0] = m_z;

	
	//T0时刻各个方向的速度(m/s)，相对于实际原点
	m_Vx = 0.4;
	m_Vy = 3;
	m_Vz = 2;

	//t0时刻的速度存入数组
	m_VxGJ[0] = m_Vx;
	m_VyGJ[0] = m_Vy;
	m_VzGJ[0] = m_Vz;
	
	
	
	m_g = 9.8;//重力加速度

	m_nxGJ = 1;
	m_nyGJ = 1;
	m_nzGJ = 1;
	m_nVxGJ = 1;
	m_nVyGJ = 1;
	m_nVzGJ = 1;

}

CPingPong::~CPingPong()
{

}

void CPingPong::Draw(QPainter *p,int nPic)
{
    pDC = p;
	DrawTable_CST();
	DrawBall_CST();
	DrawTable_FST();
	DrawBall_FST();
	if(nPic==1)
		DrawCurve_S();
	if(nPic==2)
		DrawCurve_V();
}

void CPingPong::DrawTable_CST()
{//侧视图的桌子
	
	//桌面
    pDC->drawLine(m_YDCST.x(),m_YDCST.y(),m_YDCST.x()+m_TableLength*m_kx,m_YDCST.y());


	//球网
    pDC->drawLine(m_YDCST.x()+m_TableLength/2.0*m_kx,m_YDCST.y(),m_YDCST.x()+m_TableLength/2.0*m_kx,m_YDCST.y()-m_NetHeight*m_kx);
	
}

void CPingPong::DrawTable_FST()
{//俯视图的桌子
	
	//桌面(左上点与右下点)
    pDC->drawRect(m_YDFST.x(),m_YDFST.y()-m_TableLength*m_ky,m_TableWidth*m_kx,m_TableLength*m_ky);

	
	//球网
    pDC->drawLine(m_YDFST.x()-10,m_YDFST.y()-m_TableLength*m_ky/2.0,m_YDFST.x()+m_TableWidth*m_kx+10,m_YDFST.y()-m_TableLength*m_ky/2.0);

}

void CPingPong::DrawBall_CST()
{//侧视图的小球运动，只涉及m_y与m_z

	int x,y,r;
    x = m_YDCST.x()+m_y*m_kx;//对应着实际坐标
    y = m_YDCST.y()-m_z*m_ky;
	r = 3;
    pDC->drawEllipse(x-r,y-r,2*r,2*r);

}

void CPingPong::DrawBall_FST()
{//俯视图的小球运动，只涉及m_x与m_y

	int x,y,r;
    x = m_YDFST.x()+m_x*m_kx;//对应着实际坐标
    y = m_YDFST.y()-m_y*m_ky;
	r = 3;
    pDC->drawEllipse(x-r,y-r,2*r,2*r);

}

void CPingPong::Move()
{
	float deltaT = 0.04;//时间间隔（秒）

	//以下为Ti时刻瞬时值

	//水平方向为匀速运动
	m_x += m_Vx*deltaT;
	m_y += m_Vy*deltaT;
	m_z += m_Vz*deltaT-1/2.0*m_g*deltaT*deltaT;
	
	
	//竖直方向为上抛，速度受加速度影响
	m_Vz = m_Vz-m_g*deltaT;
	
	//如果下一秒m_z<=0，则反弹
	if((m_z+m_Vz*deltaT-1/2.0*m_g*deltaT*deltaT)<=0)
		m_Vz = -m_Vz*0.8;
		



	m_xGJ[m_nxGJ] = m_x;
	m_yGJ[m_nyGJ] = m_y;
	m_zGJ[m_nzGJ] = m_z;

	m_VxGJ[m_nVxGJ] = m_Vx;
	m_VyGJ[m_nVyGJ] = m_Vy;
	m_VzGJ[m_nVzGJ] = m_Vz;

	m_nxGJ++;
	m_nyGJ++;
	m_nzGJ++;
	m_nVxGJ++;
	m_nVyGJ++;
	m_nVzGJ++;


	

}

void CPingPong::DrawCurve_S()
{//画位移曲线
	
	int X,Y,xLength,yLength;//曲线坐标轴原点坐标，与坐标轴长度
    X = 800;
    Y = 450;
	xLength = 700;
	yLength = 500;

	//原点(600,350)
    pDC->drawLine(X,Y,X+xLength,Y);

    pDC->drawLine(X,Y-yLength/2,X,Y+yLength/2);

	
	//画刻度
    QString str;
	int i;
	for(i = 1;i<=70;i++)
	{
        pDC->drawLine(X+i*10,Y,X+i*10,Y-3);
		if(i%5==0)
		{
            QString str = QString::number(i * 0.04, 'f', 1); // 格式化浮点数为字符串，保留一位小数
            pDC->drawText(X + i * 10 - 10, Y + 10, str); // 在指定位置绘制文本
		}
	}
    pDC->drawText(X+i*10+10,Y+5,"单位：秒");

//	pDC->MoveTo(X,Y);//画y上半轴刻度
	for(i = 1;i<=25;i++)//250像素25刻度，每格10px表示0.1m
	{
        pDC->drawLine(X,Y-i*10,X+3,Y-i*10);
		if(i%5==0)
		{
            QString str = QString::number(i * 0.1, 'f', 1); // 格式化浮点数为字符串，保留一位小数
            pDC->drawText(X-25,Y-i*10-8,str); // 在指定位置绘制文本
		}
	}
    pDC->drawText(X-25,Y-i*10-20,"单位：米");

//	pDC->MoveTo(X,Y);//画y下半轴刻度
	for(i = 1;i<=25;i++)//250像素25刻度，每格10px表示0.1m
	{
        pDC->drawLine(X,Y+i*10,X+3,Y+i*10);
		if(i%5==0)
		{
            QString str = QString::number(-i * 0.1, 'f', 1); // 格式化浮点数为字符串，保留一位小数
            pDC->drawText(X-25,Y+i*10-8,str); // 在指定位置绘制文本
		}
	}
	

    QPen redPen(Qt::red);//x
    QPen bluePen(Qt::blue);//y
    QPen greenPen(Qt::green);//z

    pDC->setPen(redPen); // 设置画笔颜色为红色
	float Px,Py,Pz;

    for(i = 1;i<m_nxGJ;i++)
    {
        Px = (m_xGJ[i]/0.1)*10;
        pDC->drawLine(X+(i-1)*10,Y-(m_xGJ[i-1]/0.1)*10,X+i*10,Y-Px);
	}

    pDC->setPen(bluePen); // 设置画笔颜色为蓝色
	for(i = 1;i<m_nyGJ;i++)
	{
		Py = (m_yGJ[i]/0.1)*10;
        pDC->drawLine(X+(i-1)*10,Y-(m_yGJ[i-1]/0.1)*10,X+i*10,Y-Py);
	}
    pDC->setPen(greenPen);//绿色

	for(i = 1;i<m_nzGJ;i++)
	{
		Pz = (m_zGJ[i]/0.1)*10;
        pDC->drawLine(X+(i-1)*10,Y-(m_zGJ[i-1]/0.1)*10,X+i*10,Y-Pz);
	}

}

void CPingPong::DrawCurve_V()
{//画速度曲线
		
	int X,Y,xLength,yLength;//曲线坐标轴原点坐标，与坐标轴长度
    X = 800;
    Y = 450;
	xLength = 700;
	yLength = 600;

	//原点(600,350)
    pDC->drawLine(X,Y,X+xLength,Y);
    pDC->drawLine(X,Y-yLength/2,X,Y+yLength/2);

	//画刻度
    QString str;
	int i;
	for(i = 1;i<=70;i++)
	{
        pDC->drawLine(X+i*10,Y,X+i*10,Y-3);
		if(i%5==0)
		{
            QString str = QString::number(i * 0.04, 'f', 1); // 格式化浮点数为字符串，保留一位小数
            pDC->drawText(X + i * 10 - 10, Y + 10, str); // 在指定位置绘制文本
		}
	}
    pDC->drawText(X+i*10+10,Y+5,"单位：秒");

//	pDC->MoveTo(X,Y);//画y上半轴刻度
	for(i = 1;i<=30;i++)//300像素30刻度，每格10px表示0.2m/s
	{
        pDC->drawLine(X,Y-i*10,X+3,Y-i*10);
		if(i%5==0)
		{
            QString str = QString::number(i * 0.2, 'f', 1); // 格式化浮点数为字符串，保留一位小数
            pDC->drawText(X-25,Y-i*10-8,str); // 在指定位置绘制文本
		}
	}
    pDC->drawText(X-25,Y-i*10-20,"单位：米/秒");

//	pDC->MoveTo(X,Y);//画y下半轴刻度
	for(i = 1;i<=30;i++)//300像305刻度，每格10px表示0.2m/s
	{
        pDC->drawLine(X,Y+i*10,X+3,Y+i*10);
		if(i%5==0)
		{
            QString str = QString::number(-i * 0.2, 'f', 1); // 格式化浮点数为字符串，保留一位小数
            pDC->drawText(X-25,Y+i*10-8,str); // 在指定位置绘制文本
		}
	}
	

    QPen redPen(Qt::red);
    QPen bluePen(Qt::blue);
    QPen greenPen(Qt::green);

    pDC->setPen(redPen);
	float Px,Py,Pz;
	for(i = 1;i<m_nVxGJ;i++)
    {
        Px = (m_VxGJ[i]/0.2)*10;
        pDC->drawLine(X+(i-1)*10,Y-(m_VxGJ[i-1]/0.2)*10,X+i*10,Y-Px);

	}

    pDC->setPen(bluePen); // 设置画笔颜色为蓝色
	for(i = 1;i<m_nVyGJ;i++)
    {
        Py = (m_VyGJ[i]/0.2)*10;
        pDC->drawLine(X+(i-1)*10,Y-(m_VyGJ[i-1]/0.2)*10,X+i*10,Y-Py);

	}

    pDC->setPen(greenPen); // 设置画笔颜色为绿色
	for(i = 1;i<m_nVzGJ;i++)
    {
        Pz = (m_VzGJ[i]/0.2)*10;
        pDC->drawLine(X+(i-1)*10,Y-(m_VzGJ[i-1]/0.2)*10,X+i*10,Y-Pz);

	}


}
