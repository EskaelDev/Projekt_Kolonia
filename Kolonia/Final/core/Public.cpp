#include "stdafx.h"
#include "Public.h"
#include "People.h"
#include "GlobalVariables.h"

Public::Public() {}

Public::Public(int _moneyToBuild, int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _maintenanceActiveCost, int _size, int _peopleToBuild, int _peopleClass)
{
	number = 0;
	moneyToBuild = _moneyToBuild;
	bricksToBuild = _bricksToBuild;
	toolsToBuild = _toolsToBuild;
	woodToBuild = _woodToBuild;
	maintenanceActiveCost = _maintenanceActiveCost;
	size = _size;
	peopleToBuild = _peopleToBuild;
	peopleClass = _peopleClass;
	status = true;
}

bool Public::Build(Resource* TResource[21])
{
	if (moneyToBuild > TResource[Money]->getNumber() || bricksToBuild > TResource[Bricks]->getNumber() || toolsToBuild > TResource[Tools]->getNumber() || woodToBuild > TResource[Wood]->getNumber())
		return false;
	else
	{
		++number;
		TResource[Money]->decrease(moneyToBuild);
		TResource[Bricks]->decrease(bricksToBuild);
		TResource[Tools]->decrease(toolsToBuild);
		TResource[Wood]->decrease(woodToBuild);
		return true;
	}
}

bool Public::Destroy()
{
	if (number > 0)
	{
		--number;
		return true;
	}
	else
		return false;
}

int Public::getNumber() const
{
	return number;
}

void Public::setNumber(int _number)
{
	number = _number;
}