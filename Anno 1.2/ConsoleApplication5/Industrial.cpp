#include "stdafx.h"
#include <iostream>
#include "Industrial.h"
#include "People.h"
using namespace std;

Industrial::Industrial()
{
	moneyToBuild = 0;
	maintenanceActiveCost = 0;
	maintenancePassiveCost = 0;
	peopleToBuild = 0;
	peopleClass = 0;
}

Industrial::Industrial(int _moneyToBuild, int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _maintenanceCost, int _size, int _peopleToBuild, int _peopleClass)
{
	moneyToBuild = _moneyToBuild;
	bricksToBuild = _bricksToBuild;
	toolsToBuild = _toolsToBuild;
	woodToBuild = _woodToBuild;
	maintenanceActiveCost = _maintenanceCost;
	maintenancePassiveCost = _maintenanceCost;
	size = _size;
	peopleToBuild = _peopleToBuild;
	peopleClass = _peopleClass;
}

Industrial::~Industrial()
{
}

int Industrial::checkStatus(Industrial & _nameB, People & _nameP) const
{
	if (peopleToBuild > _nameP.getNumber())
		return 1;
	else
		return 0;
}

int Industrial::checkRequirements(int money, int bricks, int tools, int wood) const
{
	if (moneyToBuild > money || bricksToBuild > bricks || toolsToBuild > tools || woodToBuild > wood)
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
	if(number > 0)
		--number;
}

int Industrial::getMoney() const
{
	return moneyToBuild;
}

void Industrial::test() const
{
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
