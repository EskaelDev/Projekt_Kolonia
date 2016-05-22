#ifndef Production_h
#define Production_h

#include "Industrial.h"

class Production : public Industrial
{
protected:
	int magazineCapacity;
	int product;				// wartosc pola odpowiada rodzajowi towaru wedlug indeksow tablicy tResource, -1 oznacza ze nic nie produkuje

public:
	Production();
	Production(int, int, int, int, int, int, int, int, int, int, int);
	~Production();
	bool activate();
	bool deactivate();
	int getProduct() const;
	void test() const;
};

#endif