
// udvhView.cpp : implementation of the CudvhView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "udvh.h"
#endif

#include "udvhDoc.h"
#include "udvhView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CudvhView

IMPLEMENT_DYNCREATE(CudvhView, CView)

BEGIN_MESSAGE_MAP(CudvhView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CudvhView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CudvhView construction/destruction

CudvhView::CudvhView()
{
	// TODO: add construction code here
	b1.thietlap(160, 20, 190, 40);//hcn
	b2.thietlap(215, 15, 245, 45);//hv
	b3.thietlap(260, 15, 290, 45);//htron
	b4.thietlap(310, 15, 340, 45);//tam giac
	b5.thietlap(360, 15, 410, 45);//dxu
	b6.thietlap(410, 15, 440, 45);
	b7.thietlap(500, 15, 560, 45);//xem lai
	pt.thietlap(570, 15, 600, 45);//phong to
	tn.thietlap(610, 15, 640, 45);//thu nho
	dc.thietlap(650, 15, 680, 45);//di chuyen
	xh.thietlap(690, 15, 720, 45);//xoa hinh
	// cac dieu kien ban dau
	n = 0;
	o1 = 0; o2 = 0; o3 = 0; o4 = 0; o5 = 0;
}

CudvhView::~CudvhView()
{
}

BOOL CudvhView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CudvhView drawing

void CudvhView::OnDraw(CDC* /*pDC*/)
{
	CudvhDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC pDC(this);
	CBrush *B1, *B2;							//khai bao mau but
	B1 = new CBrush(RGB(90, 90, 90));
	B2 = new CBrush(RGB(236, 236, 236));
	
	//khai bao mau to
	CPen *pen1, *pen2;
	pen1 = new CPen(PS_SOLID, 2, RGB(255, 255, 255));
	pen2 = new CPen(PS_SOLID, 1, RGB(236, 236, 236));

	menu1.thanhmenu(&pDC);
	menu1.sideba(&pDC);
	pDC.SelectObject(B1);
	pDC.SelectObject(pen1);
	b1.hcn(&pDC);
	b2.hv(&pDC);
	b3.htron(&pDC);
	b4.tg(&pDC);
	/*---ve nut dong xu----*/
	b5.htron(&pDC);
	pDC.SetBkColor(RGB(255, 255, 255));
	pDC.TextOutW(368, 22, _T("Xu"));
	/*---ve nut ngoi sao----*/
	b6.nsao(&pDC);
	/*---ve nut xem lai----*/
	b7.xemlai(&pDC);
	pDC.SetBkColor(RGB(90, 90, 90));
	pDC.TextOutW(505, 22, _T("Xem lai"));
	/*---ve nut phong to----*/
	pt.phongto(&pDC);
	pDC.SetBkColor(RGB(90, 90, 90));
	pDC.TextOutW(575, 22, _T("PT"));
	/*---ve nut thu nho----*/
	tn.thunho(&pDC);
	pDC.SetBkColor(RGB(90, 90, 90));
	pDC.TextOutW(615, 22, _T("TN"));
	/*---ve nut di chuyen----*/
	dc.dichuyen(&pDC);
	pDC.SetBkColor(RGB(90, 90, 90));
	pDC.TextOutW(655, 22, _T("DC"));
	/*---ve nut xoa hinh----*/
	xh.xoa(&pDC);
	pDC.SetBkColor(RGB(90, 90, 90));
	pDC.TextOutW(695, 22, _T("XH"));
	// TODO: add draw code for native data here
}


// CudvhView printing


void CudvhView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CudvhView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CudvhView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CudvhView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CudvhView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CudvhView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CudvhView diagnostics

#ifdef _DEBUG
void CudvhView::AssertValid() const
{
	CView::AssertValid();
}

void CudvhView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CudvhDoc* CudvhView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CudvhDoc)));
	return (CudvhDoc*)m_pDocument;
}
#endif //_DEBUG


// CudvhView message handlers


