#pragma once
#include"Configure.h"
class Button
{
public:
	Button();
	Button(int x, int y, int w, int h, const string& text);
	~Button();
	void show();//����ť��UI����չʾ����
	bool isin(const ExMessage& msg);//�ж�����Ƿ��ƶ����˰�ť��Χ
	bool isClicked(const ExMessage& msg);//�ж�����Ƿ����˰�ť
	void setPos(int x, int y);
	void setSize(int w, int h);
	void setContent(const string& text);
	void Delay();//��һ�ΰ�ť�ᴥ����Σ������ʱ����ʹֻ֮����һ��
	int getX();
	int getY();
	int getW();
	int getH();
private:
	int x, y, w, h;
	string content;
	COLORREF cur = WHITE;
};

