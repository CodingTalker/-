#include "city.h"

city::city() {
	cid = -1; name = "";
}

city::city(int id, string cname) :cid(id), name(cname) {
}

int city::getId() const{
	return cid;
}

string city::getName() const{
	return name;
}

string city::getStrId() const
{
	char id[4];
	snprintf(id, 4, "%03d", cid);
	string ans(id);
	return ans;
}

void city::setName(string newName){
	name = newName;
}
