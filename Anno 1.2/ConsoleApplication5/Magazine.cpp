#include "stdafx.h"
#include <iostream>
#include "Magazine.h"
#include "People.h"

using namespace std;

Magazine::Magazine()
{
	bricksToBuild = 0;
	toolsToBuild = 3;
	woodToBuild = 6;
	size = 6;
	moneyToBuild = 100;
	maintenanceActiveCost = 15;
	peopleToBuild = 0;
	peopleClass = -1;
	status;
	level = 0;
	magazineCapacity = 30;
}

Magazine::Magazine(int _moneyToBuild, int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _maintenanceActiveCost, int _peopleToBuild, int _peopleClass, int _magazineCapacity)
{
	level = 1;
	moneyToBuild = _moneyToBuild;
	bricksToBuild = _bricksToBuild;
	toolsToBuild = _toolsToBuild;
	woodToBuild = _woodToBuild;
	maintenanceActiveCost = _maintenanceActiveCost;
	size = 4;
	peopleToBuild = _peopleToBuild;
	peopleClass = _peopleClass;
	status = true;
	magazineCapacity = _magazineCapacity;
}

void Magazine::test() const
{
	cout << "Poziom magazynu = " << level << endl;
	cout << "Pojemnosc magazynu = " << magazineCapacity << endl;
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
