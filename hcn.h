#pragma once
#include "hinh.h"
class hcn :public hinh
{
private:

public:
	int x1, x2, y1, y2;
	hcn(CPoint p1, CPoint p2);
	void thietlap(int mx1, int my1, int mx2, int my2);
	void vehinh(CClientDC *pDC);
	int chonhinh(CPoint p);
	void phongto();
	void phongtovavehinh(CClientDC *pDC);
	void thunho();
	void thunhovavehinh(CClientDC *pDC);
	int dientich();
	int chuvi();
	void xuatlai(CClientDC *pDC);
	void xoahinh(CClientDC *pDC);
	void dichuyen(int dx, int dy, CClientDC *pDC);
	hcn();
	~hcn();


};

