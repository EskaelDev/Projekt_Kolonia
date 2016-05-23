#include "stdafx.h"
#include "Processing.h"

Processing::Processing(int _moneyToBuild, int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _maintenanceActiveCost,
	int _maintenancePassiveCost, int _magazineCapacity, int _peopleToBuild, int _peopleClass, int _productID, int _materialID)
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
}

int Processing::getMaterialID() const
{
	return materialID;
}