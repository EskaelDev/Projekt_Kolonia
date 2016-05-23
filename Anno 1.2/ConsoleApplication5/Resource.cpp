#include "stdafx.h"
#include <iostream>
#include "Resource.h"
using namespace std;

Resource::Resource(int _quantity, int _price)
{
	quantity = _quantity;
	price = _price;
}

void Resource::buy()
{
}

void Resource::sell()
{
}

void Resource::increase(int _Number)
{
	quantity += _Number;
}

int Resource::getNumber() const
{
	return quantity;
}

void Resource::test()
{
	cout << "Ilosc surowca = " << quantity << endl;
	cout << "Cena = " << price << endl;
}
