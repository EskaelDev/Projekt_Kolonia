#pragma once
//#include "Glob_Funk.h"
#include "Globalne.h"

// Wlaczenie SDL i stworzenie okna
bool init();

// Ladowanie mediow
bool loadMedia();

// Zwalnianie mediow i zamykanie SDL
void close();

// Ladowanie obrazka jako tekstury
SDL_Texture* loadTexture(std::string path);
