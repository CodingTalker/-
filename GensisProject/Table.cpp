#include "Table.h"

Table::Table(const vector<Flight>& Flights)
{
	starX = 5; starY = 13; endX = 365; endY = 343;
	cellHigh = 30; colNum = 11; rowNum = 6;
	Ws.push_back(70);
	Ws.push_back(70);
	Ws.push_back(70);
	Ws.push_back(50);
	Ws.push_back(50);
	Ws.push_back(50);
	t1.setContent("上一页");
	t1.setSize(75, 30);
	t1.setPos(5, 343);
	t2.setContent("下一页");
	t2.setSize(75, 30);
	t2.setPos(290, 343);
	::loadimage(&RouteBk, "./resource/loadimg.jpg");//导入图片
}

Table::Table(const vector<Train>& Trains)
{
	starX = 5; starY = 13; endX = 365; endY = 343;
	cellHigh = 30; colNum = 11; rowNum = 5;
	Ws.push_back(80);
	Ws.push_back(80);
	Ws.push_back(70);
	Ws.push_back(70);
	Ws.push_back(60);
	t1.setContent("上一页");
	t1.setSize(75, 30);
	t1.setPos(5, 343);
	t2.setContent("下一页");
	t2.setSize(75, 30);
	t2.setPos(290, 343);
	::loadimage(&RouteBk, "./resource/loadimg.jpg");//导入图片
}

Table::Table(const vector<city>& citys)
{
	starX = 5; starY = 13; endX = 365; endY = 343;
	cellHigh = 30; colNum = 11; rowNum = 8;
	Ws.push_back(20);
	Ws.push_back(70);
	Ws.push_back(20);
	Ws.push_back(70);
	Ws.push_back(20);
	Ws.push_back(70);
	Ws.push_back(20);
	Ws.push_back(70);
	t1.setContent("上一页");
	t1.setSize(75, 30);
	t1.setPos(5, 343);
	t2.setContent("下一页");
	t2.setSize(75, 30);
	t2.setPos(290, 343);
	::loadimage(&RouteBk, "./resource/loadimg.jpg");//导入图片
}

Table::Table(const Flight& t)
{
	starX = 5; starY = 148; endX = 365; endY = 208;
	cellHigh = 30; colNum = 2; rowNum = 7;
	Ws.push_back(45);
	Ws.push_back(45);
	Ws.push_back(45);
	Ws.push_back(35);
	Ws.push_back(35);
	Ws.push_back(35);
	Ws.push_back(120);
	t1.setContent("修改");
	t1.setSize(60, 30);
	t1.setPos(245, 178);
	t2.setContent("删除");
	t2.setSize(60, 30);
	t2.setPos(305, 178);
	::loadimage(&RouteBk, "./resource/loadimg.jpg");//导入图片
}

Table::Table(const Train& t)
{
	starX = 5; starY = 148; endX = 365; endY = 208;
	cellHigh = 30; colNum = 2; rowNum = 6;
	Ws.push_back(54);
	Ws.push_back(54);
	Ws.push_back(44);
	Ws.push_back(44);
	Ws.push_back(44);
	Ws.push_back(120);
	t1.setContent("修改");
	t1.setSize(60, 30);
	t1.setPos(245, 178);
	t2.setContent("删除");
	t2.setSize(60, 30);
	t2.setPos(305, 178);
	::loadimage(&RouteBk, "./resource/loadimg.jpg");//导入图片
}

Table::Table(const Route& t)
{
	starX = 5; starY = 73; endX = 365; endY = 343;
	cellHigh = 30; colNum = 9; rowNum = 6;
	Ws.push_back(38);
	for (size_t i = 1; i < 5; i++){
		Ws.push_back(58);
	}
	Ws.push_back(90);
	RoutesBtns.push_back(new Button(5, 43, 75, 30, "耗价最少"));
	RoutesBtns.push_back(new Button(147, 43, 75, 30, "用时最少"));
	RoutesBtns.push_back(new Button(290, 43, 75, 30, "中转最少"));//新填三个按钮用以选择方案
	t1.setContent("上一页");
	t1.setSize(75, 30);
	t1.setPos(5, 343);
	t2.setContent("下一页");
	t2.setSize(75, 30);
	t2.setPos(290, 343);
	::loadimage(&RouteBk, "./resource/loadimg.jpg");//导入图片
}

