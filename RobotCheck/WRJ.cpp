// WRJ.cpp: implementation of the CWRJ class.
//
//////////////////////////////////////////////////////////////////////

#include "WRJ.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWRJ::CWRJ()
{
	m_WJ_r = m_w / 2;
	m_LXJ_JSD = 60;
    m_LXJ_JD = 0;
	m_LXJ_L = m_w / 4;
	m_WJ_x = 100;//m
	m_WJ_y = 100;
	m_kWRJ = 100;
	m_WRJ_ND = 0;
    m_WRJL = 50;

	

}

CWRJ::~CWRJ()
{

}

void CWRJ::Draw(CDC *p)
{
	int x,y;
	pDC = p;
	DrawWRJ();
    QString str = QString("无人机感应浓度：%1").arg(m_WRJ_ND,0,'f',3);
	x = 1700;
    y = 60;
    pDC->drawText(x,y,str);

	
}


void CWRJ::DrawMoveLuoXuanJiang(int LXJx,int LXJy)
{

	int x,y;
	x = LXJx + (m_LXJ_L / 2 * m_kWRJ)  * cos(m_LXJ_JD + 0 / 180.0 * PI); 
	y = LXJy + (m_LXJ_L / 2 * m_kWRJ)  * sin(m_LXJ_JD + 0 / 180.0 * PI);
    pDC->drawLine(LXJx,LXJy,x,y);

	x = LXJx + (m_LXJ_L / 2 * m_kWRJ)  * cos(m_LXJ_JD + 90 / 180.0 * PI); 
	y = LXJy + (m_LXJ_L / 2 * m_kWRJ)  * sin(m_LXJ_JD + 90 / 180.0 * PI);
    pDC->drawLine(LXJx,LXJy,x,y);

	x = LXJx + (m_LXJ_L / 2 * m_kWRJ)  * cos(m_LXJ_JD + 180 / 180.0 * PI); 
	y = LXJy + (m_LXJ_L / 2 * m_kWRJ)  * sin(m_LXJ_JD + 180 / 180.0 * PI);
    pDC->drawLine(LXJx,LXJy,x,y);

	x = LXJx + (m_LXJ_L / 2 * m_kWRJ)  * cos(m_LXJ_JD + 270 / 180.0 * PI); 
	y = LXJy + (m_LXJ_L / 2 * m_kWRJ)  * sin(m_LXJ_JD + 270 / 180.0 * PI);
    pDC->drawLine(LXJx,LXJy,x,y);
	


	

}

void CWRJ::DrawWRJ()
{

    QBrush *b = new QBrush;//创建画刷对象
    b->setColor(Qt::red);//给画刷设置颜色
    b->setStyle(Qt::SolidPattern);//设置填充风格
    pDC->setBrush(*b);//将画刷交给画家
    int x,y,r,InitX,InitY,x1,y1;
    InitX = m_YD.x + m_WJ_x * m_kx;
    InitY = m_YD.y + m_WJ_y * m_ky;
	r = m_WJ_r * m_kCar;
	x = InitX;
	y = InitY;
    pDC->drawEllipse(x - r,y - r,2 * r,2 * r);

    QPen pen(QColor(0, 128, 0));
    pen.setWidth(2);
    pDC->setPen(pen);
	//左边螺旋桨
    x = InitX;
    y = InitY;
    x1 = x - m_WRJL;
    pDC->drawLine(x,y,x1,y);
    DrawMoveLuoXuanJiang(x1,y);
	//右边螺旋桨
	x = InitX;
	y = InitY;
    x1 = x + m_WRJL;
    pDC->drawLine(x,y,x1,y);
    DrawMoveLuoXuanJiang(x1,y);
	//上边螺旋桨
	x = InitX;
	y = InitY;
    y1 = y - m_WRJL;
    pDC->drawLine(x,y,x,y1);
    DrawMoveLuoXuanJiang(x,y1);
	//下边螺旋桨
	x = InitX;
	y = InitY;
    y1 = y + m_WRJL;
    pDC->drawLine(x,y,x,y1);
    DrawMoveLuoXuanJiang(x,y1);



	
}



void CWRJ::MoveLXJ()
{
	m_LXJ_JD += m_LXJ_JSD * m_deltat;
}

void CWRJ::MoveWRJ()
{
//	switch()//移动无人机
//	{
//		case 37:
//			m_WJ_x -= 6;
//		break;
//		case 38:
//			m_WJ_y += 6;
//		break;
//		case 39:
//			m_WJ_x += 6;
//		break;
//		case 40:
//			m_WJ_y -= 6;
//		break;
//	}
}
