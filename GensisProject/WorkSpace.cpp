#include "WorkSpace.h"

static vector<Way>Ways[MaxCitySize];//ȫ�ֱ���,������ͼ
static set<string>citybase;//���������ͼ�ĳ���
static map<string, int>TrainNums;//���ڼ���г�����Ƿ�����
static int citynum;//��������
static bool visited[MaxCitySize];//�Ƿ����,����·������
static Route t;//�洢����
//ʹ�þ�̬������������Щֵ��ʹ�÷�Χ�޶��ڱ��ļ���

void WorkSpace::initialUI()
{
	handle = ::initgraph(370, 373, EW_SHOWCONSOLE);//��������
	::loadimage(&bk, "./resource/loadimg.jpg");//����ͼƬ
	SetWindowText(handle, "���ų��з����Ƽ�ϵͳ");//���ƴ��ڱ���
	//------����ʼ������-----------------
	MenuBtns.push_back(new Button(10, 145, 75, 30, "չʾ�г����"));
	MenuBtns.push_back(new Button(10, 180, 75, 30, "չʾ�ɻ�����"));
	MenuBtns.push_back(new Button(10, 215, 75, 30, "չʾ����ϵͳ"));//new
	MenuBtns.push_back(new Button(10, 75, 75, 30, "��ӷɻ�����"));
	MenuBtns.push_back(new Button(10, 40, 75, 30, "����г����"));
	MenuBtns.push_back(new Button(10, 110, 75, 30, "��Ӵ��³���"));//new
	MenuBtns.push_back(new Button(10, 250, 75, 30, "�༭�г����"));
	MenuBtns.push_back(new Button(10, 285, 75, 30, "�༭�ɻ�����"));
	MenuBtns.push_back(new Button(10, 320, 75, 30, "�༭����ϵͳ"));//new
	MenuBtns.push_back(new Button(240, 105, 75, 30, "��ѯ����·��"));
	MenuBtns.push_back(new Button(220, 221, 75, 30, "�˳���ѯϵͳ"));
	//------����ʼ�����˵���ť----------
	Tables.push_back(new Table(Flights));
	Tables.push_back(new Table(Trains));
	Flight t1;//ֻ����t1,t2���ͳ�ʼ�����,����Flights[0]��Ϊ�˷�ֹFlights��TrainsΪ�յ��³�ʼ��ʧ��
	Tables.push_back(new Table(t1));
	Train t2;
	Tables.push_back(new Table(t2));
	Route t3;
	Tables.push_back(new Table(t3));
	Tables.push_back(new Table(citys));
	//------����ʼ������չʾ����---------
}

void WorkSpace::initialData()
{
	fstream s1("./resource/FlightSchedule.txt", ios::in);//����FlightSchedule.txt
	if (!s1.is_open()) {
		cout << "FlightSchedule.txt�ļ���ʧ�ܣ�" << endl;
		return;
	}
	else {
		while (!s1.eof())
		{
			string flightNum, starp, endp;
			int starh, starm, endh, endm;
			double price;
			s1 >> flightNum >> starp >> endp >> starh >> starm >> endh >> endm >> price;
			if (flightNum.empty())
				break;//����ĩ�˿���
			Flight t(flightNum, starp, endp, starh, starm, endh, endm, price);
			Flights.push_back(t);
		}
	}

	fstream s2("./resource/TrainTime.txt", ios::in);//����TrainTime.txt
	if (!s2.is_open()) {
		cout << "TrainTime.txt�ļ���ʧ�ܣ�" << endl;
		return;
	}
	else {
		while (!s2.eof())
		{
			string trainNum, station;
			int starh, starm, endh, endm;
			double price;
			s2 >> trainNum >> station >> starh >> starm >> endh >> endm >> price;
			if (trainNum.empty())
				break;
			Train t(trainNum, station, starh, starm, endh, endm, price);
			Trains.push_back(t);
		}
	}

	s1.close(); s2.close();
}

