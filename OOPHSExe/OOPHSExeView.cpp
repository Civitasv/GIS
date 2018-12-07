
// OOPHSExeView.cpp : COOPHSExeView ���ʵ��
//

#include "stdafx.h"
#include <afxpriv.h>
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "OOPHSExe.h"
#endif

#include "OOPHSExeDoc.h"
#include "OOPHSExeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COOPHSExeView

IMPLEMENT_DYNCREATE(COOPHSExeView, CView)

BEGIN_MESSAGE_MAP(COOPHSExeView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &COOPHSExeView::OnFileOpen)
END_MESSAGE_MAP()

// COOPHSExeView ����/����

COOPHSExeView::COOPHSExeView()
{
	this->map = NULL;
	
}

COOPHSExeView::~COOPHSExeView()
{
	if(map!=NULL){
		delete map;
	}
}

BOOL COOPHSExeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// COOPHSExeView ����

void COOPHSExeView::OnDraw(CDC* pDC)
{
	COOPHSExeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if(map!=NULL){
		map->draw(pDC);
	}
	//map2.draw(pDC);
}


// COOPHSExeView ��ӡ

BOOL COOPHSExeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void COOPHSExeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void COOPHSExeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// COOPHSExeView ���

#ifdef _DEBUG
void COOPHSExeView::AssertValid() const
{
	CView::AssertValid();
}

void COOPHSExeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COOPHSExeDoc* COOPHSExeView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COOPHSExeDoc)));
	return (COOPHSExeDoc*)m_pDocument;
}
#endif //_DEBUG


// COOPHSExeView ��Ϣ�������
/*void COOPHSExeView::OnFileOpen(){
	
	}*/

void COOPHSExeView::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog dlg(true);
	if( dlg.DoModal() != IDOK )
		return;

	CString fileName = dlg.GetPathName();
	USES_CONVERSION;
	//CString --> char *
	char *filename = T2A(fileName);
	FILE *fp;
	fopen_s(&fp,filename,"r");
	
	if(fp==NULL)
	{
		MessageBox(CString("File Open Failed!"));
		return;
	}
	
	if(map!=NULL)
		delete map;
	map = new CGeoMap();
	
	CGeoLayer *layer = new CGeoLayer();
	map->addLayer(layer);
	//map1.addLayer(layer);

	int x1,y1,x2,y2;
	while( !feof(fp))
	{
		CGeoPolyline *poly = new CGeoPolyline;
		layer->addPolylines(poly);
		//CPoint point;
		//CGeoPoint *point2 = new CGeoPoint;
		
		fscanf_s(fp,"%d%d%d%d",&x1,&y1,&x2,&y2);
		poly->addPoint(CPoint(x1,y1));
		poly->addPoint(CPoint(x2,y2));
		/*fscanf_s(fp,"%d%d",&point.x,&point.y);
		point2->setPoint(point);
		layer->addPoints(point2);*/
	}
	fclose(fp);
	Invalidate();
}
