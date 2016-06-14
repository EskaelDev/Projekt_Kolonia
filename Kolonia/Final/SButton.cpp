#include "SButton.h"
#include "conio.h"
SButton::SButton(Actions action, int width, int height, int pos_x, int pos_y, char *image)
	: action(action), w(width), h(height), mCurrentSprite(BUTTON_SPRITE_MOUSE_OUT)
{
	img = new char[strlen(image) + strlen("imgs/buttons/") + 2];
	strcpy(img, "imgs/buttons/");
	strcat(img, image);

	setPosition(pos_x, pos_y);
	setTexture();
}

SButton::SButton(int ident, Actions action, int width, int height, int pos_x, int pos_y, char *image)
	: id(ident), action(action), w(width), h(height), mCurrentSprite(BUTTON_SPRITE_MOUSE_OUT)
{
	img = new char[strlen(image) + strlen("imgs/buttons/") + 2];
	strcpy(img, "imgs/buttons/");
	strcat(img, image);

	setPosition(pos_x, pos_y);
	setTexture();
}

SButton::~SButton()
{
	this->w = NULL;
	this->h = NULL;
	delete[] img;
	gButtonSpriteSheetTexture.free();
}

void SButton::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}

void SButton::handleEvent(SDL_Event* e)
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
		bool RightPaneSButton = false;
		if ((w == BUILDINGS_BUTTON_WIDTH && h == BUILDINGS_BUTTON_HEIGHT) || (w == BUILD_BUTTON_WIDTH && h == BUILD_BUTTON_HEIGHT) || (w == ALLOW_BUILD_BUTTON_WIDTH && h == ALLOW_BUILD_BUTTON_HEIGHT))
			RightPaneSButton = true;

		// Czy na prawym panelu
		if (RightPaneSButton)
		{
			inside = true;
			// Mysz jest z lewej strony splasha
			if (x < mPosition.x + SCREEN_WIDTH / 3)
				inside = false;
			// Mysz jest z prawej strony splasha
			else if (x > mPosition.x + w + SCREEN_WIDTH / 3)
				inside = false;
			// Mysz jest ponad przyciskiem
			else if (y < mPosition.y)
				inside = false;
			// Mysz jest ponizej przycisku
			else if (y > mPosition.y + h)
				inside = false;
		}
		else
			// Mysz jest z lewej strony przycisku
			if (x < mPosition.x)
				inside = false;
			// Mysz jest z prawej strony przycisku
			else if (x > mPosition.x + w)
				inside = false;
			// Mysz jest ponad przyciskiem
			else if (y < mPosition.y)
				inside = false;
			// Mysz jest ponizej przycisku
			else if (y > mPosition.y + h)
				inside = false;

		// Mysz jest poza przyciskiem
		if (!inside)
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		// Mysz jest na przycisku
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
				if (action != NONE)
					Mix_PlayChannel(-1, gClickSound, 0);
				
				operation(action);
				SDL_WaitEvent(e);

				break;

			case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				
				break;
			}
		}
	}
}

void SButton::setTexture()
{
	if (!gButtonSpriteSheetTexture.loadFromFile(img))
		cout << "Nie mozna zaladowac tekstury przycisku!" << endl;
	else
		// Ustawianie spritow
		for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
		{
			gSpriteClips[i].x = 0;
			gSpriteClips[i].y = i * h;
			gSpriteClips[i].w = w;
			gSpriteClips[i].h = h;
	}
}

void SButton::render()
{
	gButtonSpriteSheetTexture.render(mPosition.x, mPosition.y, &gSpriteClips[mCurrentSprite]);
}

