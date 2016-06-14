#ifndef People_h
#define People_h

class People
{
protected:
	int number;					// liczba mieszkancow
	int tax;					// podatek od mieszkanca
	int* resourceId;			// wskaznik do tablicy wartosci odpowiadajacych indeksom surowcow, ktore sa pobierane przez mieszkancow
	int tabIdSize;				// rozmiar tablicy resourceId

public:
	People(int, int[], int);
	~People();
	int getNumber() const;		
	int getTax() const;				// pobiera calkowita kwote podatku jaka placi dana klasa mieszkancow
	int getResourceId(int) const;	// argumentem jest indeks tablicy
	int getTabIdSize() const;
	void increase(int);				// zwieksza liczbe mieszkancow o podana wartosc
	void setNumber(int);			// ustawia liczbe mieszkancow na konkretna wartosc
	void test() const;
};

#endif