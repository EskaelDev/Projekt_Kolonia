//#include "Globalne.h"
//#include "Glob_Funk.h"
//#include "T_LTexture.h"
#include "T_LButton.h"


int main(int argc, char* args[])
{

	// Tekstura tekstu
	T_LTexture gTextTexture;
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
