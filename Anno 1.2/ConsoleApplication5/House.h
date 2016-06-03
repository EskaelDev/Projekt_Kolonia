#ifndef House_h  
#define House_h

#include "Building.h"
#include "Resource.h"
#include "Public.h"

class House : public Building
{
protected:
	int number;					// liczba budynkow
	int inhabitants;			// max ilosc mieszkancow dla jednego domu
	int startPeople;			// liczba mieszkancow, ktorzy wprowadzaja sie zaraz po budowie budynku
	int buildingID[3];			// tablica wartosci odpowiadajacych indeksom budynkow z tablicy tPublic, ktore sa wymagane aby wybudowac budynek, -1 oznacza brak wymagan co do budynku
	bool status;				// true - jesli dla budynku spelniono warunki z tablicy buildingID[], false - jesli nie

public:
	House(int, int, int, int, int, int, int, int);
	bool Build(Resource & _Bricks, Resource & _Tools, Resource & _Wood);	// tworzy budynek, zwraca false jesli nie ma dostepnych surowcow na budowe, true w przypadku powodzenia
	bool Destroy();															// niszczy budynek jesli istnieje, zwraca true w przypadku powodzenia i false w przypadku niepowodzenia
	int getNumber() const;
	int getInhabitants() const;
	int getStartPeople() const;
	int getBuildingID(int) const;											// argumentem jest indeks tablicy
	bool getStatus() const;
	void checkStatus(int);													// sprawdza czy posiadamy budynek i ustawia pole status
	void test() const;
};

#endif House_h
