#ifndef Industrial_h
#define Industrial_h

#include "Building.h"
#include "Resource.h"
#include "People.h"

class Industrial : public Building
{
protected:
	int moneyToBuild;				// liczba pieniedzy wymagana do budowy
	int maintenanceActiveCost;		// koszty utrzymania przy aktywnej produkcji
	int maintenancePassiveCost;		// koszty utrzymania przy wstrzymanej produkcji
	int peopleToBuild;				// liczba ludzi klasy peopleClass wymaga do budowy budynku
	int peopleClass;				// okresla jaka klasa ludnosci w liczbie peopleToBuild jest wymagana do spelnienia warunku dostepnosci budynku do budowy, 0 - Pioneers ... 4 - Aristocrats, dla -1 peopleToBuild = 0
	bool status;					// true - dostepny do budowy, false - niedostepny

public:
	Industrial();
	Industrial(int, int, int, int, int, int, int, int);
	void checkStatus(People &);																		// aktualizuje pole status w oparciu o spelnienie warunku wymaganej liczby ludzi  											
	bool Build(Resource & _Money, Resource & _Bricks, Resource & _Tools, Resource & _Wood);			// aktualizuje stan surowcow po budowie i parametry budynku, zwraca false jesli brakuje surowcowow, true jesli sa dostepne surowce 
	bool Destroy();																					// niszczy budynek jesli istnieje, w przypadku powodzenia zwraca true, w przypadku niepowodzenia false
	int getMoney() const;
	int getClass() const;
	bool getStatus() const;
	void test() const;
};

#endif