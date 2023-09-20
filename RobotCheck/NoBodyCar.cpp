// NoBodyCar.cpp: implementation of the CNoBodyCar class.
//
//////////////////////////////////////////////////////////////////////

#include "NoBodyCar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNoBodyCar::CNoBodyCar()
{
	m_x = 10;
	m_y = 0;
	m_vx = 0;
	m_vy = 0;
	m_w = 0.8;
	m_kx = 1900 / 1000.0;
	m_ky = - 950 / 1000.0;
	m_kCar = 30;

	m_YD.x = 800;
	m_YD.y = 700;

    m_JSD = 100;//单位度/s
    m_CirR = 50;//单位3m
	m_WZ = 12;//12点方向
	m_JD = 0;
	m_v = 60;
	m_deltat = 0.1;
	m_FX = 1;
	m_nLX = 0;
	m_nMBD = 0;
	m_BJ = 0;
	//浓度
	m_ND = 0;
	m_CirNDCS.jd = 0;	
	m_CirNDCS.r = 100;
	m_CirNDCS.w = 100;//度/s
	m_CirNDCS.x = m_x;
	m_CirNDCS.y = m_y;
    InitialCirND();
}

CNoBodyCar::~CNoBodyCar()
{

}

void CNoBodyCar::Draw(CDC *p)
{
	pDC = p;
    int x,y;
    DrawTiaoShi();
	DrawCar();
    QString str = QString("小车感应浓度：%1").arg(m_ND, 0, 'f', 3);
	x = 1700;
    y = 40;
    pDC->drawText(x,y,str);
	DrawLuXian();

}

void CNoBodyCar::DrawCar()
{
	int x,y,w,h,r;
	//矩形
    QBrush *b = new QBrush;//创建画刷对象
    b->setColor(Qt::red);//给画刷设置颜色
    b->setStyle(Qt::SolidPattern);//设置填充风格
    pDC->setBrush(*b);//将画刷交给画家
	w = m_w * m_kCar;
	h = m_w / 3 * m_kCar;
	r = m_w / 6 * m_kCar;
	x = m_YD.x + m_x * m_kx;
	y = m_YD.y + m_y * m_ky;
    pDC->drawRect(x,y,w,h);
	//圆形
	x += w + r;
	y += h - r;
    pDC->drawEllipse(x - r,y - r,2 * r,2 * r);

	
	
}

void CNoBodyCar::MoveDianNaDaoNa()
{
	m_x = m_MBx;
	m_y = m_MBy;
}

void CNoBodyCar::MoveCircleSport()
{
//    qDebug("22");
	m_JD += m_JSD * m_FX * m_deltat;
    m_x = m_YXx + m_CirR * cos(m_JD / 180.0 * PI);
    m_y = m_YXy + m_CirR * sin(m_JD / 180.0 * PI);
}

void CNoBodyCar::MoveYunSuYunDong()
{

	m_d = sqrt((m_MBx - m_x) * (m_MBx - m_x) + (m_MBy - m_y) * (m_MBy - m_y));

	m_vx = m_v * (m_MBx - m_x)/m_d;
	m_vy = m_v * (m_MBy - m_y)/m_d;
	if(m_d > 4)
	{
 		m_x += m_vx * m_deltat;
 		m_y += m_vy * m_deltat;	

	}
 

 }	


void CNoBodyCar::ChuLiLBD(int x,int y)
{
    m_MBx = (x - m_YD.x)/m_kx;
    m_MBy = (y - m_YD.y)/m_ky;
	if(m_CarZT == DNDN)
	{
		MoveDianNaDaoNa();
	}
	if(m_CarZT == LUXIAN)
	{
		QiuLuXianZB();
	}
}

void CNoBodyCar::Move()
{
	if(m_CarZT == YSYD)
		MoveYunSuYunDong();
	if(m_CarZT == GJYD)
		MoveCircleSport();
	if(m_CarZT == DNDN)
		MoveDianNaDaoNa();
	if(m_CarZT == LUXIAN)
		MoveLuXian();
		
}

void CNoBodyCar::QiuCircleDot()
{
	m_JD = (12 + 3 - m_WZ) * (360 / 12);
	m_YXx = m_x - m_CirR * cos((180-m_JD)/ 180.0 * PI);
	m_YXy = m_y - m_CirR * sin((180-m_JD) / 180.0 * PI);
	
}

