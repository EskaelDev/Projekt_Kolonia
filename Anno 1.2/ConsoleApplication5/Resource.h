#ifndef Resource_h
#define Resource_h

class Resource
{
	friend class Industrial;
	friend class House;

protected:
	int quantity;		// ilosc/liczba surowca
	int price;			// cena za jednostke surowca	

public:
	Resource(int, int);
	void buy();				// funkcja kupna towaru
	void sell();			// funkcja sprzedazy towaru
	void increase(int);		// zwieksza ilosc/liczbe surowca o podana wartosc
	int getNumber() const;
	void test();
};

#endif