void SButton::operation(Actions action)
{
	switch (action)
	{
	case NEW_GAME:
		if (popUp)
		{
			if (gTexture != NULL)
			{
				SDL_DestroyTexture(gTexture);
				gTexture = NULL;
			}
			gTexture = loadTexture("imgs/load_save.png");
			screen = MAIN;
			subScreen = POPUPMSG;
			popUp = false;
			break;
		}
		timer.stop();
		timer.start();
		if (gTexture != NULL)
		{
			SDL_DestroyTexture(gTexture);
			gTexture = NULL;
		}
		gTexture = loadTexture("imgs/left.png");
		screen = GAME;
		subScreen = GAME;
		break;

	case CONTINUE_GAME:
		if (gTexture != NULL)
		{
			SDL_DestroyTexture(gTexture);
			gTexture = NULL;
		}
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

	case LOAD_SLOT:
	{
		string path = "saves/slot" + to_string(id) + ".txt";
		slot[id] = fopen(path.c_str(), "r");
		int var = 0;
		if (slot[id] != NULL)
		{
			timer.stop();
			fscanf(slot[id], "%d", &var);
			timer.setSeconds(var);
			fscanf(slot[id], "%d", &var);
			timer.setMinutes(var);
			
			// Odczytanie stanu surowcow
			for (int i = 0; i < 21; i++)
			{
				fscanf(slot[id], "%d", &var);
				tResource[i]->setNumber(var);
			}
			// Odczytanie ilosci ludnosci
			for (int i = 0; i < 5; i++)
			{
				fscanf(slot[id], "%d", &var);
				tPeople[i]->setNumber(var);
			}
			// Odczytanie ilosci domow
			for (int i = 0; i < 5; i++)
			{
				fscanf(slot[id], "%d", &var);
				tHouse[i]->setNumber(var);
			}
			// Odczytanie ilosci budynkow publicznych
			for (int i = 0; i < 12; i++)
			{
				fscanf(slot[id], "%d", &var);
				tPublic[i]->setNumber(var);
			}
			// Odczytanie ilosci budynkow rolniczych
			for (int i = 0; i < 16; i++)
			{
				fscanf(slot[id], "%d", &var);
				tProcessing[i]->setNumber(var);
			}
			// Odczytanie ilosci budynkow przetworczych
			for (int i = 0; i < 11; i++)
			{
				fscanf(slot[id], "%d", &var);
				tProcessing[i]->setNumber(var);
			}
			/*
			dane do odczytania
			*/
			timer.start();
		}
		if (gTexture != NULL)
		{
			SDL_DestroyTexture(gTexture);
			gTexture = NULL;
		}
		gTexture = loadTexture("imgs/left.png");
		screen = GAME;
		subScreen = GAME;
		break;
		}

	case SAVE_GAME:
		SDL_DestroyTexture(gTexture);
		gTexture = NULL;
		gTexture = loadTexture("imgs/load_save.png");
		screen = MAIN;
		subScreen = SAVE;
		break;

	case SAVE_SLOT:
	{
		string path = "saves/slot" + to_string(id) + ".txt";
		slot[id] = fopen(path.c_str(), "w");
		if (slot[id] != NULL)
		{
			fprintf(slot[id], "%d\n", timer.getSeconds());
			fprintf(slot[id], "%d\n", timer.getMinutes());
			for (int i = 0; i < 21; i++)
			{
				fprintf(slot[id], "%d\n", tResource[i]->getNumber());
			}
			// Zapisywanie ilosci ludnosci
			for (int i = 0; i < 5; i++)
			{
				fprintf(slot[id], "%d\n", tPeople[i]->getNumber());
			}
			// Zapisywanie ilosci domow
			for (int i = 0; i < 5; i++)
			{
				fprintf(slot[id], "%d\n", tHouse[i]->getNumber());
			}
			// Zapisywanie ilosci budynkow publicznych
			for (int i = 0; i < 12; i++)
			{
				fprintf(slot[id], "%d\n", tPublic[i]->getNumber());
			}
			// Zapisywanie ilosci budynkow rolniczych
			for (int i = 0; i < 16; i++)
			{
				fprintf(slot[id], "%d\n", tProcessing[i]->getNumber());
			}
			// Zapisywanie ilosci budynkow przetworczych
			for (int i = 0; i < 11; i++)
			{
				fprintf(slot[id], "%d\n", tProcessing[i]->getNumber());
			}
		}
		if (gTexture != NULL)
		{
			SDL_DestroyTexture(gTexture);
			gTexture = NULL;
		}
		fclose(slot[id]);
		gTexture = loadTexture("imgs/left.png");
		screen = GAME;
		subScreen = GAME;
		break;
	}

	case MAIN_MENU:
		if (popUp)
			popUp = false;
		if (timer.getTicks() > 0)
			popUp = true;
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

	case EXIT_GAME:
		screen = QUIT;
		break;

	case BUY:
		sell = false;
		buy = true;
		break;

	case BUY_RESOURCE:
		break;

	case SELL:
		buy = false;
		sell = true;
		break;

	case SELL_RESOURCE:
		break;

	case PUBLIC:
		SDL_DestroyTexture(gTexture2);
		gTexture2 = NULL;
		gTexture2 = loadTexture("imgs/public.png");
		screen = GAME;
		subScreen = PUB;
		break;

	case PROCESSING_BUTTON:
		SDL_DestroyTexture(gTexture2);
		gTexture2 = NULL;
		gTexture2 = loadTexture("imgs/production.png");
		screen = GAME;
		subScreen = PROC;
		break;

	case PRODUCTION:
		SDL_DestroyTexture(gTexture2);
		gTexture2 = NULL;
		gTexture2 = loadTexture("imgs/farms.png");
		screen = GAME;
		subScreen = PROD;
		break;

	case VIEW_STATS:
		SDL_DestroyTexture(gTexture2);
		gTexture2 = NULL;
		gTexture2 = loadTexture("imgs/statistics.png");
		screen = GAME;
		subScreen = STATS;
		break;

	case BUILD_PUB:
		Build_Pub(*tPublic[id], tResource);
		break;

	case DESTROY_PUB:
		Destroy_Pub(*tPublic[id]);
		break;

	case BUILD_PROC:
		Build_Pub(*tProcessing[id], tResource);
		break;
		
	case DESTROY_PROC:
		Destroy_Pub(*tProcessing[id]);
		break;

	case BUILD_PROD:
		Build_Pub(*tProduction[id], tResource);
		break;

	case DESTROY_PROD:
		Destroy_Pub(*tProduction[id]);
		break;

	case BUILD_HOUSE:
		Build_House(*tHouse[id], tResource);
		break;

	case DESTROY_HOUSE:
		Destroy_House(*tHouse[id]);
		break;

	case UPGRADE://///////////////////////////////////////////////////////////////////////////////////////////////////////////// WYWALIC
		SDL_DestroyTexture(Warehouse_I_texture);
		Warehouse_I_texture = NULL;
		SDL_DestroyTexture(Warehouse_II_texture);
		Warehouse_II_texture = NULL;
		if (licze_magazyny == 0)
		{
			Warehouse_I_texture = loadTexture("imgs/magazyn2.png");
			Warehouse_II_texture = loadTexture("imgs/magazyn3.png");
		}
		if (licze_magazyny == 1)
		{
			Warehouse_I_texture = loadTexture("imgs/magazyn3.png");
			Warehouse_II_texture = loadTexture("imgs/magazyn4.png");
		}
		if (licze_magazyny == 2)
		{
			Warehouse_I_texture = loadTexture("imgs/magazyn4.png");
			Warehouse_II_texture = loadTexture("imgs/magazyn5.png");
		}
		licze_magazyny++;
		upgrade = false;
		break;

	case CANCEL:
		sell = false;
		buy = false;
		break;

	case ALLOW_BUILD:
		allow_build = false;
		break;

	case DENY_BUILD:
		allow_build = true;
		break;

	case CHANGE_MUSIC:
		if (MUSIC_ON == true)
			MUSIC_ON = false;
		else
			MUSIC_ON = true;
		break;
	}
}