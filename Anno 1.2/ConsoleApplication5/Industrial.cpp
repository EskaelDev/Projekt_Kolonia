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
