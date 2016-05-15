#pragma once
//#include "Glob_Funk.h"

#include <SDL.h>
#include <SDL_image.h>
#include <conio.h>
#include "SDL_ttf.h"
#include <stdio.h>
#include <string>
#include <SDL_mixer.h>
#include <iostream>

// Rozmiar okna
const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;

// Rozmiar przyciskow menu glownego
const int MAIN_BUTTON_WIDTH = 118;
const int MAIN_BUTTON_HEIGHT = 35;

// Rozmiar splashy
const int BUILDINGS_BUTTON_WIDTH = 911;
const int BUILDINGS_BUTTON_HEIGHT = 256;

// Rozmiar buduj zburz
const int BUILD_BUTTON_WIDTH = 60;
const int BUILD_BUTTON_HEIGHT = 20;

// Rozmiar kupuj sprzedaj
const int BUY_BUTTON_WIDTH = 90;
const int BUY_BUTTON_HEIGHT = 70;



// Switch reakcji na mysz
enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4,
	UNKNOWN = 5
};

// Warstwy do wyswieltania
enum Screen
{
	MAIN,
	GAME,
	LOAD,
	SAVE,
	QUIT
};
Screen screen;

// Przypadki uzycia przyciskow
enum Actions
{
	NONE,
	NEW_GAME,
	PLAY_GAME,
	LOAD_GAME,
	SAVE_GAME,
	MAIN_MENU,
	EXIT_GAME,
	BUY,
	SELL,
	PUBLIC,
	INDUSTRIAL,
	PRODUCTION,
	BUILD,
	DESTROY
};



// Okno do ktorego bedziemy renderowac
SDL_Window* gWindow = NULL;

// Renderowane okno
SDL_Renderer* gRenderer = NULL;

// Aktualnie wyswietlana tekstura
SDL_Texture* gTexture = NULL;
SDL_Texture* gTexture2 = NULL;



// Czcionka
TTF_Font *gFont = NULL;

// Obiekt do spritow
SDL_Rect gSpriteClips[BUTTON_SPRITE_TOTAL];

// Dziwieki ktorych bede uzywac
Mix_Chunk *gSplash_click = NULL;




//#include "Globalne.h"
#include "T_LTexture.h"

// Wlaczenie SDL i stworzenie okna
bool init();

// Ladowanie mediow
bool loadMedia();

// Zwalnianie mediow i zamykanie SDL
void close();

// Ladowanie obrazka jako tekstury
SDL_Texture* loadTexture(std::string path);

T_LTexture gTextTexture;

