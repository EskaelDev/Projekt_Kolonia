#ifndef Processing_h
#define Processing_h

#include "Production.h"

class Processing : public Production
{
protected:
	int materialID;		// wartosc odpowiada indeksowi produktu zawartego w tablicy surowcow tResouce, ktory pobiera (przetwarza) budynek do wyrobu innego produktu okreslonego przez pole productID

public:
	Processing(int, int, int, int, int, int, int, int, int, int, int);
	int getMaterialID() const;
};

#endif 
