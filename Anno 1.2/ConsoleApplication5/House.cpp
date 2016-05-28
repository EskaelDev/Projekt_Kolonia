#include "stdafx.h"
#include <iostream>
#include "House.h"
using namespace std;

House::House(int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _inhabitants, int _startPeople, int buildingID0, int buildingID1, int buildingID2)
{
	number = 0;
	bricksToBuild = _bricksToBuild;
	toolsToBuild = _toolsToBuild;
	woodToBuild = _woodToBuild;
	size = 4;
	inhabitants = _inhabitants;
	startPeople = _startPeople;
	buildingID[0] = buildingID0;
	buildingID[1] = buildingID1;
	buildingID[2] = buildingID2;
	status = true;
}

bool House::Build(Resource & _Bricks, Resource & _Tools, Resource & _Wood)
{
	if (bricksToBuild > _Bricks.number || toolsToBuild > _Tools.number || woodToBuild > _Wood.number)
		return false;
	else
	{
		++number;
		_Bricks.number -= bricksToBuild;
		_Tools.number -= toolsToBuild;
		_Wood.number -= woodToBuild;
		return true;
	}
}

bool House::Destroy()
{
	if (number > 0)
	{
		--number;
		return true;
	}
	else
		return false;
}

int House::getNumber() const
{
	return number;
}

int House::getInhabitants() const
{
	return inhabitants;
}

int House::getStartPeople() const
{
	return startPeople;
}

int House::getBuildingID(int index) const
{
	return buildingID[index];
}

bool House::getStatus() const
{
	return status;
}

void House::checkStatus(Public & _Building)
{
	if (_Building.getNumber() > 0)
		status = true;
	else
		status = false;
}


void House::test() const
{
	cout << "Liczba = " << number << endl;
	cout << "Cegly do budowy = " << bricksToBuild << endl;
	cout << "Narzedzia do budowy = " << toolsToBuild << endl;
	cout << "Drewno do budowy = " << woodToBuild << endl;
	cout << "Zajmowany obszar = " << size << endl;
	cout << "Mieszkancy max = " << inhabitants << endl;
	cout << "Mieszkancy po wprowadzeniu = " << startPeople << endl;
	if (buildingID[0] > -1) cout << "Budynki wymagane do budowy: ";
	if (4 == buildingID[0]) cout << "kaplica, plac targowy" << endl;
	if (2 == buildingID[0]) cout << "straz ogniowa, szkola, tawerna" << endl;
	if (0 == buildingID[0]) cout << "przychodnia lekarska, laznia publiczna, kosciol" << endl;
	if (3 == buildingID[0]) cout << "uniwersytet, teart, katedra" << endl;
	cout << "Status dostepnosci: ";
	if (status == true) cout << "dostepny" << endl;
	else cout << "niedostepny" << endl;
}