#include "sdl_functions.h"

SDL_Texture* loadTexture(std::string path)
{
	// Finalna tekstura
	SDL_Texture* newTexture = NULL;

	// Wczytuje obrazek ze sciezki
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
		std::cout << "Nie mozna wczytac obrazka: " << path.c_str() << "! SDL_image Error: " << IMG_GetError() << std::endl;
	else
	{
		SDL_Renderer *gRenderer = NULL;
		// Wczytuje teksture z powierzchni pikseli
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
			std::cout << "Nie mozna utworzyc tekstury z " << path.c_str() << "! SDL Error: " << path.c_str() << SDL_GetError() << std::endl;

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}