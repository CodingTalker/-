#pragma once
#include"Configure.h"
#include"Flight.h"
#include"Button.h"
#include"Train.h"
#include"Route.h"
#include"city.h"
class Table//用于绘制展示界面
{
public:
	Table(const vector<Flight>& Flights);
	Table(const vector<Train>& Trains);
	Table(const vector<city>& citys);
	Table(const Flight& t);
	Table(const Train& t);
	Table(const Route& t);
	~Table();
	void show();
	void DisplayAll(const vector<Flight>& Flights,const ExMessage& msg);//展示所有飞机航班
	void DisplayAll(const vector<Train>& Trains, const ExMessage& msg);//展示所有列车班次
	void DisplayAll(const vector<city>& citys, const ExMessage& msg);//展示系统内所有城市
	int ChangeFlight(const Flight& t, const ExMessage& msg);//t1被点击返回1,t2被点击返回2,其他情况返回0
	int ChangeTrain(const Train& t, const ExMessage& msg);
	int ChangeCity(const city& t, const ExMessage& msg);
	void DisplayFlight(const Flight& t,int num);//展示单个飞机航班
	void DisplayTrain(const Train& t,int num);//展示单个列车班次
	void DisplayCity(const city& t, int row, int col);//展示单个城市
	void DisplayWay(const Way& t, int num);
	void DisplayRoute(const Route& t, const ExMessage& msg);
	void DisplayRoutes(const string& starp, const string& endp,\
		const Route& MinPri, const Route& MinTime, const Route& MinTurn, ExMessage& msg);
	void drawFlightHeader()const;//绘制表格的表头
	void drawFlightsHeader()const;
	void drawCitysHeader()const;
	void drawTrainHeader()const;
	void drawTrainsHeader()const;
	void drawRouteHeader(const string& starp, const string& endp)const;
	void Refresh()const;//刷新界面
private:
	int starX, starY, endX, endY, colNum, rowNum;//存储表格最左上角坐标和最右下角坐标、以及行列数
	vector<int>Ws;//存储每一列的宽度
	int cellHigh;//存储每一行的高度
	int page = 1;//记录当前页数
	Button t1, t2;//用于触发相应事件
	vector<Button*>RoutesBtns;//用于让用户选择何种推荐方案
	IMAGE RouteBk;//Table背景
};

