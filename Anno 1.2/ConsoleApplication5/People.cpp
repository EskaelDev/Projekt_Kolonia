#include "stdafx.h"
#include <iostream>
#include "People.h"
using namespace std;

People::People(int _tax)
{
	tax = _tax;
}

int People::getNumber() const
{
	return number;
}

int People::getTax() const
{
	return (tax * number);
}

void People::increase(int _startPeople)
{
	number += _startPeople;
}

void People::test() const
{
	cout << "Liczba = " << number << endl;
	cout << "Podatek = " << tax << endl;
}
