#include "stdafx.h"
#include "Resource.h"

Resource::Resource(int _price)
{
	number = 0;

	price = _price;
}

bool Resource::buy(Resource & _Money)
{
	if (_Money.getNumber() >= price*5)
	{
		number+=5;
		_Money.decrease(price*5);
		return true;
	}
	else
		return false;
}

bool Resource::sell(Resource & _Money)
{
	if (number > 0)
	{
		number-=5;
		_Money.increase(price*4);
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