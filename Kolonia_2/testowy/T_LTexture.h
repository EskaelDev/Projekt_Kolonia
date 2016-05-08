#pragma once
#include "Glob_Funk.h"

using namespace std;

class T_LTexture
{
	// Aktualna textura sprzetu?
	SDL_Texture* mTexture;

	//  Wymiary obrazu
	int mWidth;
	int mHeight;
public:
	// Inicjalizuje smienne
	T_LTexture();

	// Dealokuje pamiec
	~T_LTexture();

	// Laduje obrazek ze sciezki
	bool loadFromFile(string path);

	// Laduje obrazek z tekstu
	bool loadFromRenderedText(string textureText, SDL_Color textColor);

	// Dealokuje texture
	void free();

	// Ustawia modulacje koloru
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	// Ustawia blendowanie?
	void setBlendMode(SDL_BlendMode blending);

	// Ustawia alphe modulacji
	void setAlpha(Uint8 alpha);

	// Renderuje texture w punkcie
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// Pobiera rozmiary obrazka
	int getWidth();
	int getHeight();
};

