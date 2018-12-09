#include "stdafx.h"
#include "GeoAnno.h"


CGeoAnno::CGeoAnno(void)
{
}


CGeoAnno::~CGeoAnno(void)
{
}

void CGeoAnno::addPoint(CPoint pt)
{
	pts.Add(pt);
}

/*int CGeoPolyline::getSize(void)
{
	return 0;
}*/


void CGeoAnno::draw(CDC* pDC)
{
	int size = pts.GetSize();
	for(int i=0;i<size;i++)
	{
		if(i==0)
			pDC->MoveTo(pts[i]);
		else
			pDC->LineTo(pts[i]);
	}
}