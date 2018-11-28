#pragma once
#include "afxtempl.h" //模板类头文件
#include "GeoObject.h"
class CGeoLayer
{
private:
	//图层名称
	CString name;
	//地理目标数组，与CGeoObjects建立关联
	CArray<CGeoObject *,CGeoObject *> geoObjects;
	//是否可见
	bool isVisible;
	//图层范围
	CRect crRect;
public:
	CGeoLayer(void);
	virtual ~CGeoLayer(void);

	void setRect(CRect crRect);
	CRect getRect();

	void setName(CString name);
	CString getName();

	void setVisible(bool isVisible);
	bool getVisible();

	void setGeoObjects(CArray<CGeoObject *,CGeoObject *> geoObjects);
	CArray<CGeoObject *,CGeoObject *> getGeoObjects();
	void addObject(CGeoObject *obj);
	void deleteObjectAt(int index);
	void deleteObjectAll();

	void draw(CDC *pDC);
	
	
};

