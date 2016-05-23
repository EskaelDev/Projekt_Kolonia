#ifndef Building_h
#define Building_h

class Building
{
protected:
	int number;					// liczba budynkow
	int bricksToBuild;			// liczba cegiel wymaganych do budowy
	int toolsToBuild;			// liczba narzedzi wymaganych do budowy
	int woodToBuild;			// liczba drewna wymaganych do budowy
	int size;					// liczba pol zajmowana przez budynek

public:
	Building();
	int getNumber() const;
	int getBricks() const;
	int getTools() const;
	int getWood() const;
};

#endif