#ifndef Production_h
#define Production_h

#include "Industrial.h"

class Production : public Industrial
{
protected:
	int magazineCapacity;		// rozmiar magazynu budynku
	int productID;				// wartosc pola odpowiada rodzajowi towaru wedlug indeksow tablicy tResource, -1 oznacza ze nic nie produkuje, wszystkie budynki produkuja jedna jednostke surowca

public:
	Production();
	Production(int, int, int, int, int, int, int, int, int, int, int);
	bool activate();			// funkcja wznawia produkcje budynku
	bool deactivate();			// funkcja wstrzymuje produkcje budynku
	int getProductID() const;
	void test() const;
};

#endif