void WorkSpace::Update_city_map()
{
	sort(Trains.begin(), Trains.end());
	sort(Flights.begin(), Flights.end());
	memset(visited, 0, sizeof(visited));
	citys.clear();
	Routes.clear();
	citybase.clear();
	TrainNums.clear();
	citynum = 0;
	//-------------------�˶θ����б��,ͬʱ�洢����----------------------
	int num;
	num = Flights.size();
	for (int i = 0; i < num; i++) {
		if (citybase.find(Flights[i].getStarp()) == citybase.end())
		{
			citybase.insert(Flights[i].getStarp());
			city t(citynum++, Flights[i].getStarp());
			citys.push_back(t);
		}
		if (citybase.find(Flights[i].getEndp()) == citybase.end())
		{
			citybase.insert(Flights[i].getEndp());
			city t(citynum++, Flights[i].getEndp());
			citys.push_back(t);
		}
	}
	num = Trains.size();
	for (int i = 0; i < num; i++) {
		if (citybase.find(Trains[i].getStation()) == citybase.end())
		{
			citybase.insert(Trains[i].getStation());
			city t(citynum++, Trains[i].getStation());
			citys.push_back(t);
		}
	}
	//-------------------�˶θ��ݷɻ��������г���λ��Ƶ�ͼ----------------------
	for (int i = 0; i < citynum; i++)
		Ways[i].clear();
	//------------��������վɵ�ͼ-----------------
	num = Flights.size();
	for (int i = 0; i < num; i++)
	{
		int star = string2num(Flights[i].getStarp()), end = string2num(Flights[i].getEndp());
		Way t;
		t.star = star; t.end = end; t.isFlight = true;
		t.wid = Flights[i].getFlightNum(); t.price = Flights[i].getPrice();
		t.starh = Flights[i].getStarh(); t.starm = Flights[i].getStarm();
		t.endh = Flights[i].getEndh(); t.endm = Flights[i].getEndm();
		t.costTime = (Flights[i].getEndh() - Flights[i].getStarh()) * 60 + Flights[i].getEndm() - Flights[i].getStarm();
		t.starp = Flights[i].getStarp(); t.endp = Flights[i].getEndp();
		Ways[star].push_back(t);
	}
	num = Trains.size();
	for (int i = 0; i < num; i++)
	{
		if (Trains[i].getStarm() == Trains[i].getEndm() && Trains[i].getStarh() == Trains[i].getEndh()\
			&& Trains[i].getPrice() != 0)//�г������β
			continue;
		if (i == num - 1)
			break;
		int star = string2num(Trains[i].getStation()), end = string2num(Trains[i + 1].getStation());
		Way t;
		t.star = star; t.end = end; t.isFlight = false;
		t.wid = Trains[i].getTrainNum(); t.price = Trains[i + 1].getPrice();
		t.starh = Trains[i].getStarh(); t.starm = Trains[i].getStarm();
		t.endh = Trains[i + 1].getStarh(); t.endm = Trains[i + 1].getStarm();
		t.costTime = (Trains[i + 1].getStarh() - Trains[i].getStarh()) * 60 + Trains[i + 1].getStarm() - Trains[i].getStarm();
		t.starp = Trains[i].getStation(); t.endp = Trains[i + 1].getStation();
		Ways[star].push_back(t);
	}
	//--------�˴����ڴ洢�г������Ϣ-----------------
	//num = Trains.size();
	pair<string, int>t;
	t.second = 0;
	map<string, int>::iterator it;
	for (int i = 0; i < num; i++)
	{
		bool isHorT = Trains[i].getStarh() * 60 + Trains[i].getStarm() == \
					  Trains[i].getEndh() * 60 + Trains[i].getEndm();
		t.first = Trains[i].getTrainNum();
		it = TrainNums.find(t.first);
		if (it == TrainNums.end()) {
			if (isHorT)
				TrainNums.insert(make_pair(t.first, t.second + 1));
			else
				TrainNums.insert(t);
		}
		else if (isHorT) 
			it->second++;
	}
}

void WorkSpace::displayTrain(const ExMessage& a)
{
	cout << "displayTrain" << endl;
	Tables[1]->show();
	Tables[1]->DisplayAll(Trains, a);
}

void WorkSpace::displayFlight(const ExMessage& a)
{
	cout << "displayFlight" << endl;
	//if (Trains.size() == 0)
	//	cout << "�г�����Ϊ�գ�" << endl;
	//else {
	//	cout << "����\t վ��\t��վʱ��\t����ʱ��\tƱ��\t" << endl;
	//	for (auto t : Trains)
	//		t.show();
	//}
	//if (Flights.size() == 0)
	//	cout << "�ɻ�����Ϊ�գ�" << endl;
	//else {
	//	cout << "�����\t ���վ\t �յ�վ\t ���ʱ��\t��վʱ��\tƱ��\t" << endl;
	//	for (auto t : Flights)
	//		t.show();
	//}
	Tables[0]->show();
	Tables[0]->DisplayAll(Flights, a);
}

