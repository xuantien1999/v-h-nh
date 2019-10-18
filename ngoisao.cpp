#include "StdAfx.h"
#include "ngoisao.h"





ngoisao::ngoisao()
{
}
ngoisao::ngoisao(CPoint p1, CPoint p2)
{
	x1 = p1.x;
	y1 = p1.y;
	x2 = p2.x;
	y2 = p2.y;
}
void ngoisao::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
	
}
void ngoisao::vehinh(CClientDC *pDC)
{
	x3 = x2 - (x2 - x1) / 8; y3 = y1;
	x4 = x1 + (x2 - x1) / 8; y4 = y2;
	x5 = ((x2 + x1) / 2); y5 = y1 - (y2 - y1) / 50;
	x6 = x2 + (x2 - x1) / 9; y6 = (y2 + y1) / 2.2;
	x7 = x1 - (x2 - x1) / 9; y7 = y6;
	pDC->MoveTo(x5, y5); pDC->LineTo(x2, y2);
	pDC->MoveTo(x2, y2); pDC->LineTo(x7, y7);
	pDC->MoveTo(x7, y7); pDC->LineTo(x6, y6);
	pDC->MoveTo(x6, y6); pDC->LineTo(x4, y4);
	pDC->MoveTo(x4, y4); pDC->LineTo(x5, y5);
}
int ngoisao::chonhinh(CPoint p)
{
	int kq = 0;
	if (p.x > x1 && p.y > y1 && p.x < x2 && p.y < y2)
	{
		kq = 1;
	}
	return kq;
}
void ngoisao::xuatlai(CClientDC *pDC)
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
	t = "Hinh ngoi sao";				//Xuat chu khi chon vao bieu tuong
	pDC->SetTextColor(RGB(0, 150, 150));
	pDC->TextOutW(10, 70, t);
}
void ngoisao::phongto()
{
	x1 -= 10; y1 -= 10; x2 += 10; y2 += 10;

}
void ngoisao::phongtovavehinh(CClientDC *pDC)
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

void ngoisao::thunho()
{
	x1 += 10; y1 += 10; x2 -= 10; y2 -= 10;
}
void ngoisao::thunhovavehinh(CClientDC *pDC)
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
void ngoisao::xoahinh(CClientDC *pDC)
{
	CPen *pen;
	//CBrush *brush;
	pen = new CPen(PS_SOLID, 1, RGB(255, 255, 255));
	//brush = new CBrush(RGB(255, 255, 255));
	pDC->SelectObject(pen);
	//pDC->SelectObject(brush);
	vehinh(pDC);
}
void ngoisao::dichuyen(int dx, int dy, CClientDC *pDC)
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
ngoisao::~ngoisao()
{
}
