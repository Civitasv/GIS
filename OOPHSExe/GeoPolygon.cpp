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
	if(this->areaType==0){
		int size = pts.GetSize();
		for(int i=0;i<size;i++)
		{
			if(i==0)
				pDC->MoveTo(pts[i]);
			else
				pDC->LineTo(pts[i]);
		}
	}else{
		int size = pts.GetSize();
		POINT *point = new POINT[size];
		for(int i=0;i<size;i++)
		{
			point[i] = pts[i];
		}
		CBrush brush1(RGB(r2,g2,b2));

		pDC->SelectObject(&brush1);
		pDC->Polygon(point,size);
	}
}