void WorkSpace::displayCity(const ExMessage& a)
{
	cout << "displayCity" << endl;
	Tables[5]->show();
	Tables[5]->DisplayAll(citys, a);
}

void WorkSpace::addFlight()
{
	cout << "addFlight" << endl;
	Flight t;
	if (!IsInFlight(t))
		return;
	Flights.push_back(t);
	Update_city_map();
	cout << "��ӳɹ���" << endl;
	InputBox(NULL, 0, "����ɹ���", "�ɹ���ʾ", "/�ɹ���ʾ������������/");
}

void WorkSpace::addTrain()
{
	cout << "addTrain" << endl;
	Train t;
	if (!IsInTrain(t))
		return;
	Trains.push_back(t);
	Update_city_map();
	cout << "��ӳɹ���" << endl;
	InputBox(NULL, 0, "����ɹ���", "�ɹ���ʾ", "/�ɹ���ʾ������������/");
}

void WorkSpace::addCity()
{
	cout << "addCity" << endl;
	char buffer[100];
	bool isIn = InputBox(buffer, 100, "�������³�������", "��Ϣ��ʾ", "��:���֮��", 0, 0, false);
	if (!isIn)
		return;
	string newCity = buffer;
	if (!IsInCity(newCity))
	{
		cout << "�����ظ������ʧ��" << endl;
		InputBox(NULL, 0, "�����ظ������ʧ��", "��Ϣ��ʾ", "/��Ϣ��ʾ������������/");
		return;
	}
	cout << "������ӳɹ���" << endl;
	InputBox(NULL, 0, "������ӳɹ�", "�ɹ���ʾ", "/�ɹ���ʾ������������/");
}

void WorkSpace::changeTrain(ExMessage& a)
{
	cout << "changeTrain" << endl;
	char buffer[100];
	bool isChange = InputBox(buffer, 100, "��������༭�г����εĳ�����վ��(������Ϊ����)", "��ʾ��Ϣ", \
		"G77 ����", 0, 0, false);
	if (!isChange)
		return;
	int bp = 0;
	char num[100], sta[100];
	readBuffer(bp, buffer, num);
	readBuffer(bp, buffer, sta);
	int pos = NandS2pos(num, sta);
	if (pos == -1) {
		cout << "δ�ҵ����޸�Ŀ��,���˳��޸��г����๦��!" << endl;
		InputBox(NULL, 0, "δ�ҵ��޸�Ŀ�꣡", "ʧ����ʾ", "/�쳣��ʾ������������/");
		return;
	}
	else {
		int flag;
		string hint(Trains[pos].getTrainNum());
		hint = hint + " " + Trains[pos].getStation() + " " + Trains[pos].getStarTime() + " "\
			+ Trains[pos].getEndTime() + " " + Trains[pos].getStrPrc();
		while (true)
		{
			Tables[3]->show();
			peekmessage(&a);
			if (a.rbutton)
				return;
			flag = Tables[3]->ChangeTrain(Trains[pos], a);
			//cout << "���޸ĳ��� " << endl;
			//Trains[pos].show();  ����̨������
			if (!flag)
				continue;
			else if (flag == 1) {
				if (IsInTrain(Trains[pos], hint, false))
					break;
			}
			else {
				bool isDelete = InputBox(NULL, 0, "ȷ��ɾ��?", "��Ϣ��ʾ", "/��Ϣ��ʾ������������/", 0, 0, false);
				if (isDelete) {
					Trains.erase(Trains.begin() + pos);
					break;
				}
			}
		}
		Update_city_map();
		InputBox(NULL, 0, "�༭�ɹ���", "�ɹ���ʾ", "/�ɹ���ʾ������������/");
		cout << "\n���˳��޸��г�������" << endl;
	}
}

