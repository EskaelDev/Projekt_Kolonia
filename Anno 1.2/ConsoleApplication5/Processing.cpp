#include "stdafx.h"
#include <iostream>
#include "Processing.h"
using namespace std;

Processing::Processing(int _moneyToBuild, int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _maintenanceActiveCost, int _maintenancePassiveCost, 
	int _magazineCapacity, int _peopleToBuild, int _peopleClass, int _productID, int _materialID, int _productNumber, int _materialNumber)
{
	moneyToBuild = _moneyToBuild;
	bricksToBuild = _bricksToBuild;
	toolsToBuild = _toolsToBuild;
	woodToBuild = _woodToBuild;
	maintenanceActiveCost = _maintenanceActiveCost;
	maintenancePassiveCost = _maintenancePassiveCost;
	size = 4;													// jednakowa wartosc dla wszystkich budynkow processing
	magazineCapacity = _magazineCapacity;
	peopleToBuild = _peopleToBuild;
	peopleClass = _peopleClass;
	status = true;
	productID = _productID;
	materialID = _materialID;
	productNumber = _productNumber;
	materialNumber = _materialNumber;
}

int Processing::getMaterialID() const
{
	return materialID;
}

int Processing::getProductNumber() const
{
	return productNumber;
}

int Processing::getMaterialNumber() const
{
	return materialNumber;
}

void Processing::test() const
{
	Production::test();
	cout << "Indeks przetwarzanego towaru: " << materialID << endl;
	cout << "Liczba produkowanego towaru: " << productNumber << endl;
	cout << "Liczba przetwarzanego towaru: " << materialNumber << endl;
}