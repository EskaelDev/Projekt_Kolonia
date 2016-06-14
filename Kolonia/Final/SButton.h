#ifndef SButton_H  
#define SButton_H

#include "STexture.h"
#include "STimer.h"
#include "sdl_functions.h"
#include "sdl_variables.h"
#include "sdl_consts.h"
#include "sdl_enums.h"
#include "sdl_objects.h"
#include <string>

class SButton
{
public:
	SButton(Actions, int, int, int, int, char*);
	SButton(int, Actions, int, int, int, int, char*);
	~SButton();

	// Ustawia pozycje przycisku
	void setPosition(int, int);

	// Kieruje akcja przycisku
	void handleEvent(SDL_Event* e);

	// Wyswietla przycisk
	void render();

	// Ustawia teksture przycisku
	void setTexture();

	// Dzialanie po nacisnieciu na przycisk
	void operation(Actions);

private:
	// Tekstura przycisku
	STexture gButtonSpriteSheetTexture;

	// id budynku, szerokosc, wysokosc
	int id, w, h, w_b, h_b;

	// Sciezka (nazwa) pliku
	char *img;

	// Pozycja przycisku
	SDL_Point mPosition;

	// Warunek akcji przycisku
	Actions action;

	// Aktualnie wyswietlany sprite
	SButtonSprite mCurrentSprite;
	SDL_Rect gSpriteClips[BUTTON_SPRITE_TOTAL];
};
#endif