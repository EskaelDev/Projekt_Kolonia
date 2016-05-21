#ifndef People_h
#define People_h

class People
{
protected:
	int number;
	int tax;

public:
	People();
	People(int);
	~People();
	int getTax() const;
	void test() const;
};

#endif