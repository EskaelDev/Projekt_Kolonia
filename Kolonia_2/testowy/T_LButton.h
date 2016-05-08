#pragma once
//#include "Globalne.h"
//#include "Glob_Funk.h"
#include "T_LTexture.h"

class T_LButton
{

	int id, w, h;			// id_bud szer, wys
	char *img;				// sciezka do pliku
	SDL_Point mPosition;	// gorny lewy rog
	Actions action;			// akcja na mysz
	LButtonSprite mCurrentSprite;	// zmiana sprita na mysz

public:

	// Inicjalizacja wewnetrznych zmiennych
	T_LButton(Actions, int, int, int, int, char*);
	T_LButton(int, Actions, int, int, int, int, char*);

	// Ustawia lew gorny rog
	void setPosition(int x, int y);

	// Przchowuje eventy myszy
	void handleEvent(SDL_Event* e);

	// Pokazuje buttony spritow
	void render();

	// Pozbywa sie przyciskow
	void del();

	// Reakcja na mysz
	void operation(Actions);
	
	~T_LButton();
};

