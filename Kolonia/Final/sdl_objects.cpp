#include "sdl_objects.h"

// Okno bedzie renderowane do
SDL_Window* gWindow = NULL;

// Renderer okna
SDL_Renderer* gRenderer = NULL;
SDL_Renderer* gRenderer2 = NULL;

// Wyswietlane tekstury
SDL_Texture* gTexture = NULL;
SDL_Texture* gTexture2 = NULL;

// Tekstury magazyow
SDL_Texture* Warehouse_I_texture = NULL;
SDL_Texture* Warehouse_II_texture = NULL;
SDL_Texture* Warehouse_III_texture = NULL;
SDL_Texture* Warehouse_IV_texture = NULL;

SDL_Texture* popUpMsg_texture = NULL;

// Czworokaty magazynow
SDL_Rect gWarehouse_rect_right;
SDL_Rect gWarehouse_rect_left;
SDL_Rect gWarehouse_rect_centre;

SDL_Rect popUpMsg;

// Czcionka
TTF_Font *gFont = NULL;

// Kolor renderowanego tekstu
SDL_Color textColor = { 255, 255, 255, 255 };

// Dzwiek klikania
Mix_Chunk *gClickSound = NULL;
Mix_Music *gBackgroundMusic = NULL;