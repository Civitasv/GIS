#pragma once
#include "afxtempl.h" //ģ����ͷ�ļ�
#include "GeoObject.h"
class CGeoLayer
{
private:
	//ͼ������
	CString name;
	//����Ŀ�����飬��CGeoObjects��������
	CArray<CGeoObject *,CGeoObject *> geoObjects;
	//�Ƿ�ɼ�
	bool isVisible;
	//ͼ�㷶Χ
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

