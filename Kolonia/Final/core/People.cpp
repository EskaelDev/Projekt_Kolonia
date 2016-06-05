#include "stdafx.h"
#include <iostream>
#include "People.h"
using namespace std;

People::People(int _tax)
{
	number = 0;
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
