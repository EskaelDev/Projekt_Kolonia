
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

// Rozmiary przyciskow (zasoby)
const int RESOURCES_BUTTON_HEIGHT = 52;
const int RESOURCES_BUTTON_WIDTH = 56;

// Wspolrzedne przyiskow build, destroy
int C_1 = 17, C_2 = 204, C_3 = 402, C_4 = 596, C_5 = 770;
int W_1 = 252, W_2 = 488, W_3 = 723;
int R_R = 66;


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
	BUY_RESOURCE,
	SELL,
	SELL_RESOURCE,
	PUBLIC,
	INDUSTRIAL,
	PRODUCTION,
	BUILD,
	DESTROY,
	NONE
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
Mix_Music *gBackgroundMusic = NULL;

// Wlaczenie SDL i stworzenie okna
bool init();

// Ladowanie mediow
bool loadMedia();

// Zwalnianie mediow i zamykanie SDL
void close();

bool buy = false;
bool sell = false;

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
		if ((w == BUILDINGS_BUTTON_WIDTH && h == BUILDINGS_BUTTON_HEIGHT) || (w == BUILD_BUTTON_WIDTH &&h == BUILD_BUTTON_HEIGHT))
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
	if (buy == true)
		buy = false;
	if (sell == true)
		sell = false;
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
		gTexture2 = loadTexture("imgs/production.png");
		screen = GAME;
		subScreen = IND;
		break;

	case PRODUCTION:
		SDL_DestroyTexture(gTexture2);
		gTexture2 = NULL;
		gTexture2 = loadTexture("imgs/farms.png");
		screen = GAME;
		subScreen = PROD;
		break;

	case BUY:
		buy = true;
		break;

	case BUY_RESOURCE:
		break;

	case SELL:
		sell = true;
		break;

	case SELL_RESOURCE:
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

	// Ladowanie tla muzycznego
	gBackgroundMusic = Mix_LoadMUS("sounds/background.ogg");
	if (gBackgroundMusic == NULL)
	{
		cout << "Nie zaladowano dzwieku tla SDL_mixer Error: " << Mix_GetError() << endl;
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

	// Zwalnia muzyke
	Mix_FreeMusic(gBackgroundMusic);
	gBackgroundMusic = NULL;

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

			// Przyciski menu
			// przycisk(akcja, szerokosc, wysokosc, poz_x, poz_y, nazwa_pliku)
			LButton new_game_button(NEW_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 400, "new.png");
			LButton continue_button(PLAY_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 350, "back.png");
			LButton load_game_button(LOAD_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 480, "load.png");
			LButton save_game_button(SAVE_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 560, "save.png");
			LButton exit_game_button(EXIT_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 660, "exit.png");
			LButton main_menu_button(MAIN_MENU, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 660, "menu.png");
			LButton back_button(PLAY_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 300, 730, "back.png");

			// Przyciski splashy
			LButton ind_button(INDUSTRIAL, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 0, 0, "/buildings/ind.png");
			LButton prod_button(PRODUCTION, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 0, 256, "/buildings/prod.png");
			LButton pub_button(PUBLIC, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 0, 512, "/buildings/pub.png");

			// Przyciski: kup, sprzedaj
			LButton buy_button(BUY, BUY_BUTTON_WIDTH, BUY_BUTTON_HEIGHT, 335, 270, "buy.png");
			LButton sell_button(SELL, BUY_BUTTON_WIDTH, BUY_BUTTON_HEIGHT, 335, 420, "sell.png");

			// Przyciski kupowania zasobow
			// przycisk(id, akcja, szerokosc, wysokosc, poz_x, poz_y, nazwa_pliku)
			LButton buy_iron_ore_button(1, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 244, "/resources/iron_ore.png");
			LButton buy_gold_button(2, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 244, "/resources/gold.png");
			LButton buy_cottom_button(3, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 244, "/resources/cottom.png");
			LButton buy_sugarcane_button(4, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 244, "/resources/sugarcane.png");
			LButton buy_food_button(10, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 244, "/resources/food.png");

			LButton buy_tobacco_button(5, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 318, "/resources/tobacco.png");
			LButton buy_cattle_button(6, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 318, "/resources/cattle.png");
			LButton buy_grain_button(7, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 318, "/resources/grain.png");
			LButton buy_flour_button(8, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 318, "/resources/flour.png");
			LButton buy_alcohol_button(14, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 318, "/resources/alcohol.png");

			LButton buy_spices_button(12, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 387, "/resources/spices.png");
			LButton buy_textiles_button(15, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 387, "/resources/textiles.png");
			LButton buy_clothes_button(16, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 387, "/resources/clothes.png");
			LButton buy_cigarettes_button(11, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 387, "/resources/cigarettes.png");
			LButton buy_jewelry_button(17, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 387, "/resources/jewelry.png");

			LButton buy_tools_button(18, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 456, "/resources/tools.png");
			LButton buy_wood_button(19, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 456, "/resources/wood.png");
			LButton buy_bricks_button(20, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 456, "/resources/bricks.png");
			LButton buy_iron_button(9, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 456, "/resources/iron.png");
			LButton buy_cocoa_button(13, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 456, "/resources/cocoa.png");

			// Przyciski sprzedazy zasobow
			// przycisk(id, akcja, szerokosc, wysokosc, poz_x, poz_y, nazwa_pliku)
			LButton sell_iron_ore_button(1, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 244, "/resources/iron_ore.png");
			LButton sell_gold_button(2, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 244, "/resources/gold.png");
			LButton sell_cottom_button(3, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 244, "/resources/cottom.png");
			LButton sell_sugarcane_button(4, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 244, "/resources/sugarcane.png");
			LButton sell_food_button(10, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 244, "/resources/food.png");

			LButton sell_tobacco_button(5, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 318, "/resources/tobacco.png");
			LButton sell_cattle_button(6, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 318, "/resources/cattle.png");
			LButton sell_grain_button(7, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 318, "/resources/grain.png");
			LButton sell_flour_button(8, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 318, "/resources/flour.png");
			LButton sell_alcohol_button(14, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 318, "/resources/alcohol.png");

			LButton sell_spices_button(12, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 387, "/resources/spices.png");
			LButton sell_textiles_button(15, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 387, "/resources/textiles.png");
			LButton sell_clothes_button(16, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 387, "/resources/clothes.png");
			LButton sell_cigarettes_button(11, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 387, "/resources/cigarettes.png");
			LButton sell_jewelry_button(17, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 387, "/resources/jewelry.png");

			LButton sell_tools_button(18, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 456, "/resources/tools.png");
			LButton sell_wood_button(19, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 456, "/resources/wood.png");
			LButton sell_bricks_button(20, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 456, "/resources/bricks.png");
			LButton sell_iron_button(9, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 456, "/resources/iron.png");
			LButton sell_cocoa_button(13, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 456, "/resources/cocoa.png");

			// Przyciski Buduj i Zburz
			// przycisk(id, akcja, szerokosc, wysokosc, poz_x, poz_y, nazwa_pliku)

			// Production
			// CottonPlantation
			LButton build_NAV_CottonPlantation(19, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_3, "/build_nav.png");
			LButton destroy_NAV_CottonPlantation(19, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_3, "/destroy_nav.png");
			LButton build_AV_CottonPlantation(19, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_3, "/build_av.png");
			LButton destroy_AV_CottonPlantation(19, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_3, "/destroy_av.png");
			// ForestersLodge
			LButton build_AV_ForestersLodge(20, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "/build_av.png");
			LButton destroy_AV_ForestersLodge(20, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "/destroy_av.png");
			// GrainFarm
			LButton build_NAV_GrainFarm(21, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "/build_nav.png");
			LButton destroy_NAV_GrainFarm(21, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_GrainFarm(21, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "/build_av.png");
			LButton destroy_AV_GrainFarm(21, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "/destroy_av.png");
			// SpiceFarm
			LButton build_NAV_SpiceFarm(22, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "/build_nav.png");
			LButton destroy_NAV_SpiceFarm(22, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_SpiceFarm(22, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "/build_av.png");
			LButton destroy_AV_SpiceFarm(22, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "/destroy_av.png");
			// HuntersHut
			LButton build_NAV_HuntersHut(23, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "/build_nav.png");
			LButton destroy_NAV_HuntersHut(23, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "/destroy_nav.png");
			LButton build_AV_HuntersHut(23, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "/build_av.png");
			LButton destroy_AV_HuntersHut(23, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "/destroy_av.png");
			// CocoaPlantation
			LButton build_NAV_CocoaPlantation(24, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_3, "/build_nav.png");
			LButton destroy_NAV_CocoaPlantation(24, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_3, "/destroy_nav.png");
			LButton build_AV_CocoaPlantation(24, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_3, "/build_av.png");
			LButton destroy_AV_CocoaPlantation(24, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_3, "/destroy_av.png");
			// CattleFarm
			LButton build_NAV_CattleFarm(25, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "/build_nav.png");
			LButton destroy_NAV_CattleFarm(25, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "/destroy_nav.png");
			LButton build_AV_CattleFarm(25, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "/build_av.png");
			LButton destroy_AV_CattleFarm(25, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "/destroy_av.png");
			// SheepFarm
			LButton build_NAV_SheepFarm(26, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "/build_nav.png");
			LButton destroy_NAV_SheepFarm(26, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "/destroy_nav.png");
			LButton build_AV_SheepFarm(26, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "/build_av.png");
			LButton destroy_AV_SheepFarm(26, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "/destroy_av.png");
			// Winery
			LButton build_NAV_Winery(27, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "/build_nav.png");
			LButton destroy_NAV_Winery(27, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_Winery(27, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "/build_av.png");
			LButton destroy_AV_Winery(27, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "/destroy_av.png");
			// TobaccoPlantation
			LButton build_NAV_TobaccoPlantation(28, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "/build_nav.png");
			LButton destroy_NAV_TobaccoPlantation(28, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_TobaccoPlantation(28, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "/build_av.png");
			LButton destroy_AV_TobaccoPlantation(28, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "/destroy_av.png");
			// SugarcanePlantation
			LButton build_NAV_SugarcanePlantation(29, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "/build_nav.png");
			LButton destroy_NAV_SugarcanePlantation(29, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_SugarcanePlantation(29, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "/build_av.png");
			LButton destroy_AV_SugarcanePlantation(29, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "/destroy_av.png");
			// IronMine
			LButton build_NAV_IronMine(30, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_3, "/build_nav.png");
			LButton destroy_NAV_IronMine(30, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_3, "/destroy_nav.png");
			LButton build_AV_IronMine(30, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_3, "/build_av.png");
			LButton destroy_AV_IronMine(30, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_3, "/destroy_av.png");
			// DeepIronMine
			LButton build_NAV_DeepIronMine(31, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_3, "/build_nav.png");
			LButton destroy_NAV_DeepIronMine(31, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_3, "/destroy_nav.png");
			LButton build_AV_DeepIronMine(31, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_3, "/build_av.png");
			LButton destroy_AV_DeepIronMine(31, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_3, "/destroy_av.png");
			// GoldMine
			LButton build_NAV_GoldMine(32, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_3, "/build_nav.png");
			LButton destroy_NAV_GoldMine(32, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_3, "/destroy_nav.png");
			LButton build_AV_GoldMine(32, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_3, "/build_av.png");
			LButton destroy_AV_GoldMine(32, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_3, "/destroy_av.png");
			// FishersHut
			LButton build_NAV_FishersHut(33, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "/build_nav.png");
			LButton destroy_NAV_FishersHut(33, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "/destroy_nav.png");
			LButton build_AV_FishersHut(33, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "/build_av.png");
			LButton destroy_AV_FishersHut(33, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "/destroy_av.png");

			// Processing
			// Bakery
			LButton build_NAV_Bakery(34, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "/build_nav.png");
			LButton destroy_NAV_Bakery(34, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_Bakery(34, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "/build_av.png");
			LButton destroy_AV_Bakery(34, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "/destroy_av.png");
			// OreRafinery
			LButton build_NAV_OreRafinery(35, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "/build_nav.png");
			LButton destroy_NAV_OreRafinery(35, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_OreRafinery(35, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "/build_av.png");
			LButton destroy_AV_OreRafinery(35, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "/destroy_av.png");
			// GoldSmith
			LButton build_NAV_GoldSmith(36, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_3, "/build_nav.png");
			LButton destroy_NAV_GoldSmith(36, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_3, "/destroy_nav.png");
			LButton build_AV_GoldSmith(36, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_3, "/build_av.png");
			LButton destroy_AV_GoldSmith(36, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_3, "/destroy_av.png");
			// ButchersShop
			LButton build_NAV_ButchersShop(37, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "/build_nav.png");
			LButton destroy_NAV_ButchersShop(37, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "/destroy_nav.png");
			LButton build_AV_ButchersShop(37, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "/build_av.png");
			LButton destroy_AV_ButchersShop(37, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "/destroy_av.png");
			// RumDistillery
			LButton build_NAV_RumDistillery(38, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "/build_nav.png");
			LButton destroy_NAV_RumDistillery(38, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "/destroy_nav.png");
			LButton build_AV_RumDistillery(38, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "/build_av.png");
			LButton destroy_AV_RumDistillery(38, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "/destroy_av.png");
			// Clothiers
			LButton build_NAV_Clothiers(39, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "/build_nav.png");
			LButton destroy_NAV_Clothiers(39, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_Clothiers(39, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "/build_av.png");
			LButton destroy_AV_Clothiers(39, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "/destroy_av.png");
			// StoneMason
			LButton build_NAV_StoneMason(40, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "/build_nav.png");
			LButton destroy_NAV_StoneMason(40, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "/destroy_nav.png");
			LButton build_AV_StoneMason(40, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "/build_av.png");
			LButton destroy_AV_StoneMason(40, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "/destroy_av.png");
			// TobaccoProduction
			LButton build_NAV_TobaccoProduction(41, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "/build_nav.png");
			LButton destroy_NAV_TobaccoProduction(41, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "/destroy_nav.png");
			LButton build_AV_TobaccoProduction(41, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "/build_av.png");
			LButton destroy_AV_TobaccoProduction(41, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "/destroy_av.png");
			// WeavingMill
			LButton build_NAV_WeavingMill(42, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "/build_nav.png");
			LButton destroy_NAV_WeavingMill(42, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_WeavingMill(42, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "/build_av.png");
			LButton destroy_AV_WeavingMill(42, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "/destroy_av.png");
			// WeavingHut
			LButton build_NAV_WeavingHut(43, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "/build_nav.png");
			LButton destroy_NAV_WeavingHut(43, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "/destroy_nav.png");
			LButton build_AV_WeavingHut(43, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "/build_av.png");
			LButton destroy_AV_WeavingHut(43, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "/destroy_av.png");
			// ToolSmith
			LButton build_NAV_ToolSmith(44, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "/build_nav.png");
			LButton destroy_NAV_ToolSmith(44, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_ToolSmith(44, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "/build_av.png");
			LButton destroy_AV_ToolSmith(44, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "/destroy_av.png");
			// WindMill
			LButton build_NAV_WindMill(45, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "/build_nav.png");
			LButton destroy_NAV_WindMill(45, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_WindMill(45, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "/build_av.png");
			LButton destroy_AV_WindMill(45, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "/destroy_av.png");

			// Industrial
			// Doctor
			LButton build_NAV_Doctor(2, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "/build_nav.png");
			LButton destroy_NAV_Doctor(2, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_Doctor(2, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "/build_av.png");
			LButton destroy_AV_Doctor(2, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "/destroy_av.png");
			// PublicBath
			LButton build_NAV_PublicBath(3, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "/build_nav.png");
			LButton destroy_NAV_PublicBath(3, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_PublicBath(3, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "/build_av.png");
			LButton destroy_AV_PublicBath(3, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "/destroy_av.png");
			// FireDepartment
			LButton build_NAV_FireDepartment(4, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "/build_nav.png");
			LButton destroy_NAV_FireDepartment(4, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "/destroy_nav.png");
			LButton build_AV_FireDepartment(4, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "/build_av.png");
			LButton destroy_AV_FireDepartment(4, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "/destroy_av.png");
			// Gallows pojbalo?
			// University
			LButton build_NAV_University(6, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "/build_nav.png");
			LButton destroy_NAV_University(6, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_University(6, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "/build_av.png");
			LButton destroy_AV_University(6, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "/destroy_av.png");
			// Chapel
			LButton build_NAV_Chapel(7, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "/build_nav.png");
			LButton destroy_NAV_Chapel(7, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "/destroy_nav.png");
			LButton build_AV_Chapel(7, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "/build_av.png");
			LButton destroy_AV_Chapel(7, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "/destroy_av.png");
			// Church
			LButton build_NAV_Church(8, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "/build_nav.png");
			LButton destroy_NAV_Church(8, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_Church(8, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "/build_av.png");
			LButton destroy_AV_Church(8, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "/destroy_av.png");
			// MarketPlace
			LButton build_NAV_MarketPlace(10, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "/build_nav.png");
			LButton destroy_NAV_MarketPlace(10, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "/destroy_nav.png");
			LButton build_AV_MarketPlace(10, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "/build_av.png");
			LButton destroy_AV_MarketPlace(10, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "/destroy_av.png");
			// Palace
			LButton build_NAV_Palace(11, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "/build_nav.png");
			LButton destroy_NAV_Palace(11, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_Palace(11, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "/build_av.png");
			LButton destroy_AV_Palace(11, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "/destroy_av.png");
			// School
			LButton build_NAV_School(12, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "/build_nav.png");
			LButton destroy_NAV_School(12, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "/destroy_nav.png");
			LButton build_AV_School(12, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "/build_av.png");
			LButton destroy_AV_School(12, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "/destroy_av.png");
			// Theatre
			LButton build_NAV_Theatre(13, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "/build_nav.png");
			LButton destroy_NAV_Theatre(13, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "/destroy_nav.png");
			LButton build_AV_Theatre(13, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "/build_av.png");
			LButton destroy_AV_Theatre(13, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "/destroy_av.png");
			// Tavern
			LButton build_NAV_Tavern(14, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "/build_nav.png");
			LButton destroy_NAV_Tavern(14, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "/destroy_nav.png");
			LButton build_AV_Tavern(14, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "/build_av.png");
			LButton destroy_AV_Tavern(14, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "/destroy_av.png");





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
				//If there is no music playing 
				if (Mix_PlayingMusic() == 0)
				{ //Play the music 
					Mix_PlayMusic(gBackgroundMusic, -1);
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
						exit_game_button.render();
						new_game_button.handleEvent(&e);
						load_game_button.handleEvent(&e);
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

						back_button.setPosition(624, 660);
						back_button.render();
						back_button.handleEvent(&e);
						break;
					}
					break;
					// Ekran rozgrywki
				case GAME:
					SDL_RenderSetViewport(gRenderer, &LeftViewport);
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

					if (buy == true)
					{
						gTextTexture.loadFromRenderedText("Kup", textC);
						gTextTexture.render(250, 210);
						buy_iron_ore_button.render();
						buy_iron_ore_button.handleEvent(&e);
						buy_gold_button.render();
						buy_gold_button.handleEvent(&e);
						buy_cottom_button.render();
						buy_cottom_button.handleEvent(&e);
						buy_sugarcane_button.render();
						buy_sugarcane_button.handleEvent(&e);
						buy_food_button.render();
						buy_food_button.handleEvent(&e);

						buy_tobacco_button.render();
						buy_tobacco_button.handleEvent(&e);
						buy_cattle_button.render();
						buy_cattle_button.handleEvent(&e);
						buy_grain_button.render();
						buy_grain_button.handleEvent(&e);
						buy_flour_button.render();
						buy_flour_button.handleEvent(&e);
						buy_alcohol_button.render();
						buy_alcohol_button.handleEvent(&e);

						buy_spices_button.render();
						buy_spices_button.handleEvent(&e);
						buy_textiles_button.render();
						buy_textiles_button.handleEvent(&e);
						buy_clothes_button.render();
						buy_clothes_button.handleEvent(&e);
						buy_cigarettes_button.render();
						buy_cigarettes_button.handleEvent(&e);
						buy_jewelry_button.render();
						buy_jewelry_button.handleEvent(&e);

						buy_tools_button.render();
						buy_tools_button.handleEvent(&e);
						buy_wood_button.render();
						buy_wood_button.handleEvent(&e);
						buy_bricks_button.render();
						buy_bricks_button.handleEvent(&e);
						buy_iron_button.render();
						buy_iron_button.handleEvent(&e);
						buy_cocoa_button.render();
						buy_cocoa_button.handleEvent(&e);
					}
					if (sell == true)
					{
						gTextTexture.loadFromRenderedText("Sprzedaj", textC);
						gTextTexture.render(250, 210);
						sell_iron_ore_button.render();
						sell_iron_ore_button.handleEvent(&e);
						sell_gold_button.render();
						sell_gold_button.handleEvent(&e);
						sell_cottom_button.render();
						sell_cottom_button.handleEvent(&e);
						sell_sugarcane_button.render();
						sell_sugarcane_button.handleEvent(&e);
						sell_food_button.render();
						sell_food_button.handleEvent(&e);

						sell_tobacco_button.render();
						sell_tobacco_button.handleEvent(&e);
						sell_cattle_button.render();
						sell_cattle_button.handleEvent(&e);
						sell_grain_button.render();
						sell_grain_button.handleEvent(&e);
						sell_flour_button.render();
						sell_flour_button.handleEvent(&e);
						sell_alcohol_button.render();
						sell_alcohol_button.handleEvent(&e);

						sell_spices_button.render();
						sell_spices_button.handleEvent(&e);
						sell_textiles_button.render();
						sell_textiles_button.handleEvent(&e);
						sell_clothes_button.render();
						sell_clothes_button.handleEvent(&e);
						sell_cigarettes_button.render();
						sell_cigarettes_button.handleEvent(&e);
						sell_jewelry_button.render();
						sell_jewelry_button.handleEvent(&e);

						sell_tools_button.render();
						sell_tools_button.handleEvent(&e);
						sell_wood_button.render();
						sell_wood_button.handleEvent(&e);
						sell_bricks_button.render();
						sell_bricks_button.handleEvent(&e);
						sell_iron_button.render();
						sell_iron_button.handleEvent(&e);
						sell_cocoa_button.render();
						sell_cocoa_button.handleEvent(&e);
					}

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

						// Obiekty przyciskow
						// RENDER							//HANDLE_EVENT
						build_NAV_Doctor.render();			build_NAV_Doctor.handleEvent(&e);
						destroy_NAV_Doctor.render();		destroy_NAV_Doctor.handleEvent(&e);

						build_NAV_PublicBath.render();		build_NAV_PublicBath.handleEvent(&e);
						destroy_NAV_PublicBath.render();	destroy_NAV_PublicBath.handleEvent(&e);

						build_NAV_FireDepartment.render();	build_NAV_FireDepartment.handleEvent(&e);
						destroy_NAV_FireDepartment.render(); destroy_NAV_FireDepartment.handleEvent(&e);

						build_NAV_University.render();		build_NAV_University.handleEvent(&e);
						destroy_NAV_University.render();	destroy_NAV_University.handleEvent(&e);

						build_AV_Chapel.render();			build_AV_Chapel.handleEvent(&e);
						destroy_AV_Chapel.render();			destroy_AV_Chapel.handleEvent(&e);

						build_NAV_Church.render();			build_NAV_Church.handleEvent(&e);
						destroy_NAV_Church.render();		destroy_NAV_Church.handleEvent(&e);

						build_AV_MarketPlace.render();		build_AV_MarketPlace.handleEvent(&e);
						destroy_AV_MarketPlace.render();	destroy_AV_MarketPlace.handleEvent(&e);

						build_NAV_School.render();			build_NAV_School.handleEvent(&e);
						destroy_NAV_School.render();		destroy_NAV_School.handleEvent(&e);

						build_NAV_Theatre.render();			build_NAV_Theatre.handleEvent(&e);
						destroy_NAV_Theatre.render();		destroy_NAV_Theatre.handleEvent(&e);

						build_NAV_Tavern.render();			build_NAV_Tavern.handleEvent(&e);
						destroy_NAV_Tavern.render();		destroy_NAV_Tavern.handleEvent(&e);
						break;
						// Ekran rozgrywki - przetworstwo
					case IND:
						back_button.render();
						back_button.handleEvent(&e);
						SDL_RenderSetViewport(gRenderer, &RightViewport);
						SDL_RenderCopy(gRenderer, gTexture2, NULL, NULL);

						// Obiekty przyciskow
						// RENDER								// HANDLE_EVENT
						build_NAV_Bakery.render();				build_NAV_Bakery.handleEvent(&e);
						destroy_NAV_Bakery.render();			destroy_NAV_Bakery.handleEvent(&e);

						build_NAV_OreRafinery.render();			build_NAV_OreRafinery.handleEvent(&e);
						destroy_NAV_OreRafinery.render();		destroy_NAV_OreRafinery.handleEvent(&e);

						build_NAV_GoldSmith.render();			build_NAV_GoldSmith.handleEvent(&e);
						destroy_NAV_GoldSmith.render();			destroy_NAV_GoldSmith.handleEvent(&e);

						build_NAV_ButchersShop.render();		build_NAV_ButchersShop.handleEvent(&e);
						destroy_NAV_ButchersShop.render();		destroy_NAV_ButchersShop.handleEvent(&e);

						build_NAV_RumDistillery.render();		build_NAV_RumDistillery.handleEvent(&e);
						destroy_NAV_RumDistillery.render();		destroy_NAV_RumDistillery.handleEvent(&e);

						build_NAV_Clothiers.render();			build_NAV_Clothiers.handleEvent(&e);
						destroy_NAV_Clothiers.render();			destroy_NAV_Clothiers.handleEvent(&e);

						build_NAV_StoneMason.render();			build_NAV_StoneMason.handleEvent(&e);
						destroy_NAV_StoneMason.render();		destroy_NAV_StoneMason.handleEvent(&e);

						build_NAV_TobaccoProduction.render();	build_NAV_TobaccoProduction.handleEvent(&e);
						destroy_NAV_TobaccoProduction.render(); destroy_NAV_TobaccoProduction.handleEvent(&e);

						build_NAV_WeavingMill.render();			build_NAV_WeavingMill.handleEvent(&e);
						destroy_NAV_WeavingMill.render();		destroy_NAV_WeavingMill.handleEvent(&e);

						build_AV_WeavingHut.render();			build_AV_WeavingHut.handleEvent(&e);
						destroy_AV_WeavingHut.render();			destroy_AV_WeavingHut.handleEvent(&e);

						build_NAV_ToolSmith.render();			build_NAV_ToolSmith.handleEvent(&e);
						destroy_NAV_ToolSmith.render();			destroy_NAV_ToolSmith.handleEvent(&e);

						build_NAV_WindMill.render();			build_NAV_WindMill.handleEvent(&e);
						destroy_NAV_WindMill.render();			destroy_NAV_WindMill.handleEvent(&e);

						break;
						// Ekran rozgrywki - produkcja
					case PROD:
						back_button.render();
						back_button.handleEvent(&e);
						SDL_RenderSetViewport(gRenderer, &RightViewport);
						SDL_RenderCopy(gRenderer, gTexture2, NULL, NULL);


						// Obiekty przyciskow
						// RENDER								// HANDLE_EVENT
						build_AV_ForestersLodge.render();		build_AV_ForestersLodge.handleEvent(&e);
						destroy_AV_ForestersLodge.render();		destroy_AV_ForestersLodge.handleEvent(&e);

						build_NAV_CottonPlantation.render();	build_NAV_CottonPlantation.handleEvent(&e);
						destroy_NAV_CottonPlantation.render();	destroy_NAV_CottonPlantation.handleEvent(&e);

						build_NAV_GrainFarm.render();			build_NAV_GrainFarm.handleEvent(&e);
						destroy_NAV_GrainFarm.render();			destroy_NAV_GrainFarm.handleEvent(&e);

						build_NAV_SpiceFarm.render();			build_NAV_SpiceFarm.handleEvent(&e);
						destroy_NAV_SpiceFarm.render();			destroy_NAV_SpiceFarm.handleEvent(&e);

						build_AV_HuntersHut.render();			build_AV_HuntersHut.handleEvent(&e);
						destroy_AV_HuntersHut.render();			destroy_AV_HuntersHut.handleEvent(&e);

						build_NAV_CocoaPlantation.render();		build_NAV_CocoaPlantation.handleEvent(&e);
						destroy_NAV_CocoaPlantation.render();	destroy_NAV_CocoaPlantation.handleEvent(&e);

						build_NAV_CattleFarm.render();			build_NAV_CattleFarm.handleEvent(&e);
						destroy_NAV_CattleFarm.render();		destroy_NAV_CattleFarm.handleEvent(&e);

						build_AV_SheepFarm.render();			build_AV_SheepFarm.handleEvent(&e);
						destroy_AV_SheepFarm.render();			destroy_AV_SheepFarm.handleEvent(&e);

						build_NAV_Winery.render();				build_NAV_Winery.handleEvent(&e);
						destroy_NAV_Winery.render();			destroy_NAV_Winery.handleEvent(&e);
						// RENDER								// HANDLE_EVENT
						build_NAV_TobaccoPlantation.render();	build_NAV_TobaccoPlantation.handleEvent(&e);
						destroy_NAV_TobaccoPlantation.render();	destroy_NAV_TobaccoPlantation.handleEvent(&e);

						build_NAV_SugarcanePlantation.render();	build_NAV_SugarcanePlantation.handleEvent(&e);
						destroy_NAV_SugarcanePlantation.render(); destroy_NAV_SugarcanePlantation.handleEvent(&e);

						build_NAV_IronMine.render();			build_NAV_IronMine.handleEvent(&e);
						destroy_NAV_IronMine.render();			destroy_NAV_IronMine.handleEvent(&e);

						build_NAV_DeepIronMine.render();		build_NAV_DeepIronMine.handleEvent(&e);
						destroy_NAV_DeepIronMine.render();		destroy_NAV_DeepIronMine.handleEvent(&e);

						build_NAV_GoldMine.render();			build_NAV_GoldMine.handleEvent(&e);
						destroy_NAV_GoldMine.render();			destroy_NAV_GoldMine.handleEvent(&e);

						build_AV_FishersHut.render();			build_AV_FishersHut.handleEvent(&e);
						destroy_AV_FishersHut.render();			destroy_AV_FishersHut.handleEvent(&e);


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
	// getch do testowania
	//_getch();
	// Zwalnianie zasobów i zamykanie SDL
	close();
	return 0;
}