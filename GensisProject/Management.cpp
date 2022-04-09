#include "Management.h"

void Management::run()
{
	m.initialData();//根据保存txt文件初始化数据
	m.Update_city_map();//更新城市与地图
	m.initialUI();//初始化应用界面
	int opt = MENU;
	::BeginBatchDraw();
	while (true)
	{
		m.Refresh();//刷新背景
		peekmessage(&listener);
		if (listener.rbutton)
			opt = MENU;//如果右键，返回主菜单
		switch (opt)
		{
		case Management::DISPLAYTRAIN:
			m.displayTrain(listener);
			break;
		case Management::DISPLAYFLIGHT:
			m.displayFlight(listener);
			break;
		case Management::DISPLAYCITY:
			m.displayCity(listener);
			break;
		case Management::ADDFLIGHT:
			m.addFlight();
			opt = MENU;
			break;
		case Management::ADDTRAIN:
			m.addTrain();
			opt = MENU;
			break;
		case Management::ADDCITY:
			m.addCity();
			opt = MENU;
			break;
		case Management::CHANGETRAIN:
			m.changeTrain(listener);
			opt = MENU;
			break;
		case Management::CHANGEFLIGHT:
			m.changeFlight(listener);
			opt = MENU;
			break;
		case Management::CHANGECITY:
			m.changeCity(listener);
			opt = MENU;
			break;
		case Management::SEARCHWAY:
			m.searchWay(listener);
			opt = MENU;
			break;
		case Management::EXIT:
			m.saveData();
			exit(0);
			break;
		case Management::MENU://主菜单界面,获取被触发按钮信息
			opt = m.ChoseOpt(listener);
			break;
		default:
			break;
		}
		::FlushBatchDraw();
	}
	::EndBatchDraw();
}
