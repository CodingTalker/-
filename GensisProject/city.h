#pragma once
#include"Configure.h"
class city
{
public:
	city();
	city(int id, string cname);
	int getId() const;
	string getName() const;
	string getStrId() const;
	void setName(string newName);
private:
	int cid;
	string name;
};

