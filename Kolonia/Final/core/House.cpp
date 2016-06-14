#include "stdafx.h"
#include "House.h"
#include "GlobalVariables.h"

House::House(int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _inhabitants, int _startPeople, int tabBuildingId[], int tabSize)
{
	number = 0;
	bricksToBuild = _bricksToBuild;
	toolsToBuild = _toolsToBuild;
	woodToBuild = _woodToBuild;
	size = 4;
	inhabitants = _inhabitants;
	startPeople = _startPeople;
	status = true;
	tabIdSize = tabSize;
	if (tabBuildingId[0] > -1)
	{
		buildingId = new int[tabSize];
		for (int i = 0; i < tabSize; ++i)
			buildingId[i] = tabBuildingId[i];
	}
	else
		buildingId = 0;
}

bool House::Build(Resource *TResource[21])
{
	if (bricksToBuild > TResource[Bricks]->getNumber() || toolsToBuild > TResource[Tools]->getNumber() || woodToBuild > TResource[Wood]->getNumber())
		return false;
	
	else
	{
		++number;
		TResource[Bricks]->decrease(bricksToBuild);
		TResource[Tools]->decrease(toolsToBuild);
		TResource[Wood]->decrease(woodToBuild);
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

int House::getBuildingId(int index) const
{
	return buildingId[index];
}

int House::getTabIdSize() const
{
	return tabIdSize;
}

void House::setNumber(int _number)
{
	number = _number;
}

void House::checkStatus(int buildingNumber)
{
	if (buildingNumber > 0)
		status = true;
	else
		status = false;
}

House::~House()
{
	delete[] buildingId;
}