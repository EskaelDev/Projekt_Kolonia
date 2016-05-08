#include "T_LButton.h"
//#include "Globalne.h"

T_LTexture gButtonSpriteSheetTexture;	// Sprity przyciskow mysz

T_LButton::T_LButton(Actions action, int width, int height, int pos_x, int pos_y, char *image)
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

T_LButton::T_LButton(int id, Actions action, int w, int h, int pos_x, int pos_y, char *image)
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

T_LButton::~T_LButton()
{
	this->action = NONE;
	this->w = NULL;
	this->h = NULL;
	img = NULL;

	setPosition(0, 0);
	mCurrentSprite = UNKNOWN;
}
// button(action, width, height, pos_x, pos_y, filename)

T_LButton new_game_button(NEW_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 400, "new.png");
T_LButton load_game_button(LOAD_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 480, "load.png");
T_LButton save_game_button(SAVE_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 560, "save.png");
T_LButton exit_game_button(EXIT_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 660, "exit.png");
T_LButton main_menu_button(MAIN_MENU, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 660, "back.png");
T_LButton pub_button(PUBLIC, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 455, 0, "/buildings/pub.png");
T_LButton ind_button(INDUSTRIAL, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 455, 256, "/buildings/ind.png");
T_LButton prod_button(PRODUCTION, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 455, 512, "/buildings/prod.png");
T_LButton buy_button(BUY, BUY_BUTTON_WIDTH, BUY_BUTTON_HEIGHT, 624, 660, "back.png");
T_LButton sell_button(SELL, BUY_BUTTON_WIDTH, BUY_BUTTON_HEIGHT, 624, 660, "back.png");

void T_LButton::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}

void T_LButton::handleEvent(SDL_Event* e)
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

void T_LButton::render()
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

void T_LButton::del()
{
	setPosition(-999, -999);
}

void T_LButton::operation(Actions action)
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
