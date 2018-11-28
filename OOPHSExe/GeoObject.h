#pragma once
class CGeoObject
{
private:
	//目标名称
	CString name;
	//目标id
	int id;
	//外界矩形
	CRect crRect;
protected:
	//目标类型,1,2,3,4可以分别表示点、线、面、文字等
	int type;
public:
	CGeoObject(void);
	virtual ~CGeoObject(void);
	
	void setName(CString name);
	CString getName();

	void setId(int id);
	int getId();

	void draw(CDC *pDC);
	void setRect(CRect rect);
	void setRect(int x,int y,int width,int height);
	CRect getRect();
};

