// NoBodyCar.h: interface for the CNoBodyCar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOBODYCAR_H__66FF9ED9_C61A_4E68_9905_38F72BCA4FFA__INCLUDED_)
#define AFX_NOBODYCAR_H__66FF9ED9_C61A_4E68_9905_38F72BCA4FFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "math.h"
#include <QString>
#include <QPainter>
#include "cditu.h"
#define PI 3.141592
enum ZT{DNDN,YSYD,GJYD,LUXIAN,CSND,XZXLD};


typedef struct
{
	float r;
	float w;
	float Max,Min;//浓度最大值
	float xMax,yMax;
	float xMin,yMin;
	float x,y;
	float jd;
}SCircleNDCS;
class CNoBodyCar  
{
public:
	void InitialCirND();
	void DrawTiaoShi();
	void ZhuanQuanSearchXieLou();
	void QiuLuXianZB();
	void MoveLuXian();
	void DrawLuXian();
	void QiuCircleDot();
	void Move();
    void ChuLiLBD(int x,int y);
	void MoveCircleSport();
	void MoveDianNaDaoNa();
	void MoveYunSuYunDong();
	void DrawCar();
	void Draw(CDC *p);
	CNoBodyCar();
	virtual ~CNoBodyCar();
	CDC *pDC;
	CPoint m_YD;
	//小车
	float m_x,m_y;//相对原点
	float m_w;//小车宽
	float m_kCar;//小车的比例尺
	float m_kx,m_ky;
	int m_CarZT;
	float m_d;
	
	//运动
	float m_JSD,m_CirR,m_WZ;
	float m_JD;
	float m_vx,m_vy,m_v,m_deltat,m_FX;
	float m_MBx,m_MBy;
	float m_YXx,m_YXy;//圆心坐标
	//路线
	float m_LX[100][2];
	int m_nLX;
	int m_nMBD;
	int m_BJ;//小车停止的标记
	//寻找泄漏点
	float m_ND;
	SCircleNDCS m_CirNDCS;//圆上的浓度测试



	

};

#endif // !defined(AFX_NOBODYCAR_H__66FF9ED9_C61A_4E68_9905_38F72BCA4FFA__INCLUDED_)
