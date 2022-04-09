#include "Route.h"

int Route::getAllTurn()const {
	return aRoad.size();
}

double Route::getAllPrice()const
{
	double ans = 0;
	for (auto i : aRoad)
		ans = ans + i.price;
	return ans;
}

int Route::getAllTime()const
{
	int ans = 0;
	for (auto i : aRoad)
		ans = ans + i.costTime;
	return ans;
}

void Route::show()
{
	if (aRoad.size() == 0)
		return;
	cout << aRoad[0].starp << "(" << aRoad[0].starh << ":" << aRoad[0].starm << ")" << "--" << aRoad[0].wid << "(";
	if (aRoad[0].isFlight)
		cout << "飞机航班";
	else
		cout << "列车车次";
	cout << ")-->" << aRoad[0].endp << "(" << aRoad[0].endh << ":" << aRoad[0].endm << ")";
	int num = aRoad.size();
	for (int i = 1; i < num; i++)
	{
		cout << "--" << aRoad[i].wid << "(";
		if (aRoad[i].isFlight)
			cout << "飞机航班";
		else
			cout << "列车车次";
		cout << ")-->" << aRoad[i].endp << "(" << aRoad[i].endh << ":" << aRoad[i].endm << ")";
	}
	cout << "\n";
}

void Route::push_back(const Way& t) {
	aRoad.push_back(t);
}

void Route::pop_back() {
	aRoad.pop_back();
}

void Route::getWays(vector<Way>& t)const {
	t = aRoad;
}