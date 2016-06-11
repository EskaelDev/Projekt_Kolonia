#include "SButton.h"
#include "STexture.h"
#include "STimer.h"
#include "sdl_functions.h"
#include "sdl_objects.h"
#include "sdl_variables.h"
#include "sdl_consts.h"
#include "sdl_enums.h"
#include "core/House.h"
#include "core/Industrial.h"
#include "core/Magazine.h"
#include "core/Public.h"
#include "core/Production.h"
#include "core/Processing.h"
#include "core/Resource.h"
#include "core/People.h"
#include <conio.h>

using namespace std;
int thisTime = 0;
int lastTime = 0;
float deltaTime = 0.0;
Uint32 sdl_timer;
////


int main(int argc, char* args[])
{
	Fill_Arrays();
	tResource[0]->increase(5000);
	tResource[18]->increase(50);
	tResource[19]->increase(70);
	tResource[20]->increase(13);

	// Wlaczenie SDL i stworzenie okna
	if (!init())
		cout << "Blad inicjalizacji!" << endl;
	else
	{
		// Ladowanie mediow
		if (!loadMedia())
			cout << "Nie mozna zaladowac mediow!" << endl;
		else
		{
			// Flaga glownej petli
			bool quit = false;

			LargeViewport.x = 0;
			LargeViewport.y = 0;
			LargeViewport.w = SCREEN_WIDTH;
			LargeViewport.h = SCREEN_HEIGHT;

			LeftViewport.x = 0;
			LeftViewport.y = 0;
			LeftViewport.w = SCREEN_WIDTH / 3;
			LeftViewport.h = SCREEN_HEIGHT;

			RightViewport.x = SCREEN_WIDTH / 3;
			RightViewport.y = 0;
			RightViewport.w = 2 * SCREEN_WIDTH / 3;
			RightViewport.h = SCREEN_HEIGHT;

			gFont = TTF_OpenFont("fonts/times.ttf", 19);
			gFont_12 = TTF_OpenFont("fonts/times.ttf", 12);


			// Przyciski menu
			// przycisk(akcja, szerokosc, wysokosc, poz_x, poz_y, nazwa_pliku)	
			SButton new_game_button(NEW_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 400, "new.png");
			SButton continue_button(CONTINUE_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 350, "continue.png");
			SButton load_game_button(LOAD_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 480, "load.png");
			SButton exit_game_button(EXIT_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 660, "exit.png");
			SButton main_menu_button(MAIN_MENU, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 660, "menu.png");
			SButton save_game_button(SAVE_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 150, 732, "save.png");
			SButton back_button(CONTINUE_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 300, 732, "back.png");
			SButton stats_button(VIEW_STATS, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 5, 732, "stats.png");

			// Przyciski wczytyania ze slotu
			SButton* load_slot_button[4];
			load_slot_button[0] = new SButton(1, LOAD_SLOT, SLOT_BUTTON_WIDTH, SLOT_BUTTON_HEIGHT, (SCREEN_WIDTH - SLOT_BUTTON_WIDTH) / 2, 380, "slot1.png");
			load_slot_button[1] = new SButton(2, LOAD_SLOT, SLOT_BUTTON_WIDTH, SLOT_BUTTON_HEIGHT, (SCREEN_WIDTH - SLOT_BUTTON_WIDTH) / 2, 430, "slot2.png");
			load_slot_button[2] = new SButton(3, LOAD_SLOT, SLOT_BUTTON_WIDTH, SLOT_BUTTON_HEIGHT, (SCREEN_WIDTH - SLOT_BUTTON_WIDTH) / 2, 480, "slot3.png");
			load_slot_button[3] = new SButton(4, LOAD_SLOT, SLOT_BUTTON_WIDTH, SLOT_BUTTON_HEIGHT, (SCREEN_WIDTH - SLOT_BUTTON_WIDTH) / 2, 530, "slot4.png");

			// Przyciski zapisu na slot
			SButton* save_slot_button[4];
			save_slot_button[0] = new SButton(1, SAVE_SLOT, SLOT_BUTTON_WIDTH, SLOT_BUTTON_HEIGHT, (SCREEN_WIDTH - SLOT_BUTTON_WIDTH) / 2, 380, "slot1.png");
			save_slot_button[1] = new SButton(2, SAVE_SLOT, SLOT_BUTTON_WIDTH, SLOT_BUTTON_HEIGHT, (SCREEN_WIDTH - SLOT_BUTTON_WIDTH) / 2, 430, "slot2.png");
			save_slot_button[2] = new SButton(3, SAVE_SLOT, SLOT_BUTTON_WIDTH, SLOT_BUTTON_HEIGHT, (SCREEN_WIDTH - SLOT_BUTTON_WIDTH) / 2, 480, "slot3.png");
			save_slot_button[3] = new SButton(4, SAVE_SLOT, SLOT_BUTTON_WIDTH, SLOT_BUTTON_HEIGHT, (SCREEN_WIDTH - SLOT_BUTTON_WIDTH) / 2, 530, "slot4.png");

			// Przyciski splashy
			SButton ind_button(PROCESSING_BUTTON, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 0, 0, "/buildings/ind.png");
			SButton prod_button(PRODUCTION, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 0, 256, "/buildings/prod.png");
			SButton pub_button(PUBLIC, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 0, 512, "/buildings/pub.png");

			// Przyciski: kup, sprzedaj
			SButton buy_button(BUY, BUY_BUTTON_WIDTH, BUY_BUTTON_HEIGHT, 335, 250, "buy.png");
			SButton sell_button(SELL, BUY_BUTTON_WIDTH, BUY_BUTTON_HEIGHT, 335, 345, "sell.png");
			SButton cancel_NAV_button(NONE, BUY_BUTTON_WIDTH, BUY_BUTTON_HEIGHT, 335, 440, "cancel_nav.png");
			SButton cancel_AV_button(CANCEL, BUY_BUTTON_WIDTH, BUY_BUTTON_HEIGHT, 335, 440, "cancel_av.png");

			// Przyciski kupowania zasobow
			// przycisk(id, akcja, szerokosc, wysokosc, poz_x, poz_y, nazwa_pliku)
			SButton buy_iron_ore_button(1, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 244, "/resources/iron_ore.png");
			SButton buy_gold_button(2, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 244, "/resources/gold.png");
			SButton buy_cottom_button(3, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 244, "/resources/cottom.png");
			SButton buy_sugarcane_button(4, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 244, "/resources/sugarcane.png");
			SButton buy_food_button(10, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 244, "/resources/food.png");

			SButton buy_tobacco_button(5, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 318, "/resources/tobacco.png");
			SButton buy_cattle_button(6, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 318, "/resources/cattle.png");
			SButton buy_grain_button(7, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 318, "/resources/grain.png");
			SButton buy_flour_button(8, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 318, "/resources/flour.png");
			SButton buy_alcohol_button(14, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 318, "/resources/alcohol.png");

			SButton buy_spices_button(12, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 387, "/resources/spices.png");
			SButton buy_textiles_button(15, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 387, "/resources/textiles.png");
			SButton buy_clothes_button(16, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 387, "/resources/clothes.png");
			SButton buy_cigarettes_button(11, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 387, "/resources/cigarettes.png");
			SButton buy_jewelry_button(17, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 387, "/resources/jewelry.png");

			SButton buy_tools_button(18, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 456, "/resources/tools.png");
			SButton buy_wood_button(19, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 456, "/resources/wood.png");
			SButton buy_bricks_button(20, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 456, "/resources/bricks.png");
			SButton buy_iron_button(9, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 456, "/resources/iron.png");
			SButton buy_cocoa_button(13, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 456, "/resources/cocoa.png");

			// Przyciski sprzedazy zasobow
			// Przycisk(id, akcja, szerokosc, wysokosc, poz_x, poz_y, nazwa_pliku)
			SButton sell_iron_ore_button(1, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 244, "/resources/iron_ore.png");
			SButton sell_gold_button(2, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 244, "/resources/gold.png");
			SButton sell_cottom_button(3, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 244, "/resources/cottom.png");
			SButton sell_sugarcane_button(4, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 244, "/resources/sugarcane.png");
			SButton sell_food_button(10, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 244, "/resources/food.png");

			SButton sell_tobacco_button(5, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 318, "/resources/tobacco.png");
			SButton sell_cattle_button(6, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 318, "/resources/cattle.png");
			SButton sell_grain_button(7, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 318, "/resources/grain.png");
			SButton sell_flour_button(8, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 318, "/resources/flour.png");
			SButton sell_alcohol_button(14, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 318, "/resources/alcohol.png");

			SButton sell_spices_button(12, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 387, "/resources/spices.png");
			SButton sell_textiles_button(15, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 387, "/resources/textiles.png");
			SButton sell_clothes_button(16, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 387, "/resources/clothes.png");
			SButton sell_cigarettes_button(11, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 387, "/resources/cigarettes.png");
			SButton sell_jewelry_button(17, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 387, "/resources/jewelry.png");

			SButton sell_tools_button(18, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 456, "/resources/tools.png");
			SButton sell_wood_button(19, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 456, "/resources/wood.png");
			SButton sell_bricks_button(20, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 456, "/resources/bricks.png");
			SButton sell_iron_button(9, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 456, "/resources/iron.png");
			SButton sell_cocoa_button(13, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 456, "/resources/cocoa.png");

			// Przyciski Buduj i Zburz
			// Przycisk(id, akcja, szerokosc, wysokosc, poz_x, poz_y, nazwa_pliku)

			// Tablica Production
			// build_AV		Production
			SButton* Production_build_AV[16];
			Production_build_AV[0] = new SButton(0, BUILD_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_3, "build_av.png");			// CottonPlantation
			Production_build_AV[1] = new SButton(1, BUILD_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_av.png");			// ForestersLodge
			Production_build_AV[2] = new SButton(2, BUILD_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_av.png");			// GrainFarm
			Production_build_AV[3] = new SButton(3, BUILD_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_av.png");			// SpiceFarm
			Production_build_AV[4] = new SButton(4, BUILD_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_av.png");			// HuntersHut
			Production_build_AV[5] = new SButton(5, BUILD_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_3, "build_av.png");			// CocoaPlantation
			Production_build_AV[6] = new SButton(6, BUILD_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_av.png");			// CattleFarm
			Production_build_AV[7] = new SButton(7, BUILD_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_av.png");			// SheepFarm
			Production_build_AV[8] = new SButton(8, BUILD_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_av.png");			// Winery
			Production_build_AV[9] = new SButton(9, BUILD_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_av.png");			// TobaccoPlantation
			Production_build_AV[10] = new SButton(10, BUILD_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_av.png");		// SugarcanePlantation
			Production_build_AV[11] = new SButton(11, BUILD_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_3, "build_av.png");		// IronMine
			Production_build_AV[12] = new SButton(12, BUILD_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_3, "build_av.png");		// DeepIronMine
			Production_build_AV[13] = new SButton(13, BUILD_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_3, "build_av.png");		// GoldMine
			Production_build_AV[14] = new SButton(14, BUILD_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_av.png");		// FishersHut
		
			// build_NAV	Production
			SButton* Production_build_NAV[16];
			Production_build_NAV[0] = new SButton(0, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_3, "build_nav.png");		// CottonPlantation
			Production_build_NAV[1] = new SButton(1, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_nav.png");		// ForestersLodge
			Production_build_NAV[2] = new SButton(2, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_nav.png");		// GrainFarm
			Production_build_NAV[3] = new SButton(3, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_nav.png");		// SpiceFarm
			Production_build_NAV[4] = new SButton(4, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_nav.png");		// HuntersHut
			Production_build_NAV[5] = new SButton(5, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_3, "build_nav.png");		// CocoaPlantation
			Production_build_NAV[6] = new SButton(6, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_nav.png");		// CattleFarm
			Production_build_NAV[7] = new SButton(7, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_nav.png");		// SheepFarm
			Production_build_NAV[8] = new SButton(8, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_nav.png");		// Winery
			Production_build_NAV[9] = new SButton(9, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_nav.png");		// TobaccoPlantation
			Production_build_NAV[10] = new SButton(10, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_nav.png");		// SugarcanePlantation
			Production_build_NAV[11] = new SButton(11, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_3, "build_nav.png");		// IronMine
			Production_build_NAV[12] = new SButton(12, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_3, "build_nav.png");		// DeepIronMine
			Production_build_NAV[13] = new SButton(13, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_3, "build_nav.png");		// GoldMine
			Production_build_NAV[14] = new SButton(14, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_nav.png");		// FishersHut

			// destroy_AV	Production
			SButton* Production_destroy_AV[16];
			Production_destroy_AV[0] = new SButton(0, DESTROY_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_3, "destroy_av.png");		// CottonPlantation
			Production_destroy_AV[1] = new SButton(1, DESTROY_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_av.png");		// ForestersLodge
			Production_destroy_AV[2] = new SButton(2, DESTROY_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_av.png");		// GrainFarm
			Production_destroy_AV[3] = new SButton(3, DESTROY_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_av.png");		// SpiceFarm
			Production_destroy_AV[4] = new SButton(4, DESTROY_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_av.png");		// HuntersHut
			Production_destroy_AV[5] = new SButton(5, DESTROY_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_3, "destroy_av.png");		// CocoaPlantation
			Production_destroy_AV[6] = new SButton(6, DESTROY_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_av.png");		// CattleFarm
			Production_destroy_AV[7] = new SButton(7, DESTROY_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_av.png");		// SheepFarm
			Production_destroy_AV[8] = new SButton(8, DESTROY_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_av.png");		// Winery
			Production_destroy_AV[9] = new SButton(9, DESTROY_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_av.png");		// TobaccoPlantation
			Production_destroy_AV[10] = new SButton(10, DESTROY_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_av.png");	// SugarcanePlantation
			Production_destroy_AV[11] = new SButton(11, DESTROY_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_3, "destroy_av.png");	// IronMine
			Production_destroy_AV[12] = new SButton(12, DESTROY_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_3, "destroy_av.png");	// DeepIronMine
			Production_destroy_AV[13] = new SButton(13, DESTROY_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_3, "destroy_av.png");	// GoldMine
			Production_destroy_AV[14] = new SButton(14, DESTROY_PROD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_av.png");	// FishersHut

			// destroy_NAV	Production
			SButton* Production_destroy_NAV[16];
			Production_destroy_NAV[0] = new SButton(0, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_3, "destroy_nav.png");		// CottonPlantation
			Production_destroy_NAV[1] = new SButton(1, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_nav.png");		// ForestersLodge
			Production_destroy_NAV[2] = new SButton(2, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_nav.png");		// GrainFarm
			Production_destroy_NAV[3] = new SButton(3, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_nav.png");		// SpiceFarm
			Production_destroy_NAV[4] = new SButton(4, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_nav.png");		// HuntersHut
			Production_destroy_NAV[5] = new SButton(5, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_3, "destroy_nav.png");		// CocoaPlantation
			Production_destroy_NAV[6] = new SButton(6, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_nav.png");		// CattleFarm
			Production_destroy_NAV[7] = new SButton(7, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_nav.png");		// SheepFarm
			Production_destroy_NAV[8] = new SButton(8, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_nav.png");		// Winery
			Production_destroy_NAV[9] = new SButton(9, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_nav.png");		// TobaccoPlantation
			Production_destroy_NAV[10] = new SButton(10, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_nav.png");		// SugarcanePlantation
			Production_destroy_NAV[11] = new SButton(11, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_3, "destroy_nav.png");		// IronMine
			Production_destroy_NAV[12] = new SButton(12, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_3, "destroy_nav.png");		// DeepIronMine
			Production_destroy_NAV[13] = new SButton(13, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_3, "destroy_nav.png");		// GoldMine
			Production_destroy_NAV[14] = new SButton(14, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_nav.png");		// FishersHut

			// Tablica Processing
			// build_AV		Processing
			SButton* Processing_build_AV[12];
			Processing_build_AV[0] = new SButton(0, BUILD_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_av.png");			// Bakery
			Processing_build_AV[1] = new SButton(1, BUILD_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_av.png");			// OreRafinery
			Processing_build_AV[2] = new SButton(2, BUILD_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_3, "build_av.png");			// GoldSmith
			Processing_build_AV[3] = new SButton(3, BUILD_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_av.png");			// ButchersShop
			Processing_build_AV[4] = new SButton(4, BUILD_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_av.png");			// RumDistillery
			Processing_build_AV[5] = new SButton(5, BUILD_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_3, "build_av.png");			// Clothiers
			Processing_build_AV[6] = new SButton(6, BUILD_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_av.png");			// TobaccoProduction
			Processing_build_AV[7] = new SButton(7, BUILD_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_av.png");			// WeavingMill
			Processing_build_AV[8] = new SButton(8, BUILD_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_av.png");			// WeavingHut
			Processing_build_AV[9] = new SButton(9, BUILD_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_av.png");			// ToolSmith
			Processing_build_AV[10] = new SButton(10, BUILD_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_av.png");		// WindMill
			Processing_build_AV[11] = new SButton(15, BUILD_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_av.png");		// StoneMason

			// build_NAV	Processing
			SButton* Processing_build_NAV[12];
			Processing_build_NAV[0] = new SButton(0, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_nav.png");			// Bakery
			Processing_build_NAV[1] = new SButton(1, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_nav.png");			// OreRafinery
			Processing_build_NAV[2] = new SButton(2, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_3, "build_nav.png");			// GoldSmith
			Processing_build_NAV[3] = new SButton(3, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_nav.png");			// ButchersShop
			Processing_build_NAV[4] = new SButton(4, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_nav.png");			// RumDistillery
			Processing_build_NAV[5] = new SButton(5, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_3, "build_nav.png");			// Clothiers
			Processing_build_NAV[6] = new SButton(6, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_nav.png");			// TobaccoProduction
			Processing_build_NAV[7] = new SButton(7, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_nav.png");			// WeavingMill
			Processing_build_NAV[8] = new SButton(8, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_nav.png");			// WeavingHut
			Processing_build_NAV[9] = new SButton(9, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_nav.png");			// ToolSmith
			Processing_build_NAV[10] = new SButton(10, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_nav.png");		// WindMill
			Processing_build_NAV[11] = new SButton(15, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_nav.png");		// StoneMason

			// destroy_AV	Processing	
			SButton* Processing_destroy_AV[12];
			Processing_destroy_AV[0] = new SButton(0, DESTROY_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_av.png");			// Bakery
			Processing_destroy_AV[1] = new SButton(1, DESTROY_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_av.png");			// OreRafinery
			Processing_destroy_AV[2] = new SButton(2, DESTROY_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_3, "destroy_av.png");			// GoldSmith
			Processing_destroy_AV[3] = new SButton(3, DESTROY_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_av.png");			// ButchersShop
			Processing_destroy_AV[4] = new SButton(4, DESTROY_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_av.png");			// RumDistillery
			Processing_destroy_AV[5] = new SButton(5, DESTROY_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_3, "destroy_av.png");			// Clothiers
			Processing_destroy_AV[6] = new SButton(6, DESTROY_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_av.png");			// TobaccoProduction
			Processing_destroy_AV[7] = new SButton(7, DESTROY_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_av.png");			// WeavingMill
			Processing_destroy_AV[8] = new SButton(8, DESTROY_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_av.png");			// WeavingHut
			Processing_destroy_AV[9] = new SButton(9, DESTROY_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_av.png");			// ToolSmith
			Processing_destroy_AV[10] = new SButton(10, DESTROY_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_av.png");		// WindMill
			Processing_destroy_AV[11] = new SButton(15, DESTROY_PROC, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_av.png");		// StoneMason

			// destroy_NAV	Processing
			SButton* Processing_destroy_NAV[12];
			Processing_destroy_NAV[0] = new SButton(0, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_nav.png");			// Bakery
			Processing_destroy_NAV[1] = new SButton(1, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_nav.png");			// OreRafinery
			Processing_destroy_NAV[2] = new SButton(2, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_3, "destroy_nav.png");			// GoldSmith
			Processing_destroy_NAV[3] = new SButton(3, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_nav.png");			// ButchersShop
			Processing_destroy_NAV[4] = new SButton(4, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_nav.png");			// RumDistillery
			Processing_destroy_NAV[5] = new SButton(5, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_3, "destroy_nav.png");			// Clothiers
			Processing_destroy_NAV[6] = new SButton(6, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_nav.png");			// TobaccoProduction
			Processing_destroy_NAV[7] = new SButton(7, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_nav.png");			// WeavingMill
			Processing_destroy_NAV[8] = new SButton(8, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_nav.png");			// WeavingHut
			Processing_destroy_NAV[9] = new SButton(9, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_nav.png");			// ToolSmith
			Processing_destroy_NAV[10] = new SButton(10, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_nav.png");			// WindMill
			Processing_destroy_NAV[11] = new SButton(15, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_nav.png");			// StoneMason

			// Tablica Public
			// build_AV		Public
			SButton* Public_build_AV[12];
			Public_build_AV[0] = new SButton(0, BUILD_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_av.png");		// Doctor
			Public_build_AV[1] = new SButton(1, BUILD_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_av.png");		// Public Bath	
			Public_build_AV[2] = new SButton(2, BUILD_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_av.png");		// Fire Department
			Public_build_AV[3] = new SButton(3, BUILD_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_av.png");		// University
			Public_build_AV[4] = new SButton(4, BUILD_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_av.png");		// Chapel
			Public_build_AV[5] = new SButton(5, BUILD_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_3, "build_av.png");		// Cathedral
			Public_build_AV[6] = new SButton(6, BUILD_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_av.png");		// Church
			Public_build_AV[7] = new SButton(7, BUILD_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_av.png");		// Marketplace
			Public_build_AV[8] = new SButton(8, BUILD_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 - 53, W_3, "build_av.png");		// Palace 
			Public_build_AV[9] = new SButton(9, BUILD_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_av.png");		// School
			Public_build_AV[10] = new SButton(10, BUILD_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_av.png");	// Theatre
			Public_build_AV[11] = new SButton(11, BUILD_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_av.png");	// Tavern

			// build_NAV	Public
			SButton* Public_build_NAV[12];
			Public_build_NAV[0] = new SButton(0, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_nav.png");		// Doctor
			Public_build_NAV[1] = new SButton(1, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_nav.png");		// Public Bath	
			Public_build_NAV[2] = new SButton(2, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_nav.png");		// Fire Department
			Public_build_NAV[3] = new SButton(3, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_nav.png");		// University
			Public_build_NAV[4] = new SButton(4, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_nav.png");		// Chapel
			Public_build_NAV[5] = new SButton(5, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_3, "build_nav.png");		// Cathedral
			Public_build_NAV[6] = new SButton(6, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_nav.png");		// Church
			Public_build_NAV[7] = new SButton(7, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_nav.png");		// Marketplace
			Public_build_NAV[8] = new SButton(8, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 - 53, W_3, "build_nav.png");		// Palace 
			Public_build_NAV[9] = new SButton(9, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_nav.png");		// School
			Public_build_NAV[10] = new SButton(10, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_nav.png");	// Theatre
			Public_build_NAV[11] = new SButton(11, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1	, "build_nav.png");	// Tavern

			// destroy_AV	Public
			SButton* Public_destroy_AV[12];
			Public_destroy_AV[0] = new SButton(0, DESTROY_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_av.png");		// Doctor
			Public_destroy_AV[1] = new SButton(1, DESTROY_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_av.png");		// Public Bath	
			Public_destroy_AV[2] = new SButton(2, DESTROY_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_av.png");		// Fire Department
			Public_destroy_AV[3] = new SButton(3, DESTROY_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_av.png");		// University
			Public_destroy_AV[4] = new SButton(4, DESTROY_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_av.png");		// Chapel
			Public_destroy_AV[5] = new SButton(5, DESTROY_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_3, "destroy_av.png");		// Cathedral
			Public_destroy_AV[6] = new SButton(6, DESTROY_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_av.png");		// Church
			Public_destroy_AV[7] = new SButton(7, DESTROY_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_av.png");		// Marketplace
			Public_destroy_AV[8] = new SButton(8, DESTROY_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_3, "destroy_av.png");			// Palace 
			Public_destroy_AV[9] = new SButton(9, DESTROY_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_av.png");		// School
			Public_destroy_AV[10] = new SButton(10, DESTROY_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_av.png");	// Theatre
			Public_destroy_AV[11] = new SButton(11, DESTROY_PUB, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_av.png");	// Tavern

			// destroy_NAV	Public
			SButton* Public_destroy_NAV[12];
			Public_destroy_NAV[0] = new SButton(0, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_nav.png");		// Doctor
			Public_destroy_NAV[1] = new SButton(1, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_nav.png");		// Public Bath	
			Public_destroy_NAV[2] = new SButton(2, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_nav.png");		// Fire Department
			Public_destroy_NAV[3] = new SButton(3, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_nav.png");		// University
			Public_destroy_NAV[4] = new SButton(4, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_nav.png");		// Chapel
			Public_destroy_NAV[5] = new SButton(5, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_3, "destroy_nav.png");		// Cathedral
			Public_destroy_NAV[6] = new SButton(6, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_nav.png");		// Church
			Public_destroy_NAV[7] = new SButton(7, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_nav.png");		// Marketplace
			Public_destroy_NAV[8] = new SButton(8, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_3, "destroy_nav.png");				// Palace 
			Public_destroy_NAV[9] = new SButton(9, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_nav.png");		// School
			Public_destroy_NAV[10] = new SButton(10, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_nav.png");		// Theatre
			Public_destroy_NAV[11] = new SButton(11, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_nav.png");		// Tavern

			// DOMY
			// Pionerzy
			SButton build_NAV_House_L1(0, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_nav.png");
			SButton destroy_NAV_House_L1(0, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_House_L1(0, BUILD_HOUSE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_av.png");
			SButton destroy_AV_House_L1(0, DESTROY_HOUSE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_av.png");
			// Osadnicy
			SButton build_NAV_House_L2(1, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_nav.png");
			SButton destroy_NAV_House_L2(1, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_House_L2(1, BUILD_HOUSE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_av.png");
			SButton destroy_AV_House_L2(1, DESTROY_HOUSE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_av.png");
			// Mieszczanie
			SButton build_NAV_House_L3(2, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_nav.png");
			SButton destroy_NAV_House_L3(2, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_House_L3(2, BUILD_HOUSE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_av.png");
			SButton destroy_AV_House_L3(2, DESTROY_HOUSE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_av.png");
			// Kupcy
			SButton destroy_NAV_House_L4(3, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_nav.png");
			SButton destroy_AV_House_L4(3, DESTROY_HOUSE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_av.png");
			// Arystokraci
			SButton destroy_NAV_House_L5(4, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_nav.png");
			SButton destroy_AV_House_L5(4, DESTROY_HOUSE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_av.png");

			// Pozwol budowac
			SButton Allow_Build(666, ALLOW_BUILD, ALLOW_BUILD_BUTTON_WIDTH, ALLOW_BUILD_BUTTON_HEIGHT, A_B_X, A_B_Y, "allow_build.png");
			SButton Deny_Build(666, DENY_BUILD, ALLOW_BUILD_BUTTON_WIDTH, ALLOW_BUILD_BUTTON_HEIGHT, A_B_X, A_B_Y, "deny_build.png");
			// Zabron budowac

			//  MAGAZYNY
			// WarehouseIIUpgrade
			SButton upgrade_NAV_Warehouse(15, NONE, UPGRADE_BUTTON_WIDTH, UPGRADE_BUTTON_HEIGHT, U_X, U_Y, "upgrade_nav.png");
			SButton upgrade_AV_Warehouse(15, UPGRADE, UPGRADE_BUTTON_WIDTH, UPGRADE_BUTTON_HEIGHT, U_X, U_Y, "upgrade_av.png");

			// Muzyka i info
			SButton Music_On(CHANGE_MUSIC, 45, 37, 1315, 725, "music_on.png");
			SButton Music_Off(CHANGE_MUSIC, 45, 37, 1315, 725, "music_off.png");

			// Wspolrzedne czworokatow magazynu 
			// LEWY
			gWarehouse_rect_left.x = gWarehouse_rect_left_x;
			gWarehouse_rect_left.y = gWarehouse_rect_left_y;
			gWarehouse_rect_left.h = gWarehouse_rect_left_h;
			gWarehouse_rect_left.w = gWarehouse_rect_left_w;
			// PRAWY
			gWarehouse_rect_right.x = gWarehouse_rect_right_x;
			gWarehouse_rect_right.y = gWarehouse_rect_right_y;
			gWarehouse_rect_right.h = gWarehouse_rect_right_h;
			gWarehouse_rect_right.w = gWarehouse_rect_right_w;

			gWarehouse_rect_centre.x = gWarehouse_rect_centre_h;
			gWarehouse_rect_centre.y = gWarehouse_rect_centre_y;
			gWarehouse_rect_centre.h = gWarehouse_rect_centre_h;
			gWarehouse_rect_centre.w = gWarehouse_rect_centre_w;

			// Glowna petla gry
			sdl_timer = SDL_AddTimer(3000, Update_All, NULL);
			while (!quit)
			{
				// Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					// Sprawdzenie zadania wyjscia
					if (e.type == SDL_QUIT)
						quit = true;
				}
				// Jesli muzyka sie nie odtwarza
				if (Mix_PlayingMusic() == 0)
					// Odtworz muzyke
					Mix_PlayMusic(gBackgroundMusic, -1);

				// Klawisz ESCAPE - wychodzenie do menu glownego
				const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
				if (currentKeyStates[SDL_SCANCODE_ESCAPE])
					if (!(screen == MAIN && subScreen == MAIN))
					{
						if (gTexture2 != NULL)
						{
							SDL_DestroyTexture(gTexture2);
							gTexture2 = NULL;
						}
						SDL_DestroyTexture(gTexture);
						gTexture = NULL;
						gTexture = loadTexture("imgs/main.png");
						if (timer.getTicks() > 0)
							popUp = true;
						screen = MAIN;
						subScreen = MAIN;
					}

				// Czyszczenie ekranu
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				// Paski surowców
				SDL_Rect fillRect = { 6, 295, 56 * tResource[1]->getNumber() / WareHouse.getmagazineCapacity(), 5 };		// 1 Iron Ore
				SDL_Rect fillRect2 = { 71, 295, 56 * tResource[2]->getNumber() / WareHouse.getmagazineCapacity(), 5 };		// 2 Gold
				SDL_Rect fillRect3 = { 136, 295, 56 * tResource[3]->getNumber() / WareHouse.getmagazineCapacity(), 5 };		// 3 Wool
				SDL_Rect fillRect4 = { 201, 295, 56 * tResource[4]->getNumber() / WareHouse.getmagazineCapacity(), 5 };		// 4 Sugar
				SDL_Rect fillRect5 = { 266, 295, 56 * tResource[10]->getNumber() / WareHouse.getmagazineCapacity(), 5 };	// 10 Food

				SDL_Rect fillRect6 = { 6, 369, 56 * tResource[5]->getNumber() / WareHouse.getmagazineCapacity(), 5 };		// 5 Tobacco
				SDL_Rect fillRect7 = { 71, 369, 56 * tResource[6]->getNumber() / WareHouse.getmagazineCapacity(), 5 };		// 6 Cattle
				SDL_Rect fillRect8 = { 136, 369, 56 * tResource[7]->getNumber() / WareHouse.getmagazineCapacity(), 5 };		// 7 Grain
				SDL_Rect fillRect9 = { 201, 369, 56 * tResource[8]->getNumber() / WareHouse.getmagazineCapacity(), 5 };		// 8 Flour
				SDL_Rect fillRect10 = { 266, 369, 56 * tResource[14]->getNumber() / WareHouse.getmagazineCapacity(), 5 };	// 14 Liquor
				
				SDL_Rect fillRect11 = { 6, 437, 56 * tResource[12]->getNumber() / WareHouse.getmagazineCapacity(), 5 };		// 12 Spices
				SDL_Rect fillRect12 = { 71, 437, 56 * tResource[15]->getNumber() / WareHouse.getmagazineCapacity(), 5 };	// 15 Cloth
				SDL_Rect fillRect13 = { 136, 437, 56 * tResource[16]->getNumber() / WareHouse.getmagazineCapacity(), 5 };	// 16 Clothes
				SDL_Rect fillRect14 = { 201, 437, 56 * tResource[11]->getNumber() / WareHouse.getmagazineCapacity(), 5 };	// 11 Tobacco Products
				SDL_Rect fillRect15 = { 266, 437, 56 * tResource[17]->getNumber() / WareHouse.getmagazineCapacity(), 5 };	// 17 Jewerly

				SDL_Rect fillRect16 = { 6, 507, 56 * tResource[18]->getNumber()/WareHouse.getmagazineCapacity(), 5 };		// 18 Tools
				SDL_Rect fillRect17 = { 71, 507, 56 * tResource[19]->getNumber() / WareHouse.getmagazineCapacity(), 5 };	// 19 Wood
				SDL_Rect fillRect18 = { 136, 507, 56 * tResource[20]->getNumber() / WareHouse.getmagazineCapacity(), 5 };	// 20 Bricks
				SDL_Rect fillRect19 = { 201, 507, 56 * tResource[9]->getNumber() / WareHouse.getmagazineCapacity(), 5 };	// 9 Iron
				SDL_Rect fillRect20 = { 266, 507, 56 * tResource[13]->getNumber() / WareHouse.getmagazineCapacity(), 5 };	// 13 Cocoa
				
				switch (screen)
				{
				case MAIN:
					timer.pause();
					SDL_RenderSetViewport(gRenderer, &LargeViewport);
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
					switch (subScreen)
					{
					// Ekran menu glownego
					case MAIN:
						if (timer.getTicks() > 0)
						{
							continue_button.render();
							continue_button.handleEvent(&e);
						}
						new_game_button.setPosition(624, 400);
						new_game_button.handleEvent(&e);		new_game_button.render();					
						load_game_button.render();				load_game_button.handleEvent(&e);
						exit_game_button.render();				exit_game_button.handleEvent(&e);
						if (MUSIC_ON == true)
						{
							Music_On.render();
							Music_On.handleEvent(&e);
							Mix_ResumeMusic();
						}
						else
						{
							Music_Off.render();
							Music_Off.handleEvent(&e);
							Mix_PauseMusic();
						}
						break;
						// Komunikat - potwierdzenie nowej gry
					case POPUPMSG:
						gTextTexture.loadFromRenderedText("Czy na pewno chcesz rozpoczac nowa gre?", textC, gFont);
						gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 380);

						new_game_button.setPosition(SCREEN_WIDTH - MAIN_BUTTON_WIDTH - 525, 520);
						new_game_button.render();				new_game_button.handleEvent(&e);

						main_menu_button.setPosition(525, 520);
						main_menu_button.render();				main_menu_button.handleEvent(&e);
						break;
						// Ekran wczytywania stanu gry
					case LOAD:
					{
						gTextTexture.loadFromRenderedText("Wczytaj", textC, gFont);
						gTextTexture.render(600, 200);
						main_menu_button.setPosition(624, 660);
						main_menu_button.render();				main_menu_button.handleEvent(&e);
						string path;
						for (int i = 0; i < MAX_SLOTS; i++)
						{
							path = "saves/slot" + to_string(i + 1) + ".txt";
							if ((slot[i] = fopen(path.c_str(), "r")) != NULL)
							{
								load_slot_button[i]->render();		load_slot_button[i]->handleEvent(&e);
								fclose(slot[i]);
							}
						}
						break;
					}
						// Ekran zapisu stanu gry
					case SAVE:
						gTextTexture.loadFromRenderedText("Zapisz", textC, gFont);
						gTextTexture.render(624, 200);
						back_button.setPosition(624, 660);
						back_button.render();					back_button.handleEvent(&e);
						for (int i = 0; i < MAX_SLOTS; i++)
						{
							save_slot_button[i]->render();		save_slot_button[i]->handleEvent(&e);
						}
						break;
					}
					break;
					// Ekran rozgrywki
				case GAME:
					timer.unpause();
					timer.count();

					SDL_RenderSetViewport(gRenderer, &LeftViewport);
					SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

					// Skarbiec - wyswietlanie wartosci
					// Podatki
					gTextTexture.loadFromRenderedText(_itoa(0, Money_char_buffor, 10), textC, gFont);
					gTextTexture.render(155 - gTextTexture.getWidth(), 38);
					// Koszty
					gTextTexture.loadFromRenderedText("0", textC, gFont);
					gTextTexture.render(155 - gTextTexture.getWidth(), 61);
					// Sprzedaz
					gTextTexture.loadFromRenderedText("0", textC, gFont);
					gTextTexture.render(155 - gTextTexture.getWidth(), 89);
					// Kupno
					gTextTexture.loadFromRenderedText("0", textC, gFont);
					gTextTexture.render(155 - gTextTexture.getWidth(), 113);
					// Bilans
					gTextTexture.loadFromRenderedText("0", textC, gFont);
					gTextTexture.render(155 - gTextTexture.getWidth(), 139);
					// Srodki
					gTextTexture.loadFromRenderedText(_itoa(tResource[0]->getNumber(), Money_char_buffor, 10), textC, gFont);
					gTextTexture.render(155 - gTextTexture.getWidth(), 168);

					// Ludnosc - wyswietlanie wartosci
					// Pionierzy
					gTextTexture.loadFromRenderedText(_itoa(tPeople[0]->getNumber(), People_char_buffor, 10), textC, gFont);
					gTextTexture.render(400 - gTextTexture.getWidth(), 38);
					// Osadnicy
					gTextTexture.loadFromRenderedText(_itoa(tPeople[1]->getNumber(), People_char_buffor, 10), textC, gFont);
					gTextTexture.render(400 - gTextTexture.getWidth(), 62);
					// Mieszczanie
					gTextTexture.loadFromRenderedText(_itoa(tPeople[2]->getNumber(), People_char_buffor, 10), textC, gFont);
					gTextTexture.render(400 - gTextTexture.getWidth(), 91);
					// Kupcy
					gTextTexture.loadFromRenderedText(_itoa(tPeople[3]->getNumber(), People_char_buffor, 10), textC, gFont);
					gTextTexture.render(400 - gTextTexture.getWidth(), 118);
					// Arystokraci
					gTextTexture.loadFromRenderedText(_itoa(tPeople[4]->getNumber(), People_char_buffor, 10), textC, gFont);
					gTextTexture.render(400 - gTextTexture.getWidth(), 146);
					// Mieszkancy
					gTextTexture.loadFromRenderedText(_itoa(tPeople[0]->getNumber() + tPeople[1]->getNumber() + tPeople[2]->getNumber() 
						+ tPeople[3]->getNumber() + tPeople[4]->getNumber(), People_char_buffor, 10), textC, gFont);
					gTextTexture.render(400 - gTextTexture.getWidth(), 175);

					// Magazyny
					// LVL1////////////////////////////////////////////////////////////////////////////////////////////////////// WWYWALIC (coœ z tym zrobic)
					{
						SDL_RenderCopy(gRenderer, Warehouse_I_texture, NULL, &gWarehouse_rect_left);
						SDL_RenderCopy(gRenderer, Warehouse_II_texture, NULL, &gWarehouse_rect_right);
					}
					// LVL2
					/*
					{
						if (Warehouse_I_texture != NULL)
						{
							SDL_DestroyTexture(Warehouse_I_texture);
							Warehouse_I_texture = NULL;
						{
						SDL_RenderCopy(gRenderer, Warehouse_I_texture, NULL, &gWarehouse_rect_left);
						SDL_RenderCopy(gRenderer, Warehouse_III_texture, NULL, &gWarehouse_rect_right);
					}
					// LVL3
					{
						if (Warehouse_I_texture != NULL)
						{
							SDL_DestroyTexture(Warehouse_II_texture);
							Warehouse_I_texture = NULL;
						{
						SDL_RenderCopy(gRenderer, Warehouse_III_texture, NULL, &gWarehouse_rect_left);
						SDL_RenderCopy(gRenderer, Warehouse_IV_texture, NULL, &gWarehouse_rect_right);
					}
					// LVL4
					{
						if (Warehouse_I_texture != NULL)
						{
							SDL_DestroyTexture(Warehouse_III_texture);
							Warehouse_I_texture = NULL;
						{
						SDL_RenderCopy(gRenderer, Warehouse_IV_texture, NULL, &gWarehouse_rect_centre);
					}
					*/
					if (WareHouse.getClass() > -1)
						WareHouse.checkStatus(tPeople[WareHouse.getClass()]->getNumber());
					// UPGRADE
					if (WareHouse.getStatus() == false)
					{
						upgrade_NAV_Warehouse.render();
						upgrade_NAV_Warehouse.handleEvent(&e);
					}
					else
					{
						upgrade_AV_Warehouse.render();
						upgrade_AV_Warehouse.handleEvent(&e);
					}
						
					// Aktualizacje stanów	
					
					// AKTUALIZACJA STANU SUROWCOW
					thisTime = timer.getTicks();
					deltaTime = (float)(thisTime - lastTime);
					cout << thisTime << " " << deltaTime << " " << lastTime << endl;
					lastTime = thisTime;
					
					


					if (buy == true)
					{
						gTextTexture.loadFromRenderedText("Kup", textC, gFont);
						gTextTexture.render(250, 210);

						buy_iron_ore_button.render();			buy_iron_ore_button.handleEvent(&e);
						buy_gold_button.render();				buy_gold_button.handleEvent(&e);
						buy_cottom_button.render();				buy_cottom_button.handleEvent(&e);
						buy_sugarcane_button.render();			buy_sugarcane_button.handleEvent(&e);
						buy_food_button.render();				buy_food_button.handleEvent(&e);

						buy_tobacco_button.render();			buy_tobacco_button.handleEvent(&e);
						buy_cattle_button.render();				buy_cattle_button.handleEvent(&e);
						buy_grain_button.render();				buy_grain_button.handleEvent(&e);
						buy_flour_button.render();				buy_flour_button.handleEvent(&e);
						buy_alcohol_button.render();			buy_alcohol_button.handleEvent(&e);

						buy_spices_button.render();				buy_spices_button.handleEvent(&e);
						buy_textiles_button.render();			buy_textiles_button.handleEvent(&e);
						buy_clothes_button.render();			buy_clothes_button.handleEvent(&e);
						buy_cigarettes_button.render();			buy_cigarettes_button.handleEvent(&e);
						buy_jewelry_button.render();			buy_jewelry_button.handleEvent(&e);

						buy_tools_button.render();				buy_tools_button.handleEvent(&e);
						buy_wood_button.render();				buy_wood_button.handleEvent(&e);
						buy_bricks_button.render();				buy_bricks_button.handleEvent(&e);
						buy_iron_button.render();				buy_iron_button.handleEvent(&e);
						buy_cocoa_button.render();				buy_cocoa_button.handleEvent(&e);

						cancel_AV_button.render();				cancel_AV_button.handleEvent(&e);
					}
					else if (sell == true)
					{
						gTextTexture.loadFromRenderedText("Sprzedaj", textC, gFont);
						gTextTexture.render(250, 210);

						sell_iron_ore_button.render();			sell_iron_ore_button.handleEvent(&e);
						sell_gold_button.render();				sell_gold_button.handleEvent(&e);
						sell_cottom_button.render();			sell_cottom_button.handleEvent(&e);
						sell_sugarcane_button.render();			sell_sugarcane_button.handleEvent(&e);
						sell_food_button.render();				sell_food_button.handleEvent(&e);

						sell_tobacco_button.render();			sell_tobacco_button.handleEvent(&e);
						sell_cattle_button.render();			sell_cattle_button.handleEvent(&e);
						sell_grain_button.render();				sell_grain_button.handleEvent(&e);
						sell_flour_button.render();				sell_flour_button.handleEvent(&e);
						sell_alcohol_button.render();			sell_alcohol_button.handleEvent(&e);

						sell_spices_button.render();			sell_spices_button.handleEvent(&e);
						sell_textiles_button.render();			sell_textiles_button.handleEvent(&e);
						sell_clothes_button.render();			sell_clothes_button.handleEvent(&e);
						sell_cigarettes_button.render();		sell_cigarettes_button.handleEvent(&e);
						sell_jewelry_button.render();			sell_jewelry_button.handleEvent(&e);

						sell_tools_button.render();				sell_tools_button.handleEvent(&e);
						sell_wood_button.render();				sell_wood_button.handleEvent(&e);
						sell_bricks_button.render();			sell_bricks_button.handleEvent(&e);
						sell_iron_button.render();				sell_iron_button.handleEvent(&e);
						sell_cocoa_button.render();				sell_cocoa_button.handleEvent(&e);

						cancel_AV_button.render();				cancel_AV_button.handleEvent(&e);
					}
					else
					{
						cancel_NAV_button.render();				cancel_NAV_button.handleEvent(&e);
					}
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);

					// Paski stanu zasobow
					SDL_RenderFillRect(gRenderer, &fillRect);
					SDL_RenderFillRect(gRenderer, &fillRect2);
					SDL_RenderFillRect(gRenderer, &fillRect3);
					SDL_RenderFillRect(gRenderer, &fillRect4);
					SDL_RenderFillRect(gRenderer, &fillRect5);

					SDL_RenderFillRect(gRenderer, &fillRect6);
					SDL_RenderFillRect(gRenderer, &fillRect7);
					SDL_RenderFillRect(gRenderer, &fillRect8);
					SDL_RenderFillRect(gRenderer, &fillRect9);
					SDL_RenderFillRect(gRenderer, &fillRect10);

					SDL_RenderFillRect(gRenderer, &fillRect11);
					SDL_RenderFillRect(gRenderer, &fillRect12);
					SDL_RenderFillRect(gRenderer, &fillRect13);
					SDL_RenderFillRect(gRenderer, &fillRect14);
					SDL_RenderFillRect(gRenderer, &fillRect15);

					SDL_RenderFillRect(gRenderer, &fillRect16);
					SDL_RenderFillRect(gRenderer, &fillRect17);
					SDL_RenderFillRect(gRenderer, &fillRect18);
					SDL_RenderFillRect(gRenderer, &fillRect19);
					SDL_RenderFillRect(gRenderer, &fillRect20);

					buy_button.render();						buy_button.handleEvent(&e);
					sell_button.render();						sell_button.handleEvent(&e);
					stats_button.render();						stats_button.handleEvent(&e);
					save_game_button.render();					save_game_button.handleEvent(&e);
					switch (subScreen)
					{
						// Ekran rozgrywki - wybor budynkow
					case GAME:
						main_menu_button.setPosition(300, 732);
						main_menu_button.render();				main_menu_button.handleEvent(&e);

						SDL_RenderSetViewport(gRenderer, &RightViewport);
						ind_button.render();					ind_button.handleEvent(&e);
						prod_button.render();					prod_button.handleEvent(&e);
						pub_button.render();					pub_button.handleEvent(&e);
						break;

						// Ekran rozgrywki - statystyki
					case STATS:
						back_button.setPosition(300, 732);
						back_button.render();					back_button.handleEvent(&e);
		
						SDL_RenderSetViewport(gRenderer, &RightViewport);
						SDL_RenderCopy(gRenderer, gTexture2, NULL, NULL);
						timer.render();

						// Wyswietlanie iloœci domów
						gTextTexture.loadFromRenderedText(_itoa(tHouse[0]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_1, T_W_1 - 43);
						gTextTexture.loadFromRenderedText(_itoa(tHouse[1]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_2+2, T_W_1 - 29);
						gTextTexture.loadFromRenderedText(_itoa(tHouse[2]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_3+3, T_W_1 - 29);
						gTextTexture.loadFromRenderedText(_itoa(tHouse[3]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_4+3, T_W_1 - 29);
						gTextTexture.loadFromRenderedText(_itoa(tHouse[4]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_5+3, T_W_1 - 29);

						// Wyswietlanie stanu surowcow
						gTextTexture.loadFromRenderedText(_itoa(tResource[1]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(85 - gTextTexture.getWidth(), 415);
						gTextTexture.loadFromRenderedText(_itoa(tResource[2]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(250 - gTextTexture.getWidth(), 415);
						gTextTexture.loadFromRenderedText(_itoa(tResource[3]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(415 - gTextTexture.getWidth(), 415);
						gTextTexture.loadFromRenderedText(_itoa(tResource[4]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(580 - gTextTexture.getWidth(), 415);
						gTextTexture.loadFromRenderedText(_itoa(tResource[10]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(745 - gTextTexture.getWidth(), 415);

						gTextTexture.loadFromRenderedText(_itoa(tResource[5]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(85 - gTextTexture.getWidth(), 490);
						gTextTexture.loadFromRenderedText(_itoa(tResource[6]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(250 - gTextTexture.getWidth(), 490);
						gTextTexture.loadFromRenderedText(_itoa(tResource[7]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(415 - gTextTexture.getWidth(), 490);
						gTextTexture.loadFromRenderedText(_itoa(tResource[8]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(580 - gTextTexture.getWidth(), 490);
						gTextTexture.loadFromRenderedText(_itoa(tResource[14]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(745 - gTextTexture.getWidth(), 490);

						gTextTexture.loadFromRenderedText(_itoa(tResource[12]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(85 - gTextTexture.getWidth(), 560);
						gTextTexture.loadFromRenderedText(_itoa(tResource[15]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(250 - gTextTexture.getWidth(), 560);
						gTextTexture.loadFromRenderedText(_itoa(tResource[16]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(415 - gTextTexture.getWidth(), 560);
						gTextTexture.loadFromRenderedText(_itoa(tResource[11]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(580 - gTextTexture.getWidth(), 560);
						gTextTexture.loadFromRenderedText(_itoa(tResource[17]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(745 - gTextTexture.getWidth(), 560);

						gTextTexture.loadFromRenderedText(_itoa(tResource[18]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(85 - gTextTexture.getWidth(), 625);
						gTextTexture.loadFromRenderedText(_itoa(tResource[19]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(250 - gTextTexture.getWidth(), 625);
						gTextTexture.loadFromRenderedText(_itoa(tResource[20]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(415 - gTextTexture.getWidth(), 625);
						gTextTexture.loadFromRenderedText(_itoa(tResource[9]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(580 - gTextTexture.getWidth(), 625);
						gTextTexture.loadFromRenderedText(_itoa(tResource[13]->getNumber(), People_char_buffor, 10), textC, gFont);
						gTextTexture.render(745 - gTextTexture.getWidth(), 625);
						//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// WYWALIC
						/*gTextTexture.loadFromRenderedText(_itoa(s1, Money_char_buffor, 10), textC);			gTextTexture.loadFromRenderedText(_itoa(s11, Money_char_buffor, 10), textC);
						gTextTexture.render(kolumna_stat_1, wiersz_stat_1);									gTextTexture.render(kolumna_stat_3, wiersz_stat_3);
						gTextTexture.loadFromRenderedText(_itoa(s2, Money_char_buffor, 10), textC);			gTextTexture.loadFromRenderedText(_itoa(s12, Money_char_buffor, 10), textC);
						gTextTexture.render(kolumna_stat_1, wiersz_stat_2);									gTextTexture.render(kolumna_stat_3, wiersz_stat_4);
						gTextTexture.loadFromRenderedText(_itoa(s3, Money_char_buffor, 10), textC);			gTextTexture.loadFromRenderedText(_itoa(s13, Money_char_buffor, 10), textC);
						gTextTexture.render(kolumna_stat_1, wiersz_stat_3);									gTextTexture.render(kolumna_stat_4, wiersz_stat_1);
						gTextTexture.loadFromRenderedText(_itoa(s4, Money_char_buffor, 10), textC);			gTextTexture.loadFromRenderedText(_itoa(s14, Money_char_buffor, 10), textC);
						gTextTexture.render(kolumna_stat_1, wiersz_stat_4);									gTextTexture.render(kolumna_stat_4, wiersz_stat_2);
						gTextTexture.loadFromRenderedText(_itoa(s5, Money_char_buffor, 10), textC);			gTextTexture.loadFromRenderedText(_itoa(s15, Money_char_buffor, 10), textC);
						gTextTexture.render(kolumna_stat_2, wiersz_stat_1);									gTextTexture.render(kolumna_stat_4, wiersz_stat_3);
						gTextTexture.loadFromRenderedText(_itoa(s6, Money_char_buffor, 10), textC);			gTextTexture.loadFromRenderedText(_itoa(s16, Money_char_buffor, 10), textC);
						gTextTexture.render(kolumna_stat_2, wiersz_stat_2);									gTextTexture.render(kolumna_stat_4, wiersz_stat_4);
						gTextTexture.loadFromRenderedText(_itoa(s7, Money_char_buffor, 10), textC);			gTextTexture.loadFromRenderedText(_itoa(s17, Money_char_buffor, 10), textC);
						gTextTexture.render(kolumna_stat_2, wiersz_stat_3);									gTextTexture.render(kolumna_stat_5, wiersz_stat_1);
						gTextTexture.loadFromRenderedText(_itoa(s8, Money_char_buffor, 10), textC);			gTextTexture.loadFromRenderedText(_itoa(s18, Money_char_buffor, 10), textC);
						gTextTexture.render(kolumna_stat_2, wiersz_stat_4);									gTextTexture.render(kolumna_stat_5, wiersz_stat_2);
						gTextTexture.loadFromRenderedText(_itoa(s9, Money_char_buffor, 10), textC);			gTextTexture.loadFromRenderedText(_itoa(s19, Money_char_buffor, 10), textC);
						gTextTexture.render(kolumna_stat_3, wiersz_stat_1);									gTextTexture.render(kolumna_stat_5, wiersz_stat_3);
						gTextTexture.loadFromRenderedText(_itoa(s10, Money_char_buffor, 10), textC);		gTextTexture.loadFromRenderedText(_itoa(s20, Money_char_buffor, 10), textC);
						gTextTexture.render(kolumna_stat_3, wiersz_stat_2);									gTextTexture.render(kolumna_stat_5, wiersz_stat_4);*/
						//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// WYWALIC


						//gTextTexture.loadFromRenderedText("Zapisz", textC);
					//	gTextTexture.render(624, 200);

						// Wyœwietlenie iloœci pól na wyspie i pól wolnych
						gTextTexture.loadFromRenderedText(_itoa(islandSize, People_char_buffor, 10), textC, gFont);
						gTextTexture.render(I_S_X, I_S_Y);
						gTextTexture.loadFromRenderedText(_itoa(islandSize-usedFields, People_char_buffor, 10), textC, gFont);
						gTextTexture.render(U_F_X, U_F_Y);

						// Pozwolenie i zakaz budowy
						if (allow_build == true)
						{
							Allow_Build.render();				Allow_Build.handleEvent(&e);
						}
						else
						{
							Deny_Build.render();				Deny_Build.handleEvent(&e);
						}
						// Buduj zburz domy
						// Pionierzy
						build_AV_House_L1.render();				destroy_AV_House_L1.render();
						build_AV_House_L1.handleEvent(&e);		destroy_AV_House_L1.handleEvent(&e);

						// Osadnicy
						if(tHouse[1]->getStatus())
						{
							build_AV_House_L2.render();			destroy_AV_House_L2.render();
							build_AV_House_L2.handleEvent(&e);	destroy_AV_House_L2.handleEvent(&e);
						}
						else
						{
							build_NAV_House_L2.render();			destroy_NAV_House_L2.render();
							build_NAV_House_L2.handleEvent(&e);		destroy_NAV_House_L2.handleEvent(&e);
						}
						
						// Mieszczanie
						if (tHouse[2]->getStatus())
						{
							build_AV_House_L3.render();			destroy_AV_House_L3.render();
							build_AV_House_L3.handleEvent(&e);	destroy_AV_House_L3.handleEvent(&e);
						}
						else
						{
							build_NAV_House_L3.render();			destroy_NAV_House_L3.render();
							build_NAV_House_L3.handleEvent(&e);		destroy_NAV_House_L3.handleEvent(&e);
						}

						// Kupcy
						if (tHouse[3]->getStatus())
						{
							destroy_AV_House_L4.render();
							destroy_AV_House_L4.handleEvent(&e);
						}
						else
						{
							destroy_NAV_House_L4.render();
							destroy_NAV_House_L4.handleEvent(&e);
						}

						// Arystokraci
						if (tHouse[4]->getStatus())
						{
							destroy_AV_House_L5.render();
							destroy_AV_House_L5.handleEvent(&e);
						}
						else
						{
							destroy_NAV_House_L5.render();
							destroy_NAV_House_L5.handleEvent(&e);
						}


						break;
						// Ekran rozgrywki - budynki publiczne
					case PUB:
						back_button.setPosition(300, 732);
						back_button.render();					back_button.handleEvent(&e);

						SDL_RenderSetViewport(gRenderer, &RightViewport);
						SDL_RenderCopy(gRenderer, gTexture2, NULL, NULL);

						for (int i = 0; i < 12; i++)
						{
							if(tPublic[i]->getStatus())
							{
								Public_build_AV[i]->render();
								Public_build_AV[i]->handleEvent(&e);

								Public_destroy_AV[i]->render();
								Public_destroy_AV[i]->handleEvent(&e);
							}
							else
							{
								Public_build_NAV[i]->render();
								Public_build_NAV[i]->handleEvent(&e);
								Public_destroy_NAV[i]->render();
								Public_destroy_NAV[i]->handleEvent(&e);
							}
							
						}
						// Wyswietlanie ilosci budynkow publicznych
						gTextTexture.loadFromRenderedText(_itoa(tPublic[7]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_1, T_W_1);
						gTextTexture.loadFromRenderedText(_itoa(tPublic[4]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_2, T_W_1); 
						gTextTexture.loadFromRenderedText(_itoa(tPublic[11]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_3, T_W_1);
						gTextTexture.loadFromRenderedText(_itoa(tPublic[2]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_4, T_W_1);
						gTextTexture.loadFromRenderedText(_itoa(tPublic[9]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_5, T_W_1);

						gTextTexture.loadFromRenderedText(_itoa(tPublic[0]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_1, T_W_2);
						gTextTexture.loadFromRenderedText(_itoa(tPublic[6]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_2, T_W_2);
						gTextTexture.loadFromRenderedText(_itoa(tPublic[10]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_3, T_W_2);
						gTextTexture.loadFromRenderedText(_itoa(tPublic[3]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_4, T_W_2);
						gTextTexture.loadFromRenderedText(_itoa(tPublic[1]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_5, T_W_2);

						gTextTexture.loadFromRenderedText(_itoa(tPublic[5]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_1, T_W_3);
						gTextTexture.loadFromRenderedText(_itoa(tPublic[8]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_4 + 85, T_W_3);
						break;
						// Ekran rozgrywki - przetworstwo
					case PROC:
						back_button.setPosition(300, 732);
						back_button.render();					back_button.handleEvent(&e);
						SDL_RenderSetViewport(gRenderer, &RightViewport);
						SDL_RenderCopy(gRenderer, gTexture2, NULL, NULL);

						for (int i = 0; i < 12; i++)
						{
							if(tProcessing[i]->getStatus())
							{
								Processing_build_AV[i]->render();
								Processing_build_AV[i]->handleEvent(&e);

								Processing_destroy_AV[i]->render();
								Processing_destroy_AV[i]->handleEvent(&e);
							}
							else
							{
								Processing_build_NAV[i]->render();
								Processing_build_NAV[i]->handleEvent(&e);

								Processing_destroy_NAV[i]->render();
								Processing_destroy_NAV[i]->handleEvent(&e);
							}
							
						}

						// Wyswietlanie ilosci budynkow przetworczych
						gTextTexture.loadFromRenderedText(_itoa(tProcessing[8]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_1, T_W_1);
						gTextTexture.loadFromRenderedText(_itoa(tProcessing[3]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_2, T_W_1);
						gTextTexture.loadFromRenderedText(_itoa(tProduction[15]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_3, T_W_1);
						gTextTexture.loadFromRenderedText(_itoa(tProcessing[6]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_4, T_W_1);
						gTextTexture.loadFromRenderedText(_itoa(tProcessing[4]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_5, T_W_1);

						gTextTexture.loadFromRenderedText(_itoa(tProcessing[0]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_1, T_W_2);
						gTextTexture.loadFromRenderedText(_itoa(tProcessing[7]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_2, T_W_2);
						gTextTexture.loadFromRenderedText(_itoa(tProcessing[10]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_3, T_W_2);
						gTextTexture.loadFromRenderedText(_itoa(tProcessing[9]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_4, T_W_2);
						gTextTexture.loadFromRenderedText(_itoa(tProcessing[1]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_5, T_W_2);

						gTextTexture.loadFromRenderedText(_itoa(tProcessing[5]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_2, T_W_3);
						gTextTexture.loadFromRenderedText(_itoa(tProcessing[2]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_4, T_W_3);
						break;
						// Ekran rozgrywki - produkcja
					case PROD:
						back_button.setPosition(300, 732);
						back_button.render();					back_button.handleEvent(&e);
						SDL_RenderSetViewport(gRenderer, &RightViewport);
						SDL_RenderCopy(gRenderer, gTexture2, NULL, NULL);

						for (int i = 0; i < 15; i++)
						{
							if(tProduction[i]->getStatus())
							{
							Production_build_AV[i]->render();
							Production_build_AV[i]->handleEvent(&e);

							Production_destroy_AV[i]->render();
							Production_destroy_AV[i]->handleEvent(&e);
							}
							else
							{
								Production_build_NAV[i]->render();
								Production_build_NAV[i]->handleEvent(&e);

								Production_destroy_NAV[i]->render();
								Production_destroy_NAV[i]->handleEvent(&e);
							}

						}
						gTextTexture.loadFromRenderedText(_itoa(tProduction[1]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_1, T_W_1);
						gTextTexture.loadFromRenderedText(_itoa(tProduction[14]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_2, T_W_1);
						gTextTexture.loadFromRenderedText(_itoa(tProduction[7]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_3, T_W_1);
						gTextTexture.loadFromRenderedText(_itoa(tProduction[4]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_4, T_W_1);
						gTextTexture.loadFromRenderedText(_itoa(tProduction[6]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_5, T_W_1);

						gTextTexture.loadFromRenderedText(_itoa(tProduction[10]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_1, T_W_2);
						gTextTexture.loadFromRenderedText(_itoa(tProduction[8]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_2, T_W_2);
						gTextTexture.loadFromRenderedText(_itoa(tProduction[9]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_3, T_W_2);
						gTextTexture.loadFromRenderedText(_itoa(tProduction[3]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_4, T_W_2);
						gTextTexture.loadFromRenderedText(_itoa(tProduction[2]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_5, T_W_2);

						gTextTexture.loadFromRenderedText(_itoa(tProduction[11]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_1, T_W_3);
						gTextTexture.loadFromRenderedText(_itoa(tProduction[13]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_2, T_W_3);
						gTextTexture.loadFromRenderedText(_itoa(tProduction[5]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_3, T_W_3);
						gTextTexture.loadFromRenderedText(_itoa(tProduction[0]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_4, T_W_3);
						gTextTexture.loadFromRenderedText(_itoa(tProduction[12]->getNumber(), People_char_buffor, 10), textC, gFont_12);
						gTextTexture.render(T_C_5, T_W_3);
						break;
					}
					break;
				case QUIT:
					quit = true;
					break;

				}
				// Odswiezenie ekranu
				SDL_RenderPresent(gRenderer);
				
			}
		}
	}
	// getch do testowania
	//_getch();
	// Zwalnianie zasobów i zamykanie SDL
	close();
	return 0;
}