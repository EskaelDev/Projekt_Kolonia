#ifndef Public_h
#define Public_h

#include "Industrial.h"
#include "Resource.h"
#include "People.h"

class Public : public Industrial
{
protected:
	int number;						// liczba budynkow
	int maintenanceActiveCost;		// koszty utrzymania budynku

public:
	Public();
	Public(int, int, int, int, int, int, int, int);
	void checkStatus(People &);																// aktualizuje pole status w oparciu o spelnienie warunku wymaganej liczby ludzi  											
	bool Build(Resource & _Money, Resource & _Bricks, Resource & _Tools, Resource & _Wood);	// aktualizuje stan surowcow po budowie i parametry budynku, zwraca false jesli brakuje surowcowow, true jesli sa dostepne surowce 
	bool Destroy();																			// niszczy budynek jesli istnieje, w przypadku powodzenia zwraca true, w przypadku niepowodzenia false
	int getNumber() const;
	int getMoney() const;
	int getClass() const;
	bool getStatus() const;
	void test() const;
};

#endif


