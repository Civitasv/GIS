#pragma once
#include "GeoObject.h"

class CGeoPoint : public CGeoObject  
{
public:
	CGeoPoint();
	virtual ~CGeoPoint();
	void setPoint(CPoint pt);
	void draw(CDC *pDC);
private:
	//µã
	CPoint pt;
};

