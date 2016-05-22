#include "stdafx.h"
#include <iostream>
#include "Production.h"
using namespace std;

Production::Production()
{
	magazineCapacity = 0;
	peopleClass = -1;
	status = true;
	product = -1;
}

Production::Production(int _moneyToBuild, int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _maintenanceActiveCost,
	int _maintenancePassiveCost, int _size, int _magazineCapacity, int _peopleToBuild, int _peopleClass, int _product)
{
	moneyToBuild = _moneyToBuild;
	bricksToBuild = _bricksToBuild;
	toolsToBuild = _toolsToBuild;
	woodToBuild = _woodToBuild;
	maintenanceActiveCost = _maintenanceActiveCost;
	maintenancePassiveCost = _maintenancePassiveCost;
	size = _size;
	magazineCapacity = _magazineCapacity;
	peopleToBuild = _peopleToBuild;
	peopleClass = _peopleClass;
	status = true;
	product = _product;
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


int Production::getProduct() const
{
	return product;
}

void Production::test() const
{
	cout << "Liczba = " << number << endl;
	cout << "Pieniadze do budowy = " << moneyToBuild << endl;
	cout << "Cegly do budowy = " << bricksToBuild << endl;
	cout << "Narzedzia do budowy = " << toolsToBuild << endl;
	cout << "Drewno do budowy = " << woodToBuild << endl;
	cout << "Koszt aktywnej produkcji = " << maintenanceActiveCost << endl;
	cout << "Koszt wstrzymanej produkcji = " << maintenancePassiveCost << endl;
	cout << "Zajmowany obszar = " << size << endl;
	cout << "Pojemnosc magazynu = " << magazineCapacity << endl;
	cout << "Wymaga liczba ludzi do budowy = " << peopleToBuild << endl;
	cout << "Wymagana klasa ludzi: ";
	if (peopleClass == 0) cout << "Pioneers" << endl;
	else if (peopleClass == 1) cout << "Settlers" << endl;
	else if (peopleClass == 2) cout << "Citizens" << endl;
	else if (peopleClass == 3) cout << "Merchants" << endl;
	else if (peopleClass == 4) cout << "Aristocrats" << endl;
	else if (peopleClass == -1) cout << "-" << endl;
	cout << "Status dostepnosci: ";
	if (status == true) cout << "dostepny" << endl;
	else cout << "niedostepny" << endl;
}