#include "T_LTexture.h"


T_LTexture::T_LTexture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

T_LTexture::~T_LTexture()
{
	free();
}

bool T_LTexture::loadFromFile(string path)
{
	// Wyrzucenie przedistniejacej textury
	free();

	// Finalna textura
	SDL_Texture* newTexture = NULL;

	// £adowanie obrazka ze œcierzki
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
		cout << "Nie mozna zaladowac obrazka z " << path.c_str() << "SDL_image Error" << IMG_GetError() << endl;
	else
	{
		// Klucz koloru obrazka
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0, 0));

		// Tworzenie textury z pixei powierzchni?
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
			cout << "Nie mozna zrobic textury z obrazka " << path.c_str() << "SDL_image Error" << IMG_GetError() << endl;
		else
		{
			// Pobranie wymiarow obrazka
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		// Wywalenie starej zaladowanej textury
		SDL_FreeSurface(loadedSurface);
	}

	// Return sukcesu
	mTexture = newTexture;
	return mTexture != NULL;
}


bool T_LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (mTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}

	//Return success
	return mTexture != NULL;
}

void T_LTexture::free()
{
	// Zwolnij texture jesli jakas istenieje
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void T_LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	// Modulacja rgb textury 
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void T_LTexture::setBlendMode(SDL_BlendMode blending)
{
	// Ustawia funkcje blendowania
	SDL_SetTextureBlendMode(mTexture, blending);
}

void T_LTexture::setAlpha(Uint8 alpha)
{
	// Modulacja alpha textury
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void T_LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	// Ustawia renderowana przstrzen i irenderuje na ekran
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	// Ustawia wymiary clipu?
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	// Renderuje na ekran
	SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int T_LTexture::getHeight()
{
	return mHeight;
}

int T_LTexture::getWidth()
{
	return mWidth;
}