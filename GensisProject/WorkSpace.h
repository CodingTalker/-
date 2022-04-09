#pragma once
#include"Configure.h"
#include"Button.h"
#include"city.h"
#include"Flight.h"
#include"Route.h"
#include"Train.h"
#include"Way.h"
#include"Table.h"
class WorkSpace
{
public:
	void initialUI();//初始化UI类
	void initialData();//根据txt初始化Flight、Train等数据
	void Update_city_map();//根据Flights和Trains规划city和map
	void displayTrain(const ExMessage& a);//展示列车班次
	void displayFlight(const ExMessage& a);//展示飞机航班
	void displayCity(const ExMessage& a);//展示交通系统中的城市
	void addFlight();//添加飞机航班
	void addTrain();//添加列车班次
	void addCity();//添加交通系统中的城市
	void changeTrain(ExMessage& a);//编辑列车车次
	void changeFlight(ExMessage& a);//编辑飞机航班
	void changeCity(ExMessage& a);//编辑城市系统中的城市
	void searchWay(ExMessage& a);//查询路线并展示
	void saveData();//退出时保存数据
	int ChoseOpt(const ExMessage& a);//展示主菜单按钮，并根据按钮被按返回相应的值，触发相应事件
	void Refresh();//刷新UI界面
	~WorkSpace();


	void readBuffer(int& p, char buffer[], char databuffer[]);//读取添加航班功能的输入框
	int FNum2pos(const string& num);//通过航班号搜索在Flights中的位置、用二分法实现
	int NandS2pos(const string& num, const string& sta);//通过车次和站名搜索在Trains中的位置、用二分法实现
	int string2num(const string& cname);//通过城市名搜索编号、城市体量不大，穷举搜索
	void buf2time(char buffer[], int& h, int& m);//将读入的时间字符串转化为整型时间数据
	double buf2price(char buffer[]);//将读入的价格字符串转化为浮点型价格数据
	bool checkTimeAndPrice(const int starh, const int starm, const int endh, const int endm, const double price);
	//检查输入的时间和价格是否有问题,true表示没问题
	bool IsInFlight(Flight& t,const string& hint="AK233 北京 南京 12:00 15:00 300.0",const bool isAdd = true);//检查输入是否能记录到FlightSchedule.txt里,true表示可以
	bool IsInTrain(Train& t, const string& hint = "AK47 武汉 08:30 08:45 60.0", const bool isAdd = true);//检查输入是否能记录到TrainTime.txt里
	bool CheckTrains();//如果列车班次正常，返回true
	void StationDfs(int star, int end);//深度优先搜索,查找两城路线
	void saveRoutes(int pricePos, int timePos, int turnPos);//将三种方案存储到Routes上

	bool IsInCity(const string& newCity);//添加新城市,如果不能添加则返回false
	bool checkCityName(const string& cityName);//检查城市名是否在城市交通体系中,在的话返回true
	void editCity(int cityID, const string& newCityName);//将城市改名
	void deleteCity(int cityID);//将对应城市从交通系统中移出
	bool checkRep();//检查列车与航班是否有重复,如果没有问题则返回true

private:
	IMAGE bk;//背景图片
	HWND handle;//背景图句柄
	vector<Button*>MenuBtns;//存放与管理菜单按钮
	vector<Table*>Tables;//存放六种展示界面

	vector<Flight>Flights;//存储飞机航班信息
	vector<Train>Trains;//存储列车车班信息
	vector<Route>Routes;//存储路线解决方案信息
	vector<city>citys;//存储城市信息
};

