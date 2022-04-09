#pragma once
#include"Configure.h"
class Flight
{
public:
	Flight();
	Flight(const string& flighnum, const string& starp, const string& endp, const int sh, const int sm, const int eh, const int em, const double pc);
	string getFlightNum()const;
	string getStarp()const;
	string getEndp()const;
	string getStarTime()const;
	string getEndTime()const;
	string getStrPrc()const;
	int getStarh()const;
	int getStarm()const;
	int getEndh()const;
	int getEndm()const;
	double getPrice()const;
	void setFlightNum(const string& num);
	void setStarp(const string& sp);
	void setEndp(const string& ep);
	void setStarh(int sh);
	void setStarm(int sm);
	void setEndh(int eh);
	void setEndm(int em);
	void setPrice(double pc);
	bool operator==(const Flight& right) const;
	bool operator>(const Flight& right) const;
	bool operator<(const Flight& right) const;
	void operator=(const Flight& right);
	void show();//在控制台上展示
private:
	string FlightNum, Starp, Endp;
	int starh, starm, endh, endm;
	double price;
};

