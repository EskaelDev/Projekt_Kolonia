#ifndef SDL_CONSTS_H
#define SDL_CONSTS_H

// Rozmiar ekranu
const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;

// Rozmiary przyciskow (nowa gra,wczytaj gre, zapisz gre, wyjdz z gry, wroc, graj)
const int MAIN_BUTTON_WIDTH = 118;
const int MAIN_BUTTON_HEIGHT = 35;

// Rozmiary przyciskow splashy
const int BUILDINGS_BUTTON_WIDTH = 911;
const int BUILDINGS_BUTTON_HEIGHT = 256;

// Rozmiary przyciskow (zbuduj, zburz)
const int BUILD_BUTTON_WIDTH = 60;
const int BUILD_BUTTON_HEIGHT = 20;

// Rozmiary przyciskow (kup, sprzedaj)
const int BUY_BUTTON_WIDTH = 90;
const int BUY_BUTTON_HEIGHT = 70;

// Rozmiary przyciskow (zasoby)
const int RESOURCES_BUTTON_HEIGHT = 52;
const int RESOURCES_BUTTON_WIDTH = 56;

// Rozmiary przycisku Ulepsz
const int UPGRADE_BUTTON_HEIGHT = 63;
const int UPGRADE_BUTTON_WIDTH = 87;

// Rozmiary przyciskow zakaz budowy
const int ALLOW_BUILD_BUTTON_HEIGHT = 37;
const int ALLOW_BUILD_BUTTON_WIDTH = 105;

// Wspolrzedne przyciskow zakaz budowy
const int A_B_X = 584;
const int A_B_Y = 308;

// Wspolrzedne przyiskow build, destroy
const int C_1 = 17;
const int C_2 = 204;
const int C_3 = 402;
const int C_4 = 596;
const int C_5 = 770;
const int W_1 = 252;
const int W_2 = 488;
const int W_3 = 723;
const int R_R = 66;;

// Wspolrzedne ulepszenia
const int U_X = 171, U_Y = 595;

// Rozmiary rectow magazynow
const int gWarehouse_rect_left_x = 9;
const int gWarehouse_rect_left_y = 558;
const int gWarehouse_rect_left_h = 162;
const int gWarehouse_rect_left_w = 197;

const int gWarehouse_rect_right_x = 223;
const int gWarehouse_rect_right_y = 558;
const int gWarehouse_rect_right_h = 162;
const int gWarehouse_rect_right_w = 197;

const int gWarehouse_rect_centre_x = 115;
const int gWarehouse_rect_centre_y = 558;
const int gWarehouse_rect_centre_h = 162;
const int gWarehouse_rect_centre_w = 197;

// Pozycja tekstu w panelu statystyk
const int kolumna_stat_1 = 75 - 14;
const int kolumna_stat_2 = 236 - 14;
const int kolumna_stat_3 = kolumna_stat_2 + 166;
const int kolumna_stat_4 = kolumna_stat_3 + 166;
const int kolumna_stat_5 = kolumna_stat_4 + 166;

const int wiersz_stat_1 = 427;
const int wiersz_stat_2 = 500;
const int wiersz_stat_3 = 570;
const int wiersz_stat_4 = 640;

const int C_M_B = 242, C_M_D = 276, W_M = 701;

#endif