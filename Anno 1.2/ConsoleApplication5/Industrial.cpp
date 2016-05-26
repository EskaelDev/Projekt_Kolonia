#include "stdafx.h"
#include <iostream>
#include "Industrial.h"
#include "People.h"

void Industrial::checkStatus(People & _class) 
{
	if (peopleToBuild > _class.getNumber())
		status = false;
	else
		status = true;
}

bool Industrial::Build(Resource & _Money, Resource & _Bricks, Resource & _Tools, Resource & _Wood)
{
	if (moneyToBuild > _Money.number || bricksToBuild > _Bricks.number || toolsToBuild > _Tools.number || woodToBuild > _Wood.number)
		return false;
	else
	{
		_Money.number -= moneyToBuild;
		_Bricks.number -= bricksToBuild;
		_Tools.number -= toolsToBuild;
		_Wood.number -= woodToBuild;
		return true;
	}
}

int Industrial::getMoney() const
{
	return moneyToBuild;
}

int Industrial::getClass() const
{
	return peopleClass;
}

bool Industrial::getStatus() const
{
	return status;
}
