#ifndef Building_h
#define Building_h

class Building
{
protected:
	int number;					// liczba budynkow
	int bricksToBuild;
	int toolsToBuild;
	int woodToBuild;
	int size;

public:
	Building();
	int getNumber() const;
	int getBricks() const;
	int getTools() const;
	int getWood() const;
};

#endif