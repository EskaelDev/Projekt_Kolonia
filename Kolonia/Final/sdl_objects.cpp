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

// Czworokaty magazynow
SDL_Rect gWarehouse_rect_right;
SDL_Rect gWarehouse_rect_left;
SDL_Rect gWarehouse_rect_centre;
/*
// Paski stanow zasobow
SDL_Rect fillRect = { 6, 295, 30, 5 };
SDL_Rect fillRect2 = { 71, 295, 30, 5 };
SDL_Rect fillRect3 = { 136, 295, 30, 5 };
SDL_Rect fillRect4 = { 201, 295, 30, 5 };
SDL_Rect fillRect5 = { 266, 295, 30, 5 };

SDL_Rect fillRect6 = { 6, 369, 30, 5 };
SDL_Rect fillRect7 = { 71, 369, 30, 5 };
SDL_Rect fillRect8 = { 136, 369, 30, 5 };
SDL_Rect fillRect9 = { 201, 369, 30, 5 };
SDL_Rect fillRect10 = { 266, 369, 30, 5 };

SDL_Rect fillRect11 = { 6, 437, 30, 5 };
SDL_Rect fillRect12 = { 71, 437, 30, 5 };
SDL_Rect fillRect13 = { 136, 437, 30, 5 };
SDL_Rect fillRect14 = { 201, 437, 30, 5 };
SDL_Rect fillRect15 = { 266, 437, 30, 5 };

SDL_Rect fillRect16 = { 6, 507, 30, 5 };
SDL_Rect fillRect17 = { 71, 507, 30, 5 };
SDL_Rect fillRect18 = { 136, 507, 30, 5 };
SDL_Rect fillRect19 = { 201, 507, 30, 5 };
SDL_Rect fillRect20 = { 266, 507, 30, 5 };
*/
// Viewporty
SDL_Rect LargeViewport;
SDL_Rect LeftViewport;
SDL_Rect RightViewport;

// Czcionka
TTF_Font *gFont = NULL;
TTF_Font *gFont_12 = NULL;

// Kolor tekstu
SDL_Color textC = { 255, 255, 255 };

// Kolor renderowanego tekstu
SDL_Color textColor = { 255, 255, 255, 255 };

// Dzwiek klikania
Mix_Chunk *gClickSound = NULL;
Mix_Music *gBackgroundMusic = NULL;

SDL_Event e;