Table::~Table(){
	for (size_t i = 0; i < RoutesBtns.size(); i++){
		delete RoutesBtns[i];//回收按钮空间
	}
}

void Table::show()
{
	setfillcolor(WHITE);
	fillrectangle(starX, starY, endX, endY);
	for (int y = starY; y <= endY; y = y + cellHigh){
		::line(starX, y, endX, y);
	}
	int x = 5;
	for (size_t i = 0; i < Ws.size(); i++){
		::line(x, starY, x, endY);
		x = x + Ws[i];
	}
	::line(x, starY, x, endY);
}

void Table::DisplayAll(const vector<Flight>& Flights, const ExMessage& msg)
{
	drawFlightsHeader();
	int allNum = Flights.size();
	for (int i = page * 10 - 10; i <= page * 10 - 1 && i < allNum; i++){
		DisplayFlight(Flights[i], i % 10 + 1);
	}
	t1.show(); t2.show();
	if (t1.isClicked(msg)&&page!=1) {
		page--;
	}
	if (t2.isClicked(msg)&&page*10<allNum) {
		page++;
	}
}

void Table::DisplayAll(const vector<Train>& Trains, const ExMessage& msg)
{
	drawTrainsHeader();
	int allNum = Trains.size();
	for (int i = page * 10 - 10; i <= page * 10 - 1 && i < allNum; i++) {
		DisplayTrain(Trains[i], i % 10 + 1);
	}
	t1.show(); t2.show();
	if (t1.isClicked(msg) && page != 1) {
		page--;
	}
	if (t2.isClicked(msg) && page * 10 < allNum) {
		page++;
	}
}

void Table::DisplayAll(const vector<city>& citys, const ExMessage& msg)
{
	drawCitysHeader();
	int allNum = citys.size(), row = 0, col = 0;//row为展示城市所在行数,col为列数
	for (int i = page * 40 - 40; i <= page * 40 - 1 && i < allNum; i++) {
		row = i % 10 + 1;
		col = i / 10;
		DisplayCity(citys[i], row, col);
	}
	t1.show(); t2.show();
	if (t1.isClicked(msg) && page != 1) {
		page--;
	}
	if (t2.isClicked(msg) && page * 40 < allNum) {
		page++;
	}
}

int Table::ChangeFlight(const Flight& t, const ExMessage& msg)
{
	drawFlightHeader();
	DisplayFlight(t, 1);
	t1.show(); t2.show();
	::FlushBatchDraw();
	if (t1.isClicked(msg))
		return 1;
	if (t2.isClicked(msg))
		return 2;
	return 0;
}

int Table::ChangeTrain(const Train& t, const ExMessage& msg)
{
	drawTrainHeader();
	DisplayTrain(t, 1);
	t1.show(); t2.show();
	::FlushBatchDraw();
	if (t1.isClicked(msg))
		return 1;
	if (t2.isClicked(msg))
		return 2;
	return 0;
}

