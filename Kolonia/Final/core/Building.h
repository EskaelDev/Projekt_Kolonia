#ifndef Building_h
#define Building_h

#include "Resource.h"

class Building
{
protected:
	int bricksToBuild;			// liczba cegiel wymaganych do budowy
	int toolsToBuild;			// liczba narzedzi wymaganych do budowy
	int woodToBuild;			// liczba drewna wymaganych do budowy
	int size;					// liczba pol zajmowana przez budynek
	bool status;				// true - dostepny do budowy, false - niedostepny

public:
	int getBricks() const;
	int getTools() const;
	int getWood() const;
	int getSize() const;
	bool getStatus() const;

	virtual ~Building() {};
	virtual bool Build(Resource* [21]) = 0;
	virtual void checkStatus(int) = 0;		
	virtual void test() const = 0;
};

#endif