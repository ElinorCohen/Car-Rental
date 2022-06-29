#include "pch.h"
#include "Luxury.h"


Luxury::Luxury(CString number) : Sport(number) {
	type = 0;
}

void Luxury::setFeatures(int i)
{
	this->_seats[i] = true;
}

bool Luxury::getFeatures(int i)
{
	return this->_seats[i];
}