void WorkSpace::changeFlight(ExMessage& a)
{
	cout << "changeFlight" << endl;
	char buffer[100];
	bool isChange = InputBox(buffer, 100, "��������༭�ɻ�����ĺ����(������Ϊ����)", "��ʾ��Ϣ", \
		"AK233", 0, 0, false);
	if (!isChange)
		return;
	int bp = 0;
	char num[100];
	readBuffer(bp, buffer, num);
	int pos = FNum2pos(num);
	if (pos == -1) {
		cout << "δ�ҵ����޸�Ŀ��,���˳��޸ķɻ����๦��!" << endl;
		InputBox(NULL, 0, "δ�ҵ��޸�Ŀ�꣡", "ʧ����ʾ", "/�쳣��ʾ������������/");
		return;
	}
	else {
		int flag;
		string hint(Flights[pos].getFlightNum());
		hint = hint + " " + Flights[pos].getStarp() + " " + Flights[pos].getEndp() + " " + Flights[pos].getStarTime() + " "\
			+ Flights[pos].getEndTime() + " " + Flights[pos].getStrPrc();
		while (true)
		{
			Tables[2]->show();
			peekmessage(&a);
			if (a.rbutton)
				return;
			flag = Tables[2]->ChangeFlight(Flights[pos], a);
			//Flights[pos].show();  ����̨������
			if (!flag)
				continue;
			else if (flag == 1) {
				if (IsInFlight(Flights[pos], hint, false))
					break;
			}
			else {
				bool isDelete = InputBox(NULL, 0, "ȷ��ɾ��?", "��Ϣ��ʾ", "/��Ϣ��ʾ������������/", 0, 0, false);
				if (isDelete) {
					Flights.erase(Flights.begin() + pos);
					break;
				}
			}
		}
		Update_city_map();
		InputBox(NULL, 0, "�༭�ɹ���", "�ɹ���ʾ", "/�ɹ���ʾ������������/");
		cout << "\n���˳��޸ķɻ����๦��" << endl;
	}
}

void WorkSpace::changeCity(ExMessage& a)
{
	cout << "changeCity" << endl;
	char buffer[100];
	bool isin = InputBox(buffer, 100, "��������༭����", "��Ϣ��ʾ", "����֮��", 0, 0, false);
	if (!isin)
		return;
	int pos = string2num(buffer);
	if (pos == -1)
	{
		cout << "δ�ҵ����༭���У�" << endl;
		InputBox(NULL, 0, "δ�ҵ����༭����!", "��Ϣ��ʾ", "/��Ϣ��ʾ������������/");
		return;
	}
	else {
		int flag;
		while (true)
		{
			peekmessage(&a);
			if (a.rbutton)
				return;
			flag = Tables[2]->ChangeCity(citys[pos], a);
			if (!flag)
				continue;
			else if (flag == 1) {
				char buffer[100];
				bool isin = InputBox(buffer, 100, "�������³�����", "��Ϣ��ʾ", citys[pos].getName().c_str(), 0, 0, false);
				if (isin) {
					editCity(pos, buffer);
					break;
				}
			}
			else {
				bool isDelete = InputBox(NULL, 0, "ȷ��ɾ���ó��У�(���а����ó��еĺ����복�ν���ȫ��ɾ��!)", \
					"��Ϣ��ʾ", "/(�� �㧥 ��;)��ȷ��Ҫɾ����/", 0, 0, false);
				if (isDelete) {
					deleteCity(citys[pos].getId());
					break;
				}
			}
		}
		Update_city_map();
		cout << "�༭�ɹ���" << endl;
		InputBox(NULL, 0, "�༭�ɹ���", "�ɹ���ʾ", "/�ɹ���ʾ��������Ҫ����/");
	}
}

