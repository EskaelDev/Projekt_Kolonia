#ifndef SDL_FUNCTIONS_H
#define SDL_FUNCTIONS_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include "sdl_objects.h"
#include "STexture.h"
#include "core/Public.h"
#include "core/House.h"


using namespace std;

// Wlaczenie SDL i stworzenie okna
bool init();

// Ladowanie mediow
bool loadMedia();

// Zwalnianie mediow i zamykanie SDL
void close();

// Ladowanie obrazka jako tekstury
SDL_Texture* loadTexture(std::string path);

// Tekstura tekstu
extern STexture gTextTexture;

// Buowanie budynk�w Publiczych
bool Build_Pub(Public & Name,Resource *TResource[21]);
// Burzenie budynkow Publicznych
bool Destroy_Pub(Public & Name);

// Buowanie budynk�w Procesing
bool Build_Proc(Processing & Name,Resource *TResource[21]);
// Burzenie budynkow Procesing
bool Destroy_Proc(Processing & Name);

// Buowanie budynk�w Production
bool Build_Prod(Production & Name,Resource *TResource[21]);
// Burzenie budynkow Production
bool Destroy_ProD(Production & Name);

// Buowanie dom�w
bool Build_House(House & Name, Resource *TResource[21]);
// Burzenie dom�w
bool Destroy_House(House & Name);


void Fill_Arrays();

// Update budynkow
Uint32 Update_Prod(Uint32 interval, void *param);
Uint32 Update_Proc(Uint32 interval, void *param);

// Update reszty
Uint32 Update_Tax(Uint32 interval, void *param);
Uint32 Update_Req(Uint32 interval, void *param);

// Levelowanie si� ludzi
Uint32 Update_PeopleLVL(Uint32 interval, void *param);

// Update pobierania z magazynu przez ludzi
Uint32 Update_ResourcesOutgo(Uint32 interval, void *param);


#endif