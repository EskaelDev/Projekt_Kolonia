#ifndef SDL_FUNCTIONS_H
#define SDL_FUNCTIONS_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include "sdl_objects.h"
#include "STexture.h"

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
#endif