void WorkSpace::searchWay(ExMessage& a)
{
	if (!CheckTrains()) {
		InputBox(NULL, 0, "�г����α���Ϣ�쳣,���ȼ���г����α�", "�쳣��ʾ", "/�쳣��ʾ������������/");
		return;
	}
	if (!checkRep()) {
		InputBox(NULL, 0, "�г��򺽰�����ظ��������飡", "�쳣��ʾ", "/�쳣��ʾ������������/");
		return;
	}
	cout << "searchWay" << endl;
	char buffer[100], starp[100], endp[100];
	bool isInput = InputBox(buffer, 100, "������������յ����(Ĭ������������)", "��Ϣ��ʾ", "�人 ����", 0, 0, false);
	if (!isInput)
		return;
	int ip = 0;
	readBuffer(ip, buffer, starp);
	readBuffer(ip, buffer, endp);
	int star = string2num(starp), end = string2num(endp);
	if (star == -1) {
		cout << "δ�ҵ������أ���ѯ·�߹����˳�" << endl;
		InputBox(NULL, 0, "δ�ҵ������أ���ѯ·�߹����˳�", "�쳣��ʾ", "/�쳣��ʾ������������/");
		return;
	}
	if (end == -1) {
		cout << "δ�ҵ�Ŀ�ĵأ���ѯ·�߹����˳�" << endl;
		InputBox(NULL, 0, "δ�ҵ�Ŀ�ĵأ���ѯ·�߹����˳�", "�쳣��ʾ", "/�쳣��ʾ������������/");
		return;
	}
	StationDfs(star, end);
	int num = Routes.size();
	if (num == 0) {
		cout << "���ǲ�ͨ��" << endl;
		InputBox(NULL, 0, "���ǲ�ͨ��", "��Ϣ��ʾ", "/��Ϣ��ʾ������������/");
		return;
	}
	int pricePos = 0, turnPos = 0, timePos = 0;
	double minPrice = FLT_MAX;
	int minTurn = INT_MAX, minTime = INT_MAX;
	for (int i = 0; i < num; i++)
	{
		int bufTurn = Routes[i].getAllTurn();
		int bufTime = Routes[i].getAllTime();
		double bufPrice = Routes[i].getAllPrice();
		if (bufTurn < minTurn) {
			minTurn = bufTurn;
			turnPos = i;
		}
		if (bufPrice < minPrice) {
			minPrice = bufPrice;
			pricePos = i;
		}
		if (bufTime < minTime) {
			minTime = bufTime;
			timePos = i;
		}
	}
	saveRoutes(pricePos, timePos, turnPos);
	Tables[4]->DisplayRoutes(starp, endp, Routes[pricePos], Routes[timePos], Routes[turnPos], a);
}

void WorkSpace::saveData()
{
	fstream write1("./resource/FlightSchedule.txt", ios::trunc | ios::out);
	if (!write1.is_open()) {
		cout << "δ�ܴ�resource/FlightSchedule.txt�����ݱ���ʧ�ܣ�" << endl;
		return;
	}
	int num = Flights.size();
	for (int i = 0; i < num; i++)
		write1 << Flights[i].getFlightNum() << " " << Flights[i].getStarp() << " " << Flights[i].getEndp() << \
		" " << Flights[i].getStarh() << " " << Flights[i].getStarm() << " " << Flights[i].getEndh() << " " << \
		Flights[i].getEndm() << " " << Flights[i].getPrice() << endl;
	fstream write2("./resource/TrainTime.txt", ios::trunc | ios::out);
	if (!write2.is_open()) {
		cout << "δ�ܴ�resource/TrainTime.txt�����ݱ���ʧ�ܣ�" << endl;
		return;
	}
	num = Trains.size();
	for (int i = 0; i < num; i++)
		write2 << Trains[i].getTrainNum() << " " << Trains[i].getStation() << " " << Trains[i].getStarh() << \
		" " << Trains[i].getStarm() << " " << Trains[i].getEndh() << " " << \
		Trains[i].getEndm() << " " << Trains[i].getPrice() << endl;
	cout << "���ݱ���ɹ���" << endl;
	write1.close(); write2.close();
}

int WorkSpace::ChoseOpt(const ExMessage& a)
{
	settextstyle(20, 0, "����");
	settextcolor(RED);
	char title[50] = "���ų��з����Ƽ�ϵͳ";
	outtextxy((::getwidth() - textwidth(title)) / 2, 40, title);

	settextstyle(15, 0, "����");
	settextcolor(BLUE);
	outtextxy(240, 65, "���2001������");
	for (auto t : MenuBtns)
		t->show();
	for (size_t i = 0; i < MenuBtns.size(); i++)
	{
		if (MenuBtns[i]->isClicked(a))
			return i;
	}
	return 11;//return MENU;
}

void WorkSpace::Refresh()
{
	::cleardevice();
	::putimage(0, 0, &bk);
}

WorkSpace::~WorkSpace()
{
	for (size_t i = 0; i < MenuBtns.size(); i++){
		delete MenuBtns[i];//�������˵���ť�ռ�
	}
	for (size_t i = 0; i < Tables.size(); i++) {
		delete Tables[i];//���ջ��Ʊ��ռ�
	}
}

