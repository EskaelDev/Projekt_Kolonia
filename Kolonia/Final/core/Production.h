#ifndef Production_h
#define Production_h

#include "Public.h"

class Production : public Public
{
protected:
	int maintenancePassiveCost;	// koszty utrzymania przy wstrzymanej produkcji
	int activeNumber;			// liczba budynkow ktore produkuja surowce w danej chwili
	int magazineCapacity;		// rozmiar magazynu budynku
	int productID;				// wartosc pola odpowiada rodzajowi towaru wedlug indeksow tablicy tResource, -1 oznacza ze nic nie produkuje, wszystkie budynki produkuja jedna jednostke surowca

public:
	Production();
	Production(int, int, int, int, int, int, int, int, int, int, int);
	bool Build(Resource* [21]) override;
	bool activate();						// funkcja wznawia produkcje budynku, zwraca true, jesli posiadamy choc jeden budynek z wstrzymana produkcja, false jesli nie
	bool deactivate();						// funkcja wstrzymuje produkcje budynku, zwraca true, jesli posiadamy choc jeden budynek z aktywna produkcja, false jesli nie
	int getProductID() const;
	int getMagazineCapacity() const;
	int getMaintenancePassiveCost() const;
	int getActiveNumber() const;
	void test() const;
};

#endif