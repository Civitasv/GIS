#include "stdafx.h"
#include "GeoMap.h"


CGeoMap::CGeoMap(void)
{
}


CGeoMap::~CGeoMap(void)
{
}

void CGeoMap::setName(CString mapName){
	this->name =mapName;
}
CString CGeoMap::getName(){
	return this->name;
}

void CGeoMap::setGeoLayers(CArray<CGeoLayer *,CGeoLayer *> geoLayers){
	this->geoLayers = geoLayers;
}
CArray<CGeoLayer *,CGeoLayer *> CGeoMap::getGeoLayers(){
	return this->geoLayers;
}

void CGeoMap::setScale(int mapScale){
	this->scale = scale;
}
int CGeoMap::getScale(){
	return this->scale;
}

void CGeoMap::setRect(CRect crRect){
	this->crRect = crRect;
}
CRect CGeoMap::getRect(){
	return this->crRect;
}

void CGeoMap::addLayer(CGeoLayer *layer){

}
void CGeoMap::deleteLayerAt(int index){

}
void CGeoMap::deleteLayerAll(int index){

}
void CGeoMap::setLayerVisible(CString layerName,bool isVisible){

}
void CGeoMap::draw(CDC *pDC){

}