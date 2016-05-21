using namespace std;

#ifndef House_h  
#define House_h

class House : public Building
{
protected:
	int inhabitants;

public:
	House();
	House(int, int, int, int, int);
	~House();
	void test();
};

House::House()
{
	inhabitants = 0;
}

House::House(int _id, int _bricksToBuild, int _toolsToBuild, int _woodToBuild, int _inhabitants)
{
	id = _id;
	bricksToBuild = _bricksToBuild;
	toolsToBuild = _toolsToBuild;
	woodToBuild = _woodToBuild;
	inhabitants = _inhabitants;
}

House::~House()
{
}

void House::test()
{
	cout << "Id = " << id << endl;
	cout << "Liczba = " << number << endl;
	cout << "Cegly do budowy = " << bricksToBuild << endl;
	cout << "Narzedzia do budowy = " << toolsToBuild << endl;
	cout << "Drewno do budowy = " << woodToBuild << endl;
	cout << "Zajmowany obszar = " << size << endl;
	cout << "Mieszkancy = " << inhabitants << endl << endl;
}

#endif House_h
