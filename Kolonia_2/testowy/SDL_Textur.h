#pragma once

class SDL_Textur
{
public:
	SDL_Textur();
	~SDL_Textur();

	// Ladowanie obrazka z podanej sciezki
	bool loadFromFile(std::string path);

	// Tworzenie obrazka z tekstu
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);

	// Zwalnianie tekstury
	void free();

	// Ustawianie koloru modulacji
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	// Ustawianie mieszania
	void setBlendMode(SDL_BlendMode blending);

	// Ustawianie modulacji przezroczystosci
	void setAlpha(Uint8 alpha);

	// Renderowanie tekstury w podanym punkcie
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// Pobranie rozmiarow obrazka
	int getWidth();
	int getHeight();

private:
	// Aktualna tekstura
	SDL_Texture* mTexture;

	// Rozmiary obrazka
	int mWidth;
	int mHeight;
};
SDL_Textur gTextTexture;
SDL_Textur gPromptTextTexture;
SDL_Textur gTimeTextTexture;
