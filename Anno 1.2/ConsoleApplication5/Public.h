#ifndef Public_h
#define Public_h

#include "Industrial.h"
#include "Resource.h"
#include "People.h"

class Public : public Industrial
{
protected:
	int number;						// liczba budynkow

public:
	Public();
	Public(int, int, int, int, int, int, int, int); 											
	bool Build(Resource* [21]) override;	// aktualizuje stan surowcow po budowie i parametry budynku, zwraca false jesli brakuje surowcowow, true jesli sa dostepne surowce 
	bool Destroy();							// niszczy budynek jesli istnieje, w przypadku powodzenia zwraca true, w przypadku niepowodzenia false
	int getNumber() const;
	void test() const;
};

#endif


