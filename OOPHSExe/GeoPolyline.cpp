#include "stdafx.h"
#include "GeoPolyline.h"


CGeoPolyline::CGeoPolyline(void)
{
}


CGeoPolyline::~CGeoPolyline(void)
{
}


void CGeoPolyline::addPoint(CPoint pt)
{
	pts.Add(pt);
}


/*int CGeoPolyline::getSize(void)
{
return 0;
}*/


void CGeoPolyline::draw(CDC* pDC)
{	
	/*
	CPen pen(PS_SOLID, this->lineWidth, RGB(r,g,b));
	pDC->SelectObject(&pen);//保存原始的CPen
	if(clipPts.GetSize()!=0){
		//pDC->PolyBezier(&clipPts[0],clipPts.GetSize()/3*3-2);
		int size = clipPts.GetSize();
		for(int i=0;i<size;i++)
		{
			if(i==0)
				pDC->MoveTo(clipPts[i]);
			else
				pDC->LineTo(clipPts[i]);
		}

	}
	else{
		//pDC->PolyBezier(&pts[0],pts.GetSize()/3*3-2);
		int size = pts.GetSize();
		for(int i=0;i<size;i++)
		{
			if(i==0)
				pDC->MoveTo(pts[i]);
			else
				pDC->LineTo(pts[i]);
		}

	}*/
	drawBezier(pDC);
}


// 插值处理画直线
void CGeoPolyline::drawDDA(CDC* pDC){
	float x = pts[0].x;
	float y = pts[0].y;
	float dx = pts[1].x-pts[0].x;
	float dy = pts[1].y-pts[0].y;
	int n = abs((int)dx)>abs((int)dy)?abs((int)dx):abs((int)dy);
	dx = dx/n;
	dy = dy/n;
	for(int i=0;i<n;i++){
		pDC->SetPixel(x,y,RGB(255,0,0));
		Sleep(1);
		x = x+dx;
		y = y+dy;
	}
}

int CGeoPolyline::getCode(CRect wcRect1,CPoint pt1){
	int code = 0;
	if(pt1.x<wcRect1.left){
		code+=1;
	}
	else if(pt1.x>wcRect1.right)
	{
		code+=2;
	}
	else if(pt1.y<wcRect1.bottom)
	{
		code+=4;
	}
	else if(pt1.y>wcRect1.top){
		code+=8;
	}
	return code;
}

void CGeoPolyline::clipObj(CRect wcRect1){
	clipPts.RemoveAll();
	CPoint pt1,pt2;
	int code1,code2,code;
	int size = pts.GetSize();
	for(int i=0;i<size-1;i++){
		pt1 = pts[i];
		pt2 = pts[i+1];
		code1 = 1;
		code2 = 2;
		code1 = getCode(wcRect1,pt1);
		code2 = getCode(wcRect1,pt2);
		if(code1==0&&code2==0){
			clipPts.Add(pt1);
			clipPts.Add(pt2);
		}
		else if((code1&code2)!=0){
			break;
		}
		else{
			code = code1;
			if(code1==0){
				code = code2;
			}
		}
	}
	if(clipPts.GetSize()>0){
		this->r = 255;
		this->g = 0;
		this->b = 0;
	}
}
void CGeoPolyline::drawBezier(CDC *pDC){
	int i,j,nPoint;
	double tt;
	double step;
	CPen dotpen(PS_DOT,1,RGB(0,0,200)),*oldpen;
	CPen pen(PS_SOLID,1,RGB(0,0,0));
	CPoint *point= &pts[0];
	CPoint p[BEZIER_STEP+1];

	step=(double)1.0/(double)BEZIER_STEP;
	nPoint = pts.GetSize();

	oldpen=(CPen*)pDC->SelectObject(&pen);
	while(nPoint>=4)
	{
		for(tt=0.0,j=0;tt<1.01;tt=tt+step,j++)
			p[j]=hor(3,point,tt);
		
		pDC->SelectObject(&dotpen);
		
	
		pDC->SelectObject(pen);
		pDC->MoveTo(p[0].x,p[0].y);
		for(i=1;i<j;i++)
			pDC->LineTo(p[i].x,p[i].y);
		nPoint-=3;
		point+=3;
	}
	pDC->SelectObject(oldpen);
}

CPoint CGeoPolyline::hor(int degree, CPoint *point, double t)//hornbez
{
	int i,choose_i;
	double fact,t1,x,y;
	CPoint aux;
	t1=1.0-t;
	fact=1.0;
	choose_i=1;
	x=(double)point[0].x*t1;
	y=(double)point[0].y*t1;
	for(i=1;i<degree;i++)
	{
		fact=fact*t;
		choose_i=choose_i*(degree-i+1)/i;
		x=(x+fact*choose_i*point[i].x)*t1;
		y=(y+fact*choose_i*point[i].y)*t1;
	}
	x=x+fact*t*(double)point[degree].x;
	y=y+fact*t*(double)point[degree].y;
	aux.x=(long)x;
	aux.y=(long)y;
	return aux;
}
