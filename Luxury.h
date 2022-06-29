#pragma once

#include "Sport.h"
enum Metal {
	Mno, Myes
};

class Luxury : public Sport
{
protected:
	bool _metal[2];
public:
	Luxury(CString number);
	void setFeatures(int);
	bool getFeatures(int);

};

