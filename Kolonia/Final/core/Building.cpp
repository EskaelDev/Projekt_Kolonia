#include "stdafx.h"
#include "Building.h"

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

int Building::getSize() const
{
	return size;
}

