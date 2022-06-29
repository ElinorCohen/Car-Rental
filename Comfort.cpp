#include "pch.h"
#include "Comfort.h"
#include "Car.h"


Comfort::Comfort(CString number) : Sport(number)
{
	
	type = 2;//בחירה של כפתור רדיו 
}

void Comfort::setFeatures(int i)
{
	this->_seats[i] = true;
}

bool Comfort::getFeatures(int i)
{
	return this->_seats[i];
}