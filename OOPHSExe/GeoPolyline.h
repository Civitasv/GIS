#pragma once
//#include "GeoObject.h"
#include "afxtempl.h" //ģ����ͷ�ļ�
class CGeoPolyline //: public CGeoObject  
{
public:
	CArray<CPoint ,CPoint > pts;
	CGeoPolyline();
	virtual ~CGeoPolyline();
	void addPoint(CPoint pt);
	//int getSize(void);
	void draw(CDC* pDC);
};
