#include "Train.h"
Train::Train() :TrainNum(""), station(""), starh(-1), starm(-1), endh(-1), endm(-1), price(-1) {
}

Train::Train(const string& num, const string& sta, int sh, int sm, int eh, int em, double pc)
    : TrainNum(num), station(sta), starh(sh), starm(sm), endh(eh), endm(em), price(pc) {
}

string Train::getTrainNum()const {
    return TrainNum;
}

string Train::getStation()const {
    return station;
}

string Train::getStarTime()const {
    if (starh * 60 + starm == endh * 60 + endm && price == 0.0) {
        return "--:--";
    }
    char h[3], m[3];
    snprintf(h, 3, "%02d", starh);
    snprintf(m, 3, "%02d", starm);
    string t(h);
    t = t + ':';
    t = t + m;
    return t;
}

string Train::getEndTime()const {
    if (starh * 60 + starm == endh * 60 + endm && price != 0) {
        return "--:--";
    }
    char h[3], m[3];
    snprintf(h, 3, "%02d", endh);
    snprintf(m, 3, "%02d", endm);
    string t(h);
    t = t + ':';
    t = t + m;
    return t;
}

string Train::getStrPrc()const {
    char pc[7];
    snprintf(pc, 7, "%lf", price);
    string t = pc;
    return t;
}

int Train::getStarh()const {
    return starh;
}

int Train::getStarm()const {
    return starm;
}

int Train::getEndh()const {
    return endh;
}

int Train::getEndm()const {
    return endm;
}

double Train::getPrice()const {
    return price;
}

void Train::setTrainNum(const string& num) {
    TrainNum = num;
}

void Train::setStation(const string& sta) {
    station = sta;
}
void Train::setStarh(int sh) {
    starh = sh;
}

void Train::setStarm(int sm) {
    starm = sm;
}

void Train::setEndh(int eh) {
    endh = eh;
}

void Train::setEndm(int em) {
    endm = em;
}

void Train::setPrice(double pc) {
    price = pc;
}

bool Train::operator==(const Train& right) const
{
    return (this->TrainNum == right.TrainNum) && \
        (this->starh * 60 + this->starm == right.starh * 60 + right.starm);
}

bool Train::operator>(const Train& right) const
{
    if (this->TrainNum > right.TrainNum)
        return true;
    else if (this->TrainNum == right.TrainNum)
        return this->starh * 60 + this->starm > right.starh * 60 + right.starm;
    else
        return false;
}

bool Train::operator<(const Train& right) const
{
    if (this->TrainNum < right.TrainNum)
        return true;
    else if (this->TrainNum == right.TrainNum)
        return this->starh * 60 + this->starm < right.starh * 60 + right.starm;
    else
        return false;
}

void Train::operator=(const Train& right)
{
    this->TrainNum = right.TrainNum;
    this->station = right.station;
    this->starh = right.starh; this->endh = right.endh;
    this->starm = right.starm; this->endm = right.endm;
    this->price = right.price;
}

void Train::show()
{
    if (this->starh * 60 + this->starm == this->endh * 60 + this->endm) {//车次的头尾两站
        if (this->price != 0)//尾站
            cout << TrainNum << "\t " << station << "\t  " << starh << ":" << starm \
            << "        \t" << "--:--" << "\t       " << price << "\t" << endl;
        else
            cout << TrainNum << "\t " << station << "\t  " << "--:--"\
            << "        \t" << endh << ":" << endm << "\t       " << "   " << "\t" << endl;
    }
    else
        cout << TrainNum << "\t " << station << "\t  " << starh << ":" << starm \
        << "        \t" << endh << ":" << endm << "\t       " << price << "\t" << endl;
}

