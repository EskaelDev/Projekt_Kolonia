#ifndef SDL_OBJECTS_H
#define SDL_OBJECTS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "sdl_variables.h"
#include "sdl_consts.h"
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

// Paski stanow zasobow
/*
extern SDL_Rect fillRect;
extern SDL_Rect fillRect2;
extern SDL_Rect fillRect3;
extern SDL_Rect fillRect4;
extern SDL_Rect fillRect5;

extern SDL_Rect fillRect6;
extern SDL_Rect fillRect7;
extern SDL_Rect fillRect8;
extern SDL_Rect fillRect9;
extern SDL_Rect fillRect10;

extern SDL_Rect fillRect11;
extern SDL_Rect fillRect12;
extern SDL_Rect fillRect13;
extern SDL_Rect fillRect14;
extern SDL_Rect fillRect15;

extern SDL_Rect fillRect16;
extern SDL_Rect fillRect17;
extern SDL_Rect fillRect18;
extern SDL_Rect fillRect19;
extern SDL_Rect fillRect20;
*/
// Viewporty
extern SDL_Rect LargeViewport;
extern SDL_Rect LeftViewport;
extern SDL_Rect RightViewport;

// Czcionka
extern TTF_Font *gFont;
extern TTF_Font *gFont_12;

// Kolor tekstu
extern SDL_Color textC;

// Kolor renderowanego tekstu
extern SDL_Color textColor;

// Dzwiek klikania
extern Mix_Chunk *gClickSound;
extern Mix_Music *gBackgroundMusic;

extern SDL_Event e;

#endif