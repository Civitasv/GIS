#pragma once
#include "afxtempl.h" //ģ����ͷ�ļ�
#include "GeoLayer.h"
class CGeoMap
{
private:
	//��ͼ����
	CString name;
	//��ͼ������
	const int mapScale;
	//��ͼ��Χ
	CRect crRect;

public:
	CGeoMap(void);
	virtual ~CGeoMap(void);
	void setName(CString mapName);
	CString getName();
	//��ͼ����ͼ��
	CArray<CGeoLayer *,CGeoLayer *> geoLayers;
	/*void setGeoLayers(CArray<CGeoLayer *,CGeoLayer *> geoLayers);
	CArray<CGeoLayer *,CGeoLayer *> getGeoLayers();*/

	/*void setScale(int mapScale);*/
	int getScale();
	void setRect(CRect crRect);
	CRect getRect();
	void addLayer(CGeoLayer *layer);
	void deleteLayerAt(int index);
	void deleteLayerAll();
	void setLayerVisible(CString layerName,bool isVisible);
	void draw(CDC *pDC);
	CGeoLayer* getLayerByName(CString layerName); 
};

