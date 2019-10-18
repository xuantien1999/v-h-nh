//#include "StdAfx.h"
#include "stdafx.h"
#include "dongxu.h"



dongxu::dongxu()
{
}
dongxu::dongxu(CPoint p1, CPoint p2)
{
	x1 = p1.x;
	y1 = p1.y;
	x2 = p2.x;
	y2 = p2.y;
}
void dongxu::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}
void dongxu::vehinh(CClientDC *pDC)
{
	dx1.thietlap(x1, y1, x2, y2);
	dx2.thietlap(x1 + 30, y1 + 30, x2 - 30, y2 - 30);
	dx1.vehinh(pDC);
	dx2.vehinh(pDC);
}
int dongxu::chonhinh(CPoint p)
{
	int kq = 0;
	if (p.x > x1 && p.y > y1 && p.x < x2 && p.y < y2)
	{
		kq = 1;
	}
	return kq;
}
void dongxu::phongto()
{
	x1 -= 10; y1 -= 10; x2 += 10; y2 += 10;

}
void dongxu::phongtovavehinh(CClientDC *pDC)
{
	if (y1 > 67)
	{
		CPen *pen, *pen2;
		CBrush *brush;
		pen = new CPen(PS_SOLID, 1, RGB(255, 255, 255));
		brush = new CBrush(RGB(255, 255, 255));
		pDC->SelectObject(pen);
		pDC->SelectObject(brush);
		vehinh(pDC);
		phongto();
		thietlap(x1, y1, x2, y2);
		pen2 = new CPen(PS_SOLID, 1, RGB(0, 0, 0));
		pDC->SelectObject(pen2);
		pDC->SelectObject(brush);
		vehinh(pDC);
	}
}
void dongxu::thunho()
{
	x1 += 10; y1 += 10; x2 -= 10; y2 -= 10;
}
void dongxu::thunhovavehinh(CClientDC *pDC)
{
	if (x2 - x1 > 0 && y2 - y1 > 0)
	{
		CPen *pen, *pen2;
		CBrush *brush;
		pen = new CPen(PS_SOLID, 1, RGB(255, 255, 255));
		brush = new CBrush(RGB(255, 255, 255));
		pDC->SelectObject(pen);
		pDC->SelectObject(brush);
		vehinh(pDC);
		thunho();
		thietlap(x1, y1, x2, y2);
		pen2 = new CPen(PS_SOLID, 1, RGB(0, 0, 0));
		pDC->SelectObject(pen2);
		pDC->SelectObject(brush);
		vehinh(pDC);
	}
}
void dongxu::xuatlai(CClientDC *pDC)
{
	CPen *pen2, *penn;			//khai bao but mau
	penn = new CPen(PS_SOLID, 2, RGB(255, 255, 255));
	pen2 = new CPen(PS_SOLID, 2, RGB(236, 236, 236));

	CBrush *B1, *B2;						//khai bao mau to
	B1 = new CBrush(RGB(90, 90, 90));
	B2 = new CBrush(RGB(236, 236, 236));
	CBrush *olderbrush;
	CPen *older;
	olderbrush = pDC->SelectObject(B2);
	older = pDC->SelectObject(penn);
	pDC->Rectangle(0, 67, 129, 90);
	older = pDC->SelectObject(pen2);
	pDC->Rectangle(0, 91, 129, 200);
	CString t;
	t = "Hinh dong xu";				//Xuat chu khi chon vao bieu tuong
	pDC->SetTextColor(RGB(0, 150, 150));
	pDC->TextOutW(10, 70, t);
	CString dt, a, cv, b;
	a = "Dien tich: ";
	dt.Format(_T("%d"), dientich());
	pDC->SetTextColor(RGB(0, 150, 150));
	pDC->TextOutW(12, 92, a);
	pDC->TextOutW(82, 92, dt);
	b = "Chu vi: ";
	cv.Format(_T("%d"), chuvi());
	pDC->TextOutW(12, 112, b);
	pDC->TextOutW(82, 112, cv);
}
void dongxu::xoahinh(CClientDC *pDC)
{
	CPen *pen;
	//CBrush *brush;
	pen = new CPen(PS_SOLID, 1, RGB(255, 255, 255));
	//brush = new CBrush(RGB(255, 255, 255));
	pDC->SelectObject(pen);
	//pDC->SelectObject(brush);
	dx1.vehinh(pDC);
	dx2.vehinh(pDC);
}
void dongxu::dichuyen(int dx, int dy, CClientDC *pDC)
{
	CPen *pen, *pen2;
	CBrush *brush;
	pen = new CPen(PS_SOLID, 1, RGB(255, 255, 255));
	brush = new CBrush(RGB(255, 255, 255));
	pDC->SelectObject(pen);
	pDC->SelectObject(brush);
	vehinh(pDC);
	x1 = x1 + dx;
	x2 += dx;
	y1 += dy;
	y2 += dy;
	thietlap(x1, y1, x2, y2);
	pen2 = new CPen(PS_SOLID, 1, RGB(0, 0, 0));
	pDC->SelectObject(pen2);
	pDC->SelectObject(brush);
	vehinh(pDC);
}
dongxu::~dongxu()
{
}
