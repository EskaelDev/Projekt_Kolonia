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

// Buowanie budynków Publiczych
bool Build_Pub(Public & Name, Resource & Money, Resource & Bricks, Resource & Tools, Resource & Wood);
// Burzenie budynkow Publicznych
bool Destroy_Pub(Public & Name);

// Buowanie budynków Procesing
bool Build_Proc(Processing & Name, Resource & Money, Resource & Bricks, Resource & Tools, Resource & Wood);
// Burzenie budynkow Procesing
bool Destroy_Proc(Processing & Name);

// Buowanie budynków Production
bool Build_Prod(Production & Name, Resource & Money, Resource & Bricks, Resource & Tools, Resource & Wood);
// Burzenie budynkow Production
bool Destroy_ProD(Production & Name);

// Buowanie domów
bool Build_House(House & Name, Resource & Bricks, Resource & Tools, Resource & Wood);
// Burzenie domów
bool Destroy_House(House & Name);


void Fill_Arrays();

Uint32 Update_All(Uint32 interval, void *param);

#endif