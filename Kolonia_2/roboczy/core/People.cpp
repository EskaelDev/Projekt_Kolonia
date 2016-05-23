#include "stdafx.h"
#include <iostream>
#include "People.h"
using namespace std;

People::People()
{
	number = 0;
	tax = 0;
}

People::People(int _tax)
{
	tax = _tax;
}

People::~People()
{
}

int People::getNumber() const
{
	return number;
}

int People::getTax() const
{
	int taxes = tax*number;
	return taxes;
}

void People::test() const
{
	cout << "Liczba = " << number << endl;
	cout << "Podatek = " << tax << endl;
}
