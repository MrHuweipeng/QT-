// WRJ.h: interface for the CWRJ class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WRJ_H__FF293B11_C2DF_49E7_91C2_D80371387F13__INCLUDED_)
#define AFX_WRJ_H__FF293B11_C2DF_49E7_91C2_D80371387F13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NoBodyCar.h"
#include <QPainter>
class CWRJ : public CNoBodyCar
{
public:
    void MoveWRJ();
	void MoveLXJ();
	void DrawWRJ();
	void DrawMoveLuoXuanJiang(int x,int y);
	void Draw(CDC *p);
	CWRJ();
	virtual ~CWRJ();
	float m_WJ_r,m_WJ_x,m_WJ_y;
	float m_LXJ_JSD,m_LXJ_JD,m_WRJ_ND;
	float m_LXJ_L;
    float m_kWRJ,m_WRJL;



};

#endif // !defined(AFX_WRJ_H__FF293B11_C2DF_49E7_91C2_D80371387F13__INCLUDED_)
