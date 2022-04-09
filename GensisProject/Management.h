#pragma once
#include"WorkSpace.h"
class Management
{
	enum Options//功能表一览
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
	ExMessage listener;//监听器,用来监视鼠标事件,以便更新UI界面
	WorkSpace m;//提供工作空间,所有操作都在工作空间完成
};

