#pragma once
#include "geoobject.h"
class CGeoAnno :
	public CGeoObject
{
public:
	CGeoAnno(void);
	virtual ~CGeoAnno(void);
	CArray<CPoint ,CPoint > pts;
	void addPoint(CPoint pt);
	//int getSize(void);
	void draw(CDC* pDC);
};

