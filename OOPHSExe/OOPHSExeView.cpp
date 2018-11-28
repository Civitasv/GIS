
// OOPHSExeView.cpp : COOPHSExeView 类的实现
//

#include "stdafx.h"
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
END_MESSAGE_MAP()

// COOPHSExeView 构造/析构

COOPHSExeView::COOPHSExeView()
{
	// TODO: 在此处添加构造代码

}

COOPHSExeView::~COOPHSExeView()
{
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
	/*CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);
	CPoint ld,rt;//
 
	//绘制外部黑色椭圆
	ld=CPoint(-200,-150),rt=CPoint(200,150);
	CBrush NewBrush, *pOldBrush;
	NewBrush.CreateSolidBrush(RGB(0,0,0));
	pOldBrush=pDC->SelectObject(&NewBrush);
	pDC->Ellipse(CRect(ld,rt));
	pDC->SelectObject(pOldBrush);
	NewBrush.DeleteObject();
 
    //绘制白色外部圆
	ld=CPoint(-147,-147),rt=CPoint(147,147);
	pDC->Ellipse(CRect(ld,rt));*/
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
