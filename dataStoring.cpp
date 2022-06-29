#include "pch.h"
#include "dataStoring.h"




vector<customer> dataStoring::clients = {};

vector<Car*> dataStoring::CarList = {};

IMPLEMENT_SERIAL(dataStoring , CObject, 0);

Car* dataStoring::getCarByNumber(CString CarNumber)
{
	for (auto it = this->CarList.begin(); it != this->CarList.end(); ++it)
	{
		if ((*it)->getNumber() == CarNumber)
		{
			return *it;
		}
	}
}

void dataStoring::carserilization(CArchive& arc,customer client)
{
	
}

void dataStoring::serializing(CArchive & arc) {
	if (arc.IsStoring())//save to file
	{
		int sizeOfCarList = CarList.size();
		arc << sizeOfCarList;
		for (int i = 0; i < sizeOfCarList; i++)
		{
			arc << CarList[i]->type;
			arc << CarList[i]->getNumber();
			arc << CarList[i]->getCompany();
			arc << CarList[i]->getQuantity();
			arc << CarList[i]->getIsRent();
			arc << CarList[i]->getColor();


			switch (CarList[i]->type)
			{
			case isLuxury :
				for (int j = 0; j < 2; j++)
				{
					arc << CarList[i]->getFeatures(j);
				}
				break;
			case isSport:
				for (int j = 0; j < 3; j++)
				{
					arc << CarList[i]->getFeatures(j);
				}
				break;
			case isComfort:
				for (int j = 0; j < 3; j++)
				{
					arc << CarList[i]->getFeatures(j);
				}
				break;
			case isRegular:
				for (int j = 0; j < 2; j++)
				{
					arc << CarList[i]->getFeatures(j);
				}
				break;
		
			default:
				break;
			}
		}

		int sizeOfClients = clients.size();
		arc << sizeOfClients;
		for (int i = 0; i < sizeOfClients; i++)
		{
			arc << clients[i].getDateOfBirth();
			arc << clients[i].getId();
			arc << clients[i].getName();
			int sizeOfRented = clients[i].listofrentedcars.size();
			arc << sizeOfRented;
			for (int j = 0; j < sizeOfRented; j++)
			{
				arc << clients[i].listofrentedcars[j].carNumber;
				arc << clients[i].listofrentedcars[j].deadLine;
				arc << clients[i].listofrentedcars[j].RentDate;
			}
			
		}
	}
	else//load from file
	{
		int numberofCars;
		arc >> numberofCars;
		for (int i = 0; i < numberofCars; i++)
		{
			int cartype;
			CString carNumber;
			Car* Carptr = nullptr;
			arc >> cartype;
			arc >> carNumber;
			switch (cartype)
			{
			case isLuxury:
				Carptr = new Luxury(carNumber);
				break;
			case isSport:
				Carptr = new Sport(carNumber);
				break;
			case isComfort:
				Carptr = new Comfort(carNumber);
				break;
			case isRegular:
				Carptr = new Regular(carNumber);
				break;

			default:
				break;
			}

			CString company;
			arc >> company;
			Carptr->setCompany(company);
			int quantity;
			arc >> quantity;
			Carptr->setQuantity(quantity);
			bool isrent;
			arc >> isrent;
			Carptr->setIsRent(isrent);
			int color;
			arc >> color;
			Carptr->setColor(color);
			bool temp;
			switch (cartype)
			{
			case isLuxury:
				for (int j = 0; j < 2; j++)
				{
					arc >> temp;
					if(temp)
			     		Carptr->setFeatures(j);
				}
				break;
			case isSport:
				for (int j = 0; j < 3; j++)
				{
					arc >> temp;
					if (temp)
						Carptr->setFeatures(j);
				}
				break;
			case isComfort:
				for (int j = 0; j < 3; j++)
				{
					arc >> temp;
					if (temp)
						Carptr->setFeatures(j);
				}
				break;
			case isRegular:
				for (int j = 0; j < 2; j++)
				{
					arc >> temp;
					if (temp)
						Carptr->setFeatures(j);
				}
				break;
			default:
				break;
			}
			CarList.push_back(Carptr);
		}



		int numOfClients, NumOfRent;
		arc >> numOfClients;
		COleDateTime Date, deadLine, RentDate;
		CString ID, Name, carnum;



		for (int i = 0; i < numOfClients; i++)
		{
			arc >> Date;
			arc >> ID;
			arc >> Name;
			customer c(ID, Name, Date);
			arc >> NumOfRent;
			for (int j = 0; j < NumOfRent; j++)
			{
				arc >> carnum;
				arc >> deadLine;
				arc >> RentDate;
				RentCars rc{ carnum,RentDate,deadLine };
				c.listofrentedcars.push_back(rc);
			}
			clients.push_back(c);
		}
	}
}