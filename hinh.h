#pragma once
class hinh
{
public:
	hinh(void);
	virtual void vehinh(CClientDC *pDC);
	virtual int chonhinh(CPoint p);
	virtual int dientich();
	virtual int chuvi();
	virtual void xuatlai(CClientDC *pDC);
	virtual void phongtovavehinh(CClientDC *pDC);
	virtual void thunhovavehinh(CClientDC *pDC);
	virtual void xoahinh(CClientDC *pDC);
	virtual void dichuyen(int dx, int dy, CClientDC *pDC);
	~hinh(void);
};

