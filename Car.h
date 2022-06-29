#pragma once  //abstract parent class

#include <string>

using namespace std;

enum Color
{
	red,yellow,blue,black,white
};

class Car : public CObject
{
protected:
	CString _number;
	CString _company;
	int _topSpeed;
	int _quantity;
	int _CarColor;
	bool _isRent;
public:
	int type;
	Car(CString number);
	
	//getters
	bool getStatus() { return (_quantity > 0); }
	CString getNumber();
	int getTopSpeed();
	CString getCompany();
	int getQuantity();
	CString getColorName();
	bool getIsRent();
	virtual int getColor();

	
	//setters
	void setQuantity(int);
	void setCompany(CString);
	void setIsRent(bool);
	virtual void setColor(int);


	//pure
	virtual void setFeatures(int)=0;
	virtual bool getFeatures(int) = 0;

};

