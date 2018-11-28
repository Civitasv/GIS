#pragma once
#include "GeoObject.h"
#include "afxtempl.h" //模板类头文件
class CGeoPolyline : public CGeoObject  
{
private:
	CArray<CPoint,CPoint> pts;
public:
	CGeoPolyline();
	virtual ~CGeoPolyline();
	void addPoint(CPoint pt);
	int getSize(void);
	void draw(CDC* pDC);
};
