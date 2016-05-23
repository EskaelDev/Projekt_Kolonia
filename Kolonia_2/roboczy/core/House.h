#ifndef House_h  
#define House_h

#include "Building.h"
using namespace std;

class House : public Building
{
protected:
	int inhabitants;			// max ilosc mieszkancow dla jednego domu

public:
	House();
	House(int, int, int, int);
	~House();
	void test() const;
};

#endif House_h
