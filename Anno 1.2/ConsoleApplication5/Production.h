#ifndef Production_h
#define Production_h

#include "Industrial.h"

class Production : public Industrial
{
protected:
	int magazineCapacity;

public:
	Production();
	Production(int, int, int, int, int, int, int, int, int, int);
	~Production();
	bool activate();
	bool deactivate();
	void test() const;
};

#endif