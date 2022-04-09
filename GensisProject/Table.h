#pragma once
#include"Configure.h"
#include"Flight.h"
#include"Button.h"
#include"Train.h"
#include"Route.h"
#include"city.h"
class Table//���ڻ���չʾ����
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
	void DisplayAll(const vector<Flight>& Flights,const ExMessage& msg);//չʾ���зɻ�����
	void DisplayAll(const vector<Train>& Trains, const ExMessage& msg);//չʾ�����г����
	void DisplayAll(const vector<city>& citys, const ExMessage& msg);//չʾϵͳ�����г���
	int ChangeFlight(const Flight& t, const ExMessage& msg);//t1���������1,t2���������2,�����������0
	int ChangeTrain(const Train& t, const ExMessage& msg);
	int ChangeCity(const city& t, const ExMessage& msg);
	void DisplayFlight(const Flight& t,int num);//չʾ�����ɻ�����
	void DisplayTrain(const Train& t,int num);//չʾ�����г����
	void DisplayCity(const city& t, int row, int col);//չʾ��������
	void DisplayWay(const Way& t, int num);
	void DisplayRoute(const Route& t, const ExMessage& msg);
	void DisplayRoutes(const string& starp, const string& endp,\
		const Route& MinPri, const Route& MinTime, const Route& MinTurn, ExMessage& msg);
	void drawFlightHeader()const;//���Ʊ��ı�ͷ
	void drawFlightsHeader()const;
	void drawCitysHeader()const;
	void drawTrainHeader()const;
	void drawTrainsHeader()const;
	void drawRouteHeader(const string& starp, const string& endp)const;
	void Refresh()const;//ˢ�½���
private:
	int starX, starY, endX, endY, colNum, rowNum;//�洢��������Ͻ�����������½����ꡢ�Լ�������
	vector<int>Ws;//�洢ÿһ�еĿ��
	int cellHigh;//�洢ÿһ�еĸ߶�
	int page = 1;//��¼��ǰҳ��
	Button t1, t2;//���ڴ�����Ӧ�¼�
	vector<Button*>RoutesBtns;//�������û�ѡ������Ƽ�����
	IMAGE RouteBk;//Table����
};

