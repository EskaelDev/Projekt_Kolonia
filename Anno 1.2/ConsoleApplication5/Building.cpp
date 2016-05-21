#include "stdafx.h"
#include "Building.h"

Building::Building()
{
	id = 0;
	number = 0;
	bricksToBuild = 0;
	toolsToBuild = 0;
	woodToBuild = 0;
	size = 4;
}

int Building::getNumber() const
{
	return number;
}

int Building::getBricks() const
{
	return bricksToBuild;
}

int Building::getTools() const
{
	return toolsToBuild;
}

int Building::getWood() const
{
	return woodToBuild;
}

