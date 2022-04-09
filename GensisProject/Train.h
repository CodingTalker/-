#pragma once
#include"Configure.h"
class Train
{
public:
	Train();
	Train(const string& num, const string& sta, int sh, int sm, int eh, int em, double pc);
	string getTrainNum()const;
	string getStation()const;
	string getStarTime()const;
	string getEndTime()const;
	string getStrPrc()const;
	int getStarh()const;
	int getStarm()const;
	int getEndh()const;
	int getEndm()const;
	double getPrice()const;
	void setTrainNum(const string& num);
	void setStation(const string& sta);
	void setStarh(int sh);
	void setStarm(int sm);
	void setEndh(int eh);
	void setEndm(int em);
	void setPrice(double pc);
	bool operator==(const Train& right) const;
	bool operator>(const Train& right) const;
	bool operator<(const Train& right) const;
	void operator=(const Train& right);
	void show();//在控制台上展示
private:
	string TrainNum, station;
	int starh, starm, endh, endm;
	double price;
};

