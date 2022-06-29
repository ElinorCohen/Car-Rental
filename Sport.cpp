#include "pch.h"
#include "Sport.h"


Sport::Sport(CString number) : Car(number) {
	_topSpeed = 350;
	type = 1;
}

void Sport::setFeatures(int i)
{
	this->_seats[i] = true;
}

bool Sport::getFeatures(int i)
{
	return this->_seats[i];
}

