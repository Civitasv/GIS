
// OOPHSExeView.h : COOPHSExeView ��Ľӿ�
//

#pragma once


class COOPHSExeView : public CView
{
protected: // �������л�����
	COOPHSExeView();
	DECLARE_DYNCREATE(COOPHSExeView)

// ����
public:
	COOPHSExeDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~COOPHSExeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // OOPHSExeView.cpp �еĵ��԰汾
inline COOPHSExeDoc* COOPHSExeView::GetDocument() const
   { return reinterpret_cast<COOPHSExeDoc*>(m_pDocument); }
#endif

