#pragma once
#include "hinh.h"
#include "hcn.h"
#include "hinhvuong.h"
#include "hinhtron.h"
#include "tamgiac.h"
#include"dongxu.h"
#include"ngoisao.h"
class nutbam :public hinh
{
public:
	int x1, x2, y1, y2;
	hcn hcn1, xem_lai, phong_to, thu_nho, di_chuyen, xoa_hinh;
	hinhvuong hv1;
	hinhtron htron1;
	tamgiac tg1;
	dongxu dx;
	ngoisao ns1;
	void thietlap(int mx1, int my1, int mx2, int my2);
	void hv(CClientDC *pDC);
	void hcn(CClientDC *pDC);
	void htron(CClientDC *pDC);
	void tg(CClientDC *pDC);
	void dxu(CClientDC *pDC);
	void nsao(CClientDC *pDC);
	void xemlai(CClientDC *pDC);
	void phongto(CClientDC *pDC);
	void thunho(CClientDC *pDC);
	void dichuyen(CClientDC *pDC);
	void xoa(CClientDC *pDC);
	int chonhinh(CPoint p);
	nutbam();
	~nutbam();
};

