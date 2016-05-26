#ifndef Magazine_h
#define Magazine_h

#include "Industrial.h"
#include "Resource.h"
#include "People.h"

class Magazine : public Industrial
{
protected:
	int level;						// poziom magazynu od 0 do 4, 0 oznacza niewybudowany
	int magazineCapacity;			// rozmiar magazynu budynku

public:
	Magazine();
	bool Build(Resource &, Resource &, Resource &, Resource &);
	int getmagazineCapacity() const;
	int getLevel() const;
	void test() const;
};

#endif

