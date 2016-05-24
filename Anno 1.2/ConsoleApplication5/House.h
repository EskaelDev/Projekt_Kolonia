#ifndef House_h  
#define House_h

#include "Building.h"
#include "Resource.h"

class House : public Building
{
protected:
	int inhabitants;			// max ilosc mieszkancow dla jednego domu
	int startPeople;			// liczba mieszkancow, ktorzy wprowadzaja sie zaraz po budowie budynku

public:
	House(int, int, int, int, int);
	bool Build(Resource & _Bricks, Resource & _Tools, Resource & _Wood);			// tworzy budynek, zwraca false jesli nie ma dostepnych surowcow na budowe, true w przypadku powodzenia
	bool Destroy();																	// niszczy budynek jesli istnieje, zwraca true w przypadku powodzenia i false w przypadku niepowodzenia
	int getStartPeople() const;
	void test() const;
};

#endif House_h
