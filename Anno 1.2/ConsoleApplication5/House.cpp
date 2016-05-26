#include "stdafx.h"
#include <iostream>
#include "House.h"
using namespace std;

House::House(int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _inhabitants, int _startPeople)
{
	number = 0;
	bricksToBuild = _bricksToBuild;
	toolsToBuild = _toolsToBuild;
	woodToBuild = _woodToBuild;
	size = 4;
	inhabitants = _inhabitants;
	startPeople = _startPeople;
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

int House::getStartPeople() const
{
	return startPeople;
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
}