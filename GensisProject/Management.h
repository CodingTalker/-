#pragma once
#include"WorkSpace.h"
class Management
{
	enum Options//���ܱ�һ��
	{
		DISPLAYTRAIN,
		DISPLAYFLIGHT,
		DISPLAYCITY,//new
		ADDFLIGHT,
		ADDTRAIN,
		ADDCITY,//new
		CHANGETRAIN,
		CHANGEFLIGHT,
		CHANGECITY,//new
		SEARCHWAY,
		EXIT,
		MENU
	};
public:
	void run();
private:
	ExMessage listener;//������,������������¼�,�Ա����UI����
	WorkSpace m;//�ṩ�����ռ�,���в������ڹ����ռ����
};

