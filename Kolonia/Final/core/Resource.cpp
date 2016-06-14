#include "stdafx.h"
#include "Resource.h"

Resource::Resource(int _price)
{
	number = 0;

	price = _price;
}

bool Resource::buy(Resource & _Money)
{
	if (_Money.getNumber() >= price)
	{
		++number;
		_Money.decrease(price);
		return true;
	}
	else
		return false;
}

bool Resource::sell(Resource & _Money)
{
	if (number > 0)
	{
		--number;
		_Money.increase(price);
		return true;
	}
	else
		return false;
}

void Resource::increase(int _number)
{
	number += _number;
}

void Resource::decrease(int _number)
{
	number -= _number;
}

void Resource::setNumber(int _number)
{
	number = _number;
}

int Resource::getNumber() const
{
	return number;
}