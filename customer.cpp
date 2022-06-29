#include "pch.h"
#include "customer.h"

customer::customer(CString ID, CString name, COleDateTime DateOfBirth) {
	this->ID = ID;
	this->DateOfBirth = DateOfBirth;
	this->name = name;
}

CString customer::getId() {
	return this->ID;
}

CString customer::getName() {
	return this->name;
}

COleDateTime customer::getDateOfBirth() {
	return this->DateOfBirth;
}

void customer::ToRent(CString CarNumber)
{

	COleDateTime ren = COleDateTime::GetCurrentTime();
	COleDateTime ret = COleDateTime::GetCurrentTime();
	ret+=COleDateTimeSpan(60, 0, 0, 0);
	RentCars new_Rent = { CarNumber , ren , ret};
	this->listofrentedcars.push_back(new_Rent);

}
int customer::Toretrive(CString CarNumber)
{
	int i;
	for (i = 0; i < listofrentedcars.size(); i++)
	{
		if (listofrentedcars[i].carNumber == CarNumber)
		{
			listofrentedcars.erase(listofrentedcars.begin() + i);
			return 1;
		}
	}
	MessageBox(NULL, L" Car is not rented by this costumer", L"Error",MB_ICONWARNING);
	return 0;
}
