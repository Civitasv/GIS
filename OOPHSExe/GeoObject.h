#pragma once
class CGeoObject
{
private:
	//Ŀ������
	CString name;
	//Ŀ��id
	int id;
	//������
	CRect crRect;
protected:
	//Ŀ������,1,2,3,4���Էֱ��ʾ�㡢�ߡ��桢���ֵ�
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

