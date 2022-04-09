#include "Management.h"

void Management::run()
{
	m.initialData();//���ݱ���txt�ļ���ʼ������
	m.Update_city_map();//���³������ͼ
	m.initialUI();//��ʼ��Ӧ�ý���
	int opt = MENU;
	::BeginBatchDraw();
	while (true)
	{
		m.Refresh();//ˢ�±���
		peekmessage(&listener);
		if (listener.rbutton)
			opt = MENU;//����Ҽ����������˵�
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
		case Management::MENU://���˵�����,��ȡ��������ť��Ϣ
			opt = m.ChoseOpt(listener);
			break;
		default:
			break;
		}
		::FlushBatchDraw();
	}
	::EndBatchDraw();
}
