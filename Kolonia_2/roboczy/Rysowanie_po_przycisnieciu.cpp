/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <conio.h>
#include "SDL_ttf.h"
#include <stdio.h>
#include <string>


// Rozmiar okna
const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;

const int MAIN_BUTTON_WIDTH = 118;
const int MAIN_BUTTON_HEIGHT = 35;

const int BUILDINGS_BUTTON_WIDTH = 911;
const int BUILDINGS_BUTTON_HEIGHT = 256;

const int BUILD_BUTTON_WIDTH = 60;
const int BUILD_BUTTON_HEIGHT = 20;

const int BUY_BUTTON_WIDTH = 90;
const int BUY_BUTTON_HEIGHT = 70;

enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4,
	UNKNOWN = 5
};

enum Screen
{
	MAIN,
	GAME,
	LOAD,
	SAVE,
	QUIT
};

Screen screen;

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

// Ladowanie obrazka jako tekstury
SDL_Texture* loadTexture(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

// Aktualnie wyswietlana tekstura
SDL_Texture* gTexture = NULL;
SDL_Texture* gTexture2 = NULL;

//Globally used font
TTF_Font *gFont = NULL;

//Mouse button sprites
SDL_Rect gSpriteClips[BUTTON_SPRITE_TOTAL];

// Wlaczenie SDL i stworzenie okna
bool init();

// Ladowanie mediow
bool loadMedia();

// Zwalnianie mediow i zamykanie SDL
void close();

//Texture wrapper class
class LTexture
{
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Loads image at specified path
	bool loadFromFile(std::string path);

	//Creates image from font string
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);

	//Deallocates texture
	void free();

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	//Renders texture at given point
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};

LTexture gButtonSpriteSheetTexture;

LTexture gTextTexture;

LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile(std::string path)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		//SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
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

void LTexture::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void LTexture::setBlendMode(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

//The mouse button
class LButton
{
public:
	//Initializes internal variables
	LButton(Actions, int, int, int, int, char*);
	LButton(int, Actions, int, int, int, int, char*);
	~LButton();

	//Sets top left position
	void setPosition(int x, int y);

	//Handles mouse event
	void handleEvent(SDL_Event* e);

	//Shows button sprite
	void render();
	void del();

	void operation(Actions);
private:
	//Top left position
	int id, w, h;
	char *img;
	SDL_Point mPosition;
	Actions action;

	//Currently used global sprite
	LButtonSprite mCurrentSprite;
};

LButton::LButton(Actions action, int width, int height, int pos_x, int pos_y, char *image)
{
	this->action = action;
	this->w = width;
	this->h = height;
	img = new char[strlen(image) + strlen("imgs/buttons/")];
	strcpy(img, "imgs/buttons/");
	strcat(img, image);

	setPosition(pos_x, pos_y);
	mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

LButton::LButton(int id, Actions action, int w, int h, int pos_x, int pos_y, char *image)
{
	this->action = action;
	this->w = w;
	this->h = h;
	img = new char[strlen(image) + strlen("imgs/buttons/")];
	strcpy(img, "imgs/buttons/");
	strcat(img, image);

	setPosition(pos_x, pos_y);
	mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

LButton::~LButton()
{
	this->action = NONE;
	this->w = NULL;
	this->h = NULL;
	img = NULL;

	setPosition(0, 0);
	mCurrentSprite = UNKNOWN;
}
// button(action, width, height, pos_x, pos_y, filename)
LButton new_game_button(NEW_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 400, "new.png");
LButton load_game_button(LOAD_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 480, "load.png");
LButton save_game_button(SAVE_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 560, "save.png");
LButton exit_game_button(EXIT_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 660, "exit.png");
LButton main_menu_button(MAIN_MENU, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 660, "back.png");
LButton pub_button(PUBLIC, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 455, 0, "/buildings/pub.png");
LButton ind_button(INDUSTRIAL, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 455, 256, "/buildings/ind.png");
LButton prod_button(PRODUCTION, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 455, 512, "/buildings/prod.png");
LButton buy_button(BUY, BUY_BUTTON_WIDTH, BUY_BUTTON_HEIGHT, 624, 660, "back.png");
LButton sell_button(SELL, BUY_BUTTON_WIDTH, BUY_BUTTON_HEIGHT, 624, 660, "back.png");

void LButton::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}

void LButton::handleEvent(SDL_Event* e)
{
	//If mouse event happened
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if (x < mPosition.x)
		{
			inside = false;
		}
		//Mouse is right of the button
		else if (x > mPosition.x + w)
		{
			inside = false;
		}
		//Mouse above the button
		else if (y < mPosition.y)
		{
			inside = false;
		}
		//Mouse below the button
		else if (y > mPosition.y + h)
		{
			inside = false;
		}

		//Mouse is outside button
		if (!inside)
		{
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch (e->type)
			{
			case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

			case SDL_MOUSEBUTTONDOWN:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				break;

			case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				operation(action);
				break;
			}
		}
	}
}

void LButton::render()
{
	if (!gButtonSpriteSheetTexture.loadFromFile(img))
	{
		printf("Failed to load button sprite texture!\n");
	}
	else
	{
		//Set sprites
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClips[i].x = 0;
			gSpriteClips[i].y = i * h;
			gSpriteClips[i].w = w;
			gSpriteClips[i].h = h;
		}
	}
	gButtonSpriteSheetTexture.render(mPosition.x, mPosition.y, &gSpriteClips[mCurrentSprite]);
}

