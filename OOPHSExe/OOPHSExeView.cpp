
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
		this->isMaploaded = FALSE;
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
		//this->OnPrepareDC(pDC);
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
	void addPolylines(){

	}

	void addPolygons(){

	}

	void addAnnotations(){

	}
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
		/*--------------------��ȡ��Χ---------------------*/
		int left,top,right,bottom;
		fscanf_s(fp,"%d,%d%d,%d",&left,&top,&right,&bottom);
		map->setRect(CRect(left,top,right,bottom));
		/*-------------------------------------------------*/
		/*--------------------��ȡ����---------------------*/
		int layerNum;
		fscanf_s(fp,"%d",&layerNum);
		/*--------------------��ȡÿһ��-------------------*/
		for(int i=0;i<layerNum;i++){
			CGeoLayer *layer = new CGeoLayer();
			map->addLayer(layer);
			//��ȡ������С
			int layerSize;
			fscanf_s(fp,"%d",&layerSize);
			//��ȡ����
			char *layerName = new char[layerSize+1];
			fread( layerName , sizeof(char) , layerSize+1 , fp ) ;  
			delete []layerName;
			//��ȡĿ����Ŀ
			int number;
			fscanf_s(fp,"%d",&number);
			CGeoObject *obj = NULL;
			//�ж�Ŀ�����Ͳ���ȡÿһ��Ŀ��
			for(int i=0;i<number;i++){
				//��ȡĿ������
				int type;
				fscanf_s(fp,"%d",&type);
				/*switch(type){
				case 1:addPolylines();break;
				case 2:addPolygons();break;
				case 4:addAnnotations();break;
				}*/
				if(type==1){
					//ÿһ�����ϵĵ�
					int x,y;
					fscanf_s(fp,"%d,%d",&x,&y);
					obj = new CGeoPolyline;
					while(!(x==-99999&&y==-99999))
					{
						layer->addObjects(obj);
						((CGeoPolyline *)obj)->addPoint(CPoint(x,y));
						fscanf_s(fp,"%d,%d",&x,&y);
					}
					layer->addObjects(obj);
				}else if(type==2){
					//ÿһ�����ϵĵ�
					int x,y;
					fscanf_s(fp,"%d,%d",&x,&y);
					obj = new CGeoPolygon;
					while(!(x==-99999&&y==-99999))
					{
						layer->addObjects(obj);
						((CGeoPolygon *)obj)->addPoint(CPoint(x,y));
						fscanf_s(fp,"%d,%d",&x,&y);
					}
					layer->addObjects(obj);
				}else if(type==4){
					//ÿһ��ע�ǵĵ�
					int x,y;
					fscanf_s(fp,"%d,%d",&x,&y);
					obj = new CGeoAnno;
					while(!(x==-99999&&y==-99999))
					{
						layer->addObjects(obj);
						((CGeoAnno *)obj)->addPoint(CPoint(x,y));
						fscanf_s(fp,"%d,%d",&x,&y);
					}
					layer->addObjects(obj);
				}
			}
		}
		fclose(fp);
		this->isMaploaded = TRUE;
		Invalidate();
	}


	void COOPHSExeView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
	{
		// TODO: �ڴ����ר�ô����/����û���
		// TODO: Add your specialized code here and/or call the base class
		//���һ��bool�����������Ƿ���������Ҫ�任��������ݼ��أ����û�м��أ�����Ҫ����任

		if( !this->isMaploaded ) 
			return;
		CSize size; 
		CPoint pt;	
		CRect rectD;

		this->GetClientRect(&rectD);//ȡ�ÿͻ������������С
		size = rectD.Size();
		pt = rectD.CenterPoint();//ȡ�ÿͻ��������������ĵ�����

		pDC->SetMapMode(MM_ANISOTROPIC); //����ָ���豸������ӳ�䷽ʽ
		pDC->SetViewportExt(size);  //�趨�ӿڳߴ�
		pDC->SetViewportOrg(pt); //�����ӿ�����Ϊ����ϵԭ��
		size = map->getRect().Size();  //�趨���ڶ�Ӧ�ߴ�
		//CRect rect(-932833,1937773,2109383,-572515);
		pt =  map->getRect().CenterPoint(); //���ô�������Ϊ��Ӧԭ��
		//size = rect.Size();
		//pt = rect.CenterPoint();
		pDC->SetWindowExt(size);   //���ô��ڳ���
		pDC->SetWindowOrg(pt);	//���ô���ԭ��

		CView::OnPrepareDC(pDC, pInfo);
	}

	/*void COOPHSExeView::OnFileOpen()
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
	CGeoObject *obj = NULL;
	while( !feof(fp))
	{
	//CGeoPolyline poly;
	//layer->addPolylines(poly);
	//CGeoPoint *point2 = new CGeoPoint;
	//layer->addPoints(point2);
	//fscanf_s(fp,"%d%d%d%d",&x1,&y1,&x2,&y2);
	//poly.addPoint(CPoint(x1,y1));
	//poly.addPoint(CPoint(x2,y2));
	obj = new CGeoPoint;
	layer->addObjects(obj);
	fscanf_s(fp,"%d%d",&x1,&y1);
	((CGeoPoint *)obj)->setPoint(CPoint(x1,y1));
	//point2->setPoint(CPoint(x1,y1));
	}
	fclose(fp);
	Invalidate();
	}*/