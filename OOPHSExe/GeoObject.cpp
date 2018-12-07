#include "stdafx.h"
#include "GeoObject.h"


CGeoObject::CGeoObject(void)
{
}


CGeoObject::~CGeoObject(void)
{
}

void CGeoObject::setName(CString name){
	this->name = name;
}

CString CGeoObject::getName(){
	return this->name;
}

void CGeoObject::setId(int id){
	this->id = id;
}

int CGeoObject::getId(){
	return this->id;
}

void CGeoObject::setRect(CRect rect){
	this->crRect = rect;
}

CRect CGeoObject::getRect(){
	return this->crRect;
}

/*void CGeoObject::setRect(int left,int right,int width,int height){
	this->crRect.left = left;
	this->crRect.right = left;
}*/

//ÉèÖÃÀàÐÍ
void CGeoObject::setType(int type){
	this->type = type;
}

int CGeoObject::getType(){
	return this->type;
}
void CGeoObject::draw(CDC *pDC){
	
}

