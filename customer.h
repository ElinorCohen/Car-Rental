#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Car.h"

using namespace std;

//typedef struct date
//{
//	int day;
//	int month;
//	int year;
//}date;

typedef struct RentCars
{
	CString carNumber;
	COleDateTime RentDate;
	COleDateTime deadLine;
}RentCars;

class customer 
{
private:
	CString ID;
	COleDateTime DateOfBirth;
	CString name;
public:
	customer(CString ID, CString name, COleDateTime DateOfBirth);
	CString getId();
	CString getName();
	COleDateTime getDateOfBirth();
	void ToRent(CString);
	int Toretrive(CString);
	vector<RentCars> listofrentedcars;
};