#pragma once
#include"Configure.h"
class Way
{
public:
	Way();
	int star, end, costTime, starh, starm, endh, endm;
	double price;
	bool isFlight;
	string wid, starp, endp;
	string getDetalId()const;
	string getStarTime()const;
	string getEndTime()const;
};

