/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <conio.h>

using namespace std;

// Rozmiar okna
const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;

// Rozmiary przyciskow (nowa gra,wczytaj gre, zapisz gre, wyjdz z gry, wroc, graj)
const int MAIN_BUTTON_WIDTH = 118;
const int MAIN_BUTTON_HEIGHT = 35;

// Rozmiary przyciskow splashy
const int BUILDINGS_BUTTON_WIDTH = 911;
const int BUILDINGS_BUTTON_HEIGHT = 256;

// Rozmiary przyciskow (zbuduj, zburz)
const int BUILD_BUTTON_WIDTH = 60;
const int BUILD_BUTTON_HEIGHT = 20;

// Rozmiary przyciskow (kup, sprzedaj)
const int BUY_BUTTON_WIDTH = 90;
const int BUY_BUTTON_HEIGHT = 70;

// Sprity stanow przycisku
enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT,
	BUTTON_SPRITE_MOUSE_OVER_MOTION,
	BUTTON_SPRITE_MOUSE_DOWN,
	BUTTON_SPRITE_MOUSE_UP,
	BUTTON_SPRITE_TOTAL
};

// Stany wyswietlanego ekranu
enum Screen
{
	MAIN,
	LOAD,
	SAVE,
	GAME,
	PUB,
	IND,
	PROD,
	QUIT
} screen, subScreen;

// Akcje dla przyciskow
enum Actions
{
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
SDL_Renderer* gRenderer2 = NULL;


// Wyswietlane tekstury
SDL_Texture* gTexture = NULL;
SDL_Texture* gTexture2 = NULL;

// Czcionka
TTF_Font *gFont = NULL;

// Dzwiek klikania
Mix_Chunk *gClickSound = NULL;

// Wlaczenie SDL i stworzenie okna
bool init();

// Ladowanie mediow
bool loadMedia();

// Zwalnianie mediow i zamykanie SDL
void close();

class LTexture
{
public:
	LTexture();
	~LTexture();

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

LTexture::LTexture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	free();
}

bool LTexture::loadFromFile(std::string path)
{
	// Usuniecie wczesniejszej tekstury
	free();

	// Finalna tekstura
	SDL_Texture* newTexture = NULL;

	// Zaladowanie obrazka z podanej sciezki
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		cout << "Nie mozna zaladowac obrazka " << path.c_str() << "! SDL_image Error: " << IMG_GetError() << endl;
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		// Tworzenie tekstury z powierzchni
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			cout << "Nie mozna utworzyc tekstury z " << path.c_str() << "! SDL Error: " << SDL_GetError() << endl;
		}
		else
		{
			// Pobranie wymiarow obrazka
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		// Usuniecie starej powierzchni
		SDL_FreeSurface(loadedSurface);
	}

	// Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
	// Usuniecie wczesniejszej tekstury
	free();

	// Renderowanie powierzchni tekstu
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface == NULL)
	{
		cout << "Nie mozna wyrenderowac powierzchni tekstu! SDL_ttf Error: " << TTF_GetError() << endl;
	}
	else
	{
		// Tworzenie tekstury z powierzchni
		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (mTexture == NULL)
		{
			cout << "Nie mozna utworzyc tekstury z wyrenderowanego tekstu! SDL Error: " << SDL_GetError() << endl;
		}
		else
		{
			// Pobranie wymiarow obrazka
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		// Usuniecie starej powierzchni
		SDL_FreeSurface(textSurface);
	}

	// Return success
	return mTexture != NULL;
}

