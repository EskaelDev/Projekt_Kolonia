#include "stdafx.h"
#include <iostream>
#include "House.h"
using namespace std;

House::House(int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _inhabitants)
{
	bricksToBuild = _bricksToBuild;
	toolsToBuild = _toolsToBuild;
	woodToBuild = _woodToBuild;
	inhabitants = _inhabitants;
	number = 0;
}

bool House::Build(Resource & _Bricks, Resource & _Tools, Resource & _Wood)
{
	if (bricksToBuild > _Bricks.quantity || toolsToBuild > _Tools.quantity || woodToBuild > _Wood.quantity)
		return false;
	else
	{
		++number;
		_Bricks.quantity -= bricksToBuild;
		_Tools.quantity -= toolsToBuild;
		_Wood.quantity -= woodToBuild;
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

void House::test() const
{
	cout << "Liczba = " << number << endl;
	cout << "Cegly do budowy = " << bricksToBuild << endl;
	cout << "Narzedzia do budowy = " << toolsToBuild << endl;
	cout << "Drewno do budowy = " << woodToBuild << endl;
	cout << "Zajmowany obszar = " << size << endl;
	cout << "Mieszkancy = " << inhabitants << endl << endl;
}