void LButton::del()
{
	setPosition(-999, -999);
}

void LButton::operation(Actions action)
{
	switch (action)
	{
	case NEW_GAME:
		SDL_DestroyTexture(gTexture);
		gTexture = NULL;
		gTexture = loadTexture("imgs/left.png");
		screen = GAME;
		new_game_button.del();
		load_game_button.del();
		save_game_button.del();
		exit_game_button.del();
		break;

	case LOAD_GAME:
		/*new_game_button.del();
		load_game_button.del();
		save_game_button.del();
		exit_game_button.del();*/
		SDL_DestroyTexture(gTexture);
		gTexture = NULL;
		gTexture = loadTexture("imgs/load_save.png");
		screen = LOAD;
		break;

	case SAVE_GAME:
		SDL_DestroyTexture(gTexture);
		gTexture = NULL;
		gTexture = loadTexture("imgs/load_save.png");
		screen = SAVE;
		new_game_button.del();
		load_game_button.del();
		save_game_button.del();
		exit_game_button.del();
		break;

	case MAIN_MENU:
		if (gTexture != NULL)
		{
			SDL_DestroyTexture(gTexture);
			gTexture = NULL;
		}
		if (gTexture2 != NULL)
		{
			SDL_DestroyTexture(gTexture2);
			gTexture2 = NULL;
		}
		gTexture = loadTexture("imgs/main.png");
		screen = MAIN;
		new_game_button.setPosition(624, 400);
		load_game_button.setPosition(624, 480);
		save_game_button.setPosition(624, 560);
		SDL_Delay(40);
		exit_game_button.setPosition(624, 660);
		main_menu_button.del();

		break;

	case PLAY_GAME:
		SDL_DestroyTexture(gTexture);
		gTexture = NULL;
		gTexture = loadTexture("imgs/left.png");
		screen = GAME;
		break;

	case EXIT_GAME:
		screen = QUIT;
		break;

	case BUILD:
		break;

	case DESTROY:
		break;

	default:
		break;
	}
}

