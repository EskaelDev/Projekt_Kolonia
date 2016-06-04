#ifndef SDL_FUNCTIONS_H
#define SDL_FUNCTIONS_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include "sdl_objects.h"

// Ladowanie obrazka jako tekstury
SDL_Texture* loadTexture(std::string path);

#endif