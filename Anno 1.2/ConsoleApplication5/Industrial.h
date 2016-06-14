#ifndef Industrial_h
#define Industrial_h

#include "Building.h"

class Industrial : public Building
{
protected:
	int moneyToBuild;			// liczba pieniedzy wymagana do budowy
	int maintenanceActiveCost;	// koszty utrzymania budynku
	int peopleToBuild;			// liczba ludzi klasy peopleClass wymaga do budowy budynku
	int peopleClass;			// okresla jaka klasa ludnosci w liczbie peopleToBuild jest wymagana do spelnienia warunku dostepnosci budynku do budowy, 0 - Pioneers ... 4 - Aristocrats, dla -1 peopleToBuild = 0			

public:
	Industrial();
	void checkStatus(int) override;		// aktualizuje pole status w oparciu o spelnienie warunku wymaganej liczby ludzi										
	int getMoney() const;
	int getClass() const;
	int getMaintenanceActiveCost() const;
};

#endif


