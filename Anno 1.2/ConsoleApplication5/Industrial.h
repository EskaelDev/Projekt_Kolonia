#ifndef Industrial_h
#define Industrial_h

#include "Building.h"
#include "Resource.h"

class Industrial : public Building
{
protected:
	int moneyToBuild;
	int maintenanceActiveCost;		// koszty utrzymania przy aktywnej produkcji
	int maintenancePassiveCost;		// koszty utrzymania przy wstrzymanej produkcji
	int peopleToBuild;

public:
	Industrial();
	Industrial(int, int, int, int, int, int, int, int);
	~Industrial();
	int checkRequirements(int, int, int, int) const;												// domyslnie ustawione na -1, zwraca wartosc -1 jesli warunki do budowy nie sa spelnione, 0 jesli sa spelnione ale brakuje surowcow, 1 jesli sa spelnione warunki i dostepne surowce 
	void Build(Resource & _Money, Resource & _Bricks, Resource & _Tools, Resource & _Wood);			// aktualizuje stan surowcow po budowie i parametry budynku
	void Destroy();
	int getId() const;
	int getMoney() const;
	void test() const;
};

#endif