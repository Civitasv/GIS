#pragma once
#include "GeoObject.h"
#include "afxtempl.h" //ģ����ͷ�ļ�
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
