#include "sdl_variables.h"

bool upgrade = true;
int licze_magazyny = 0;
bool MUSIC_ON = true;
int chatka_drwala = 0;
	
bool buy = false;
bool sell = false;

bool popUp = false;
bool startScreen = false;
bool endScreen = true;

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

// Tablica ludzi
People* tPeople[5];


int maxBuildingNumber = 0;					// okresla jakiego typu budynek posiada gracz w najwiekszej liczbie
int totalMagazinesCapacity = 0;				// calkowita pojemnosc magazynow budynkow
int usedMagazine = 0;						// wykorzystane miejsce w magazynie ogolnym
int totalResources = 0;						// suma wszystkich posiadanych surowcow

int taxes = 0;			// Podatki
int costs = 0;			// Koszta
int buy_income = 0;		// dochód ze sprzedarzy
int sale_costs = 0;		// koszta kupna
int balance = 0;		// bilans