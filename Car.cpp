#include "pch.h"
#include "Car.h"


CString Car::getNumber() {
	return _number;
}

Car::Car(CString number) {
	this->_isRent = false;
	this->_number = number;
	_topSpeed = 180;
}


int Car::getTopSpeed()
{
	return this->_topSpeed;
}


void Car::setQuantity(int num) {
	this->_quantity = num;
}

void Car::setCompany(CString company)
{
	this->_company = company;   
}

void Car::setIsRent(bool b)
{
	this->_isRent = b;
}

void Car::setColor(int color)
{
	this->_CarColor = color;
}

int Car::getColor()
{
	return this->_CarColor;
}

CString Car::getCompany() {
	return this->_company;
}


int Car::getQuantity() {
	return this->_quantity;
}

CString Car::getColorName()
{
	CString col;
	switch (this->_CarColor)
	{
	case 0:col = "red";
		break;
	case 1:col = "yellow";
		break;
	case 2: col = "blue";
		break;
	case 3:col = "black";
		break;
	case 4: col = "white";
		break;
	default:
		break;
	}
	return col;
}

bool Car::getIsRent()
{
	return this->_isRent;
}

