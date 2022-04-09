#include "Flight.h"
Flight::Flight() :FlightNum(""), Starp(""), Endp(""), starh(-1), starm(-1), endh(-1), endm(-1), price(-1) {
}

Flight::Flight(const string& flighnum, const string& starp, const string& endp, const int sh, const int sm, const int eh, const int em, const double pc)
{
    FlightNum = flighnum; Starp = starp; Endp = endp; starh = sh; starm = sm;
    endh = eh; endm = em; price = pc;
}

string Flight::getFlightNum()const {
    return FlightNum;
}

string Flight::getStarp()const {
    return Starp;
}

string Flight::getEndp()const {
    return Endp;
}

string Flight::getStarTime()const{
    char h[3], m[3];
    snprintf(h, 3, "%02d", starh);
    snprintf(m, 3, "%02d", starm);
    string t(h);
    t = t + ':';
    t = t + m;
    return t;
}

string Flight::getEndTime()const{
    char h[3], m[3];
    snprintf(h, 3, "%02d", endh);
    snprintf(m, 3, "%02d", endm);
    string t(h);
    t = t + ':';
    t = t + m;
    return t;
}

string Flight::getStrPrc()const{
    char pc[7];
    snprintf(pc, 7, "%lf", price);
    string t = pc;
    return t;
}

int Flight::getStarh()const {
    return starh;
}

int Flight::getStarm()const {
    return starm;
}

int Flight::getEndh()const {
    return endh;
}

int Flight::getEndm()const {
    return endm;
}

double Flight::getPrice()const {
    return price;
}

void Flight::setFlightNum(const string& num) {
    FlightNum = num;
}

void Flight::setStarp(const string& sp) {
    Starp = sp;
}

void Flight::setEndp(const string& ep) {
    Endp = ep;
}

void Flight::setStarh(int sh) {
    starh = sh;
}

void Flight::setStarm(int sm) {
    starm = sm;
}

void Flight::setEndh(int eh) {
    endh = eh;
}

void Flight::setEndm(int em) {
    endm = em;
}

void Flight::setPrice(double pc) {
    price = pc;
}

bool Flight::operator==(const Flight& right) const
{
    return this->FlightNum == right.FlightNum;
}

bool Flight::operator>(const Flight& right) const
{
    return this->FlightNum > right.FlightNum;
}

bool Flight::operator<(const Flight& right) const
{
    return this->FlightNum < right.FlightNum;
}

void Flight::operator=(const Flight& right)
{
    this->FlightNum = right.FlightNum;
    this->Starp = right.Starp;
    this->Endp = right.Endp;
    this->starh = right.starh; this->endh = right.endh;
    this->starm = right.starm; this->endm = right.endm;
    this->price = right.price;
}

void Flight::show()
{
    cout << FlightNum << "\t " << Starp << "\t " << Endp << "\t  " << starh << ":" << starm << "\t          "\
        << endh << ":" << endm << "\t        " << price << "\t" << endl;
}

