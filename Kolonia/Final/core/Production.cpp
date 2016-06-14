#include "stdafx.h"
#include "Production.h"

Production::Production() {}

Production::Production(int _moneyToBuild, int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _maintenanceActiveCost,
	int _maintenancePassiveCost, int _size, int _magazineCapacity, int _peopleToBuild, int _peopleClass, int _productID)
{
	number = 0;
	moneyToBuild = _moneyToBuild;
	bricksToBuild = _bricksToBuild;
	toolsToBuild = _toolsToBuild;
	woodToBuild = _woodToBuild;
	maintenanceActiveCost = _maintenanceActiveCost;
	maintenancePassiveCost = _maintenancePassiveCost;
	activeNumber = 0;
	size = _size;
	magazineCapacity = _magazineCapacity;
	peopleToBuild = _peopleToBuild;
	peopleClass = _peopleClass;
	status = true;
	productID = _productID;
}

bool Production::Build(Resource *TResource[21])
{
	if (true == Public::Build(TResource))
	{
		++activeNumber;
		return true;
	}
	else 
		return false;
}

bool Production::activate()
{
	if (number - activeNumber > 0)					// number - activeNumber = passiveNumber
	{
		++activeNumber;
		return true;
	}
	else
		return false;
}

bool Production::deactivate()
{
	if (activeNumber > 0)
	{
		--activeNumber;
		return true;
	}
	else
		return false;
}

int Production::getProductID() const
{
	return productID;
}

int Production::getMagazineCapacity() const
{
	return magazineCapacity;
}

int Production::getMaintenancePassiveCost() const
{
	return maintenancePassiveCost;
}

int Production::getActiveNumber() const
{
	return activeNumber;
}