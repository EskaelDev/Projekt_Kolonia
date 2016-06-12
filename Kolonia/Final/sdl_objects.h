#ifndef SDL_OBJECTS_H
#define SDL_OBJECTS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "sdl_variables.h"
#include "sdl_consts.h"
#include <iostream>
#include "core/Magazine.h"

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

extern Magazine WareHouse;

extern FILE *slot[];

// Timery odswierzajace budynki
extern Uint32 Update_CottonPlantation;
extern Uint32 Update_ForestersLodge;
extern Uint32 Update_GrainFarm;
extern Uint32 Update_SpiceFarm;
extern Uint32 Update_HuntersHut;
extern Uint32 Update_CocoaPlantation;
extern Uint32 Update_CattleFarm;
extern Uint32 Update_SheepFarm;
extern Uint32 Update_Winery;
extern Uint32 Update_TobaccoPlantation;
extern Uint32 Update_SugarcanePlantationion;
extern Uint32 Update_IronMine;
extern Uint32 Update_DeepIronMine;
extern Uint32 Update_GoldMine;
extern Uint32 Update_FistersHut;
extern Uint32 Update_StoneMason;
extern Uint32 Update_Bakery;
extern Uint32 Update_OreRefenery;
extern Uint32 Update_GoldSmith;
extern Uint32 Update_ButcherShop;
extern Uint32 Update_RumDistillery;
extern Uint32 Update_Clothiers;
extern Uint32 Update_TobaccoProduction;
extern Uint32 Update_WeavingMill;
extern Uint32 Update_WeavingHut;
extern Uint32 Update_ToolSmithy;
extern Uint32 Update_WindMill;
#endif