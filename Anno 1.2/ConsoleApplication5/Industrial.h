#ifndef Industrial_h
#define Industrial_h

#include "Building.h"
#include "Resource.h"
#include "People.h"

class Industrial : public Building
{
protected:
	int moneyToBuild;
	int maintenanceActiveCost;		// koszty utrzymania przy aktywnej produkcji
	int maintenancePassiveCost;		// koszty utrzymania przy wstrzymanej produkcji
	int peopleToBuild;
	int peopleClass;				// okresla jaka klasa ludnosci w ilosci peopleToBuild jest wymagana do spelnienia warunku dostepnosci budynku do budowy, 1 - Pioneers ... 5 - Aristocrats, 0 - nie ma warunku

public:
	Industrial();
	Industrial(int, int, int, int, int, int, int, int);
	~Industrial();
	int checkStatus(Industrial &, People &) const;
	int checkRequirements(int, int, int, int) const;												// 0 jesli brakuje surowcowow, 1 jesli sa dostepne surowce 
	void Build(Resource & _Money, Resource & _Bricks, Resource & _Tools, Resource & _Wood);			// aktualizuje stan surowcow po budowie i parametry budynku
	void Destroy();																					// niszczy budynek jesli istnieje
	int getMoney() const;
	void test() const;
};

#endif