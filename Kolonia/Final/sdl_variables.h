#ifndef SDL_VARIABLES_H
#define SDL_VARIABLES_H
#include "core/Public.h"
#include "core/Production.h"
#include "core/Processing.h"

extern bool upgrade; 
extern int licze_magazyny; 
extern bool MUSIC_ON; 
extern int chatka_drwala;

extern bool buy;
extern bool sell;

// Czy ma pojawic sie komunikat
extern bool popUp;

// Mozna budowac
extern bool allow_build;

// Char buffor Ludzie i Pieniadze
extern char People_char_buffor[4];				extern int People_int;
extern char Money_char_buffor[7];				extern int Money_int;

// Rozmiary wysp
extern int usedFields;
extern int islandSize;

// Tablice budynków
extern Public* tPublic[12];
extern Production* tProduction[16];
extern Processing* tProcessing[11];

extern Resource* tResource[21];


#endif