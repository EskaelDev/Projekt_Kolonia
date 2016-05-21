#include "stdafx.h"
#include <iostream>
#include "Production.h"
using namespace std;

Production::Production()
{
	magazineCapacity = 0;
}

Production::Production(int _id, int _moneyToBuild, int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _maintenanceActiveCost,
	int _maintenancePassiveCost, int _size, int _magazineCapacity, int _peopleToBuild)
{
	id = _id;
	moneyToBuild = _moneyToBuild;
	bricksToBuild = _bricksToBuild;
	toolsToBuild = _toolsToBuild;
	woodToBuild = _woodToBuild;
	maintenanceActiveCost = _maintenanceActiveCost;
	maintenancePassiveCost = _maintenancePassiveCost;
	size = _size;
	magazineCapacity = _magazineCapacity;
	peopleToBuild = _peopleToBuild;
}

Production::~Production()
{
}

bool Production::activate()
{
	return true;
}

bool Production::deactivate()
{
	return true;
}

void Production::test() const
{
	cout << "Id = " << id << endl;
	cout << "Liczba = " << number << endl;
	cout << "Pieniadze do budowy = " << moneyToBuild << endl;
	cout << "Cegly do budowy = " << bricksToBuild << endl;
	cout << "Narzedzia do budowy = " << toolsToBuild << endl;
	cout << "Drewno do budowy = " << woodToBuild << endl;
	cout << "Koszt aktywnej produkcji = " << maintenanceActiveCost << endl;
	cout << "Koszt wstrzymanej produkcji = " << maintenancePassiveCost << endl;
	cout << "Zajmowany obszar = " << size << endl;
	cout << "Pojemnosc magazynu = " << magazineCapacity << endl;
	cout << "Wymaga liczba ludzi do budowy = " << peopleToBuild << endl << endl;
}