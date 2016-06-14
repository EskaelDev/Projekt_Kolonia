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


bool Build_Pub(Public & Name, Resource *TResource[21])
{
	if (Name.getStatus() == false)
		return false;

	else if (usedFields + Name.getSize() > islandSize)
		return false;

	else if (Name.Build(TResource) == false)
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

bool Build_Proc(Processing & Name, Resource *TResource[21])
{
	if (Name.getStatus() == false)
		return false;

	else if (usedFields + Name.getSize() > islandSize)
		return false;

	else if (Name.Build(TResource) == false)
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

bool Build_Prod(Production & Name, Resource *TResource[21])
{
	if (Name.getStatus() == false)
		return false;

	else if (usedFields + Name.getSize() > islandSize)
		return false;

	else if (Name.Build(TResource) == false)
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

bool Build_House(House & Name, Resource *TResource[21])
{
	if (Name.getStatus() == false)
		return false;

	else if (usedFields + Name.getSize() > islandSize)
		return false;

	else if (Name.Build(tResource) == false)
		return false;
	else
	{
		usedFields += Name.getSize();
		return true;
	}
}

bool Destroy_House(House & Name)
{
	if (Name.Destroy() == true)
	{
		usedFields -= Name.getSize();
		return true;
	}

	else
		return false;
}

void Fill_Arrays()
{
  //House(bricksToBuild, toolsToBuild, woodToBuild, inhabitants, startPeople, tabBuildingId[], tabSize)
																					{ int tab0[1] = { -1 };
	tHouse[0] = new House(0, 0, 3, 3, 1, tab0, 1); } 	/* Pioneers House */		{ int tab1[2] = { ID_Chapel , ID_Marketplace };
	tHouse[1] = new House(0, 1, 3, 7, 2, tab1, 2); }	/* Settlers House */		{ int tab2[3] = { ID_Fire_Department, ID_School, ID_Tavern };
	tHouse[2] = new House(6, 2, 2, 15, 3, tab2, 3); } 	/* Citizens House */		{ int tab3[3] = { ID_Doctor, ID_Public_Bath, ID_Church };
	tHouse[3] = new House(9, 3, 3, 25, 4, tab3, 3); }	/* Merchansts House */		{ int tab4[3] = { ID_University, ID_Cathedral, ID_Theatre };
	tHouse[4] = new House(12, 3, 3, 40, 5, tab4, 3); }	/* Aristorcats House */
	
 // Public(goldToBuild, bricksToBuild, toolsToBuild, woodToBuild, maintenanceActiveCost, size, peopleToBuild, peopleClass)

	tPublic[0] = new Public(450, 9, 4, 4, 30, 4, 50, 2);			// Doctor
	tPublic[1] = new Public(1200, 19, 6, 5, 60, 12, 210, 2);		// Public Bath	
	tPublic[2] = new Public(150, 0, 3, 5, 15, 4, 15, 1);			// Fire Department
	tPublic[3] = new Public(750, 19, 6, 5, 60, 9, 250, 3);			// University
	tPublic[4] = new Public(100, 0, 2, 5, 5, 2, 40, 0);				// Chapel
	tPublic[5] = new Public(5000, 50, 15, 20, 40, 24, 1500, 3);		// Cathedral
	tPublic[6] = new Public(1600, 25, 7, 7, 50, 12, 150, 2);		// Church
	tPublic[7] = new Public(200, 0, 4, 10, 10, 12, 75, 0);			// Marketplace
	tPublic[8] = new Public(7500, 70, 25, 25, 90, 35, 2500, 4);		// Palace 
	tPublic[9] = new Public(450, 9, 4, 4, 30, 4, 100, 1);			// School
	tPublic[10] = new Public(1200, 19, 2, 5, 80, 9, 300, 3);		// Theatre
	tPublic[11] = new Public(250, 6, 3, 4, 15, 6, 50, 1);			// Tavern

 // Production(moneyToBuild, bricksToBuild, toolsToBuild, woodToBuild, maintenanceActiveCost, maintenancePassiveCost, size, magazineCapacity, peopleToBuild, peopleClass, productID)

	tProduction[0] = new Production(200, 6, 2, 3, 25, 10, 16, 9, 200, 2, 3);		// Cotton Plantation		
	tProduction[1] = new Production(50, 0, 2, 0, 5, 0, 4, 10, 0, -1, 19);			// Foresters Lodge
	tProduction[2] = new Production(100, 0, 2, 5, 5, 0, 16, 6, 75, 1, 7);			// Grain Farm
	tProduction[3] = new Production(300, 8, 2, 3, 35, 15, 16, 4, 75, 1, 12);		// Spice Farm
	tProduction[4] = new Production(50, 0, 2, 2, 5, 0, 4, 3, 0, -1, 10);			// Hunters Hut
	tProduction[5] = new Production(300, 8, 2, 3, 35, 15, 16, 6, 200, 2, 13);		// Cocoa Plantation	
	tProduction[6] = new Production(100, 0, 1, 4, 5, 0, 16, 4, 30, 0, 6);			// Cattle Farm
	tProduction[7] = new Production(200, 0, 2, 4, 5, 0, 16, 8, 0, -1, 3);			// Sheep Farm
	tProduction[8] = new Production(300, 8, 2, 3, 35, 15, 16, 6, 40, 1, 14);		// Winery
	tProduction[9] = new Production(300, 8, 2, 3, 35, 15, 16, 6, 40, 1, 5);			// Tobacco Plantation
	tProduction[10] = new Production(300, 8, 2, 3, 25, 10, 16, 6, 40, 1, 4);		// Sugarcane Plantation
	tProduction[11] = new Production(1000, 5, 10, 20, 60, 20, 3, 4, 120, 1, 1);		// Iron Mine
	tProduction[12] = new Production(1800, 7, 15, 30, 60, 20, 3, 4, 450, 2, 1);		// Deep Iron Mine
	tProduction[13] = new Production(1000, 5, 10, 20, 60, 20, 3, 4, 150, 2, 2);		// Gold Mine
	tProduction[14] = new Production(100, 0, 3, 5, 5, 0, 1, 4, 0, -1, 10);			// Fisters Hut
	tProduction[15] = new Production(100, 0, 5, 5, 5, 0, 4, 8, 15, 1, 20);			// Stone Mason

 // Processing(moneyToBuild, bricksToBuild, toolsToBuild, woodToBuild, maintenanceActiveCost, maintenancePassiveCost, magazineCapacity, peopleToBuild, peopleClass, productID, materialID, productNumber, materialNumber)

	tProcessing[0] = new Processing(150, 0, 2, 6, 5, 0, 4, 75, 1, 10, 8, 3, 2);			// Bakery
	tProcessing[1] = new Processing(200, 4, 3, 1, 25, 10, 5, 120, 1, 9, 1, 1, 1);		// Ore Refenery
	tProcessing[2] = new Processing(1500, 10, 7, 2, 45, 20, 4, 250, 3, 17, 2, 2, 1);	// Gold Smith
	tProcessing[3] = new Processing(150, 10, 3, 4, 5, 0, 4, 30, 0, 10, 6, 1, 2);		// Butcher Shop
	tProcessing[4] = new Processing(200, 5, 3, 2, 25, 7, 4, 40, 1, 14, 4, 1, 2);		// Rum Distillery
	tProcessing[5] = new Processing(150, 2, 3, 6, 10, 5, 4, 200, 2, 16, 15, 1, 1);		// Clothiers
	tProcessing[6] = new Processing(200, 5, 3, 2, 20, 10, 4, 40, 1, 11, 5, 1, 2);		// TobaccoProduction
	tProcessing[7] = new Processing(200, 7, 4, 3, 20, 10, 4, 75, 1, 15, 3, 3, 2);		// WeavingMill
	tProcessing[8] = new Processing(200, 0, 3, 6, 10, 5, 4, 0, -1, 15, 3, 1, 2);		// WeavingHut
	tProcessing[9] = new Processing(150, 5, 3, 2, 25, 10, 4, 100, 1, 18, 9, 2, 1);		// ToolSmithy
	tProcessing[10] = new Processing(100, 0, 3, 6, 5, 0, 6, 75, 1, 10, 7, 1, 2);		// WindMill

 // People(tax)
																{ int tab0[1] = { ID_Money };
	tPeople[0] = new People(1, tab0, 1); }	/* Pioneers */		{ int tab1[3] = { ID_Money, ID_Cloth, ID_Sugar };
	tPeople[1] = new People(1, tab1, 3); }	/* Settlers	*/		{ int tab2[5] = { ID_Money, ID_Cloth, ID_Sugar, ID_Liquor, ID_Spices };
	tPeople[2] = new People(1, tab2, 5); }	/* Citizens	*/		{ int tab3[7] = { ID_Money, ID_Cloth, ID_Sugar, ID_Liquor, ID_Spices, ID_Cocoa, ID_Tobacco_Products };
	tPeople[3] = new People(2, tab3, 7); }	/* Merchants */		{ int tab4[9] = { ID_Money, ID_Cloth, ID_Sugar, ID_Liquor, ID_Spices, ID_Cocoa, ID_Tobacco_Products, ID_Jewerly, ID_Clothes };
	tPeople[4] = new People(2, tab4, 9); }	/* Aristocrats */

 // Resource(price)

	tResource[0] = new Resource(1);			// Money
	tResource[1] = new Resource(60);		// Iron Ore
	tResource[2] = new Resource(465);		// Gold
	tResource[3] = new Resource(16);		// Wool
	tResource[4] = new Resource(19);		// Sugar
	tResource[5] = new Resource(23);		// Tobacco
	tResource[6] = new Resource(6);			// Cattle
	tResource[7] = new Resource(3);			// Grain
	tResource[8] = new Resource(3);			// Flour
	tResource[9] = new Resource(84);		// Iron
	tResource[10] = new Resource(17);		// Food
	tResource[11] = new Resource(65);		// Tobacco Products
	tResource[12] = new Resource(40);		// Spices
	tResource[13] = new Resource(33);		// Cocoa
	tResource[14] = new Resource(52);		// Liquor
	tResource[15] = new Resource(32);		// Cloth
	tResource[16] = new Resource(130);		// Clothes
	tResource[17] = new Resource(590);		// Jewerly
	tResource[18] = new Resource(80);		// Tools
	tResource[19] = new Resource(20);		// Wood
	tResource[20] = new Resource(30);		// Bricks

}

Uint32 Update_Prod(Uint32 interval, void* param)
{

	int i = reinterpret_cast<int>(param);
	if (tProduction[i]->getNumber() > 0)
	{
		if (tResource[tProduction[i]->getProductID()]->getNumber() + tProduction[i]->getNumber()*tProduction[i]->getMagazineCapacity() < WareHouse.getmagazineCapacity() + tProduction[i]->getNumber()*tProduction[i]->getMagazineCapacity())
		{
			if (tProduction[i]->getNumber() < 5)
			{
				tResource[tProduction[i]->getProductID()]->increase(tProduction[i]->getNumber() );

				return 5000;
			}
			else
			{
				tResource[tProduction[i]->getProductID()]->increase(tProduction[i]->getNumber() );
				return 3000;
			}
		}
		else
			tResource[tProduction[i]->getProductID()]->setNumber(WareHouse.getmagazineCapacity() + tProduction[i]->getNumber()*tProduction[i]->getMagazineCapacity());
		return 3000;
	}
	return 2000;
}

Uint32 Update_Proc(Uint32 interval, void* param)
{
	int i = reinterpret_cast<int>(param);

	if (tProcessing[i]->getNumber() > 0)
	{
		if (tResource[tProcessing[i]->getMaterialID()]->getNumber() > tProcessing[i]->getMaterialNumber())
		{
			if (tResource[tProcessing[i]->getProductID()]->getNumber() + tProcessing[i]->getNumber()*tProcessing[i]->getNumber() < WareHouse.getmagazineCapacity() + tProcessing[i]->getNumber()*tProcessing[i]->getMagazineCapacity())
			{
				if (tProcessing[i]->getNumber() < 5)
				{
					tResource[tProcessing[i]->getProductID()]->increase(tProcessing[i]->getNumber()*tProcessing[i]->getProductNumber());
					tResource[tProcessing[i]->getMaterialID()]->decrease(tProcessing[i]->getNumber()*tProcessing[i]->getMaterialNumber());
					return 7000;
				}
				else
				{
					tResource[tProcessing[i]->getProductID()]->increase(tProcessing[i]->getNumber()*tProcessing[i]->getProductNumber());
					tResource[tProcessing[i]->getMaterialID()]->decrease(tProcessing[i]->getNumber()*tProcessing[i]->getMaterialNumber());
					return 5000;
				}
			}
			else
				tResource[tProcessing[i]->getProductID()]->setNumber(WareHouse.getmagazineCapacity() + tProcessing[i]->getNumber()*tProcessing[i]->getMagazineCapacity());
			return 3000;
		}
		else
			return 2000;
	}
	return 2000;
}

Uint32 Update_Tax(Uint32 interval, void *param) 
{
	// AKTUALIZACJA LICZBY MIESZKANCOW

	for (int i = 0; i < 5; ++i)
	{
		if (tHouse[i]->getInhabitants() * tHouse[i]->getNumber() > tPeople[i]->getNumber())			// jezeli liczba lokatorow jednego domu * liczba domow jest wieksza od liczby posiadanych mieszkancow
			tPeople[i]->increase(tHouse[i]->getNumber());											// zwieksz liczbe mieszkancow o liczbe posiadanych budynkow mieszkalnych

		if (tHouse[i]->getInhabitants() * tHouse[i]->getNumber() < tPeople[i]->getNumber())			// jezeli przekroczono limit mieszkancow jaki mozemy posiadac
			tPeople[i]->setNumber(tHouse[i]->getInhabitants() * tHouse[i]->getNumber());			// ustaw liczbe mieszkancow na maksimum
	}

	// POBOR PODATKU OD MIESZKANCOW
	taxes = 0;
	for (int i = 0; i < 5; ++i) 
	{
		tResource[0]->increase(tPeople[i]->getTax());
		taxes += tPeople[i]->getTax();
	}

	// KOSZTY UTRZYMANIA POSIADANYCH BUDYNKOW
	costs = 0;
	for (int i = 0; i < 12; ++i)
	{
		tResource[0]->decrease(tPublic[i]->getMaintenanceActiveCost() * tPublic[i]->getNumber());
		costs += tPublic[i]->getMaintenanceActiveCost() * tPublic[i]->getNumber();
	}
	for (int i = 0; i < 16; ++i)
	{
		tResource[0]->decrease(tProduction[i]->getMaintenanceActiveCost() * tProduction[i]->getActiveNumber()
			+ tProduction[i]->getMaintenancePassiveCost() * (tProduction[i]->getNumber() - tProduction[i]->getActiveNumber()));
		costs += tProduction[i]->getMaintenanceActiveCost() * tProduction[i]->getActiveNumber()
			+ tProduction[i]->getMaintenancePassiveCost() * (tProduction[i]->getNumber() - tProduction[i]->getActiveNumber());
	}
	for (int i = 0; i < 11; ++i)
	{
		tResource[0]->decrease(tProcessing[i]->getMaintenanceActiveCost() * tProcessing[i]->getActiveNumber()
			+ tProcessing[i]->getMaintenancePassiveCost() * (tProcessing[i]->getNumber() - tProcessing[i]->getActiveNumber()));
		costs += tProcessing[i]->getMaintenanceActiveCost() * tProcessing[i]->getActiveNumber()
			+ tProcessing[i]->getMaintenancePassiveCost() * (tProcessing[i]->getNumber() - tProcessing[i]->getActiveNumber());
	}
	return 1000;
}

Uint32 Update_Req(Uint32 interval, void* param)
{
	// SPRAWDZENIE WARUNKU DOSTEPNOSCI BUDYNKOW:
	// WYMAGANIA POSIADANIA KONKRETNEJ KLASY LUDNOSCI

	for (int i = 0; i < 12; ++i)
		if (tPublic[i]->getClass() > -1)
			tPublic[i]->checkStatus(tPeople[tPublic[i]->getClass()]->getNumber());

	for (int i = 0; i < 16; ++i)
		if (tProduction[i]->getClass() > -1)
			tProduction[i]->checkStatus(tPeople[tProduction[i]->getClass()]->getNumber());

	for (int i = 0; i < 11; ++i)
		if (tProcessing[i]->getClass() > -1)
			tProcessing[i]->checkStatus(tPeople[tProcessing[i]->getClass()]->getNumber());

	if (WareHouse.getClass() > -1)
		WareHouse.checkStatus(tPeople[WareHouse.getClass()]->getNumber());

	// WYMAGANIA POSIADANIA KONRETNYCH BUDYNKOW 

	for (int i = 1; i < 5; ++i)													// tHouse[0] zawsze dostepny
		for (int j = 0; j < tHouse[i]->getTabIdSize(); ++j)
		{
			tHouse[i]->checkStatus(tPublic[tHouse[i]->getBuildingId(j)]->getNumber());
			if (false == tHouse[i]->getStatus())								// wystarczy, ze nie posiadamy jednego budynku i budowa jest niedostepna
				break;
		}
	balance = taxes - costs + buy_income - sale_costs;

	return 500;

}