int WorkSpace::string2num(const string& cname)
{
	int size = citys.size();
	for (int i = 0; i < size; i++) {
		if (citys[i].getName() == cname)
			return i;
	}
	return -1;
}

int WorkSpace::NandS2pos(const string& num, const string& sta)
{
	int low = 0, high = Trains.size() - 1, mid, size = Trains.size();
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (Trains[mid].getTrainNum() == num)
			break;
		if (Trains[mid].getTrainNum() < num)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (low > high)
		return -1;
	if (Trains[mid].getStation() == sta)
		return mid;
	int sp = mid + 1, xp = mid - 1;
	while (sp < size && Trains[sp].getTrainNum() == num) {
		if (Trains[sp].getStation() == sta)
			return sp;
		sp++;
	}
	while (xp >= 0 && Trains[xp].getTrainNum() == num) {
		if (Trains[xp].getStation() == sta)
			return xp;
		xp--;
	}
	return -1;
}

void WorkSpace::readBuffer(int& p, char buffer[], char databuffer[])
{
	int len = strlen(buffer);
	if (p >= len)
		return;
	int dp = 0;
	while (buffer[p] != ' ' && buffer[p] != '\0'){
		databuffer[dp++] = buffer[p++];
	}
	databuffer[dp] = '\0';//��β����Ȼ������
	p++;
}

