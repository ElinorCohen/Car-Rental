#pragma once
#include "Car.h"

enum seats
{
	regular, orthopedic, leather
};

class Sport : public Car
{
protected:
	bool _seats[3];
public:
	Sport(CString number);
	void setFeatures(int);
	bool getFeatures(int);
};

