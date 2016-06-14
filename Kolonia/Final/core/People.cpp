#include "stdafx.h"
#include <iostream>
#include "People.h"
using namespace std;

People::People(int _tax, int tabResourceId[], int tabSize)
{
	number = 0;
	tax = _tax;

	resourceId = new int[tabSize];
	for (int i = 0; i < tabSize; ++i)
		resourceId[i] = tabResourceId[i];
}

int People::getNumber() const
{
	return number;
}

int People::getTax() const
{
	return (tax * number);
}

int People::getResourceId(int index) const
{
	return resourceId[index];
}

int People::getTabIdSize() const
{
	return tabIdSize;
}

void People::increase(int _peopleNumber)
{
	number += _peopleNumber;
}

void People::setNumber(int _peopleNumber)
{
	number = _peopleNumber;
}

People::~People()
{
	delete[] resourceId;
}

void People::test() const
{
	cout << "Liczba = " << number << endl;
	cout << "Podatek = " << tax << endl;
}
