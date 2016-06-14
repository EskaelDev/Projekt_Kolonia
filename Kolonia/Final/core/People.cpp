#include "stdafx.h"
#include <iostream>
#include "People.h"
using namespace std;

People::People(int _tax, int tabResourceId[])
{
	number = 0;
	tax = _tax;
	if (tabResourceId[0] > -1)
	{
		ResourceId = new int[tabSize];
		for (int i = 0; i < tabSize; ++i)
			ResourceId[i] = tabResourceId[i];
	}
	else
		ResourceId = 0;
}

int People::getNumber() const
{
	return number;
}

int People::getTax() const
{
	return (tax * number);
}

void People::increase(int _peopleNumber)
{
	number += _peopleNumber;
}

void People::setNumber(int _peopleNumber)
{
	number = _peopleNumber;
}

void People::test() const
{
	cout << "Liczba = " << number << endl;
	cout << "Podatek = " << tax << endl;
}
