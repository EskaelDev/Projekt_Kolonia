#include "stdafx.h"
#include <iostream>
#include "Industrial.h"
#include "People.h"

Industrial::Industrial() {}

void Industrial::checkStatus(int peopleNumber) 
{
	if (peopleToBuild > peopleNumber)
		status = false;
	else
		status = true;
}

int Industrial::getMoney() const
{
	return moneyToBuild;
}

int Industrial::getClass() const
{
	return peopleClass;
}

int Industrial::getMaintenanceActiveCost() const
{
	return maintenanceActiveCost;
}