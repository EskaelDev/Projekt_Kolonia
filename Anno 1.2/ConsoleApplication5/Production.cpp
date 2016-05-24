#include "stdafx.h"
#include <iostream>
#include "Production.h"
using namespace std;

Production::Production() {}

Production::Production(int _moneyToBuild, int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _maintenanceActiveCost,
	int _maintenancePassiveCost, int _size, int _magazineCapacity, int _peopleToBuild, int _peopleClass, int _productID)
{
	moneyToBuild = _moneyToBuild;
	bricksToBuild = _bricksToBuild;
	toolsToBuild = _toolsToBuild;
	woodToBuild = _woodToBuild;
	maintenanceActiveCost = _maintenanceActiveCost;
	maintenancePassiveCost = _maintenancePassiveCost;
	size = _size;
	magazineCapacity = _magazineCapacity;
	peopleToBuild = _peopleToBuild;
	peopleClass = _peopleClass;
	status = true;
	productID = _productID;
}

bool Production::activate()
{
	return true;
}

bool Production::deactivate()
{
	return true;
}


int Production::getProductID() const
{
	return productID;
}

void Production::test() const
{
	Industrial::test();
	cout << "Pojemnosc magazynu = " << magazineCapacity << endl;
	cout << "Indeks produkowanego towaru: " << productID << endl;
}
