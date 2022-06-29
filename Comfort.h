#pragma once
#include "Sport.h"

enum size {
     mini, medium, big
};

class Comfort : public Sport
{
protected:
	bool _size[3];
	
public:
	Comfort(CString);
	void setFeatures(int);
	bool getFeatures(int);
};

