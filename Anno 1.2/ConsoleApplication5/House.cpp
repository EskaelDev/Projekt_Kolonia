#include "stdafx.h"
#include <iostream>
#include "House.h"
using namespace std;

House::House() : inhabitants(0) {}

House::House(int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _inhabitants)
{
	bricksToBuild = _bricksToBuild;
	toolsToBuild = _toolsToBuild;
	woodToBuild = _woodToBuild;
	inhabitants = _inhabitants;
}

House::~House()
{
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