bool init()
{
	// Flaga inicjalizacji
	bool success = true;

	// Inicjalizacja SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Ustawienie filtrowania tekstury na liniowe
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		// Stworzenie okna
		gWindow = SDL_CreateWindow("Kolonia", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				// Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	// Flaga powodzenia ladowania
	bool success = true;

	// Ladowanie tekstury
	gTexture = loadTexture("imgs/main.png");/*
											gTexture2 = loadTexture("imgs/load_save.png");
											gTexture3 = loadTexture("imgs/left.png");
											gTexture4 = loadTexture("imgs/public.png");
											if (gTexture == NULL || gTexture2 == NULL)
											{
											printf("Nie mozna zaladowac obrazka!\n");
											success = false;
											}*/

											// Load sprites
											//if (!gButtonSpriteSheetTexture.loadFromFile("imgs/buttons/new_game.png"))
											//{
											//	printf("Failed to load button sprite texture!\n");
											//	success = false;
											//}
											//else
											//{
											//	//Set sprites
											//	for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
											//	{
											//		gSpriteClips[i].x = 0;
											//		gSpriteClips[i].y = i * 43;
											//		gSpriteClips[i].w = 193;
											//		gSpriteClips[i].h = 43;
											//	}
											//}

											//Open the font
	gFont = TTF_OpenFont("fonts/Caladea-Regular.ttf", 19);
	if (gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		//Render text
		SDL_Color textColor = { 200, 200, 200 };
		if (!gTextTexture.loadFromRenderedText("12", textColor))
		{
			printf("Failed to render text texture!\n");
			success = false;
		}
	}

	//Nothing to load
	return success;
}

void close()
{
	// Zwalnia zaladowany obrazek
	if (gTexture)
	{
		SDL_DestroyTexture(gTexture);
		gTexture = NULL;
	}
	if (gTexture2)
	{
		SDL_DestroyTexture(gTexture2);
		gTexture2 = NULL;
	}
	if (gTexture)
	{
		SDL_DestroyTexture(gTexture);
		gTexture = NULL;
	}

	//Free loaded images
	gTextTexture.free();

	//Free global font
	TTF_CloseFont(gFont);
	gFont = NULL;

	// Zamyka okno
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	// Wczytuje obrazek ze sciezki
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Nie mozna wczytac obrazka: %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// Wczytuje teksture z powierzchni pikseli
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

int main(int argc, char* args[])
{
	screen = MAIN;
	SDL_Color textC = { 200, 200, 200 };
	// Wlaczenie SDL i stworzenie okna
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		// Ladowanie mediow
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			// Flaga glownej petli
			bool quit = false;

			//Event handler
			SDL_Event e;
			gFont = TTF_OpenFont("fonts/Caladea-Regular.ttf", 48);
			SDL_Rect MainViewport;
			SDL_Rect LoadViewport;
			SDL_Rect SaveViewport;
			//SDL_Rect LeftViewport;
			//SDL_Rect RightViewport;

			// Glowna petla gry
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					//Handle button events
					new_game_button.handleEvent(&e);
					load_game_button.handleEvent(&e);
					save_game_button.handleEvent(&e);
					exit_game_button.handleEvent(&e);
					main_menu_button.handleEvent(&e);
					pub_button.handleEvent(&e);
					ind_button.handleEvent(&e);
					prod_button.handleEvent(&e);
				}

				const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
				if (currentKeyStates[SDL_SCANCODE_ESCAPE])
					screen = MAIN;
				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				switch (screen)
				{
				case MAIN:
				{
					MainViewport.x = 0;
					MainViewport.y = 0;
					MainViewport.w = SCREEN_WIDTH;
					MainViewport.h = SCREEN_HEIGHT;
					SDL_RenderSetViewport(gRenderer, &MainViewport);
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
					new_game_button.render();
					load_game_button.render();
					save_game_button.render();
					exit_game_button.render();
					break;
				}
				case LOAD:
				{
					LoadViewport.x = 0;
					LoadViewport.y = 0;
					LoadViewport.w = SCREEN_WIDTH;
					LoadViewport.h = SCREEN_HEIGHT;
					SDL_RenderSetViewport(gRenderer, &LoadViewport);
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
					gTextTexture.loadFromRenderedText("Wczytaj", textC);
					gTextTexture.render(600, 200);
					main_menu_button.render();
					break;
				}
				case SAVE:
				{
					SaveViewport.x = 0;
					SaveViewport.y = 0;
					SaveViewport.w = SCREEN_WIDTH;
					SaveViewport.h = SCREEN_HEIGHT;
					SDL_RenderSetViewport(gRenderer, &SaveViewport);
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
					gTextTexture.loadFromRenderedText("Zapisz", textC);
					gTextTexture.render(624, 200);
					main_menu_button.render();
					break;
				}
				case GAME:
				{
					MainViewport.x = 0;
					MainViewport.y = 0;
					MainViewport.w = SCREEN_WIDTH;
					MainViewport.h = SCREEN_HEIGHT;
					SDL_RenderSetViewport(gRenderer, &MainViewport);
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

					pub_button.render();
					ind_button.render();
					prod_button.render();
					break;
				}
				case QUIT:
					quit = true;
					break;
				}

				// Odswiezenie ekranu
				SDL_RenderPresent(gRenderer);
			}
		}
	}
	// Zwalnianie zasobów i zamykanie SDL
	close();
	_getch();
	return 0;
}