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
	status = true;
	level = 0;
	magazineCapacity = 0;
}

bool Magazine::Build(Resource & _Money, Resource & _Bricks, Resource & _Tools, Resource & _Wood)
{
	if (level < 4)
	{
		if (moneyToBuild > _Money.number || bricksToBuild > _Bricks.number || toolsToBuild > _Tools.number || woodToBuild > _Wood.number)
			return false;
		
		else
		{
			_Money.number -= moneyToBuild;
			_Bricks.number -= bricksToBuild;
			_Tools.number -= toolsToBuild;
			_Wood.number -= woodToBuild;
			++level;
			if (0 == level)
			{
				magazineCapacity = 30;
				moneyToBuild = 180;
				woodToBuild = 7;
				peopleToBuild = 30;
				peopleClass = 1;
			}

			else if (1 == level)
			{
				magazineCapacity = 50;
				moneyToBuild = 250;
				bricksToBuild = 6;
				toolsToBuild = 4;
				woodToBuild = 4;
				peopleToBuild = 100;
				peopleClass = 2;
			}

			else if (2 == level)
			{
				magazineCapacity = 75;
				bricksToBuild = 10;
				toolsToBuild = 5;
				peopleToBuild = 250;
				peopleClass = 3;
			}
			else if (3 == level)
			{
				magazineCapacity = 100;
			}

			return true;
		}
	}

	return false;
}

int Magazine::getmagazineCapacity() const
{
	return magazineCapacity;
}

int Magazine::getLevel() const
{
	return level;
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
