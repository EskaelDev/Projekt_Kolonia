#include "stdafx.h"
#include <iostream>
#include "Resource.h"
using namespace std;

Resource::Resource(int _number, int _price)
{
	number = _number;
	price = _price;
}

void Resource::buy()
{
}

void Resource::sell()
{
}

void Resource::increase(int _number)
{
	number += _number;
}

void Resource::decrease(int _number)
{
	number -= _number;
}

int Resource::getNumber() const
{
	return number;
}

void Resource::test()
{
	cout << "Ilosc surowca = " << number << endl;
	cout << "Cena = " << price << endl;
}
