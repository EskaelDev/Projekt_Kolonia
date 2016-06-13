#include "stdafx.h"
#include <iostream>
#include "Magazine.h"
#include "People.h"
#include "GlobalVariables.h"
using namespace std;

Magazine::Magazine()
{
	bricksToBuild = 0;
	toolsToBuild = 3;
	woodToBuild = 7;
	size = 6;
	moneyToBuild = 180;
	maintenanceActiveCost = 15;
	peopleToBuild = 30;
	peopleClass = 1;
	status = true;
	level = 1;
	magazineCapacity = 70;
}

bool Magazine::Build(Resource* TResource[21])
{
	if (level < 4)
	{
		if (moneyToBuild > TResource[Money]->getNumber() || bricksToBuild > TResource[Bricks]->getNumber() || toolsToBuild > TResource[Tools]->getNumber() || woodToBuild > TResource[Wood]->getNumber())
			return false;
		
		else
		{
			TResource[Money]->decrease(moneyToBuild);
			TResource[Bricks]->decrease(bricksToBuild);
			TResource[Tools]->decrease(toolsToBuild);
			TResource[Wood]->decrease(woodToBuild);

			if (2 == level)
			{
				magazineCapacity = 120;
				moneyToBuild = 250;
				bricksToBuild = 6;
				toolsToBuild = 4;
				woodToBuild = 4;
				peopleToBuild = 100;
				peopleClass = 2;
			}

			else if (3 == level)
			{
				magazineCapacity = 200;
				bricksToBuild = 10;
				toolsToBuild = 5;
				peopleToBuild = 250;
				peopleClass = 3;
			}

			++level;
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
