#pragma once
#include "GeoObject.h"

class CGeoPoint : public CGeoObject  
{
public:
	CGeoPoint();
	virtual ~CGeoPoint();
	void setPoint(CPoint pt);
	CPoint getPoint();
	void draw(CDC *pDC);
	//ÔËËã·ûÖØÔØ
	//CGeoPoint operator++(int);
private:
	//µã
	CPoint pt;
};

