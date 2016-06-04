#ifndef SDL_OBJECTS_H
#define SDL_OBJECTS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>

// Okno bedzie renderowane do
extern SDL_Window* gWindow;

// Renderer okna
extern SDL_Renderer* gRenderer;
extern SDL_Renderer* gRenderer2;

// Wyswietlane tekstury
extern SDL_Texture* gTexture;
extern SDL_Texture* gTexture2;

// Tekstury magazyow
extern SDL_Texture* Warehouse_I_texture;
extern SDL_Texture* Warehouse_II_texture;
extern SDL_Texture* Warehouse_III_texture;
extern SDL_Texture* Warehouse_IV_texture;

// Czworokaty magazynow
extern SDL_Rect gWarehouse_rect_right;
extern SDL_Rect gWarehouse_rect_left;
extern SDL_Rect gWarehouse_rect_centre;

// Czcionka
extern TTF_Font *gFont;

// Kolor renderowanego tekstu
extern SDL_Color textColor;

// Dzwiek klikania
extern Mix_Chunk *gClickSound;
extern Mix_Music *gBackgroundMusic;

#endif