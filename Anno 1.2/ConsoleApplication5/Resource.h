#ifndef Resource_h
#define Resource_h

class Resource
{
	friend class Magazine;
	friend class Public;
	friend class House;

protected:
	int number;			// liczba surowca
	int price;			// cena za jednostke surowca	

public:
	Resource(int);
	bool buy(Resource &);	// funkcja kupuje towar, zwraca true w przypadku gdy nas stac na kupno, false gdy nie
	bool sell(Resource &);	// funkcja sprzedaje towar, zwraca true w przypadku gdy posiadamy dany towar, false gdy nie
	void increase(int);		// zwieksza liczbe surowca o podana wartosc
	void decrease(int);		// zmniejsza liczbe surowca o podana wartosc
	int getNumber() const;
	void test();
};

#endif