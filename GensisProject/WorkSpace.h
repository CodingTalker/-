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
	void initialUI();//��ʼ��UI��
	void initialData();//����txt��ʼ��Flight��Train������
	void Update_city_map();//����Flights��Trains�滮city��map
	void displayTrain(const ExMessage& a);//չʾ�г����
	void displayFlight(const ExMessage& a);//չʾ�ɻ�����
	void displayCity(const ExMessage& a);//չʾ��ͨϵͳ�еĳ���
	void addFlight();//��ӷɻ�����
	void addTrain();//����г����
	void addCity();//��ӽ�ͨϵͳ�еĳ���
	void changeTrain(ExMessage& a);//�༭�г�����
	void changeFlight(ExMessage& a);//�༭�ɻ�����
	void changeCity(ExMessage& a);//�༭����ϵͳ�еĳ���
	void searchWay(ExMessage& a);//��ѯ·�߲�չʾ
	void saveData();//�˳�ʱ��������
	int ChoseOpt(const ExMessage& a);//չʾ���˵���ť�������ݰ�ť����������Ӧ��ֵ��������Ӧ�¼�
	void Refresh();//ˢ��UI����
	~WorkSpace();


	void readBuffer(int& p, char buffer[], char databuffer[]);//��ȡ��Ӻ��๦�ܵ������
	int FNum2pos(const string& num);//ͨ�������������Flights�е�λ�á��ö��ַ�ʵ��
	int NandS2pos(const string& num, const string& sta);//ͨ�����κ�վ��������Trains�е�λ�á��ö��ַ�ʵ��
	int string2num(const string& cname);//ͨ��������������š��������������������
	void buf2time(char buffer[], int& h, int& m);//�������ʱ���ַ���ת��Ϊ����ʱ������
	double buf2price(char buffer[]);//������ļ۸��ַ���ת��Ϊ�����ͼ۸�����
	bool checkTimeAndPrice(const int starh, const int starm, const int endh, const int endm, const double price);
	//��������ʱ��ͼ۸��Ƿ�������,true��ʾû����
	bool IsInFlight(Flight& t,const string& hint="AK233 ���� �Ͼ� 12:00 15:00 300.0",const bool isAdd = true);//��������Ƿ��ܼ�¼��FlightSchedule.txt��,true��ʾ����
	bool IsInTrain(Train& t, const string& hint = "AK47 �人 08:30 08:45 60.0", const bool isAdd = true);//��������Ƿ��ܼ�¼��TrainTime.txt��
	bool CheckTrains();//����г��������������true
	void StationDfs(int star, int end);//�����������,��������·��
	void saveRoutes(int pricePos, int timePos, int turnPos);//�����ַ����洢��Routes��

	bool IsInCity(const string& newCity);//����³���,�����������򷵻�false
	bool checkCityName(const string& cityName);//���������Ƿ��ڳ��н�ͨ��ϵ��,�ڵĻ�����true
	void editCity(int cityID, const string& newCityName);//�����и���
	void deleteCity(int cityID);//����Ӧ���дӽ�ͨϵͳ���Ƴ�
	bool checkRep();//����г��뺽���Ƿ����ظ�,���û�������򷵻�true

private:
	IMAGE bk;//����ͼƬ
	HWND handle;//����ͼ���
	vector<Button*>MenuBtns;//��������˵���ť
	vector<Table*>Tables;//�������չʾ����

	vector<Flight>Flights;//�洢�ɻ�������Ϣ
	vector<Train>Trains;//�洢�г�������Ϣ
	vector<Route>Routes;//�洢·�߽��������Ϣ
	vector<city>citys;//�洢������Ϣ
};

