#include "Production.h"

#ifndef Processing_h
#define Processing_h

class Processing : public Production
{
protected:
	int material;		// produkt, ktory pobiera (przetwarza) do wyrobu innego produktu okreslonego przez pole product

public:
	Processing();
	Processing(int, int, int, int, int, int, int, int, int, int, int);
	~Processing();
};

#endif 
