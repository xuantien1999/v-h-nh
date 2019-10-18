//#include "StdAfx.h"
#include "stdafx.h"
#include "nutbam.h"



nutbam::nutbam()
{
}
void nutbam::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}
void nutbam::hcn(CClientDC *pDC)
{
	hcn1.thietlap(x1, y1, x2, y2);
	hcn1.vehinh(pDC);
}
void nutbam::hv(CClientDC *pDC)
{
	hv1.thietlap(x1, y1, x2, y2);
	hv1.vehinh(pDC);
}
void nutbam::htron(CClientDC *pDC)
{
	htron1.thietlap(x1, y1, x2, y2);
	htron1.vehinh(pDC);
}
void nutbam::tg(CClientDC *pDC)
{
	tg1.thietlap(x1, y1, x2, y2);
	tg1.vehinh(pDC);
}
void nutbam::dxu(CClientDC *pDC)
{
	dx.thietlap(x1, y1, x2, y2);
	dx.vehinh(pDC);
}
void nutbam::nsao(CClientDC *pDC)
{
	ns1.thietlap(x1, y1, x2, y2);
	ns1.vehinh(pDC);
}
void nutbam::xemlai(CClientDC *pDC)
{
	xem_lai.thietlap(x1, y1, x2, y2);
	xem_lai.vehinh(pDC);
}
void nutbam::phongto(CClientDC *pDC)
{
	phong_to.thietlap(x1, y1, x2, y2);
	phong_to.vehinh(pDC);
}
void nutbam::thunho(CClientDC *pDC)
{
	thu_nho.thietlap(x1, y1, x2, y2);
	thu_nho.vehinh(pDC);
}
void nutbam::dichuyen(CClientDC *pDC)
{
	di_chuyen.thietlap(x1, y1, x2, y2);
	di_chuyen.vehinh(pDC);
}
void nutbam::xoa(CClientDC *pDC)
{
	xoa_hinh.thietlap(x1, y1, x2, y2);
	xoa_hinh.vehinh(pDC);
}
int nutbam::chonhinh(CPoint p)
{
	int kt = 0;
	if (p.x > x1&&p.x<x2&&p.y>y1&&p.y < y2)
		kt = 1;
	return kt;
}
nutbam::~nutbam()
{
}
