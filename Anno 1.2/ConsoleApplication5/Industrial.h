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
	int peopleToBuild;				// liczba ludzi klasy peopleClass wymaga do budowy budynku
	int peopleClass;				// okresla jaka klasa ludnosci w liczbie peopleToBuild jest wymagana do spelnienia warunku dostepnosci budynku do budowy, 0 - Pioneers ... 4 - Aristocrats, dla -1 peopleToBuild = 0
	bool status;					// true - dostepny, false - niedostepny

public:
	Industrial();
	Industrial(int, int, int, int, int, int, int, int);
	~Industrial();
	void checkStatus(People &);																		// aktualizuje pole status
	int checkRequirements(int, int, int, int) const;												// 0 jesli brakuje surowcowow, 1 jesli sa dostepne surowce 
	void Build(Resource & _Money, Resource & _Bricks, Resource & _Tools, Resource & _Wood);			// aktualizuje stan surowcow po budowie i parametry budynku
	void Destroy();																					// niszczy budynek jesli istnieje
	int getMoney() const;
	int getClass() const;
	bool getStatus() const;
	void test() const;
};

#endif