void LTexture::free()
{
	// Zwalnianie tekstury, jesli istnieje
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
	// Modulacja RGB tekstury
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void LTexture::setBlendMode(SDL_BlendMode blending)
{
	// Ustawienie funkcji mieszania
	SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(Uint8 alpha)
{
	// Modulacja przezroczystosci tekstury
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	// Ustawienie miejsca renderowania i renderowanie na ekran
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	// Ustawienie rozmiaru renderowania clip
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	// Renderowanie na ekran
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

LTexture gTextTexture;
LTexture gPromptTextTexture;
LTexture gTimeTextTexture;

class LButton
{
public:
	LButton(Actions, int, int, int, int, char*);
	LButton(int, Actions, int, int, int, int, char*);
	~LButton();

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
	LTexture gButtonSpriteSheetTexture;

	// id budynku, szerokosc, wysokosc
	int id, w, h, w_b, h_b;

	// Sciezka (nazwa) pliku
	char *img;

	// Pozycja przycisku
	SDL_Point mPosition;

	// Warunek akcji przycisku
	Actions action;

	// Aktualnie wyswietlany sprite
	LButtonSprite mCurrentSprite;
	SDL_Rect gSpriteClips[BUTTON_SPRITE_TOTAL];
};

LButton::LButton(Actions action, int width, int height, int pos_x, int pos_y, char *image)
	: action(action), w(width), h(height), mCurrentSprite(BUTTON_SPRITE_MOUSE_OUT)
{
	img = new char[strlen(image) + strlen("imgs/buttons/") + 2];
	strcpy(img, "imgs/buttons/");
	strcat(img, image);

	setPosition(pos_x, pos_y);
	setTexture();
}


LButton::LButton(int ident, Actions action, int width, int height, int pos_x, int pos_y, char *image)
	: id(ident), action(action), w(width), h(height), mCurrentSprite(BUTTON_SPRITE_MOUSE_OUT)
{
	img = new char[strlen(image) + strlen("imgs/buttons/") + 2];
	strcpy(img, "imgs/buttons/");
	strcat(img, image);

	setPosition(pos_x, pos_y);
	setTexture();
}

LButton::~LButton()
{
	this->w = NULL;
	this->h = NULL;
	delete[] img;
	gButtonSpriteSheetTexture.free();
}

void LButton::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}

void LButton::handleEvent(SDL_Event* e)
{
	// Jesli zdarzenie myszy zaszlo
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{


		// Pobierz pozycje myszy
		int x, y;
		SDL_GetMouseState(&x, &y);

		// Sprawdz czy mysz jest na przycisku
		bool inside = true;

		// Czy na prawym panelu
		bool RightPanelButton = false;
		if (w > 500 && h > 100)
			RightPanelButton = true;

		// Czy na prawym panelu
		if (RightPanelButton)
		{
			inside = true;
			// Mysz jest z lewej strony splasha
			if (x < mPosition.x + SCREEN_WIDTH / 3)
			{
				inside = false;
			}
			// Mysz jest z prawej strony splasha
			else if (x > mPosition.x + w + SCREEN_WIDTH / 3)
			{
				inside = false;
			}
			// Mysz jest ponad przyciskiem
			else if (y < mPosition.y)
			{
				inside = false;
			}
			// Mysz jest ponizej przycisku
			else if (y > mPosition.y + h)
			{
				inside = false;
			}

		}
		else
		// Mysz jest z lewej strony przycisku
		if (x < mPosition.x)
		{
			inside = false;
		}
		// Mysz jest z prawej strony przycisku
		else if (x > mPosition.x + w)
		{
			inside = false;
		}
		// Mysz jest ponad przyciskiem
		else if (y < mPosition.y)
		{
			inside = false;
		}
		// Mysz jest ponizej przycisku
		else if (y > mPosition.y + h)
		{
			inside = false;
		}

		// Mysz jest poza przyciskiem
		if (!inside)
		{
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		
		// Mysz jest w przycisku
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
				Mix_PlayChannel(-1, gClickSound, 0);
				SDL_Delay(200);
				operation(action);
				break;

			case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;
			}
		}
	}
}

void LButton::setTexture()
{
	if (!gButtonSpriteSheetTexture.loadFromFile(img))
	{
		cout << "Nie mozna zaladowac tekstury przycisku!" << endl;
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
}

void LButton::render()
{
	gButtonSpriteSheetTexture.render(mPosition.x, mPosition.y, &gSpriteClips[mCurrentSprite]);
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
		subScreen = GAME;
		break;

	case LOAD_GAME:
		SDL_DestroyTexture(gTexture);
		gTexture = NULL;
		gTexture = loadTexture("imgs/load_save.png");
		screen = MAIN;
		subScreen = LOAD;
		break;

	case SAVE_GAME:
		SDL_DestroyTexture(gTexture);
		gTexture = NULL;
		gTexture = loadTexture("imgs/load_save.png");
		screen = MAIN;
		subScreen = SAVE;
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
		subScreen = MAIN;
		break;

	case PLAY_GAME:
		SDL_DestroyTexture(gTexture);
		gTexture = NULL;
		gTexture = loadTexture("imgs/left.png");
		screen = GAME;
		subScreen = GAME;
		break;

	case PUBLIC:
		SDL_DestroyTexture(gTexture2);
		gTexture2 = NULL;
		gTexture2 = loadTexture("imgs/public.png");
		screen = GAME;
		subScreen = PUB;
		break;

	case INDUSTRIAL:
		SDL_DestroyTexture(gTexture2);
		gTexture2 = NULL;
		gTexture2 = loadTexture("imgs/farms.png");
		screen = GAME;
		subScreen = IND;
		break;

	case PRODUCTION:
		SDL_DestroyTexture(gTexture2);
		gTexture2 = NULL;
		gTexture2 = loadTexture("imgs/production.png");
		screen = GAME;
		subScreen = PROD;
		break;

	case EXIT_GAME:
		screen = QUIT;
		break;

	case BUILD:
		break;

	case DESTROY:
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
		cout << "SDL nie zostal zainicjalizowany! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		// Ustawienie filtrowania tekstury na liniowe
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Ostrzezenie: Liniowe filtrowanie tekstury jest wylaczone!");
		}

		// Tworzenie okna
		gWindow = SDL_CreateWindow("Kolonia", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Okno nie zostalo utworzone! SDL Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			// Tworzenie renderera dla okna
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				cout << "Renderer nie zostal utworzony! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				// Inicjalizacja kolorow renderera
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Inicjalizacja ladowania PNG
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					cout << "SDL_image nie zostal zainicjalizowany! SDL_image Error: " << IMG_GetError() << endl;
					success = false;
				}

				// Inicjalizacja SDL_ttf
				if (TTF_Init() == -1)
				{
					cout << "SDL_ttf nie zostal zainicjalizowany! SDL_ttf Error: " << TTF_GetError() << endl;
					success = false;
				}

				// Inicjalizacja SDL_mixer
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					cout << "SDL_mixer nie zostal zainicjalizowany! SDL_mixer Error: " << Mix_GetError() << endl;
					success = false;
				}
			}
		}
	}

	return success;
}