int Table::ChangeCity(const city& t, const ExMessage& msg)
{
	int tx, ty, beginX = starX;
	float tw, th;//记录文本的坐标以及大小
	setfillcolor(WHITE);
	fillrectangle(starX, starY + cellHigh, endX, endY);
	line(5, 178, 365, 178);
	line(5, 208, 365, 208);
	line(5, 178, 5, 208);
	line(45, 178, 45, 208);
	line(85, 178, 85, 208);
	line(165, 178, 165, 208);
	line(245, 178, 245, 208);
	line(305, 178, 305, 208);
	line(365, 178, 365, 208);
	th = cellHigh * 0.6f;
	string bufstr("次序");
	tw = 40 * 0.75f / bufstr.length();
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (40 - textwidth(bufstr.data())) / 2;
	ty = starY+cellHigh + (cellHigh - textheight(bufstr.data())) / 2;
	outtextxy(tx, ty, bufstr.data());
	beginX = beginX + 40;

	bufstr = t.getStrId();
	tw = 40 * 0.75f / bufstr.length();
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (40 - textwidth(bufstr.data())) / 2;
	ty = starY+cellHigh + (cellHigh - textheight(bufstr.data())) / 2;
	outtextxy(tx, ty, bufstr.data());
	beginX = beginX + 40;

	bufstr = "城市名";
	tw = 80 * 0.75f / bufstr.length();
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (80 - textwidth(bufstr.data())) / 2;
	ty = starY+cellHigh + (cellHigh - textheight(bufstr.data())) / 2;
	outtextxy(tx, ty, bufstr.data());
	beginX = beginX + 80;

	bufstr = t.getName();
	tw = 80 * 0.75f / bufstr.length();
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (80 - textwidth(bufstr.data())) / 2;
	ty = starY+cellHigh + (cellHigh - textheight(bufstr.data())) / 2;
	outtextxy(tx, ty, bufstr.data());
	beginX = beginX + 80;

	t1.show(); t2.show();
	::FlushBatchDraw();
	if (t1.isClicked(msg))
		return 1;
	if (t2.isClicked(msg))
		return 2;
	return 0;
}

void Table::DisplayFlight(const Flight& t,int num)
{
	int tx, ty, beginX = starX;
	float tw, th;//记录文本的坐标以及大小
	string bufstr;
	::setbkmode(TRANSPARENT);
	bufstr = t.getFlightNum();
	tw = Ws[0] * 0.75f / bufstr.length();
	th = cellHigh * 0.6f;
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[0] - textwidth(bufstr.data())) / 2;
	ty = starY + num * cellHigh + (cellHigh - textheight(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = t.getStarp();
	tw = Ws[1] * 0.75f / bufstr.length();
	beginX = beginX + Ws[0];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[1] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = t.getEndp();
	tw = Ws[2] * 0.75f / bufstr.length();
	beginX = beginX + Ws[1];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[2] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = t.getStarTime();
	tw = Ws[3] * 0.75f / bufstr.length();
	beginX = beginX + Ws[2];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[3] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = t.getEndTime();
	tw = Ws[4] * 0.75f / bufstr.length();
	beginX = beginX + Ws[3];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[4] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = t.getStrPrc();
	tw = Ws[5] * 0.75f / bufstr.length();
	beginX = beginX + Ws[4];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[5] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());
}

void Table::DisplayTrain(const Train& t,int num)
{
	int tx, ty, beginX = starX;
	float tw, th;//记录文本的坐标以及大小
	string bufstr;
	::setbkmode(TRANSPARENT);
	bufstr = t.getTrainNum();
	tw = Ws[0] * 0.75f / bufstr.length();
	th = cellHigh * 0.6f;
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[0] - textwidth(bufstr.data())) / 2;
	ty = starY + num * cellHigh + (cellHigh - textheight(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = t.getStation();
	tw = Ws[1] * 0.75f / bufstr.length();
	beginX = beginX + Ws[0];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[1] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = t.getStarTime();
	tw = Ws[2] * 0.75f / bufstr.length();
	beginX = beginX + Ws[1];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[2] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = t.getEndTime();
	tw = Ws[3] * 0.75f / bufstr.length();
	beginX = beginX + Ws[2];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[3] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = t.getStrPrc();
	tw = Ws[4] * 0.75f / bufstr.length();
	beginX = beginX + Ws[3];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[4] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());
}

