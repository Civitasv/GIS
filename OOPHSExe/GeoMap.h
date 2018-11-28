#pragma once
#include "afxtempl.h" //ģ����ͷ�ļ�
#include "GeoLayer.h"
class CGeoMap
{
private:
	//��ͼ����
	CString name;
	//��ͼ������
	int scale;
	//��ͼ��Χ
	CRect crRect;
	//��ͼ����ͼ��
	CArray<CGeoLayer *,CGeoLayer *> geoLayers;
public:
	CGeoMap(void);
	virtual ~CGeoMap(void);

	void setName(CString mapName);
	CString getName();

	void setGeoLayers(CArray<CGeoLayer *,CGeoLayer *> geoLayers);
	CArray<CGeoLayer *,CGeoLayer *> getGeoLayers();

	void setScale(int mapScale);
	int getScale();

	void setRect(CRect crRect);
	CRect getRect();

	void addLayer(CGeoLayer *layer);
	void deleteLayerAt(int index);
	void deleteLayerAll(int index);
	void setLayerVisible(CString layerName,bool isVisible);
	void draw(CDC *pDC);
};

