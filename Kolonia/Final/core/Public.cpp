#include "stdafx.h"
#include <iostream>
#include "Public.h"
#include "People.h"

using namespace std;

Public::Public() {}

Public::Public(int _moneyToBuild, int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _maintenanceActiveCost, int _size, int _peopleToBuild, int _peopleClass)
{
	number = 0;
	moneyToBuild = _moneyToBuild;
	bricksToBuild = _bricksToBuild;
	toolsToBuild = _toolsToBuild;
	woodToBuild = _woodToBuild;
	maintenanceActiveCost = _maintenanceActiveCost;
	size = _size;
	peopleToBuild = _peopleToBuild;
	peopleClass = _peopleClass;
	status = true;
}

bool Public::Build(Resource & _Money, Resource & _Bricks, Resource & _Tools, Resource & _Wood)
{
	if (moneyToBuild > _Money.number || bricksToBuild > _Bricks.number || toolsToBuild > _Tools.number || woodToBuild > _Wood.number)
		return false;
	else
	{
		++number;
		_Money.number -= moneyToBuild;
		_Bricks.number -= bricksToBuild;
		_Tools.number -= toolsToBuild;
		_Wood.number -= woodToBuild;
		return true;
	}
}

bool Public::Destroy()
{
	if (number > 0)
	{
		--number;
		return true;
	}
	else
		return false;
}

int Public::getNumber() const
{
	return number;
}

void Public::test() const
{
	cout << "Liczba = " << number << endl;
	cout << "Pieniadze do budowy = " << moneyToBuild << endl;
	cout << "Cegly do budowy = " << bricksToBuild << endl;
	cout << "Narzedzia do budowy = " << toolsToBuild << endl;
	cout << "Drewno do budowy = " << woodToBuild << endl;
	cout << "Koszt utrzymania budynku = " << maintenanceActiveCost << endl;
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
