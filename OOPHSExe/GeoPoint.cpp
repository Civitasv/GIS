#include "stdafx.h"
#include "GeoPoint.h"


CGeoPoint::CGeoPoint(void)
{
}

CGeoPoint::~CGeoPoint(void)
{
	
}

void CGeoPoint::setPoint(CPoint pt)
{
	this->pt = pt;
}

CPoint CGeoPoint::getPoint(){
	return this->pt;
}

void CGeoPoint::draw(CDC *pDC){
	pDC->SetPixel(pt.x,pt.y,RGB(0,255,0));
}