SDL_Color textColor = { 255, 255, 255, 255 };
std::stringstream timeText;

bool loadMedia()
{
	// Flaga powodzenia ladowania
	bool success = true;

	// Ladowanie tekstury
	gTexture = loadTexture("imgs/main.png");
	if (gTexture == NULL)
	{
		cout << "Nie mozna zaladowac obrazka!" << endl;
		success = false;
	}

	// Ladowanie czcionki
	gFont = TTF_OpenFont("fonts/Caladea-Regular.ttf", 19);
	if (gFont == NULL)
	{
		cout << "Nie mozna zaladowac czcionki! SDL_ttf Error: " << TTF_GetError() << endl;
		success = false;
	}
	else
	{
		// Renderowanie tekstu
		SDL_Color textColor = { 200, 200, 200 };
		if (!gTextTexture.loadFromRenderedText("12", textColor))
		{
			cout << "Nie mozna wyrenderowac tekstu!" << endl;
			success = false;
		}
	}

	// Ladowanie dzwieku klikniecia
	gClickSound = Mix_LoadWAV("sounds/click.wav");
	if (gClickSound == NULL)
	{
		cout << "Nie zaladowano dzwieku  SDL_mixer Error: " << Mix_GetError() << endl;
		success = false;
	}

	// Ladowanie tekstury
	if (!gPromptTextTexture.loadFromRenderedText("Nacisnij ENTER, aby zresetowac czas.", textColor))
	{
		cout << "Nie mozna wyrenderowac tekstury!" << endl;
		success = false;
	}

	return success;
}

