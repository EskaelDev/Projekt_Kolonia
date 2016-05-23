#ifndef Resource_h
#define Resource_h

class Resource
{
	friend class Industrial;
	friend class House;

protected:
	int number;			// liczba surowca
	int price;			// cena za jednostke surowca	

public:
	Resource(int, int);
	void buy();				// funkcja kupna towaru
	void sell();			// funkcja sprzedazy towaru
	void increase(int);		// zwieksza liczbe surowca o podana wartosc
	void decrease(int);		// zmniejsza liczbe surowca o podana wartosc
	int getNumber() const;
	void test();
};

#endif