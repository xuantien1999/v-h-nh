#pragma once
#include "hinh.h"
#include "hcn.h"
class menu :public hinh
{
public:
	hcn hcn1;
	void thanhmenu(CClientDC *pDC);
	void sideba(CClientDC *pDC);//hiển thị kết quả
	menu();
	~menu();
};


