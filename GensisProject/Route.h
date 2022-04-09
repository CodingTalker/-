#pragma once
#include"Configure.h"
#include"Way.h"
class Route
{
public:
	int getAllTurn()const;
	double getAllPrice()const;
	int getAllTime()const;
	void show();
	void push_back(const Way& t);
	void pop_back();
	void getWays(vector<Way>& t)const;
private:
	vector<Way>aRoad;
};

