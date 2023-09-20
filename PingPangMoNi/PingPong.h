// PingPong.h: interface for the CPingPong class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PINGPONG_H__D5585D3C_AFC7_45A4_9F98_DA4A4720678F__INCLUDED_)
#define AFX_PINGPONG_H__D5585D3C_AFC7_45A4_9F98_DA4A4720678F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <QPoint>
#include <QPaintEvent>
#include<QPainter>

class CPingPong  
{
public:
	
	float m_kx,m_ky;//比例尺
	
	//实际原点在画布中对应不同视图的像素位置
    QPoint m_YDCST,m_YDFST;
	
	float m_TableLength,m_TableWidth;//球桌的长和宽（米）
	float m_NetHeight;//球网高度（米）

	float m_x,m_y,m_z;//乒乓球距离坐标原点的位移（米）
	float m_xGJ[1000],m_yGJ[1000],m_zGJ[1000];//位移轨迹
	
	float m_Vx,m_Vy,m_Vz;//各个方向的速度(m/s)  Vx
	float m_VxGJ[1000],m_VyGJ[1000],m_VzGJ[1000];//Ti时刻速度轨迹
	

	float m_g;//重力加速度
	
	//数组下标
	int m_nxGJ,m_nyGJ,m_nzGJ;
	int m_nVxGJ,m_nVyGJ,m_nVzGJ;



	void DrawCurve_V();
	void DrawCurve_S();
	void Move();
	void DrawBall_CST();
	void DrawBall_FST();
	void DrawTable_CST();
	void DrawTable_FST();
    void Draw(QPainter *p,int nPic);

    QPainter *pDC;
	CPingPong();
	virtual ~CPingPong();

};

#endif // !defined(AFX_PINGPONG_H__D5585D3C_AFC7_45A4_9F98_DA4A4720678F__INCLUDED_)
