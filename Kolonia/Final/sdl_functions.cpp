#include "sdl_functions.h"

STexture gTextTexture;
STexture gPromptTextTexture;

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
			printf("Ostrzezenie: Liniowe filtrowanie tekstury jest wylaczone!");

		// Tworzenie okna
		gWindow = SDL_CreateWindow("Kolonia", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Okno nie zostalo utworzone! SDL Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			SDL_Surface* icon = IMG_Load("imgs/icon.png");
			SDL_SetWindowIcon(gWindow, icon);
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
	// Tekstury magazynow
	Warehouse_I_texture = loadTexture("imgs/magazyn1.png");
	if (Warehouse_I_texture == NULL)
	{
		cout << "Nie mozna zaladowac obrazka!" << endl;
		success = false;
	}
	Warehouse_II_texture = loadTexture("imgs/magazyn2.png");
	if (Warehouse_II_texture == NULL)
	{
		cout << "Nie mozna zaladowac obrazka!" << endl;
		success = false;
	}
	Warehouse_III_texture = loadTexture("imgs/magazyn3.png");
	if (Warehouse_III_texture == NULL)
	{
		cout << "Nie mozna zaladowac obrazka!" << endl;
		success = false;
	}
	Warehouse_IV_texture = loadTexture("imgs/magazyn4.png");
	if (Warehouse_IV_texture == NULL)
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
		if (!gTextTexture.loadFromRenderedText("12", textColor, gFont))
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
	if (Warehouse_I_texture != NULL)
	{
		SDL_DestroyTexture(Warehouse_I_texture);
		Warehouse_I_texture = NULL;
	}
	if (Warehouse_II_texture != NULL)
	{
		SDL_DestroyTexture(Warehouse_II_texture);
		Warehouse_II_texture = NULL;
	}
	if (Warehouse_III_texture != NULL)
	{
		SDL_DestroyTexture(Warehouse_III_texture);
		Warehouse_III_texture = NULL;
	}
	if (Warehouse_IV_texture != NULL)
	{
		SDL_DestroyTexture(Warehouse_IV_texture);
		Warehouse_IV_texture = NULL;
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

	// Zamyka systemy SDL'a
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
		std::cout << "Nie mozna wczytac obrazka: " << path.c_str() << "! SDL_image Error: " << IMG_GetError() << std::endl;
	else
	{
		// Wczytuje teksture z powierzchni pikseli
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
			std::cout << "Nie mozna utworzyc tekstury z " << path.c_str() << "! SDL Error: " << path.c_str() << SDL_GetError() << std::endl;

		// Zwalnia stare powierzchnie
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}


bool Build_Pub(Public & Name, Resource & Money, Resource & Bricks, Resource & Tools, Resource & Wood)
{
	if (Name.getStatus() == false)
		return false;

	else if (usedFields + Name.getSize() > islandSize)
		return false;

	else if (Name.Build(Money, Bricks, Tools, Wood) == false)
		return false;
	else
	{
		usedFields += Name.getSize();
		return true;
	}
}

bool Destroy_Pub(Public & Name)
{
	if (Name.Destroy() == true)
	{
		usedFields -= Name.getSize();
		return true;
	}

	else
		return false;
}

bool Build_Proc(Processing & Name, Resource & Money, Resource & Bricks, Resource & Tools, Resource & Wood)
{
	if (Name.getStatus() == false)
		return false;

	else if (usedFields + Name.getSize() > islandSize)
		return false;

	else if (Name.Build(Money, Bricks, Tools, Wood) == false)
		return false;
	else
	{
		usedFields += Name.getSize();
		return true;
	}
}

bool Destroy_Proc(Processing & Name)
{
	if (Name.Destroy() == true)
	{
		usedFields -= Name.getSize();
		return true;
	}

	else
		return false;
}

bool Build_Prod(Production & Name, Resource & Money, Resource & Bricks, Resource & Tools, Resource & Wood)
{
	if (Name.getStatus() == false)
		return false;

	else if (usedFields + Name.getSize() > islandSize)
		return false;

	else if (Name.Build(Money, Bricks, Tools, Wood) == false)
		return false;
	else
	{
		usedFields += Name.getSize();
		return true;
	}
}

bool Destroy_Prod(Production & Name)
{
	if (Name.Destroy() == true)
	{
		usedFields -= Name.getSize();
		return true;
	}

	else
		return false;
}