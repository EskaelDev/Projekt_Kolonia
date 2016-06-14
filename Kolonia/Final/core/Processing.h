#ifndef Processing_h
#define Processing_h

#include "Production.h"

class Processing : public Production
{
protected:
	int materialID;		// wartosc odpowiada indeksowi produktu zawartego w tablicy surowcow tResouce, ktory pobiera (przetwarza) budynek do wyrobu innego produktu okreslonego przez pole productID
	int productNumber;	// liczba jednostek surowca produkowana z liczny surowca przetwarzanego okreslonego przez pole materialNumber
	int materialNumber;	// liczba jednostek surowca jaka pobiera do produkcji 
public:
	Processing(int, int, int, int, int, int, int, int, int, int, int, int, int);
	int getMaterialID() const;
	int getProductNumber() const;
	int getMaterialNumber() const;
};

#endif 
