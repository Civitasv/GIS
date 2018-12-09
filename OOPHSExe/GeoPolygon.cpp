#include "stdafx.h"
#include "GeoPolygon.h"


CGeoPolygon::CGeoPolygon(void)
{
}


CGeoPolygon::~CGeoPolygon(void)
{
}

void CGeoPolygon::addPoint(CPoint pt)
{
	pts.Add(pt);
}

/*int CGeoPolyline::getSize(void)
{
	return 0;
}*/


void CGeoPolygon::draw(CDC* pDC)
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