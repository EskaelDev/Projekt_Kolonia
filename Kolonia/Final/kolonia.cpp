#ifndef SBUTTON_H
#include "SButton.h"
#endif
#ifndef STEXTURE_H
#include "STexture.h"
#endif
#ifndef STIMER_H
#include "STimer.h"
#endif
#ifndef SDL_FUNCTIONS_H
#include "sdl_functions.h"
#endif
#ifndef SDL_OBJECTS_H
#include "sdl_objects.h"
#endif
#ifndef SDL_VARIABLES_H
#include "sdl_variables.h"
#endif
#ifndef SDL_CONSTS_H
#include "sdl_consts.h"
#endif
#ifndef SDL_ENUMS_H
#include "sdl_enums.h"
#endif
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

int main(int argc, char* args[])
{
	// House(bricksToBuild, toolsToBuild, woodToBuild, inhabitants, startPeople, buildingID0, buildingID1, buildingID2)
	House* tHouse[5]; { int tab0[1] = { -1 };
	tHouse[0] = new House(0, 0, 3, 3, 1, -1, -1, -1, tab0, sizeof(tab0)); } 	/* Pioneers House */ { int tab1[2] = { 4, 7 };
	tHouse[1] = new House(0, 1, 3, 7, 2, 4, 7, -1, tab1, sizeof(tab1)); }		/* Settlers House */ { int tab2[3] = { 2, 9, 11 };
	tHouse[2] = new House(6, 2, 2, 15, 3, 2, 9, 11, tab2, sizeof(tab2)); } 	/* Citizens House */ { int tab3[3] = { 0, 1, 6 };
	tHouse[3] = new House(9, 3, 3, 25, 4, 0, 1, 6, tab3, sizeof(tab3)); }		/* Merchansts House */ { int tab4[3] = { 3, 5, 10 };
	tHouse[4] = new House(12, 3, 3, 40, 5, 3, 5, 10, tab4, sizeof(tab4)); }		/* Aristorcats House */

	Magazine WareHouse;

	// Public(goldToBuild, bricksToBuild, toolsToBuild, woodToBuild, maintenanceActiveCost, size, peopleToBuild, peopleClass)
	Public* tPublic[12];
	tPublic[0] = new Public(450, 9, 4, 4, 30, 4, 50, 2);			// Doctor
	tPublic[1] = new Public(1200, 19, 6, 5, 60, 12, 210, 2);		// Public Bath	
	tPublic[2] = new Public(150, 0, 3, 5, 15, 4, 15, 1);			// Fire Department
	tPublic[3] = new Public(750, 19, 6, 5, 60, 9, 250, 3);			// University
	tPublic[4] = new Public(100, 0, 2, 5, 5, 2, 40, 0);				// Chapel
	tPublic[5] = new Public(5000, 50, 15, 20, 40, 24, 1500, 3);		// Cathedral
	tPublic[6] = new Public(1600, 25, 7, 7, 50, 12, 150, 2);		// Church
	tPublic[7] = new Public(200, 0, 4, 10, 10, 12, 75, 0);			// Marketplace
	tPublic[8] = new Public(7500, 70, 25, 25, 90, 35, 2500, 4);		// Palace 
	tPublic[9] = new Public(450, 9, 4, 4, 30, 4, 100, 1);			// School
	tPublic[10] = new Public(1200, 19, 2, 5, 80, 9, 300, 3);		// Theatre
	tPublic[11] = new Public(250, 6, 3, 4, 15, 6, 50, 1);			// Tavern

	// Production(moneyToBuild, bricksToBuild, toolsToBuild, woodToBuild, maintenanceActiveCost, maintenancePassiveCost, size, magazineCapacity, peopleToBuild, peopleClass, productID)
	Production* tProduction[16];
	tProduction[0] = new Production(200, 6, 2, 3, 25, 10, 16, 9, 200, 2, 3);		// Cotton Plantation		
	tProduction[1] = new Production(50, 0, 2, 0, 5, 0, 4, 10, 0, -1, 19);			// Foresters Lodge
	tProduction[2] = new Production(100, 0, 2, 5, 5, 0, 16, 6, 75, 1, 7);			// Grain Farm
	tProduction[3] = new Production(300, 8, 2, 3, 35, 15, 16, 4, 75, 1, 12);		// Spice Farm
	tProduction[4] = new Production(50, 0, 2, 2, 5, 0, 4, 3, 0, -1, 10);			// Hunters Hut
	tProduction[5] = new Production(300, 8, 2, 3, 35, 15, 16, 6, 200, 2, 13);		// Cocoa Plantation	
	tProduction[6] = new Production(100, 0, 1, 4, 5, 0, 16, 4, 30, 0, 6);			// Cattle Farm
	tProduction[7] = new Production(200, 0, 2, 4, 5, 0, 16, 8, 0, -1, 3);			// Sheep Farm
	tProduction[8] = new Production(300, 8, 2, 3, 35, 15, 16, 6, 40, 1, 14);		// Winery
	tProduction[9] = new Production(300, 8, 2, 3, 35, 15, 16, 6, 40, 1, 5);			// Tobacco Plantation
	tProduction[10] = new Production(300, 8, 2, 3, 25, 10, 16, 6, 40, 1, 4);		// Sugarcane Plantation
	tProduction[11] = new Production(1000, 5, 10, 20, 60, 20, 3, 4, 120, 1, 1);		// Iron Mine
	tProduction[12] = new Production(1800, 7, 15, 30, 60, 20, 3, 4, 450, 2, 1);		// Deep Iron Mine
	tProduction[13] = new Production(1000, 5, 10, 20, 60, 20, 3, 4, 150, 2, 2);		// Gold Mine
	tProduction[14] = new Production(100, 0, 3, 5, 5, 0, 1, 4, 0, -1, 10);			// Fisters Hut
	tProduction[15] = new Production(100, 0, 5, 5, 5, 0, 4, 8, 15, 1, 20);			// Stone Mason

	// Processing(moneyToBuild, bricksToBuild, toolsToBuild, woodToBuild, maintenanceActiveCost, maintenancePassiveCost, magazineCapacity, peopleToBuild, peopleClass, productID, materialID, productNumber, materialNumber)
	Processing* tProcessing[11];
	tProcessing[0] = new Processing(150, 0, 2, 6, 5, 0, 4, 75, 1, 10, 8, 1, 2);			// Bakery
	tProcessing[1] = new Processing(200, 4, 3, 1, 25, 10, 5, 120, 1, 9, 1, 1, 1);		// Ore Refenery
	tProcessing[2] = new Processing(1500, 10, 7, 2, 45, 20, 4, 250, 3, 17, 2, 2, 1);	// Gold Smith
	tProcessing[3] = new Processing(150, 10, 3, 4, 5, 0, 4, 30, 0, 10, 6, 1, 2);		// Butcher Shop
	tProcessing[4] = new Processing(200, 5, 3, 2, 25, 7, 4, 40, 1, 14, 4, 1, 2);		// Rum Distillery
	tProcessing[5] = new Processing(150, 2, 3, 6, 10, 5, 4, 200, 2, 16, 15, 1, 1);		// Clothiers
	tProcessing[6] = new Processing(200, 5, 3, 2, 20, 10, 4, 40, 1, 11, 5, 1, 2);		// TobaccoProduction
	tProcessing[7] = new Processing(200, 7, 4, 3, 20, 10, 4, 75, 1, 15, 3, 1, 1);		// WeavingMill
	tProcessing[8] = new Processing(200, 0, 3, 6, 10, 5, 4, 0, -1, 15, 3, 1, 2);		// WeavingHut
	tProcessing[9] = new Processing(150, 5, 3, 2, 25, 10, 4, 100, 1, 18, 9, 2, 1);		// ToolSmithy
	tProcessing[10] = new Processing(100, 0, 3, 6, 5, 0, 6, 75, 1, 10, 7, 1, 2);		// WindMill

	// People(tax)
	People* tPeople[5];
	tPeople[0] = new People(1);		// Pioneers
	tPeople[1] = new People(1);		// Settlers
	tPeople[2] = new People(1);		// Citizens
	tPeople[3] = new People(2);		// Merchants
	tPeople[4] = new People(2);		// Aristocrats

	// Resource(price)
	Resource* tResource[21];
	tResource[0] = new Resource(1);			// Money
	tResource[1] = new Resource(60);		// Iron Ore
	tResource[2] = new Resource(465);		// Gold
	tResource[3] = new Resource(16);		// Wool
	tResource[4] = new Resource(19);		// Sugar
	tResource[5] = new Resource(23);		// Tobacco
	tResource[6] = new Resource(6);			// Cattle
	tResource[7] = new Resource(3);			// Grain
	tResource[8] = new Resource(3);			// Flour
	tResource[9] = new Resource(84);		// Iron
	tResource[10] = new Resource(17);		// Food
	tResource[11] = new Resource(65);		// Tobacco Products
	tResource[12] = new Resource(40);		// Spices
	tResource[13] = new Resource(33);		// Cocoa
	tResource[14] = new Resource(52);		// Liquor
	tResource[15] = new Resource(32);		// Cloth
	tResource[16] = new Resource(130);		// Clothes
	tResource[17] = new Resource(590);		// Jewerly
	tResource[18] = new Resource(80);		// Tools
	tResource[19] = new Resource(20);		// Wood
	tResource[20] = new Resource(30);		// Bricks

	tResource[0]->increase(5000);

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

			gFont = TTF_OpenFont("fonts/Caladea-Regular.ttf", 19);

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

			// Przyciski splashy
			SButton ind_button(INDUSTRIAL, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 0, 0, "/buildings/ind.png");
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
			// Production
			// CottonPlantation
			SButton build_NAV_CottonPlantation(19, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_3, "build_nav.png");
			SButton destroy_NAV_CottonPlantation(19, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_3, "destroy_nav.png");
			SButton build_AV_CottonPlantation(19, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_3, "build_av.png");
			SButton destroy_AV_CottonPlantation(19, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_3, "destroy_av.png");
			// ForestersLodge
			SButton build_AV_ForestersLodge(20, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_av.png");
			SButton destroy_AV_ForestersLodge(20, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_av.png");
			// GrainFarm
			SButton build_NAV_GrainFarm(21, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_nav.png");
			SButton destroy_NAV_GrainFarm(21, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_nav.png");
			SButton build_AV_GrainFarm(21, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_av.png");
			SButton destroy_AV_GrainFarm(21, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_av.png");
			// SpiceFarm
			SButton build_NAV_SpiceFarm(22, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_nav.png");
			SButton destroy_NAV_SpiceFarm(22, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_nav.png");
			SButton build_AV_SpiceFarm(22, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_av.png");
			SButton destroy_AV_SpiceFarm(22, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_av.png");
			// HuntersHut
			SButton build_NAV_HuntersHut(23, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_nav.png");
			SButton destroy_NAV_HuntersHut(23, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_HuntersHut(23, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_av.png");
			SButton destroy_AV_HuntersHut(23, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_av.png");
			// CocoaPlantation
			SButton build_NAV_CocoaPlantation(24, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_3, "build_nav.png");
			SButton destroy_NAV_CocoaPlantation(24, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_3, "destroy_nav.png");
			SButton build_AV_CocoaPlantation(24, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_3, "build_av.png");
			SButton destroy_AV_CocoaPlantation(24, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_3, "destroy_av.png");
			// CattleFarm
			SButton build_NAV_CattleFarm(25, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_nav.png");
			SButton destroy_NAV_CattleFarm(25, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_CattleFarm(25, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_av.png");
			SButton destroy_AV_CattleFarm(25, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_av.png");
			// SheepFarm
			SButton build_NAV_SheepFarm(26, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_nav.png");
			SButton destroy_NAV_SheepFarm(26, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_SheepFarm(26, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_av.png");
			SButton destroy_AV_SheepFarm(26, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_av.png");
			// Winery
			SButton build_NAV_Winery(27, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_nav.png");
			SButton destroy_NAV_Winery(27, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_nav.png");
			SButton build_AV_Winery(27, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_av.png");
			SButton destroy_AV_Winery(27, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_av.png");
			// TobaccoPlantation
			SButton build_NAV_TobaccoPlantation(28, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_nav.png");
			SButton destroy_NAV_TobaccoPlantation(28, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_nav.png");
			SButton build_AV_TobaccoPlantation(28, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_av.png");
			SButton destroy_AV_TobaccoPlantation(28, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_av.png");
			// SugarcanePlantation
			SButton build_NAV_SugarcanePlantation(29, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_nav.png");
			SButton destroy_NAV_SugarcanePlantation(29, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_nav.png");
			SButton build_AV_SugarcanePlantation(29, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_av.png");
			SButton destroy_AV_SugarcanePlantation(29, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_av.png");
			// IronMine
			SButton build_NAV_IronMine(30, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_3, "build_nav.png");
			SButton destroy_NAV_IronMine(30, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_3, "destroy_nav.png");
			SButton build_AV_IronMine(30, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_3, "build_av.png");
			SButton destroy_AV_IronMine(30, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_3, "destroy_av.png");
			// DeepIronMine
			SButton build_NAV_DeepIronMine(31, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_3, "build_nav.png");
			SButton destroy_NAV_DeepIronMine(31, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_3, "destroy_nav.png");
			SButton build_AV_DeepIronMine(31, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_3, "build_av.png");
			SButton destroy_AV_DeepIronMine(31, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_3, "destroy_av.png");
			// GoldMine
			SButton build_NAV_GoldMine(32, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_3, "build_nav.png");
			SButton destroy_NAV_GoldMine(32, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_3, "destroy_nav.png");
			SButton build_AV_GoldMine(32, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_3, "build_av.png");
			SButton destroy_AV_GoldMine(32, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_3, "destroy_av.png");
			// FishersHut
			SButton build_NAV_FishersHut(33, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_nav.png");
			SButton destroy_NAV_FishersHut(33, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_FishersHut(33, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_av.png");
			SButton destroy_AV_FishersHut(33, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_av.png");

			// Processing
			// Bakery
			SButton build_NAV_Bakery(34, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_nav.png");
			SButton destroy_NAV_Bakery(34, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_nav.png");
			SButton build_AV_Bakery(34, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_av.png");
			SButton destroy_AV_Bakery(34, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_av.png");
			// OreRafinery
			SButton build_NAV_OreRafinery(35, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_nav.png");
			SButton destroy_NAV_OreRafinery(35, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_nav.png");
			SButton build_AV_OreRafinery(35, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_av.png");
			SButton destroy_AV_OreRafinery(35, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_av.png");
			// GoldSmith
			SButton build_NAV_GoldSmith(36, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_3, "build_nav.png");
			SButton destroy_NAV_GoldSmith(36, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_3, "destroy_nav.png");
			SButton build_AV_GoldSmith(36, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_3, "build_av.png");
			SButton destroy_AV_GoldSmith(36, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_3, "destroy_av.png");
			// ButchersShop
			SButton build_NAV_ButchersShop(37, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_nav.png");
			SButton destroy_NAV_ButchersShop(37, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_ButchersShop(37, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_av.png");
			SButton destroy_AV_ButchersShop(37, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_av.png");
			// RumDistillery
			SButton build_NAV_RumDistillery(38, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_nav.png");
			SButton destroy_NAV_RumDistillery(38, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_RumDistillery(38, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_av.png");
			SButton destroy_AV_RumDistillery(38, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_av.png");
			// Clothiers
			SButton build_NAV_Clothiers(39, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_3, "build_nav.png");
			SButton destroy_NAV_Clothiers(39, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_3, "destroy_nav.png");
			SButton build_AV_Clothiers(39, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_3, "build_av.png");
			SButton destroy_AV_Clothiers(39, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_3, "destroy_av.png");
			// StoneMason
			SButton build_NAV_StoneMason(40, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_nav.png");
			SButton destroy_NAV_StoneMason(40, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_StoneMason(40, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_av.png");
			SButton destroy_AV_StoneMason(40, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_av.png");
			// TobaccoProduction
			SButton build_NAV_TobaccoProduction(41, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_nav.png");
			SButton destroy_NAV_TobaccoProduction(41, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_TobaccoProduction(41, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_av.png");
			SButton destroy_AV_TobaccoProduction(41, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_av.png");
			// WeavingMill
			SButton build_NAV_WeavingMill(42, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_nav.png");
			SButton destroy_NAV_WeavingMill(42, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_nav.png");
			SButton build_AV_WeavingMill(42, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_av.png");
			SButton destroy_AV_WeavingMill(42, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_av.png");
			// WeavingHut
			SButton build_NAV_WeavingHut(43, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_nav.png");
			SButton destroy_NAV_WeavingHut(43, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_WeavingHut(43, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_av.png");
			SButton destroy_AV_WeavingHut(43, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_av.png");
			// ToolSmith
			SButton build_NAV_ToolSmith(44, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_nav.png");
			SButton destroy_NAV_ToolSmith(44, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_nav.png");
			SButton build_AV_ToolSmith(44, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_av.png");
			SButton destroy_AV_ToolSmith(44, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_av.png");
			// WindMill
			SButton build_NAV_WindMill(45, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_nav.png");
			SButton destroy_NAV_WindMill(45, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_nav.png");
			SButton build_AV_WindMill(45, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_av.png");
			SButton destroy_AV_WindMill(45, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_av.png");

			// Industrial
			// Doctor
			SButton build_NAV_Doctor(2, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_nav.png");
			SButton destroy_NAV_Doctor(2, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_nav.png");
			SButton build_AV_Doctor(2, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_av.png");
			SButton destroy_AV_Doctor(2, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_av.png");
			// PublicBath
			SButton build_NAV_PublicBath(3, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_nav.png");
			SButton destroy_NAV_PublicBath(3, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_nav.png");
			SButton build_AV_PublicBath(3, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_av.png");
			SButton destroy_AV_PublicBath(3, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_av.png");
			// FireDepartment
			SButton build_NAV_FireDepartment(4, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_nav.png");
			SButton destroy_NAV_FireDepartment(4, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_FireDepartment(4, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_av.png");
			SButton destroy_AV_FireDepartment(4, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_av.png");
			// University
			SButton build_NAV_University(6, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_nav.png");
			SButton destroy_NAV_University(6, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_nav.png");
			SButton build_AV_University(6, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_av.png");
			SButton destroy_AV_University(6, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_av.png");
			// Chapel
			SButton build_NAV_Chapel(7, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_nav.png");
			SButton destroy_NAV_Chapel(7, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_Chapel(7, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_av.png");
			SButton destroy_AV_Chapel(7, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_av.png");
			// Church
			SButton build_NAV_Church(8, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_nav.png");
			SButton destroy_NAV_Church(8, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_nav.png");
			SButton build_AV_Church(8, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_av.png");
			SButton destroy_AV_Church(8, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_av.png");
			// MarketPlace
			SButton build_NAV_MarketPlace(10, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_nav.png");
			SButton destroy_NAV_MarketPlace(10, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_MarketPlace(10, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_av.png");
			SButton destroy_AV_MarketPlace(10, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_av.png");
			// Palace
			SButton build_NAV_Palace(11, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_nav.png");
			SButton destroy_NAV_Palace(11, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_nav.png");
			SButton build_AV_Palace(11, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_av.png");
			SButton destroy_AV_Palace(11, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_av.png");
			// School
			SButton build_NAV_School(12, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_nav.png");
			SButton destroy_NAV_School(12, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_School(12, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_av.png");
			SButton destroy_AV_School(12, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_av.png");
			// Theatre
			SButton build_NAV_Theatre(13, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_nav.png");
			SButton destroy_NAV_Theatre(13, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_nav.png");
			SButton build_AV_Theatre(13, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_av.png");
			SButton destroy_AV_Theatre(13, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_av.png");
			// Tavern
			SButton build_NAV_Tavern(14, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_nav.png");
			SButton destroy_NAV_Tavern(14, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_Tavern(14, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_av.png");
			SButton destroy_AV_Tavern(14, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_av.png");

			// DOMY
			// Pionerzy
			SButton build_NAV_House_L1(666, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_nav.png");
			SButton destroy_NAV_House_L1(666, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_House_L1(666, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_av.png");
			SButton destroy_AV_House_L1(666, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_av.png");
			// Osadnicy
			SButton build_NAV_House_L2(666, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_nav.png");
			SButton destroy_NAV_House_L2(666, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_House_L2(666, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_av.png");
			SButton destroy_AV_House_L2(666, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_av.png");
			// Mieszczanie
			SButton build_NAV_House_L3(666, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_nav.png");
			SButton destroy_NAV_House_L3(666, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_nav.png");
			SButton build_AV_House_L3(666, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_av.png");
			SButton destroy_AV_House_L3(666, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_av.png");
			// Kupcy
			SButton destroy_NAV_House_L4(666, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_nav.png");
			SButton destroy_AV_House_L4(666, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_av.png");
			// Arystokraci
			SButton destroy_NAV_House_L5(666, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_nav.png");
			SButton destroy_AV_House_L5(666, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_av.png");

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
						gTextTexture.loadFromRenderedText("Czy na pewno chcesz rozpoczac nowa gre?", textC);
						gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, 380);

						new_game_button.setPosition(SCREEN_WIDTH - MAIN_BUTTON_WIDTH - 525, 520);
						new_game_button.render();				new_game_button.handleEvent(&e);

						main_menu_button.setPosition(525, 520);
						main_menu_button.render();				main_menu_button.handleEvent(&e);
						break;
						// Ekran wczytywania stanu gry
					case LOAD:
						gTextTexture.loadFromRenderedText("Wczytaj", textC);
						gTextTexture.render(600, 200);
						main_menu_button.setPosition(624, 660);
						main_menu_button.render();				main_menu_button.handleEvent(&e);
						break;
						// Ekran zapisu stanu gry
					case SAVE:
						gTextTexture.loadFromRenderedText("Zapisz", textC);
						gTextTexture.render(624, 200);
						back_button.setPosition(624, 660);
						back_button.render();					back_button.handleEvent(&e);
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
					gTextTexture.loadFromRenderedText(_itoa(0, Money_char_buffor, 10), textC);
					gTextTexture.render(90, 40);
					// Koszty
					gTextTexture.loadFromRenderedText("0", textC);
					gTextTexture.render(90, 63);
					// Sprzedaz
					gTextTexture.loadFromRenderedText("0", textC);
					gTextTexture.render(90, 90);
					// Kupno
					gTextTexture.loadFromRenderedText("0", textC);
					gTextTexture.render(90, 113);
					// Bilans
					gTextTexture.loadFromRenderedText("0", textC);
					gTextTexture.render(90, 140);
					// Srodki
					gTextTexture.loadFromRenderedText("0", textC);
					gTextTexture.render(90, 170);

					// Ludnosc - wyswietlanie wartosci
					// Pionierzy
					gTextTexture.loadFromRenderedText("0", textC);
					gTextTexture.render(340, 38);
					// Osadnicy
					gTextTexture.loadFromRenderedText("0", textC);
					gTextTexture.render(340, 62);
					// Mieszczanie
					gTextTexture.loadFromRenderedText("0", textC);
					gTextTexture.render(340, 90);
					// Kupcy
					gTextTexture.loadFromRenderedText("0", textC);
					gTextTexture.render(340, 117);
					// Arystokraci
					gTextTexture.loadFromRenderedText("0", textC);
					gTextTexture.render(340, 145);
					// Mieszkancy
					gTextTexture.loadFromRenderedText(_itoa(People_int, People_char_buffor, 10), textC);
					gTextTexture.render(340, 175);
					People_int++;

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

					// UPGRADE
					if (upgrade == false)
					{
						upgrade_NAV_Warehouse.render();
						upgrade_NAV_Warehouse.handleEvent(&e);
					}
					else
					{
						upgrade_AV_Warehouse.render();
						upgrade_AV_Warehouse.handleEvent(&e);
					}
					if (buy == true)
					{
						gTextTexture.loadFromRenderedText("Kup", textC);
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
						gTextTexture.loadFromRenderedText("Sprzedaj", textC);
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

						// Pozwolenie i zakaz budowy
						if (allow_build == true)
						{
							Deny_Build.render();				Deny_Build.handleEvent(&e);
						}
						else
						{
							Allow_Build.render();				Allow_Build.handleEvent(&e);
						}
						// Buduj zburz domy
						// BUILD								DESTROY
						build_AV_House_L1.render();				destroy_AV_House_L1.render();
						build_AV_House_L1.handleEvent(&e);		destroy_AV_House_L1.handleEvent(&e);

						build_NAV_House_L2.render();			destroy_NAV_House_L2.render();
						build_NAV_House_L2.handleEvent(&e);		destroy_NAV_House_L2.handleEvent(&e);

						build_NAV_House_L3.render();			destroy_NAV_House_L3.render();
						build_NAV_House_L3.handleEvent(&e);		destroy_NAV_House_L3.handleEvent(&e);

						/* Kupcy */								destroy_NAV_House_L4.render();
						/*Tych nie budujemy*/					destroy_NAV_House_L4.handleEvent(&e);

						/* Arystokraci */						destroy_NAV_House_L5.render();
						/*Tych nie budujemy*/					destroy_NAV_House_L5.handleEvent(&e);

						break;
						// Ekran rozgrywki - budynki publiczne
					case PUB:
						back_button.setPosition(300, 732);
						back_button.render();					back_button.handleEvent(&e);

						SDL_RenderSetViewport(gRenderer, &RightViewport);
						SDL_RenderCopy(gRenderer, gTexture2, NULL, NULL);

						// Obiekty przyciskow
						// RENDER							//HANDLE_EVENT
						build_NAV_Doctor.render();				build_NAV_Doctor.handleEvent(&e);
						destroy_NAV_Doctor.render();			destroy_NAV_Doctor.handleEvent(&e);

						build_NAV_PublicBath.render();			build_NAV_PublicBath.handleEvent(&e);
						destroy_NAV_PublicBath.render();		destroy_NAV_PublicBath.handleEvent(&e);

						build_NAV_FireDepartment.render();		build_NAV_FireDepartment.handleEvent(&e);
						destroy_NAV_FireDepartment.render();	 destroy_NAV_FireDepartment.handleEvent(&e);

						build_NAV_University.render();			build_NAV_University.handleEvent(&e);
						destroy_NAV_University.render();		destroy_NAV_University.handleEvent(&e);

						build_AV_Chapel.render();				build_AV_Chapel.handleEvent(&e);
						destroy_AV_Chapel.render();				destroy_AV_Chapel.handleEvent(&e);

						build_NAV_Church.render();				build_NAV_Church.handleEvent(&e);
						destroy_NAV_Church.render();			destroy_NAV_Church.handleEvent(&e);

						build_AV_MarketPlace.render();			build_AV_MarketPlace.handleEvent(&e);
						destroy_AV_MarketPlace.render();		destroy_AV_MarketPlace.handleEvent(&e);

						build_NAV_School.render();				build_NAV_School.handleEvent(&e);
						destroy_NAV_School.render();			destroy_NAV_School.handleEvent(&e);

						build_NAV_Theatre.render();				build_NAV_Theatre.handleEvent(&e);
						destroy_NAV_Theatre.render();			destroy_NAV_Theatre.handleEvent(&e);

						build_NAV_Tavern.render();				build_NAV_Tavern.handleEvent(&e);
						destroy_NAV_Tavern.render();			destroy_NAV_Tavern.handleEvent(&e);
						break;
						// Ekran rozgrywki - przetworstwo
					case IND:
						back_button.setPosition(300, 732);
						back_button.render();					back_button.handleEvent(&e);
						SDL_RenderSetViewport(gRenderer, &RightViewport);
						SDL_RenderCopy(gRenderer, gTexture2, NULL, NULL);

						// Obiekty przyciskow
						// RENDER								// HANDLE_EVENT
						build_NAV_Bakery.render();				build_NAV_Bakery.handleEvent(&e);
						destroy_NAV_Bakery.render();			destroy_NAV_Bakery.handleEvent(&e);

						build_NAV_OreRafinery.render();			build_NAV_OreRafinery.handleEvent(&e);
						destroy_NAV_OreRafinery.render();		destroy_NAV_OreRafinery.handleEvent(&e);

						build_NAV_GoldSmith.render();			build_NAV_GoldSmith.handleEvent(&e);
						destroy_NAV_GoldSmith.render();			destroy_NAV_GoldSmith.handleEvent(&e);

						build_NAV_ButchersShop.render();		build_NAV_ButchersShop.handleEvent(&e);
						destroy_NAV_ButchersShop.render();		destroy_NAV_ButchersShop.handleEvent(&e);

						build_NAV_RumDistillery.render();		build_NAV_RumDistillery.handleEvent(&e);
						destroy_NAV_RumDistillery.render();		destroy_NAV_RumDistillery.handleEvent(&e);

						build_NAV_Clothiers.render();			build_NAV_Clothiers.handleEvent(&e);
						destroy_NAV_Clothiers.render();			destroy_NAV_Clothiers.handleEvent(&e);

						build_NAV_StoneMason.render();			build_NAV_StoneMason.handleEvent(&e);
						destroy_NAV_StoneMason.render();		destroy_NAV_StoneMason.handleEvent(&e);

						build_NAV_TobaccoProduction.render();	build_NAV_TobaccoProduction.handleEvent(&e);
						destroy_NAV_TobaccoProduction.render(); destroy_NAV_TobaccoProduction.handleEvent(&e);

						build_NAV_WeavingMill.render();			build_NAV_WeavingMill.handleEvent(&e);
						destroy_NAV_WeavingMill.render();		destroy_NAV_WeavingMill.handleEvent(&e);

						build_AV_WeavingHut.render();			build_AV_WeavingHut.handleEvent(&e);
						destroy_AV_WeavingHut.render();			destroy_AV_WeavingHut.handleEvent(&e);

						build_NAV_ToolSmith.render();			build_NAV_ToolSmith.handleEvent(&e);
						destroy_NAV_ToolSmith.render();			destroy_NAV_ToolSmith.handleEvent(&e);

						build_NAV_WindMill.render();			build_NAV_WindMill.handleEvent(&e);
						destroy_NAV_WindMill.render();			destroy_NAV_WindMill.handleEvent(&e);
						break;
						// Ekran rozgrywki - produkcja
					case PROD:
						back_button.setPosition(300, 732);
						back_button.render();					back_button.handleEvent(&e);
						SDL_RenderSetViewport(gRenderer, &RightViewport);
						SDL_RenderCopy(gRenderer, gTexture2, NULL, NULL);

						//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// WYWALIC
						gTextTexture.loadFromRenderedText(_itoa(chatka_drwala, People_char_buffor, 10), textC);
						gTextTexture.render(53, 228);

						// Obiekty przyciskow
						// RENDER								// HANDLE_EVENT
						build_AV_ForestersLodge.render();		build_AV_ForestersLodge.handleEvent(&e);
						destroy_AV_ForestersLodge.render();		destroy_AV_ForestersLodge.handleEvent(&e);

						build_NAV_CottonPlantation.render();	build_NAV_CottonPlantation.handleEvent(&e);
						destroy_NAV_CottonPlantation.render();	destroy_NAV_CottonPlantation.handleEvent(&e);

						build_NAV_GrainFarm.render();			build_NAV_GrainFarm.handleEvent(&e);
						destroy_NAV_GrainFarm.render();			destroy_NAV_GrainFarm.handleEvent(&e);

						build_NAV_SpiceFarm.render();			build_NAV_SpiceFarm.handleEvent(&e);
						destroy_NAV_SpiceFarm.render();			destroy_NAV_SpiceFarm.handleEvent(&e);

						build_AV_HuntersHut.render();			build_AV_HuntersHut.handleEvent(&e);
						destroy_AV_HuntersHut.render();			destroy_AV_HuntersHut.handleEvent(&e);

						build_NAV_CocoaPlantation.render();		build_NAV_CocoaPlantation.handleEvent(&e);
						destroy_NAV_CocoaPlantation.render();	destroy_NAV_CocoaPlantation.handleEvent(&e);

						build_NAV_CattleFarm.render();			build_NAV_CattleFarm.handleEvent(&e);
						destroy_NAV_CattleFarm.render();		destroy_NAV_CattleFarm.handleEvent(&e);

						build_AV_SheepFarm.render();			build_AV_SheepFarm.handleEvent(&e);
						destroy_AV_SheepFarm.render();			destroy_AV_SheepFarm.handleEvent(&e);

						build_NAV_Winery.render();				build_NAV_Winery.handleEvent(&e);
						destroy_NAV_Winery.render();			destroy_NAV_Winery.handleEvent(&e);
						// RENDER								// HANDLE_EVENT
						build_NAV_TobaccoPlantation.render();	build_NAV_TobaccoPlantation.handleEvent(&e);
						destroy_NAV_TobaccoPlantation.render();	destroy_NAV_TobaccoPlantation.handleEvent(&e);

						build_NAV_SugarcanePlantation.render();	build_NAV_SugarcanePlantation.handleEvent(&e);
						destroy_NAV_SugarcanePlantation.render(); destroy_NAV_SugarcanePlantation.handleEvent(&e);

						build_NAV_IronMine.render();			build_NAV_IronMine.handleEvent(&e);
						destroy_NAV_IronMine.render();			destroy_NAV_IronMine.handleEvent(&e);

						build_NAV_DeepIronMine.render();		build_NAV_DeepIronMine.handleEvent(&e);
						destroy_NAV_DeepIronMine.render();		destroy_NAV_DeepIronMine.handleEvent(&e);

						build_NAV_GoldMine.render();			build_NAV_GoldMine.handleEvent(&e);
						destroy_NAV_GoldMine.render();			destroy_NAV_GoldMine.handleEvent(&e);

						build_AV_FishersHut.render();			build_AV_FishersHut.handleEvent(&e);
						destroy_AV_FishersHut.render();			destroy_AV_FishersHut.handleEvent(&e);
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