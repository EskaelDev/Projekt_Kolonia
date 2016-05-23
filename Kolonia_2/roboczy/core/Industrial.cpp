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
	peopleClass = -1;
	status = true;
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
	status = true;
}

Industrial::~Industrial()
{
}

void Industrial::checkStatus(People & _class) 
{
	if (peopleToBuild > _class.getNumber())
		status = false;
	else
		status = true;
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

int Industrial::getClass() const
{
	return peopleClass;
}

bool Industrial::getStatus() const
{
	return status;
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
	cout << "Wymagana liczba ludzi do budowy = " << peopleToBuild << endl;
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