void CudvhView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p1.x = point.x;
	p1.y = point.y;
	CClientDC pDC(this);
	CPen *pen, *pen3, *pen2;				//khai bao but mau
	pen = new CPen(PS_SOLID, 2, RGB(162, 0, 124));
	pen2 = new CPen(PS_SOLID, 2, RGB(255, 255, 255));
	pen3 = new CPen(PS_SOLID, 2, RGB(236, 236, 236));
	CBrush *B1, *B2;		//khai bao mau to
	B1 = new CBrush(RGB(90, 90, 90));
	B2 = new CBrush(RGB(236, 236, 236));
	CBrush *olderB;
	CPen *older;

	//------- ve doi tuong hinh chu nhat ----------
	if (b1.chonhinh(p1) == 1)
	{
		if (o1 == 0)
		{
			o1 = 1;
			older = pDC.SelectObject(pen);
			olderB = pDC.SelectObject(B1);
			b1.hcn(&pDC);

			older = pDC.SelectObject(pen2);
			olderB = pDC.SelectObject(B1);
			b2.hv(&pDC);
			b3.htron(&pDC);
			b4.tg(&pDC);
			b5.htron(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(368, 22, _T("Xu"));
			b6.nsao(&pDC);
			b7.xemlai(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(505, 22, _T("Xem lai"));
			/*---ve nut phong to----*/
			pt.phongto(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(575, 22, _T("PT"));
			/*---ve nut thu nho----*/
			tn.thunho(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(615, 22, _T("TN"));
			/*---ve nut di chuyen----*/
			dc.dichuyen(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(655, 22, _T("DC"));
			/*---ve nut xoa hinh----*/
			xh.xoa(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(695, 22, _T("XH"));

			//Xuat chu tren side
			olderB = pDC.SelectObject(B2);
			older = pDC.SelectObject(pen2);
			pDC.Rectangle(0, 67, 129, 90);
			older = pDC.SelectObject(pen3);
			pDC.Rectangle(0, 91, 129, 200);
			CString a;
			a = "Hinh chu nhat";//Xuat chu khi chon vao bieu tuong
			pDC.SetTextColor(RGB(0, 150, 150));
			pDC.SetBkColor(RGB(255, 255, 255));
			pDC.TextOutW(10, 70, a);
		}
	}
	//------- ve doi tuong hinh vuong -------------
	if (b2.chonhinh(p1) == 1)
	{
		o1 = 0; o3 = 0; o4 = 0; o5 = 0; o6 = 0;
		if (o2 == 0)
		{
			o2 = 1;
			older = pDC.SelectObject(pen);
			olderB = pDC.SelectObject(B1);
			b2.hv(&pDC);

			older = pDC.SelectObject(pen2);
			olderB = pDC.SelectObject(B1);
			b1.hcn(&pDC);
			b3.htron(&pDC);
			b4.tg(&pDC);
			b5.htron(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(368, 22, _T("Xu"));
			b6.nsao(&pDC);
			b7.xemlai(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(505, 22, _T("Xem lai"));
			/*---ve nut phong to----*/
			pt.phongto(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(575, 22, _T("PT"));
			/*---ve nut thu nho----*/
			tn.thunho(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(615, 22, _T("TN"));
			/*---ve nut di chuyen----*/
			dc.dichuyen(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(655, 22, _T("DC"));
			/*---ve nut xoa hinh----*/
			xh.xoa(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(695, 22, _T("XH"));

			//Xuat chu tren side
			olderB = pDC.SelectObject(B2);
			older = pDC.SelectObject(pen2);
			pDC.Rectangle(0, 67, 129, 90);
			older = pDC.SelectObject(pen3);
			pDC.Rectangle(0, 91, 129, 200);
			CString a;
			a = "Hinh Vuong";				//Xuat chu khi chon vao bieu tuong
			pDC.SetTextColor(RGB(0, 150, 150));
			pDC.SetBkColor(RGB(255, 255, 255));
			pDC.TextOutW(10, 70, a);
		}
	}
	//------- ve doi tuong hinh tron --------------
	if (b3.chonhinh(p1) == 1)
	{
		o1 = 0; o2 = 0; o4 = 0; o5 = 0; o6 = 0;
		if (o3 == 0)
		{
			o3 = 1;
			older = pDC.SelectObject(pen);
			olderB = pDC.SelectObject(B1);
			b3.htron(&pDC);

			older = pDC.SelectObject(pen2);
			olderB = pDC.SelectObject(B1);
			b1.hcn(&pDC);
			b2.hv(&pDC);
			b4.tg(&pDC);
			b5.htron(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(368, 22, _T("Xu"));
			b6.nsao(&pDC);
			b7.xemlai(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(505, 22, _T("Xem lai"));
			/*---ve nut phong to----*/
			pt.phongto(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(575, 22, _T("PT"));
			/*---ve nut thu nho----*/
			tn.thunho(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(615, 22, _T("TN"));
			/*---ve nut di chuyen----*/
			dc.dichuyen(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(655, 22, _T("DC"));
			/*---ve nut xoa hinh----*/
			xh.xoa(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(695, 22, _T("XH"));

			//Xuat chu tren side
			olderB = pDC.SelectObject(B2);
			older = pDC.SelectObject(pen2);
			pDC.Rectangle(0, 67, 129, 90);
			older = pDC.SelectObject(pen3);
			pDC.Rectangle(0, 91, 129, 200);
			CString a;
			a = "Hinh tron";				//Xuat chu khi chon vao bieu tuong
			pDC.SetTextColor(RGB(0, 150, 150));
			pDC.SetBkColor(RGB(255, 255, 255));
			pDC.TextOutW(10, 70, a);
		}
	}
	//------- ve doi tuong hinh tam giac ----------
	if (b4.chonhinh(p1) == 1)
	{
		o1 = 0; o2 = 0; o3 = 0; o5 = 0; o6 = 0;
		if (o4 == 0)
		{
			o4 = 1;
			older = pDC.SelectObject(pen);
			olderB = pDC.SelectObject(B1);
			b4.tg(&pDC);

			older = pDC.SelectObject(pen2);
			olderB = pDC.SelectObject(B1);
			b1.hcn(&pDC);
			b2.hv(&pDC);
			b3.htron(&pDC);
			b5.htron(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(368, 22, _T("Xu"));
			b6.nsao(&pDC);
			b7.xemlai(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(505, 22, _T("Xem lai"));
			/*---ve nut phong to----*/
			pt.phongto(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(575, 22, _T("PT"));
			/*---ve nut thu nho----*/
			tn.thunho(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(615, 22, _T("TN"));
			/*---ve nut di chuyen----*/
			dc.dichuyen(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(655, 22, _T("DC"));
			/*---ve nut xoa hinh----*/
			xh.xoa(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(695, 22, _T("XH"));

			//Xuat chu tren side
			olderB = pDC.SelectObject(B2);
			older = pDC.SelectObject(pen2);
			pDC.Rectangle(0, 67, 129, 90);
			older = pDC.SelectObject(pen3);
			pDC.Rectangle(0, 91, 129, 200);
			CString a;
			a = "Hinh tam giac";				//Xuat chu khi chon vao bieu tuong
			pDC.SetTextColor(RGB(0, 150, 150));
			pDC.SetBkColor(RGB(255, 255, 255));
			pDC.TextOutW(10, 70, a);
		}
	}
	//------- ve doi tuong hinh dong xu ----------
	if (b5.chonhinh(p1) == 1)
	{
		o1 = 0; o2 = 0; o3 = 0; o4 = 0; o6 = 0;
		if (o5 == 0)
		{
			o5 = 1;
			older = pDC.SelectObject(pen);
			olderB = pDC.SelectObject(B1);
			b5.htron(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(368, 22, _T("Xu"));

			older = pDC.SelectObject(pen2);
			olderB = pDC.SelectObject(B1);
			b1.hcn(&pDC);
			b2.hv(&pDC);
			b3.htron(&pDC);
			b4.tg(&pDC);
			b6.nsao(&pDC);
			b7.xemlai(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(505, 22, _T("Xem lai"));
			/*---ve nut phong to----*/
			pt.phongto(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(575, 22, _T("PT"));
			/*---ve nut thu nho----*/
			tn.thunho(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(615, 22, _T("TN"));
			/*---ve nut di chuyen----*/
			dc.dichuyen(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(655, 22, _T("DC"));
			/*---ve nut xoa hinh----*/
			xh.xoa(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(695, 22, _T("XH"));

			//Xuat chu tren side
			olderB = pDC.SelectObject(B2);
			older = pDC.SelectObject(pen2);
			pDC.Rectangle(0, 67, 129, 90);
			older = pDC.SelectObject(pen3);
			pDC.Rectangle(0, 91, 129, 200);
			CString a;
			a = "Hinh dong xu";				//Xuat chu khi chon vao bieu tuong
			pDC.SetTextColor(RGB(0, 150, 150));
			pDC.SetBkColor(RGB(255, 255, 255));
			pDC.TextOutW(10, 70, a);
		}
	}
	//------- ve doi tuong hinh ngoi sao ----------
	if (b6.chonhinh(p1) == 1)
	{
		o1 = 0; o2 = 0; o3 = 0; o4 = 0; o5 = 0;
		if (o6 == 0)
		{
			o6 = 1;
			older = pDC.SelectObject(pen);
			olderB = pDC.SelectObject(B1);
			b6.nsao(&pDC);

			older = pDC.SelectObject(pen2);
			olderB = pDC.SelectObject(B1);
			b1.hcn(&pDC);
			b2.hv(&pDC);
			b3.htron(&pDC);
			b4.tg(&pDC);
			b5.htron(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(368, 22, _T("Xu"));
			b7.xemlai(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(505, 22, _T("Xem lai"));
			/*---ve nut phong to----*/
			pt.phongto(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(575, 22, _T("PT"));
			/*---ve nut thu nho----*/
			tn.thunho(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(615, 22, _T("TN"));
			/*---ve nut di chuyen----*/
			dc.dichuyen(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(655, 22, _T("DC"));
			/*---ve nut xoa hinh----*/
			xh.xoa(&pDC);
			pDC.SetBkColor(RGB(90, 90, 90));
			pDC.TextOutW(695, 22, _T("XH"));

			//Xuat chu tren side
			olderB = pDC.SelectObject(B2);
			older = pDC.SelectObject(pen2);
			pDC.Rectangle(0, 67, 129, 90);
			older = pDC.SelectObject(pen3);
			pDC.Rectangle(0, 91, 129, 200);
			CString a;
			a = "Hinh ngoi sao";				//Xuat chu khi chon vao bieu tuong
			pDC.SetTextColor(RGB(0, 150, 150));
			pDC.SetBkColor(RGB(255, 255, 255));
			pDC.TextOutW(10, 70, a);
		}
	}
	/*-------------------kiem tra bam vao cac nut tren menu---------------------------*/
	if (b7.chonhinh(p1) == 1)//xem lai
	{
		o1 = 0; o2 = 0; o3 = 0; o4 = 0; o5 = 0; o6 = 0;
		pt1 = 1; pt2 = 1; pt3 = 1; pt4 = 1; pt5 = 1; pt6 = 1;
		tn1 = 1; tn2 = 1; tn3 = 1; tn4 = 1; tn5 = 1; tn6 = 1;
		xh1 = 1; xh2 = 1; xh3 = 1; xh4 = 1; xh5 = 1; xh6 = 1;
		dc1 = 1; dc2 = 1; dc3 = 1; dc4 = 1; dc5 = 1; dc6 = 1;
		pDC.SelectObject(pen2);
		pDC.SelectObject(B1);
		b1.hcn(&pDC);
		b2.hv(&pDC);
		b3.htron(&pDC);
		b4.tg(&pDC);
		b5.htron(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(368, 22, _T("Xu"));
		b6.nsao(&pDC);
		/*---ve nut phong to----*/
		pt.phongto(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(575, 22, _T("PT"));
		/*---ve nut thu nho----*/
		tn.thunho(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(615, 22, _T("TN"));
		/*---ve nut di chuyen----*/
		dc.dichuyen(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(655, 22, _T("DC"));
		/*---ve nut xoa hinh----*/
		xh.xoa(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(695, 22, _T("XH"));

		pDC.SelectObject(pen);
		b7.xemlai(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(505, 22, _T("Xem lai"));

		olderB = pDC.SelectObject(B2);
		older = pDC.SelectObject(pen3);
		pDC.Rectangle(0, 90, 130, 200);
	}
	if (pt.chonhinh(p1) == 1)//phong to
	{
		pt1 = 0; pt2 = 0; pt3 = 0; pt4 = 0; pt5 = 0; pt6 = 0;
		o1 = 0; o2 = 0; o3 = 0; o4 = 0; o5 = 0; o6 = 0;
		tn1 = 1; tn2 = 1; tn3 = 1; tn4 = 1; tn5 = 1; tn6 = 1;
		xh1 = 1; xh2 = 1; xh3 = 1; xh4 = 1; xh5 = 1; xh6 = 1;
		dc1 = 1; dc2 = 1; dc3 = 1; dc4 = 1; dc5 = 1; dc6 = 1;
		pDC.SelectObject(pen2);
		pDC.SelectObject(B1);
		b1.hcn(&pDC);
		b2.hv(&pDC);
		b3.htron(&pDC);
		b4.tg(&pDC);
		b5.htron(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(368, 22, _T("Xu"));
		b6.nsao(&pDC);
		b7.xemlai(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(505, 22, _T("Xem lai"));
		/*---ve nut thu nho----*/
		tn.thunho(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(615, 22, _T("TN"));
		/*---ve nut di chuyen----*/
		dc.dichuyen(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(655, 22, _T("DC"));
		/*---ve nut xoa hinh----*/
		xh.xoa(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(695, 22, _T("XH"));

		pDC.SelectObject(pen);
		/*---ve nut phong to----*/
		pt.phongto(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(575, 22, _T("PT"));

		olderB = pDC.SelectObject(B2);
		older = pDC.SelectObject(pen3);
		pDC.Rectangle(0, 90, 130, 200);
	}
	if (tn.chonhinh(p1) == 1)//thu nho
	{
		tn1 = 0; tn2 = 0; tn3 = 0; tn4 = 0; tn5 = 0; tn6 = 0;
		pt1 = 1; pt2 = 1; pt3 = 1; pt4 = 1; pt5 = 1; pt6 = 1;
		o1 = 0; o2 = 0; o3 = 0; o4 = 0; o5 = 0; o6 = 0;
		xh1 = 1; xh2 = 1; xh3 = 1; xh4 = 1; xh5 = 1; xh6 = 1;
		dc1 = 1; dc2 = 1; dc3 = 1; dc4 = 1; dc5 = 1; dc6 = 1;
		pDC.SelectObject(pen2);
		pDC.SelectObject(B1);
		b1.hcn(&pDC);
		b2.hv(&pDC);
		b3.htron(&pDC);
		b4.tg(&pDC);
		b5.htron(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(368, 22, _T("Xu"));
		b6.nsao(&pDC);
		b7.xemlai(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(505, 22, _T("Xem lai"));
		/*---ve nut phong to----*/
		pt.phongto(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(575, 22, _T("PT"));
		/*---ve nut di chuyen----*/
		dc.dichuyen(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(655, 22, _T("DC"));
		/*---ve nut xoa hinh----*/
		xh.xoa(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(695, 22, _T("XH"));

		pDC.SelectObject(pen);
		/*---ve nut thu nho----*/
		tn.thunho(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(615, 22, _T("TN"));

		olderB = pDC.SelectObject(B2);
		older = pDC.SelectObject(pen3);
		pDC.Rectangle(0, 90, 130, 200);
	}
	if (dc.chonhinh(p1) == 1)//di chuyen
	{
		dc1 = 0; dc2 = 0; dc3 = 0; dc4 = 0; dc5 = 0; dc6 = 0;
		o1 = 0; o2 = 0; o3 = 0; o4 = 0; o5 = 0; o6 = 0;
		tn1 = 1; tn2 = 1; tn3 = 1; tn4 = 1; tn5 = 1; tn6 = 1;
		pt1 = 1; pt2 = 1; pt3 = 1; pt4 = 1; pt5 = 1; pt6 = 1;
		xh1 = 1; xh2 = 1; xh3 = 1; xh4 = 1; xh5 = 1; xh6 = 1;
		pDC.SelectObject(pen2);
		pDC.SelectObject(B1);
		b1.hcn(&pDC);
		b2.hv(&pDC);
		b3.htron(&pDC);
		b4.tg(&pDC);
		b5.htron(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(368, 22, _T("Xu"));
		b6.nsao(&pDC);
		b7.xemlai(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(505, 22, _T("Xem lai"));
		/*---ve nut phong to----*/
		pt.phongto(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(575, 22, _T("PT"));
		/*---ve nut thu nho----*/
		tn.thunho(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(615, 22, _T("TN"));
		/*---ve nut xoa hinh----*/
		xh.xoa(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(695, 22, _T("XH"));

		pDC.SelectObject(pen);
		/*---ve nut di chuyen----*/
		dc.dichuyen(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(655, 22, _T("DC"));

		olderB = pDC.SelectObject(B2);
		older = pDC.SelectObject(pen3);
		pDC.Rectangle(0, 90, 130, 200);
	}
	if (xh.chonhinh(p1) == 1)//thu nho
	{
		xh1 = 0; xh2 = 0; xh3 = 0; xh4 = 0; xh5 = 0; xh6 = 0;
		o1 = 1; o2 = 1; o3 = 1; o4 = 1; o5 = 1; o6 = 1;
		tn1 = 1; tn2 = 1; tn3 = 1; tn4 = 1; tn5 = 1; tn6 = 1;
		pt1 = 1; pt2 = 1; pt3 = 1; pt4 = 1; pt5 = 1; pt6 = 1;
		pDC.SelectObject(pen2);
		pDC.SelectObject(B1);
		b1.hcn(&pDC);
		b2.hv(&pDC);
		b3.htron(&pDC);
		b4.tg(&pDC);
		b5.htron(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(368, 22, _T("Xu"));
		b6.nsao(&pDC);
		b7.xemlai(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(505, 22, _T("Xem lai"));
		/*---ve nut phong to----*/
		pt.phongto(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(575, 22, _T("PT"));
		/*---ve nut thu nho----*/
		tn.thunho(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(615, 22, _T("TN"));
		/*---ve nut di chuyen----*/
		dc.dichuyen(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(655, 22, _T("DC"));

		pDC.SelectObject(pen);
		/*---ve nut xoa hinh----*/
		xh.xoa(&pDC);
		pDC.SetBkColor(RGB(90, 90, 90));
		pDC.TextOutW(695, 22, _T("XH"));

		olderB = pDC.SelectObject(B2);
		older = pDC.SelectObject(pen3);
		pDC.Rectangle(0, 90, 130, 200);
	}
	CView::OnLButtonDown(nFlags, point);
}


void CudvhView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p2.x = point.x;
	p2.y = point.y;
	CClientDC pDC(this);
	if (o1 == 1)
	{
		//ve hinh chu nhat
		if (p1.x > 134 && p1.y > 60 && p2.x > 134 && p2.y > 60)
		{
			A[n] = new hcn(p1, p2);
			A[n]->vehinh(&pDC);
			n++;
		}
	}

	if (o2 == 1)
	{
		if (p1.x > 134 && p1.y > 60 && p2.x > 134 && p2.y > 60)
		{
			//ve hinh vuong
			A[n] = new hinhvuong(p1, p2);
			A[n]->vehinh(&pDC);
			n++;
		}
	}

	if (o3 == 1)
	{
		if (p1.x > 134 && p1.y > 60 && p2.x > 134 && p2.y > 60)
		{
			//ve hinh tron
			A[n] = new hinhtron(p1, p2);
			A[n]->vehinh(&pDC);
			n++;
		}
	}

	if (o4 == 1)
	{
		if (p1.x > 134 && p1.y > 60 && p2.x > 134 && p2.y > 60)
		{
			//ve tam giac
			A[n] = new tamgiac(p1, p2);
			A[n]->vehinh(&pDC);
			n++;
		}
	}
	if (o5 == 1)
	{
		if (p1.x > 134 && p1.y > 60 && p2.x > 134 && p2.y > 60)
		{
			//ve dong xu
			A[n] = new dongxu(p1, p2);
			A[n]->vehinh(&pDC);
			n++;
		}
	}
	if (o6 == 1)
	{
		if (p1.x > 134 && p1.y > 60 && p2.x > 134 && p2.y > 60)
		{
			//ve dong xu
			A[n] = new ngoisao(p1, p2);
			A[n]->vehinh(&pDC);
			n++;
		}
	}
	//---------xem lai hinh ve----------
	if (o1 == 0 && o2 == 0 && o3 == 0 && o4 == 0 && o5 == 0 && o6 == 0)
	{
		for (int i = 0; i < n; i++)
			if (A[i]->chonhinh(p1) == 1)
			{
				A[i]->xuatlai(&pDC);
			}
	}
	/*---------phong to hinh------------*/
	if (pt1 == 0 && pt2 == 0 && pt3 == 0 && pt4 == 0 && pt5 == 0 && pt6 == 0)
	{
		for (int i = 0; i < n; i++)
			if (A[i]->chonhinh(p1) == 1)
			{
				A[i]->phongtovavehinh(&pDC);
			}
	}
	/*---------thu nho hinh------------*/
	if (tn1 == 0 && tn2 == 0 && tn3 == 0 && tn4 == 0 && tn5 == 0 && tn6 == 0)
	{
		for (int i = 0; i < n; i++)
			if (A[i]->chonhinh(p1) == 1)
			{
				A[i]->thunhovavehinh(&pDC);
			}
	}
	/*---------xoa hinh------------*/
	if (xh1 == 0 && xh2 == 0 && xh3 == 0 && xh4 == 0 && xh5 == 0 && xh6 == 0)
	{
		for (int i = 0; i < n; i++)
			if (A[i]->chonhinh(p1) == 1)
			{
				A[i]->xoahinh(&pDC);
			}
	}
	/*---------dc hinh------------*/
	if (dc1 == 0 && dc2 == 0 && dc3 == 0 && dc4 == 0 && dc5 == 0 && dc6 == 0)
	{
		for (int i = 0; i < n; i++)
			if (A[i]->chonhinh(p1) == 1)
			{
				
				A[i]->dichuyen(p2.x - p1.x, p2.y - p1.y, &pDC);
			}
	}
	CView::OnLButtonUp(nFlags, point);
}
