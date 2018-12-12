
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
		//this->OnPrepareDC(pDC);
		if(map!=NULL){
			int layerSize = map->geoLayers.GetSize();
			for(int i=0;i<layerSize;i++){
				int objectSize = (map->geoLayers).GetAt(i)->geoObjects.GetSize();
			}

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
		/*--------------------读取范围---------------------*/
		int left,top,right,bottom;
		fscanf_s(fp,"%d,%d%d,%d",&left,&top,&right,&bottom);
		map->setRect(CRect(left,top,right,bottom));
		/*-------------------------------------------------*/
		/*--------------------读取层数---------------------*/
		int layerNum;
		fscanf_s(fp,"%d",&layerNum);
		/*--------------------读取每一层-------------------*/
		for(int i=0;i<layerNum;i++){
			CGeoLayer *layer = new CGeoLayer();
			map->addLayer(layer);
			//读取层名大小
			int layerSize;
			fscanf_s(fp,"%d",&layerSize);
			//读取层名
			char *layerName = new char[layerSize+1];
			char tag;
			fread( &tag , sizeof(char) , 1 , fp ) ;  
			fread( layerName , sizeof(char) , layerSize+1 , fp ) ;  
			layerName[layerSize] = '\0';
			layer->setName(CString(layerName));
			delete []layerName;
			//读取目标数目
			int number;
			fscanf_s(fp,"%d",&number);
			CGeoObject *obj = NULL;
			//判断目标类型并读取每一个目标
			for(int i=0;i<number;i++){
				//获取目标类型
				int type;
				fscanf_s(fp,"%d",&type);
				/*switch(type){
				case 1:addPolylines();break;
				case 2:addPolygons();break;
				case 4:addAnnotations();break;
				}*/
				if(type==1){
					//每一条线上的点
					int x,y;
					fscanf_s(fp,"%d,%d",&x,&y);
					obj = new CGeoPolyline;
					while(!(x==-99999&&y==-99999))
					{
						//layer->addObjects(obj);
						((CGeoPolyline *)obj)->addPoint(CPoint(x,y));
						fscanf_s(fp,"%d,%d",&x,&y);
					}
					layer->addObjects(obj);
				}else if(type==2){
					//每一个面上的点
					int x,y;
					fscanf_s(fp,"%d,%d",&x,&y);
					obj = new CGeoPolygon;
					while(!(x==-99999&&y==-99999))
					{
						//layer->addObjects(obj);
						((CGeoPolygon *)obj)->addPoint(CPoint(x,y));
						fscanf_s(fp,"%d,%d",&x,&y);
					}
					layer->addObjects(obj);
				}else if(type==4){
					//每一个注记的点
					int x,y;
					fscanf_s(fp,"%d,%d",&x,&y);
					obj = new CGeoAnno;
					while(!(x==-99999&&y==-99999))
					{
						//layer->addObjects(obj);
						((CGeoAnno *)obj)->addPoint(CPoint(x,y));
						fscanf_s(fp,"%d,%d",&x,&y);
					}
					layer->addObjects(obj);
				}
			}
		}
		readOPT();
		fclose(fp);
		this->isMaploaded = TRUE;
		Invalidate();
	}


	void COOPHSExeView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
	{
		// TODO: 在此添加专用代码和/或调用基类
		// TODO: Add your specialized code here and/or call the base class
		//添加一个bool变量，控制是否是最新需要变换的这个数据加载，如果没有加载，则不需要坐标变换

		if( !this->isMaploaded ) 
			return;
		CSize size; 
		CPoint pt;	
		CRect rectD;

		this->GetClientRect(&rectD);//取得客户区矩形区域大小
		size = rectD.Size();
		pt = rectD.CenterPoint();//取得客户区矩形区域中心点坐标

		pDC->SetMapMode(MM_ANISOTROPIC); //设置指定设备环境的映射方式
		pDC->SetViewportExt(size);  //设定视口尺寸
		pDC->SetViewportOrg(pt); //设置视口中心为坐标系原点
		size = map->getRect().Size();  //设定窗口对应尺寸
		size.cx = size.cx*1.4;
		//CRect rect(-932833,1937773,2109383,-572515);
		pt =  map->getRect().CenterPoint(); //设置窗口中心为对应原点
		//size = rect.Size();
		//pt = rect.CenterPoint();
		pDC->SetWindowExt(size);   //设置窗口长宽
		pDC->SetWindowOrg(pt);	//设置窗口原点

		CView::OnPrepareDC(pDC, pInfo);
	}

	//读取颜色文件
	void COOPHSExeView::readOPT(){
		FILE *fp;
		fopen_s(&fp,"C:\\Users\\dellyx\\Desktop\\大二上\\c++实习\\china1.opt","r");
		/*--------------------读取层数---------------------*/
		int layerNum;
		fscanf_s(fp,"%d",&layerNum);
		for(int i=0;i<layerNum;i++){
			//读取层名
			char name[20];
			char tag;
			int j = 0;
			//跳过第一个\n
			fread( &tag , sizeof(char) , 1 , fp );
			fread( &tag , sizeof(char) , 1 , fp );
			while(tag!='\n'){
				name[j] = tag;
				j++;
				fread( &tag , sizeof(char) , 1 , fp );
			}
			char *layerName = new char[j];
			
			for(int k=0;k<j;k++){
				layerName[k] = name[k];
			}
			layerName[j] = '\0';
			char a = layerName[j];
			//根据层名获得某一层
			CGeoLayer* layer = map->getLayerByName(CString(layerName));
			
			//读取线型
			int lineType;
			fscanf_s(fp,"%d",&lineType);
			//读取线宽
			double lineWidth = 0;
			if(lineType == 1){
				fscanf_s(fp,"%lf",&lineWidth);
			}
			//读取线色
			int r=0,g=0,b=0;
			if(lineType==1&&lineWidth!=0){
				fscanf_s(fp,"%d,%d,%d",&r,&g,&b);
			}
			//读取面型
			int areaType;
			fscanf_s(fp,"%d",&areaType);
			int r2=0,g2=0,b2=0;
			if(areaType == 1){
				fscanf_s(fp,"%d,%d,%d",&r2,&g2,&b2);
			}
			int size = layer->geoObjects.GetSize();
			for(int i=0;i<size;i++){
				layer->geoObjects.GetAt(i)->lineType = lineType;
				if(lineType == 1){
					layer->geoObjects.GetAt(i)->lineType = lineWidth;
					if(lineWidth!=0){
						layer->geoObjects.GetAt(i)->r = r;
						layer->geoObjects.GetAt(i)->g = g;
						layer->geoObjects.GetAt(i)->b = b;
					}
				}
				layer->geoObjects.GetAt(i)->areaType = areaType;
				if(areaType==1){
					layer->geoObjects.GetAt(i)->r2 = r2;
					layer->geoObjects.GetAt(i)->g2 = g2;
					layer->geoObjects.GetAt(i)->b2 = b2;
				}
			}
		}
	}

	/*void COOPHSExeView::OnFileOpen()
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

