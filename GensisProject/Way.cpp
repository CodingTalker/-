#include "Way.h"

Way::Way():star(0),end(0),costTime(0),starh(0),starm(0),endh(0),endm(0),price(0.0),isFlight(false)\
,wid(""),starp(""),endp(""){
}

string Way::getDetalId() const
{
	string t(wid);
	if (isFlight)
		t = t + "(·É»ú)";
	else
		t = t + "(ÁÐ³µ)";
	return t;
}

string Way::getStarTime()const {
    char h[3], m[3];
    snprintf(h, 3, "%02d", starh);
    snprintf(m, 3, "%02d", starm);
    string t(h);
    t = t + ':';
    t = t + m;
    return t;
}

string Way::getEndTime()const {
    char h[3], m[3];
    snprintf(h, 3, "%02d", endh);
    snprintf(m, 3, "%02d", endm);
    string t(h);
    t = t + ':';
    t = t + m;
    return t;
}
