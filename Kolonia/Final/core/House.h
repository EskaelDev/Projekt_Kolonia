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
	int* buildingId;			// wskaznik tablicy wartosci odpowiadajacych indeksom budynkow z tablicy tPublic, ktore sa wymagane aby wybudowac budynek, wskaznik nie wksazuje na nic, jezeli nie ma wymagan
	int tabIdSize;				// rozmiar tablicy buidingID

public:
	House(int, int, int, int, int, int[], int);
	bool Build(Resource* [21]) override;	// tworzy budynek, zwraca false jesli nie ma dostepnych surowcow na budowe, true w przypadku powodzenia
	bool Destroy();							// niszczy budynek jesli istnieje, zwraca true w przypadku powodzenia i false w przypadku niepowodzenia
	int getNumber() const;
	int getInhabitants() const;
	int getStartPeople() const;									
	int getBuildingId(int) const;			// argumentem jest indeks tablicy
	int getTabIdSize() const;
	void setNumber(int);
	void checkStatus(int) override;			// sprawdza czy posiadamy budynek i ustawia pole status
	virtual ~House() override;
};

#endif House_h
