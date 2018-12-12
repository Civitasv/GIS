#include "stdafx.h"
#include "GeoPolyline.h"


CGeoPolyline::CGeoPolyline(void)
{
}


CGeoPolyline::~CGeoPolyline(void)
{
}


void CGeoPolyline::addPoint(CPoint pt)
{
	pts.Add(pt);
}


/*int CGeoPolyline::getSize(void)
{
	return 0;
}*/


void CGeoPolyline::draw(CDC* pDC)
{
	CPen pen(PS_SOLID, this->lineWidth, RGB(r, g, b));
    CPen* pOldPen=pDC->SelectObject(&pen);//保存原始的CPen
	int size = pts.GetSize();
	for(int i=0;i<size;i++)
	{
		if(i==0)
			pDC->MoveTo(pts[i]);
		else
			pDC->LineTo(pts[i]);
	}
  
   pDC->SelectObject(pOldPen);//恢复原始的CPen
	/*
	int size = pts.GetSize();
	for(int i=0;i<size;i++)
	{
		if(i==0)
			pDC->MoveTo(pts[i]);
		else
			pDC->LineTo(pts[i]);
	}
	*/
}
