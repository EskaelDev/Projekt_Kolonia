#include "stdafx.h"
#include "Building.h"

Building::Building() {}

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

