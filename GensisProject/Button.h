#pragma once
#include"Configure.h"
class Button
{
public:
	Button();
	Button(int x, int y, int w, int h, const string& text);
	~Button();
	void show();//将按钮在UI界面展示出来
	bool isin(const ExMessage& msg);//判断鼠标是否移动到了按钮范围
	bool isClicked(const ExMessage& msg);//判断鼠标是否点击了按钮
	void setPos(int x, int y);
	void setSize(int w, int h);
	void setContent(const string& text);
	void Delay();//点一次按钮会触发多次，设计延时函数使之只触发一次
	int getX();
	int getY();
	int getW();
	int getH();
private:
	int x, y, w, h;
	string content;
	COLORREF cur = WHITE;
};

