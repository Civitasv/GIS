#include "stdafx.h"
#include "GeoLayer.h"

CGeoLayer::CGeoLayer(void)
{
}

CGeoLayer::~CGeoLayer(void)
{

}

void CGeoLayer::setName(CString name){
	this->name = name;
}

CString CGeoLayer::getName(){
	return this->name;
}

void CGeoLayer::setRect(CRect rect){
	this->crRect = rect;
}

CRect CGeoLayer::getRect(){
	return this->crRect;
}

void CGeoLayer::setVisible(bool isVisible){
	this->isVisible = isVisible;
}

bool CGeoLayer::getVisible(){
	return this->isVisible;
}

void CGeoLayer::setGeoObjects(CArray<CGeoObject *,CGeoObject *> geoObjects){
	this->geoObjects = geoObjects;
}

CArray<CGeoObject *,CGeoObject *> CGeoLayer::getGeoObjects(){
	return this->geoObjects;
}
void CGeoLayer::addObject(CGeoObject *obj){

}
void CGeoLayer::deleteObjectAt(int index){

}
void CGeoLayer::deleteObjectAll(){
}
void CGeoLayer::draw(CDC *pDC){

}