void Table::DisplayCity(const city& t, int row, int col)//row为所处行数,col为所处列数
{
	int tx, ty;
	float tw, th;//记录文本的坐标以及大小
	string bufstr;
	::setbkmode(TRANSPARENT);
	bufstr = t.getStrId();
	tw = 5.0f;
	th = cellHigh * 0.6f;
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = starX + col * 90 + (20 - textwidth(bufstr.data())) / 2;
	ty = starY + row * cellHigh + (cellHigh - textheight(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = t.getName();
	tw = 70.0f * 0.75f / bufstr.length();
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = starX + col * 90 + 20 + (70 - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());
}

void Table::DisplayWay(const Way& t, int num)
{
	int tx, ty, beginX = starX;
	float tw, th;//记录文本的坐标以及大小
	string bufstr;
	char ShowNum[5];
	snprintf(ShowNum, 5, "%d", num);
	::setbkmode(TRANSPARENT);
	bufstr = ShowNum;
	tw = Ws[0] * 0.75f / bufstr.length();
	th = cellHigh * 0.6f;
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[0] - textwidth(bufstr.data())) / 2;
	ty = starY + num * cellHigh + (cellHigh - textheight(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = t.starp;
	tw = Ws[1] * 0.75f / bufstr.length();
	beginX = beginX + Ws[0];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[1] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = t.getStarTime();
	tw = Ws[2] * 0.75f / bufstr.length();
	beginX = beginX + Ws[1];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[2] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = t.endp;
	tw = Ws[3] * 0.75f / bufstr.length();
	beginX = beginX + Ws[2];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[3] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = t.getEndTime();
	tw = Ws[4] * 0.75f / bufstr.length();
	beginX = beginX + Ws[3];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[4] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = t.getDetalId();
	tw = Ws[5] * 0.75f / bufstr.length();
	beginX = beginX + Ws[4];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[5] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());
}

void Table::DisplayRoute(const Route& t, const ExMessage& msg)
{
	vector<Way>ShowBuf;
	t.getWays(ShowBuf);
	int WayNum = ShowBuf.size();
	for (int i = 8 * page - 8; i <= 8 * page - 1 && i < WayNum; i++) {
		DisplayWay(ShowBuf[i], i % 8 + 1);
	}
	t1.show(); t2.show();
	::FlushBatchDraw();
	if (t1.isClicked(msg) && page != 1) {
		page--;
	}
	if (t2.isClicked(msg) && page * 8 < WayNum) {
		page++;
	}
}

void Table::DisplayRoutes(const string& starp, const string& endp, \
	const Route& MinPri, const Route& MinTime, const Route& MinTurn, ExMessage& msg)
{
	int flag = 0;
	string showPri("目前展示最低价格路线,总计"), showTime("目前展示耗时最短路线,总计"), \
		showTurn("目前展示中转次数最少路线,总计");
	char Pri[10], Time[10], Turn[10];
	snprintf(Pri, 10, "%lf￥", MinPri.getAllPrice());
	snprintf(Time, 10, "%dmin", MinTime.getAllTime());
	snprintf(Turn, 10, "%d次", MinTurn.getAllTurn());
	showPri = showPri + Pri;
	showTime = showTime + Time;
	showTurn = showTurn + Turn;
	int tx = 80 + (210 - textwidth(showTime.data())) / 2;
	int ty = 343 + (30 - textheight(showTime.data())) / 2;
	while (true)
	{
		peekmessage(&msg);
		if (msg.rbutton)
			return;
		Refresh();
		show();
		drawRouteHeader(starp, endp);
		RoutesBtns[0]->show(); 	RoutesBtns[1]->show(); 	RoutesBtns[2]->show();
		if (flag == 0) {
			outtextxy(tx, ty, showPri.data());
			DisplayRoute(MinPri, msg);
		}
		else if (flag == 1) {
			outtextxy(tx, ty, showTime.data());
			DisplayRoute(MinTime, msg);
		}
		else if (flag == 2) {
			outtextxy(tx, ty, showTurn.data());
			DisplayRoute(MinTurn, msg);
		}

		if (RoutesBtns[1]->isClicked(msg)) {
			page = 1;
			flag = 1;
		}
		else if (RoutesBtns[2]->isClicked(msg)) {
			page = 1;
			flag = 2;
		}
		else if (RoutesBtns[0]->isClicked(msg)) {
			page = 1;
			flag = 0;
		}
	}
}

void Table::drawFlightHeader() const
{
	int tx, ty, beginX = starX;
	float tw, th;//记录文本的坐标以及大小
	string bufstr;
	::setbkmode(TRANSPARENT);
	bufstr = "航班号";
	tw = Ws[0] * 0.75f / bufstr.length();
	th = cellHigh * 0.6f;
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[0] - textwidth(bufstr.data())) / 2;
	ty = starY  + (cellHigh - textheight(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "起点站";
	tw = Ws[1] * 0.75f / bufstr.length();
	beginX = beginX + Ws[0];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[1] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "终点站";
	tw = Ws[2] * 0.75f / bufstr.length();
	beginX = beginX + Ws[1];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[2] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "起飞时间";
	tw = Ws[3] * 0.75f / bufstr.length();
	beginX = beginX + Ws[2];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[3] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "到达时间";
	tw = Ws[4] * 0.75f / bufstr.length();
	beginX = beginX + Ws[3];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[4] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "票价";
	tw = Ws[5] * 0.75f / bufstr.length();
	beginX = beginX + Ws[4];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[5] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "编辑";
	tw = Ws[6] * 0.75f / bufstr.length();
	beginX = beginX + Ws[5];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[6] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

}

void Table::drawFlightsHeader() const
{
	int tx, ty, beginX = starX;
	float tw, th;//记录文本的坐标以及大小
	string bufstr;
	::setbkmode(TRANSPARENT);
	bufstr = "航班号";
	tw = Ws[0] * 0.75f / bufstr.length();
	th = cellHigh * 0.6f;
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[0] - textwidth(bufstr.data())) / 2;
	ty = starY  + (cellHigh - textheight(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "起点站";
	tw = Ws[1] * 0.75f / bufstr.length();
	beginX = beginX + Ws[0];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[1] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "终点站";
	tw = Ws[2] * 0.75f / bufstr.length();
	beginX = beginX + Ws[1];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[2] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "起飞时间";
	tw = Ws[3] * 0.75f / bufstr.length();
	beginX = beginX + Ws[2];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[3] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "到达时间";
	tw = Ws[4] * 0.75f / bufstr.length();
	beginX = beginX + Ws[3];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[4] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "票价";
	tw = Ws[5] * 0.75f / bufstr.length();
	beginX = beginX + Ws[4];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[5] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());
}

void Table::drawCitysHeader() const
{
	float tw, th = cellHigh * 0.6f;
	string title1("次序"), title2("城市名");
	int tx, ty, beginX = starX;
	::setbkmode(TRANSPARENT);
	for (size_t i = 0; i < 4; i++)
	{
		tw = 3.75f;
		::settextstyle((int)th, (int)tw, _T("黑体"));
		tx = beginX + (20 - textwidth(title1.data())) / 2;
		ty = starY + (cellHigh - textheight(title1.data())) / 2;
		::outtextxy(tx, ty, title1.data());
		tw = 8.75f;
		::settextstyle((int)th, (int)tw, _T("黑体"));
		tx = beginX + 20 + (70 - textwidth(title2.data())) / 2;
		::outtextxy(tx, ty, title2.data());
		beginX = beginX + 90;
	}
}

void Table::drawTrainHeader() const
{
	int tx, ty, beginX = starX;
	float tw, th;//记录文本的坐标以及大小
	string bufstr;
	::setbkmode(TRANSPARENT);
	bufstr = "车次";
	tw = Ws[0] * 0.75f / bufstr.length();
	th = cellHigh * 0.6f;
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[0] - textwidth(bufstr.data())) / 2;
	ty = starY + (cellHigh - textheight(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "站名";
	tw = Ws[1] * 0.75f / bufstr.length();
	beginX = beginX + Ws[0];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[1] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "到站时间";
	tw = Ws[2] * 0.75f / bufstr.length();
	beginX = beginX + Ws[1];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[2] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "发车时间";
	tw = Ws[3] * 0.75f / bufstr.length();
	beginX = beginX + Ws[2];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[3] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "票价";
	tw = Ws[4] * 0.75f / bufstr.length();
	beginX = beginX + Ws[3];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[4] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "编辑";
	tw = Ws[5] * 0.75f / bufstr.length();
	beginX = beginX + Ws[4];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[5] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

}

void Table::drawTrainsHeader() const
{
	int tx, ty, beginX = starX;
	float tw, th;//记录文本的坐标以及大小
	string bufstr;
	::setbkmode(TRANSPARENT);
	bufstr = "车次";
	tw = Ws[0] * 0.75f / bufstr.length();
	th = cellHigh * 0.6f;
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[0] - textwidth(bufstr.data())) / 2;
	ty = starY + (cellHigh - textheight(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "站名";
	tw = Ws[1] * 0.75f / bufstr.length();
	beginX = beginX + Ws[0];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[1] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "到站时间";
	tw = Ws[2] * 0.75f / bufstr.length();
	beginX = beginX + Ws[1];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[2] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "发车时间";
	tw = Ws[3] * 0.75f / bufstr.length();
	beginX = beginX + Ws[2];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[3] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());

	bufstr = "票价";
	tw = Ws[4] * 0.75f / bufstr.length();
	beginX = beginX + Ws[3];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[4] - textwidth(bufstr.data())) / 2;
	::outtextxy(tx, ty, bufstr.data());
}

void Table::drawRouteHeader(const string& starp, const string& endp) const
{
	string ShowBuf = starp + "-->" + endp;
	int tx, ty, beginX = starX;
	float tw, th;//记录文本的坐标以及大小
	::setbkmode(TRANSPARENT);
	tx = (370 - textwidth(ShowBuf.data())) / 2;
	ty = (43 - textheight(ShowBuf.data())) / 2;
	tw = 10;
	th = 30;
	::settextstyle((int)th, (int)tw, _T("黑体"));
	::outtextxy(tx, ty, ShowBuf.data());

	ShowBuf = "次序";
	tw = Ws[0] * 0.75f / ShowBuf.length();
	th = cellHigh * 0.6f;
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[0] - textwidth(ShowBuf.data())) / 2;
	ty = starY + (cellHigh - textheight(ShowBuf.data())) / 2;
	::outtextxy(tx, ty, ShowBuf.data());

	ShowBuf = "起点站";
	tw = Ws[1] * 0.75f / ShowBuf.length();
	beginX = beginX + Ws[0];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[1] - textwidth(ShowBuf.data())) / 2;
	::outtextxy(tx, ty, ShowBuf.data());

	ShowBuf = "出发时间";
	tw = Ws[2] * 0.75f / ShowBuf.length();
	beginX = beginX + Ws[1];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[2] - textwidth(ShowBuf.data())) / 2;
	::outtextxy(tx, ty, ShowBuf.data());

	ShowBuf = "终点站";
	tw = Ws[3] * 0.75f / ShowBuf.length();
	beginX = beginX + Ws[2];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[3] - textwidth(ShowBuf.data())) / 2;
	::outtextxy(tx, ty, ShowBuf.data());

	ShowBuf = "到达时间";
	tw = Ws[4] * 0.75f / ShowBuf.length();
	beginX = beginX + Ws[3];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[4] - textwidth(ShowBuf.data())) / 2;
	::outtextxy(tx, ty, ShowBuf.data());

	ShowBuf = "车/航号";
	tw = Ws[5] * 0.75f / ShowBuf.length();
	beginX = beginX + Ws[4];
	::settextstyle((int)th, (int)tw, _T("黑体"));
	tx = beginX + (Ws[5] - textwidth(ShowBuf.data())) / 2;
	::outtextxy(tx, ty, ShowBuf.data());
}

void Table::Refresh() const
{
	::cleardevice();
	::putimage(0, 0, &RouteBk);
}
