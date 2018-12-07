
// OOPHSExeView.cpp : COOPHSExeView 类的实现
//

#include "stdafx.h"
#include <afxpriv.h>
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &COOPHSExeView::OnFileOpen)
END_MESSAGE_MAP()

// COOPHSExeView 构造/析构

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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// COOPHSExeView 绘制

void COOPHSExeView::OnDraw(CDC* pDC)
{
	COOPHSExeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	if(map!=NULL){
		map->draw(pDC);
	}
	//map2.draw(pDC);
}


// COOPHSExeView 打印

BOOL COOPHSExeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void COOPHSExeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void COOPHSExeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// COOPHSExeView 诊断

#ifdef _DEBUG
void COOPHSExeView::AssertValid() const
{
	CView::AssertValid();
}

void COOPHSExeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COOPHSExeDoc* COOPHSExeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COOPHSExeDoc)));
	return (COOPHSExeDoc*)m_pDocument;
}
#endif //_DEBUG


// COOPHSExeView 消息处理程序
/*void COOPHSExeView::OnFileOpen(){
	
	}*/

void COOPHSExeView::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
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
