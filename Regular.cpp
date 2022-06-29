#include "pch.h"
#include "Regular.h"


Regular::Regular(CString number) : Car(number) {
	type = 3;
}

void Regular::setFeatures(int i)
{
	this->_gearbox[i] = true;
}

bool Regular::getFeatures(int i)
{
	return this->_gearbox[i];
}


