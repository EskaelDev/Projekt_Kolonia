#ifndef Production_h
#define Production_h

#include "Public.h"

class Production : public Public
{
protected:
	int maintenancePassiveCost;	// koszty utrzymania przy wstrzymanej produkcji
	int magazineCapacity;		// rozmiar magazynu budynku
	int productID;				// wartosc pola odpowiada rodzajowi towaru wedlug indeksow tablicy tResource, -1 oznacza ze nic nie produkuje, wszystkie budynki produkuja jedna jednostke surowca

public:
	Production();
	Production(int, int, int, int, int, int, int, int, int, int, int);
	bool activate();			// funkcja wznawia produkcje budynku
	bool deactivate();			// funkcja wstrzymuje produkcje budynku
	int getProductID() const;
	int getMagazineCapacity() const;
	void test() const;
};

#endif