int WorkSpace::FNum2pos(const string& num)
{
	int low = 0, high = Flights.size() - 1, mid;
	while (low <= high)
	{
		if (Flights[low].getFlightNum() == num)
			return low;
		if (Flights[high].getFlightNum() == num)
			return high;
		mid = low + (high - low) / 2;
		if (Flights[mid].getFlightNum() == num)
			return mid;
		if (Flights[mid].getFlightNum() < num)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

void WorkSpace::buf2time(char buffer[], int& h, int& m)
{
	if (strlen(buffer) != 5) {
		h = -1; m = -1;
		return;
	}
	char hbuf[2], mbuf[2];
	hbuf[0] = buffer[0]; hbuf[1] = buffer[1];
	mbuf[0] = buffer[3]; mbuf[1] = buffer[4];
	h = atoi(hbuf);
	if (h >= 24 && h < 0)
		h = -1;
	m = atoi(mbuf);
	if (m >= 60 && m < 0)
		m = -1;
}

double WorkSpace::buf2price(char buffer[])
{
	int len = strlen(buffer);
	double ans = atof(buffer);
	if (ans == 0.0)//�ڴ���Ŀ��,Ʊ��0.0�Ϸ�,��ȷ��ansȷʵ��0.0
	{
		if (buffer[0] == '.' || buffer[len - 1] == '.')
			return -1.0;
		int pointCnt = 0, posCnt = 0;
		while (posCnt != len)
		{
			if (buffer[posCnt] != '0')
			{
				if (buffer[posCnt] != '.')
					return -1.0;
				pointCnt++;
			}
			posCnt++;
		}
		if (pointCnt != 1)
			return -1.0;
	}
	return ans;
}

bool WorkSpace::checkTimeAndPrice(const int starh, const int starm, const int endh, const int endm, const double price){
	if (endh * 60 + endm < starh * 60 + starm)//����һ��:����ʱ�䲻���ڿ�ʼʱ��
		return false;
	return starh != -1 && starm != -1 && endh != -1 && endm != -1 && price != -1.0;
}

bool WorkSpace::IsInFlight(Flight& t, const string& hint, const bool isAdd)
{
	char buffer[100];
	bool isInput = InputBox(buffer, 100, "�����뺽����Ϣ,��ʽ������ʾ(Ĭ������������):\n����� ���վ �յ�վ ���ʱ�� ����ʱ�� Ʊ��\n�ر�˵��:ʱ�������������λ����0����", \
		"���뺽����Ϣ", hint.data(), 0, 0, false);
	if (!isInput)
		return false;
	char Fid[100], stap[100], endp[100], starTime[100], endTime[100], price[100];
	int fp = 0;
	readBuffer(fp, buffer, Fid);
	readBuffer(fp, buffer, stap);
	readBuffer(fp, buffer, endp);
	readBuffer(fp, buffer, starTime);
	readBuffer(fp, buffer, endTime);
	readBuffer(fp, buffer, price);
	cout << Fid << " " << stap << " " << endp << " " << starTime << " " << endTime << " " << price << endl;//����̨������
	int pos = FNum2pos(Fid);
	if (isAdd && pos != -1) {
		cout << "������ظ������ʧ��" << endl;
		InputBox(NULL, 0, "������ظ������ʧ��", "������ʾ", "/������ʾ������������/");
		return false;
	}
	if (!checkCityName(stap)) {
		cout << "������ʼ�ص㲻�ڽ�ͨ��ϵ�����ʧ��" << endl;
		InputBox(NULL, 0, "������ʼ�ص㲻�ڽ�ͨ��ϵ�����ʧ��", "������ʾ", "/������ʾ������������/");
		return false;
	}
	if (!checkCityName(endp)) {
		cout << "����Ŀ�ĵز��ڽ�ͨ��ϵ�����ʧ��" << endl;
		InputBox(NULL, 0, "����Ŀ�ĵز��ڽ�ͨ��ϵ�����ʧ��", "������ʾ", "/������ʾ������������/");
		return false;
	}
	int starh, starm, endh, endm;
	double pc = buf2price(price);
	buf2time(starTime, starh, starm);
	buf2time(endTime, endh, endm);
	if (!checkTimeAndPrice(starh, starm, endh, endm, pc))
	{
		cout << "����ʱ���۸������⣡���ʧ�ܣ������ʽ��ȡֵ��Χ" << endl;
		InputBox(NULL, 0, "����ʱ���۸������⣡���ʧ�ܣ������ʽ��ȡֵ��Χ", "������ʾ", "/������ʾ������������/");
		return false;
	}
	t.setFlightNum(Fid); t.setStarp(stap); t.setEndp(endp);
	t.setStarh(starh); t.setEndh(endh); t.setStarm(starm); t.setEndm(endm);
	t.setPrice(pc);
	return true;
}

bool WorkSpace::IsInTrain(Train& t, const string& hint, const bool isAdd)
{
	char buffer[100];
	bool isInput = InputBox(buffer, 100, "�����복����Ϣ,��ʽ������ʾ(Ĭ������������):\n���� վ�� ��վʱ�� ����ʱ�� Ʊ��\n�ر�˵��:ʱ�������������λ����0����,���޵�վ/����ʱ������һ��ʱ��,����������һ����ʱ��,����Ʊ��,������0.0", \
		"���복����Ϣ", hint.data(), 0, 0, false);
	if (!isInput)
		return false;
	char Tid[100], station[100], starTime[100], endTime[100], price[100];
	int fp = 0;
	readBuffer(fp, buffer, Tid);
	readBuffer(fp, buffer, station);
	readBuffer(fp, buffer, starTime);
	readBuffer(fp, buffer, endTime);
	readBuffer(fp, buffer, price);
	cout << Tid << " " << station << " " << starTime << " " << endTime << " " << price << endl;//����̨������
	int pos = NandS2pos(Tid, station);
	if (isAdd && pos != -1) {
		cout << "�����ظ������ʧ��" << endl;
		InputBox(NULL, 0, "�����ظ������ʧ��", "������ʾ", "/������ʾ������������/");
		return false;
	}
	if (!checkCityName(station)) {
		cout << "վ̨���ڽ�ͨ��ϵ�У����ʧ��" << endl;
		InputBox(NULL, 0, "վ̨���ڽ�ͨ��ϵ�У����ʧ��", "������ʾ", "/������ʾ������������/");
		return false;
	}
	int starh, starm, endh, endm;
	double pc = buf2price(price);
	buf2time(starTime, starh, starm);
	buf2time(endTime, endh, endm);
	if (!checkTimeAndPrice(starh, starm, endh, endm, pc))
	{
		cout << "����ʱ���۸������⣡���ʧ�ܣ������ʽ��ȡֵ��Χ" << endl;
		InputBox(NULL, 0, "����ʱ���۸������⣡���ʧ�ܣ������ʽ��ȡֵ��Χ", "������ʾ", "/������ʾ������������/");
		return false;
	}
	t.setTrainNum(Tid); t.setStation(station);
	t.setStarh(starh); t.setEndh(endh); t.setStarm(starm); t.setEndm(endm);
	t.setPrice(pc);
	return true;
}

bool WorkSpace::CheckTrains()
{
	for (auto t : TrainNums) {
		if (t.second != 2)
			return false;
	}
	return true;
}

void WorkSpace::StationDfs(int star, int end)
{
	if (star == end) {
		Routes.push_back(t);
		return;
	}
	int num = Ways[star].size();
	for (int i = 0; i < num; i++) {
		if (!visited[Ways[star][i].end]) {
			visited[star] = true;
			t.push_back(Ways[star][i]);
			StationDfs(Ways[star][i].end, end);
			t.pop_back();
			visited[star] = false;
		}
	}
}

void WorkSpace::saveRoutes(int pricePos, int timePos, int turnPos)
{
	int a[3] = { pricePos,timePos,turnPos };
	fstream write("./resource/Routes.txt", ios::trunc | ios::out);
	if (!write.is_open()) {
		cout << "Routes����ʧ��" << endl;
		return;
	}
	for (int i = 0; i < 3; i++) {
		vector<Way>t;
		Routes[a[i]].getWays(t);
		if (t.size() == 0)
			return;
		write << t[0].starp << "(" << t[0].starh << ":" << t[0].starm << ")" << "--" << t[0].wid << "(";
		if (t[0].isFlight)
			write << "�ɻ�����";
		else
			write << "�г�����";
		write << ")-->" << t[0].endp << "(" << t[0].endh << ":" << t[0].endm << ")";
		int num = t.size();
		for (int i = 1; i < num; i++)
		{
			write << "--" << t[i].wid << "(";
			if (t[i].isFlight)
				write << "�ɻ�����";
			else
				write << "�г�����";
			write << ")-->" << t[i].endp << "(" << t[i].endh << ":" << t[i].endm << ")";
		}
		write << "\n";
	}
	write.close();
}

bool WorkSpace::IsInCity(const string& newCity)
{
	if (!checkCityName(newCity))
	{
		citybase.insert(newCity);
		city t(citynum++, newCity);
		citys.push_back(t);
		return true;
	}
	return false;
}

bool WorkSpace::checkCityName(const string& cityName){
	return citybase.find(cityName) != citybase.end();
}

void WorkSpace::editCity(int cityID, const string& newCityName)
{
	string cityName = citys[cityID].getName();
	unsigned int num = Flights.size();
	for (size_t i = 0; i < num; i++)
	{
		if (Flights[i].getStarp() == cityName)
			Flights[i].setStarp(newCityName);
		if (Flights[i].getEndp() == cityName)
			Flights[i].setEndp(newCityName);
	}
	num = Trains.size();
	for (size_t i = 0; i < num; i++)
	{
		if (Trains[i].getStation() == cityName)
			Trains[i].setStation(newCityName);
	}
}

void WorkSpace::deleteCity(int cityID)
{
	string cityName = citys[cityID].getName();
	unsigned int num = Flights.size();
	int delNum = 0, WriteP = 0;
	for (size_t i = 0; i < num; i++)
	{
		if (Flights[i].getStarp() == cityName || Flights[i].getEndp() == cityName) 
			delNum++;
		else
			Flights[WriteP++] = Flights[i];
	}
	for (int i = 0; i < delNum; i++)
		Flights.pop_back();
	delNum = 0, WriteP = 0;
	num = Trains.size();
	for (size_t i = 0; i < num; i++)
	{
		if (Trains[i].getStation() == cityName)
			delNum++;
		else
			Trains[WriteP++] = Trains[i];
	}
	for (int i = 0; i < delNum; i++)
		Trains.pop_back();
}

bool WorkSpace::checkRep()
{
	for (size_t i = 0; i < Flights.size(); i++)
	{
		if (Flights[i].getStarp() == Flights[i].getEndp())
			return false;
	}//���麽���������յ���ͬ�����
	set<string>TrainCityBase;
	string curNum(""), travelBuf("");
	for (size_t i = 0; i < Trains.size(); i++)
	{
		travelBuf = Trains[i].getTrainNum();
		if (travelBuf != curNum) {
			curNum = travelBuf;
			TrainCityBase.clear();
			TrainCityBase.insert(Trains[i].getStation());
		}
		else {
			if (TrainCityBase.find(Trains[i].getStation()) != TrainCityBase.end())
				return false;
			TrainCityBase.insert(Trains[i].getStation());
		}
	}//����һ��������û�г�����ͬվ̨�����
	return true;
}

