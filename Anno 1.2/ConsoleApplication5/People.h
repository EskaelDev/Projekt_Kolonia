#ifndef People_h
#define People_h

class People
{
protected:
	int number;					// liczba mieszkancow
	int tax;					// podatek od mieszkanca

public:
	People(int);
	int getNumber() const;
	int getTax() const;
	void test() const;
};

#endif