#pragma once

#include "Car.h"

enum gearbox {
	no, yes
};

class Regular : public Car
{
protected:
	bool _gearbox[2];
public:
	Regular(CString number);
	void setFeatures(int);
	bool getFeatures(int);
};

