#pragma once
#include "afxtempl.h" //模板类头文件
#include "GeoLayer.h"
class CGeoMap
{
private:
	//地图名称
	CString name;
	//地图比例尺
	int scale;
	//地图范围
	CRect crRect;
	//地图包含图层
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

