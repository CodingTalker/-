#include "Button.h"

Button::Button()
{
	x = 0; y = 0; w = 20; h = 10;
	content = "��ť";
}

Button::Button(int x, int y, int w, int h, const string& text) :x(x), y(y), w(w), h(h), content(text) {
}

Button::~Button(){
}

void Button::show()
{
	::setlinecolor(BLACK);
	::setfillcolor(cur);
	::settextstyle(18, 6, _T("����"));
	::settextcolor(BLACK);
	::setbkmode(TRANSPARENT);
	::fillroundrect(x, y, x + w, y + h, 10, 10);
	int tx = x + (w - textwidth(content.data())) / 2;
	int ty = y + (h - textheight(content.data())) / 2;
	::outtextxy(tx, ty, content.data());
}

bool Button::isin(const ExMessage& msg)
{
	return msg.x > x && msg.x<x + w && msg.y>y && msg.y < y + h;
}

bool Button::isClicked(const ExMessage& msg)
{
	if (isin(msg))
	{
		cur = LIGHTGRAY;
		if (msg.lbutton)
		{
			//Delay();�о���ͬ���Ե���ʱЧ���᲻һ������sleep�滻
			Sleep(200);
			return true;
		}
	}
	else
		cur = WHITE;
	return false;
}

void Button::setPos(int nx, int ny)
{
	x = nx; y = ny;
}

void Button::setSize(int nw, int nh)
{
	w = nw; h = nh;
}

void Button::setContent(const string& text) {
	content = text;
}

void Button::Delay()//��һ�ΰ�ť�ᴥ����Σ������ʱ����ʹֻ֮����һ��
{
	int i = 10000, j;
	while (i--) {
		j = 20000;
		while (j--);
	}
}

int Button::getX(){
	return x;
}

int Button::getY(){
	return y;
}

int Button::getW(){
	return w;
}

int Button::getH(){
	return h;
}
