#ifndef Building_h
#define Building_h

class Building
{
protected:
	int bricksToBuild;			// liczba cegiel wymaganych do budowy
	int toolsToBuild;			// liczba narzedzi wymaganych do budowy
	int woodToBuild;			// liczba drewna wymaganych do budowy
	int size;					// liczba pol zajmowana przez budynek

public:
	int getBricks() const;
	int getTools() const;
	int getWood() const;
	int getSize() const;
};

#endif