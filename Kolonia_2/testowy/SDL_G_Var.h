#pragma once
// Char buffor Ludzie i Pieniadze
char People_char_buffor[4];				int People_int = 1;
char Money_char_buffor[7];				int Money_int = 50000;

// Wspolrzedne Build, Destroy Magazynow
const int C_M_B = 242, C_M_D = 276, W_M = 701;

// Zmienne do wyswietlania czasu
int h = 0, m = 0, s = 0;

// Przyciski - Kupowanie sprzedarz
bool buy = false;
bool sell = false;

// Mozna budowac
bool allow_build = true;

// Kolor renderowanego tekstu
SDL_Color textColor = { 255, 255, 255, 255 };

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;
SDL_Renderer* gRenderer2 = NULL;


// Wyswietlane tekstury
SDL_Texture* gTexture = NULL;
SDL_Texture* gTexture2 = NULL;

// Tekstury magazyow
//SDL_Texture* gWarehouse_left = NULL;
//SDL_Texture* gWarehouse_right = NULL;
SDL_Texture* Warehouse_I_texture = NULL;
SDL_Texture* Warehouse_II_texture = NULL;
SDL_Texture* Warehouse_III_texture = NULL;
SDL_Texture* Warehouse_IV_texture = NULL;


// Czworokaty magazynow
SDL_Rect gWarehouse_rect_right;
SDL_Rect gWarehouse_rect_left;
SDL_Rect gWarehouse_rect_centre;

// Czcionka
TTF_Font *gFont = NULL;

// Dzwiek klikania
Mix_Chunk *gClickSound = NULL;
Mix_Music *gBackgroundMusic = NULL;

// Muzyka wloczona / wylaczona
bool MUSIC_ON = true;