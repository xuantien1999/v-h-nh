#pragma once
#include"hinh.h"
class ngoisao: public hinh
{
public:
	int x1, x2, y1, y2;
	int x3, y3, x4, y4;
	int x5, y5;
	int x6, y6;
	int x7, y7;
	ngoisao(CPoint p1, CPoint p2);
	int chonhinh(CPoint p);
	void xuatlai(CClientDC *pDC);
	void vehinh(CClientDC *pDC);
	void thietlap(int mx1, int my1, int mx2, int my2);
	void phongto();
	void phongtovavehinh(CClientDC *pDC);
	void thunho();
	void thunhovavehinh(CClientDC *pDC);
	void xoahinh(CClientDC *pDC);
	void dichuyen(int dx, int dy, CClientDC *pDC);
	ngoisao();
	~ngoisao();
};

