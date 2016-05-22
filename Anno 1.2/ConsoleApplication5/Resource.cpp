#include "stdafx.h"
#include <iostream>
#include "Resource.h"
using namespace std;

Resource::Resource()
{
	id = 0;
	quantity = 0;
	price = 0;
}

Resource::Resource(int _quantity, int _price)
{
	quantity = _quantity;
	price = _price;
}

Resource::~Resource()
{
}

void Resource::buy()
{
}

void Resource::sell()
{
}

int Resource::get()
{
	return quantity;
}

int Resource::getTaxes(int, int, int, int, int)
{
	allTaxes = 0;
	return 0;
}

void Resource::test()
{
	cout << "Id = " << id << endl;
	cout << "Ilosc surowca = " << quantity << endl;
	cout << "Cena = " << price << endl;
}