void close()
{
	// Zwalnia zaladowany obrazek
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

	// Zwalnia teksture tekstu
	gTextTexture.free();

	// Zwalnia czcionke
	TTF_CloseFont(gFont);
	gFont = NULL;

	// Zwalnia dzwiek
	Mix_FreeChunk(gClickSound);
	gClickSound = NULL;

	// Zamyka okno
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	// Zamkniecie systemow SDL'a
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture(std::string path)
{
	// Finalna tekstura
	SDL_Texture* newTexture = NULL;

	// Wczytuje obrazek ze sciezki
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		cout << "Nie mozna wczytac obrazka: " << path.c_str() << "! SDL_image Error: " << IMG_GetError() << endl;
	}
	else
	{
		// Wczytuje teksture z powierzchni pikseli
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			cout << "Nie mozna utworzyc tekstury z " << path.c_str() << "! SDL Error: " << path.c_str() << SDL_GetError() << endl;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

int main(int argc, char* args[])
{
	// Wlaczenie SDL i stworzenie okna
	if (!init())
		cout << "Blad inicjalizacji!" << endl;
	else
	{
		// Ladowanie mediow
		if (!loadMedia())
			cout << "Nie mozna zaladowac mediow!" << endl;
		else
		{
			// Flaga glownej petli
			bool quit = false;

			// Kolor tekstu
			SDL_Color textC = { 200, 200, 200 };

			// Ekran poczatkowy
			screen = MAIN;

			SDL_Event e;

			// Poczatkowy czas
			Uint32 startTime = 0;

			SDL_Rect LargeViewport;
			LargeViewport.x = 0;
			LargeViewport.y = 0;
			LargeViewport.w = SCREEN_WIDTH;
			LargeViewport.h = SCREEN_HEIGHT;

			SDL_Rect LeftViewport;
			LeftViewport.x = 0;
			LeftViewport.y = 0;
			LeftViewport.w = SCREEN_WIDTH / 3;
			LeftViewport.h = SCREEN_HEIGHT;

			SDL_Rect RightViewport;
			RightViewport.x = SCREEN_WIDTH / 3;
			RightViewport.y = 0;
			RightViewport.w = 2 * SCREEN_WIDTH / 3;
			RightViewport.h = SCREEN_HEIGHT;

			gFont = TTF_OpenFont("fonts/Caladea-Regular.ttf", 19);

			// przycisk(akcja, szerokosc, wysokosc, pos_x, pos_y, nazwa_pliku)
			LButton new_game_button(NEW_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 400, "new.png");
			LButton continue_button(PLAY_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 350, "back.png");
			LButton load_game_button(LOAD_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 480, "load.png");
			LButton save_game_button(SAVE_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 560, "save.png");
			LButton exit_game_button(EXIT_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 660, "exit.png");
			LButton main_menu_button(MAIN_MENU, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 660, "menu.png");
			LButton back_button(PLAY_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 300, 730, "back.png");

			LButton ind_button(INDUSTRIAL, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 0, 0, "/buildings/ind.png");
			LButton prod_button(PRODUCTION, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 0, 256, "/buildings/prod.png");
			LButton pub_button(PUBLIC, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 0, 512, "/buildings/pub.png");

			LButton buy_button(BUY, BUY_BUTTON_WIDTH, BUY_BUTTON_HEIGHT, 335, 270, "buy.png");
			LButton sell_button(SELL, BUY_BUTTON_WIDTH, BUY_BUTTON_HEIGHT, 335, 420, "sell.png");

			// Glowna petla gry
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					// User requests quit
					if (e.type == SDL_QUIT)
						quit = true;

					// Resetowanie czasu po nacisnieciu ENTER
					else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
					{
						startTime = SDL_GetTicks();
					}
				}

				// Klawisz ESCAPE - wychodzenie do menu glownego
				const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
				if (currentKeyStates[SDL_SCANCODE_ESCAPE])
				{
					if (!(screen == MAIN && subScreen == MAIN))
					{
						if (gTexture2 != NULL)
						{
							SDL_DestroyTexture(gTexture2);
							gTexture2 = NULL;
						}
						SDL_DestroyTexture(gTexture);
						gTexture = NULL;
						gTexture = loadTexture("imgs/main.png");
						screen = MAIN;
						subScreen = MAIN;
					}
				}
				// Ustawianie tekst do renderowania
				timeText.str("");
				timeText << "Czas w milisekundach: " << SDL_GetTicks() - startTime;

				// Renderowanie tekstu
				if (!gTimeTextTexture.loadFromRenderedText(timeText.str().c_str(), textColor))
				{
					cout << "Nie mozna wyrenderowac czasu!" << endl;
				}
				// Czyszczenie ekranu
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				switch (screen)
				{
					// Ekran menu glownego
				case MAIN:
					SDL_RenderSetViewport(gRenderer, &LargeViewport);
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
					switch (subScreen)
					{
					case MAIN:
						save_game_button.setPosition(624, 560);
						new_game_button.render();
						load_game_button.render();
						save_game_button.render();
						exit_game_button.render();
						new_game_button.handleEvent(&e);
						load_game_button.handleEvent(&e);
						save_game_button.handleEvent(&e);
						exit_game_button.handleEvent(&e);

						gPromptTextTexture.render((SCREEN_WIDTH - gPromptTextTexture.getWidth()) / 2, SCREEN_HEIGHT - gPromptTextTexture.getHeight());
						gTimeTextTexture.render((SCREEN_WIDTH - gTimeTextTexture.getWidth()) / 2, 0);
						break;
						// Ekran wczytywania stanu gry
					case LOAD:
						gTextTexture.loadFromRenderedText("Wczytaj", textC);
						gTextTexture.render(600, 200);

						main_menu_button.setPosition(624, 660);
						main_menu_button.render();
						main_menu_button.handleEvent(&e);
						break;
						// Ekran zapisu stanu gry
					case SAVE:
						gTextTexture.loadFromRenderedText("Zapisz", textC);
						gTextTexture.render(624, 200);

						main_menu_button.setPosition(624, 660);
						main_menu_button.render();
						main_menu_button.handleEvent(&e);
						break;
					}
					break;
					// Ekran rozgrywki
				case GAME:
					SDL_RenderSetViewport(gRenderer, &LeftViewport);
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

					buy_button.render();
					sell_button.render();
					buy_button.handleEvent(&e);
					sell_button.handleEvent(&e);
					save_game_button.setPosition(100, 730);
					save_game_button.render();
					save_game_button.handleEvent(&e);
					switch (subScreen)
					{
						// Ekran rozgrywki - wybor budynkow
					case GAME:
						main_menu_button.setPosition(300, 730);
						main_menu_button.render();
						main_menu_button.handleEvent(&e);

						SDL_RenderSetViewport(gRenderer, &RightViewport);
						ind_button.render();
						prod_button.render();
						pub_button.render();
						ind_button.handleEvent(&e);
						prod_button.handleEvent(&e);
						pub_button.handleEvent(&e);
						break;
						// Ekran rozgrywki - budynki publiczne
					case PUB:
						back_button.render();
						back_button.handleEvent(&e);
						SDL_RenderSetViewport(gRenderer, &RightViewport);
						SDL_RenderCopy(gRenderer, gTexture2, NULL, NULL);
						break;
						// Ekran rozgrywki - przetworstwo
					case IND:
						back_button.render();
						back_button.handleEvent(&e);
						SDL_RenderSetViewport(gRenderer, &RightViewport);
						SDL_RenderCopy(gRenderer, gTexture2, NULL, NULL);
						break;
						// Ekran rozgrywki - produkcja
					case PROD:
						back_button.render();
						back_button.handleEvent(&e);
						SDL_RenderSetViewport(gRenderer, &RightViewport);
						SDL_RenderCopy(gRenderer, gTexture2, NULL, NULL);
						break;
					}
					break;
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
	return 0;
}