void CNoBodyCar::DrawLuXian()
{
    int x,y,x1,y1,i;
    QPen pen(QColor(0, 128, 0));
    pen.setWidth(2);
    pDC->setPen(pen);
	x = m_YD.x + m_LX[0][0] * m_kx;
	y = m_YD.y + m_LX[0][1] * m_ky;
	for (i=1;i<m_nLX;i++)
	{

        x1 = m_YD.x + m_LX[i][0] * m_kx;
        y1 = m_YD.y + m_LX[i][1] * m_ky;
        pDC->drawLine(x,y,x1,y1);
        x = x1;
        y = y1;
	}

}

void CNoBodyCar::MoveLuXian()
{
	float d;
	d = sqrt((m_LX[m_nMBD][0] - m_x) * (m_LX[m_nMBD][0] - m_x) + (m_LX[m_nMBD][1] - m_y) * (m_LX[m_nMBD][1] - m_y));

	if(d > 4)
	{
		m_vx = m_v * (m_LX[m_nMBD][0] - m_x)/d;
		m_vy = m_v * (m_LX[m_nMBD][1] - m_y)/d;

		m_x += m_vx * m_deltat;
	    m_y += m_vy * m_deltat;	

	}
	else
	{
		m_nMBD++;
		if(m_nMBD == m_nLX - 1)//由于双击右键所以要减去
		{
			m_nLX = 0;
			m_BJ = 1;
		}
	}


}

void CNoBodyCar::QiuLuXianZB()
{
	m_LX[m_nLX][0] = m_MBx;
	m_LX[m_nLX][1] = m_MBy;
	m_nLX++;
}





void CNoBodyCar::ZhuanQuanSearchXieLou()
{
	if(m_CirNDCS.jd < 360)
	{
		m_x = m_CirNDCS.x + m_CirNDCS.r * cos(m_CirNDCS.jd / 180.0 * PI);//确定小车位置
		m_y = m_CirNDCS.y + m_CirNDCS.r * sin(m_CirNDCS.jd / 180.0 * PI);
		m_CirNDCS.jd += m_CirNDCS.w * m_deltat;//更新角度

		if(m_CirNDCS.Max < m_ND)
		{
			m_CirNDCS.Max = m_ND;//更新最大值
			m_CirNDCS.xMax = m_x;
			m_CirNDCS.yMax = m_y;

		}
		else if(m_CirNDCS.Min > m_ND)
		{
			m_CirNDCS.Min = m_ND;//更新最小值
			m_CirNDCS.xMin = m_x;
			m_CirNDCS.yMin = m_y;	
		}
	
	}
	else
	{
		m_MBx = m_CirNDCS.x + (m_CirNDCS.xMax - m_CirNDCS.xMin);//更新匀速到的目标点
		m_MBy = m_CirNDCS.y + (m_CirNDCS.yMax - m_CirNDCS.yMin);
		MoveYunSuYunDong();//运动过去
		if(m_d < 4)//到达后再下一轮的转圈以及初始化运动轨迹
		{
			m_CirNDCS.jd = 0;
			m_CirNDCS.r *= 0.9;
			m_CirNDCS.x = m_x;
			m_CirNDCS.y = m_y;
			InitialCirND();
			
		}

	}

}

void CNoBodyCar::DrawTiaoShi()
{
	int r,x,y;
    QBrush *b = new QBrush;//创建画刷对象
    b->setColor(Qt::red);//给画刷设置颜色
    b->setStyle(Qt::SolidPattern);//设置填充风格
    pDC->setBrush(*b);//将画刷交给画家

	x = m_YD.x + m_CirNDCS.xMin * m_kx;
	y = m_YD.y + m_CirNDCS.yMin * m_ky;
	r = 5;
    pDC->drawEllipse(x - r,y - r,2 * r,2 * r);

	x = m_YD.x + m_CirNDCS.xMax * m_kx;
	y = m_YD.y + m_CirNDCS.yMax * m_ky;
	r = 10;
    pDC->drawEllipse(x - r,y - r,2 * r,2 * r);

}


void CNoBodyCar::InitialCirND()
{

	m_CirNDCS.Max = -1;
	m_CirNDCS.Min = 10000;
	m_CirNDCS.xMax = m_x;
	m_CirNDCS.yMax = m_y;
	m_CirNDCS.xMin = m_x;
	m_CirNDCS.yMax = m_y;
}
