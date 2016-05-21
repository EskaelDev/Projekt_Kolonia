#include "stdafx.h"
#include <iostream>
#include "Industrial.h"
using namespace std;

Industrial::Industrial()
{
	moneyToBuild = 0;
	maintenanceActiveCost = 0;
	maintenancePassiveCost = 0;
	peopleToBuild = 0;
}

Industrial::Industrial(int _id, int _moneyToBuild, int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _maintenanceCost, int _size, int _peopleToBuild)
{
	id = _id;
	moneyToBuild = _moneyToBuild;
	bricksToBuild = _bricksToBuild;
	toolsToBuild = _toolsToBuild;
	woodToBuild = _woodToBuild;
	maintenanceActiveCost = _maintenanceCost;
	maintenancePassiveCost = _maintenanceCost;
	size = _size;
	peopleToBuild = _peopleToBuild;
}

Industrial::~Industrial()
{
}

int Industrial::checkRequirements(int money, int bricks, int tools, int wood) const
{
	if (false) // jakie wymagania?
		return -1;
	else if (moneyToBuild > money || bricksToBuild > bricks || toolsToBuild > tools || woodToBuild > wood)
		return 0;
	else
		return 1;
}

void Industrial::Build(Resource & _Money, Resource & _Bricks, Resource & _Tools, Resource & _Wood)
{
	++number;
	_Money.quantity -= moneyToBuild;
	_Bricks.quantity -= bricksToBuild;
	_Tools.quantity -= toolsToBuild;
	_Wood.quantity -= woodToBuild;
}

void Industrial::Destroy()
{
	--number;
}

int Industrial::getId() const
{
	return id;
}

int Industrial::getMoney() const
{
	return moneyToBuild;
}

void Industrial::test() const
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
	cout << "Wymaga liczba ludzi do budowy = " << peopleToBuild << endl << endl;
}
