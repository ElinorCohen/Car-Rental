#pragma once
#include "Car.h"
#include "customer.h"
#include "Comfort.h"
#include "Luxury.h"
#include "Sport.h"
#include "Regular.h"




enum car_type
{
	isLuxury, isSport, isComfort, isRegular
};

class dataStoring : public CObject
{
public:
	static vector<customer> clients;
	static vector<Car*> CarList;
	Car* getCarByNumber(CString CarNumber);
	void carserilization(CArchive& arc, customer client);
	void serializing(CArchive & arc);
	DECLARE_SERIAL(dataStoring);
};

