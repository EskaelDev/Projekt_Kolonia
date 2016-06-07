#include "sdl_variables.h"

bool upgrade = true;
int licze_magazyny = 0;
bool MUSIC_ON = true;
int chatka_drwala = 0;
	
bool buy = false;
bool sell = false;

bool popUp = false;

// Mozna budowac
bool allow_build = true;

// Char buffor Ludzie i Pieniadze
char People_char_buffor[4];				int People_int = 1;
char Money_char_buffor[7];				int Money_int = 50000;

// Pola wyspy
int usedFields=0;
int islandSize=1700;

// Tablice budynków
Public* tPublic[12];
Production* tProduction[16];
Processing* tProcessing[11];

// Tablica surowców
Resource* tResource[21];

// Tablica domów
House* tHouse[5];