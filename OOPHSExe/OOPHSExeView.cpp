
// OOPHSExeView.cpp : COOPHSExeView ���ʵ��
//

#include "stdafx.h"
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
END_MESSAGE_MAP()

// COOPHSExeView ����/����

COOPHSExeView::COOPHSExeView()
{
	// TODO: �ڴ˴���ӹ������

}

COOPHSExeView::~COOPHSExeView()
{
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
	/*CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);
	CPoint ld,rt;//
 
	//�����ⲿ��ɫ��Բ
	ld=CPoint(-200,-150),rt=CPoint(200,150);
	CBrush NewBrush, *pOldBrush;
	NewBrush.CreateSolidBrush(RGB(0,0,0));
	pOldBrush=pDC->SelectObject(&NewBrush);
	pDC->Ellipse(CRect(ld,rt));
	pDC->SelectObject(pOldBrush);
	NewBrush.DeleteObject();
 
    //���ư�ɫ�ⲿԲ
	ld=CPoint(-147,-147),rt=CPoint(147,147);
	pDC->Ellipse(CRect(ld,rt));*/
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
