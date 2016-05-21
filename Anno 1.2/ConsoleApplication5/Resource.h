#ifndef Resource_h
#define Resource_h

class Resource
{
	friend class Industrial;

protected:
	int id;
	int quantity;		// czyli number
	int price;
	int allTaxes;

public:
	Resource();
	Resource(int, int, int);
	~Resource();
	void buy();
	void sell();
	int get();
	int getTaxes(int, int, int, int, int);
	void test();
};

#endif