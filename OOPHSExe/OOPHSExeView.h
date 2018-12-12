
// OOPHSExeView.h : COOPHSExeView 类的接口
//
#include "oophsexedoc.h"
#pragma once

#include "GeoMap.h"

class COOPHSExeView : public CView
{
protected: // 仅从序列化创建
	COOPHSExeView();
	DECLARE_DYNCREATE(COOPHSExeView);

// 特性
public:
	COOPHSExeDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	

// 实现
public:
	//引入地图实例对象
	CGeoMap *map;
	bool isMaploaded;
	//CGeoMap map2;
	virtual ~COOPHSExeView();
	void readOPT();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
};

#ifndef _DEBUG  // OOPHSExeView.cpp 中的调试版本
inline COOPHSExeDoc* COOPHSExeView::GetDocument() const
   { return reinterpret_cast<COOPHSExeDoc*>(m_pDocument); }
#endif

