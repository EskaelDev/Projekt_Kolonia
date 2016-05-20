#pragma once
#include "PO_SDL.h"


	// Przyciski menu
	// przycisk(akcja, szerokosc, wysokosc, poz_x, poz_y, nazwa_pliku)
	LButton new_game_button(NEW_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 400, "new.png");
	LButton continue_button(PLAY_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 350, "back.png");
	LButton load_game_button(LOAD_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 480, "load.png");
	LButton save_game_button(SAVE_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 560, "save.png");
	LButton exit_game_button(EXIT_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 660, "exit.png");
	LButton main_menu_button(MAIN_MENU, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 624, 660, "menu.png");
	LButton back_button(PLAY_GAME, MAIN_BUTTON_WIDTH, MAIN_BUTTON_HEIGHT, 300, 730, "back.png");

	// Przyciski splashy
	LButton ind_button(INDUSTRIAL, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 0, 0, "/buildings/ind.png");
	LButton prod_button(PRODUCTION, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 0, 256, "/buildings/prod.png");
	LButton pub_button(PUBLIC, BUILDINGS_BUTTON_WIDTH, BUILDINGS_BUTTON_HEIGHT, 0, 512, "/buildings/pub.png");

	// Przyciski: kup, sprzedaj
	LButton buy_button(BUY, BUY_BUTTON_WIDTH, BUY_BUTTON_HEIGHT, 335, 270, "buy.png");
	LButton sell_button(SELL, BUY_BUTTON_WIDTH, BUY_BUTTON_HEIGHT, 335, 420, "sell.png");

	// Przyciski kupowania zasobow
	// przycisk(id, akcja, szerokosc, wysokosc, poz_x, poz_y, nazwa_pliku)
	LButton buy_iron_ore_button(1, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 244, "/resources/iron_ore.png");
	LButton buy_gold_button(2, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 244, "/resources/gold.png");
	LButton buy_cottom_button(3, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 244, "/resources/cottom.png");
	LButton buy_sugarcane_button(4, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 244, "/resources/sugarcane.png");
	LButton buy_food_button(10, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 244, "/resources/food.png");

	LButton buy_tobacco_button(5, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 318, "/resources/tobacco.png");
	LButton buy_cattle_button(6, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 318, "/resources/cattle.png");
	LButton buy_grain_button(7, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 318, "/resources/grain.png");
	LButton buy_flour_button(8, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 318, "/resources/flour.png");
	LButton buy_alcohol_button(14, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 318, "/resources/alcohol.png");

	LButton buy_spices_button(12, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 387, "/resources/spices.png");
	LButton buy_textiles_button(15, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 387, "/resources/textiles.png");
	LButton buy_clothes_button(16, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 387, "/resources/clothes.png");
	LButton buy_cigarettes_button(11, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 387, "/resources/cigarettes.png");
	LButton buy_jewelry_button(17, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 387, "/resources/jewelry.png");

	LButton buy_tools_button(18, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 456, "/resources/tools.png");
	LButton buy_wood_button(19, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 456, "/resources/wood.png");
	LButton buy_bricks_button(20, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 456, "/resources/bricks.png");
	LButton buy_iron_button(9, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 456, "/resources/iron.png");
	LButton buy_cocoa_button(13, BUY_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 456, "/resources/cocoa.png");

	// Przyciski sprzedazy zasobow
	// przycisk(id, akcja, szerokosc, wysokosc, poz_x, poz_y, nazwa_pliku)
	LButton sell_iron_ore_button(1, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 244, "/resources/iron_ore.png");
	LButton sell_gold_button(2, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 244, "/resources/gold.png");
	LButton sell_cottom_button(3, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 244, "/resources/cottom.png");
	LButton sell_sugarcane_button(4, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 244, "/resources/sugarcane.png");
	LButton sell_food_button(10, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 244, "/resources/food.png");

	LButton sell_tobacco_button(5, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 318, "/resources/tobacco.png");
	LButton sell_cattle_button(6, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 318, "/resources/cattle.png");
	LButton sell_grain_button(7, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 318, "/resources/grain.png");
	LButton sell_flour_button(8, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 318, "/resources/flour.png");
	LButton sell_alcohol_button(14, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 318, "/resources/alcohol.png");

	LButton sell_spices_button(12, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 387, "/resources/spices.png");
	LButton sell_textiles_button(15, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 387, "/resources/textiles.png");
	LButton sell_clothes_button(16, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 387, "/resources/clothes.png");
	LButton sell_cigarettes_button(11, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 387, "/resources/cigarettes.png");
	LButton sell_jewelry_button(17, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 387, "/resources/jewelry.png");

	LButton sell_tools_button(18, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 5, 456, "/resources/tools.png");
	LButton sell_wood_button(19, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 70, 456, "/resources/wood.png");
	LButton sell_bricks_button(20, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 135, 456, "/resources/bricks.png");
	LButton sell_iron_button(9, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 199, 456, "/resources/iron.png");
	LButton sell_cocoa_button(13, SELL_RESOURCE, RESOURCES_BUTTON_WIDTH, RESOURCES_BUTTON_HEIGHT, 263, 456, "/resources/cocoa.png");

	// Przyciski Buduj i Zburz
	// przycisk(id, akcja, szerokosc, wysokosc, poz_x, poz_y, nazwa_pliku)

	// Production
	// CottonPlantation
	LButton build_NAV_CottonPlantation(19, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_3, "build_nav.png");
	LButton destroy_NAV_CottonPlantation(19, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_3, "destroy_nav.png");
	LButton build_AV_CottonPlantation(19, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_3, "build_av.png");
	LButton destroy_AV_CottonPlantation(19, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_3, "destroy_av.png");
	// ForestersLodge
	LButton build_AV_ForestersLodge(20, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_av.png");
	LButton destroy_AV_ForestersLodge(20, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_av.png");
	// GrainFarm
	LButton build_NAV_GrainFarm(21, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_nav.png");
	LButton destroy_NAV_GrainFarm(21, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_GrainFarm(21, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_av.png");
	LButton destroy_AV_GrainFarm(21, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_av.png");
	// SpiceFarm
	LButton build_NAV_SpiceFarm(22, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_nav.png");
	LButton destroy_NAV_SpiceFarm(22, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_SpiceFarm(22, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_av.png");
	LButton destroy_AV_SpiceFarm(22, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_av.png");
	// HuntersHut
	LButton build_NAV_HuntersHut(23, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_nav.png");
	LButton destroy_NAV_HuntersHut(23, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_nav.png");
	LButton build_AV_HuntersHut(23, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_av.png");
	LButton destroy_AV_HuntersHut(23, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_av.png");
	// CocoaPlantation
	LButton build_NAV_CocoaPlantation(24, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_3, "build_nav.png");
	LButton destroy_NAV_CocoaPlantation(24, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_3, "destroy_nav.png");
	LButton build_AV_CocoaPlantation(24, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_3, "build_av.png");
	LButton destroy_AV_CocoaPlantation(24, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_3, "destroy_av.png");
	// CattleFarm
	LButton build_NAV_CattleFarm(25, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_nav.png");
	LButton destroy_NAV_CattleFarm(25, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_nav.png");
	LButton build_AV_CattleFarm(25, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_av.png");
	LButton destroy_AV_CattleFarm(25, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_av.png");
	// SheepFarm
	LButton build_NAV_SheepFarm(26, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_nav.png");
	LButton destroy_NAV_SheepFarm(26, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_nav.png");
	LButton build_AV_SheepFarm(26, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_av.png");
	LButton destroy_AV_SheepFarm(26, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_av.png");
	// Winery
	LButton build_NAV_Winery(27, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_nav.png");
	LButton destroy_NAV_Winery(27, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_Winery(27, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_av.png");
	LButton destroy_AV_Winery(27, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_av.png");
	// TobaccoPlantation
	LButton build_NAV_TobaccoPlantation(28, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_nav.png");
	LButton destroy_NAV_TobaccoPlantation(28, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_TobaccoPlantation(28, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_av.png");
	LButton destroy_AV_TobaccoPlantation(28, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_av.png");
	// SugarcanePlantation
	LButton build_NAV_SugarcanePlantation(29, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_nav.png");
	LButton destroy_NAV_SugarcanePlantation(29, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_SugarcanePlantation(29, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_av.png");
	LButton destroy_AV_SugarcanePlantation(29, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_av.png");
	// IronMine
	LButton build_NAV_IronMine(30, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_3, "build_nav.png");
	LButton destroy_NAV_IronMine(30, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_3, "destroy_nav.png");
	LButton build_AV_IronMine(30, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_3, "build_av.png");
	LButton destroy_AV_IronMine(30, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_3, "destroy_av.png");
	// DeepIronMine
	LButton build_NAV_DeepIronMine(31, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_3, "build_nav.png");
	LButton destroy_NAV_DeepIronMine(31, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_3, "destroy_nav.png");
	LButton build_AV_DeepIronMine(31, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_3, "build_av.png");
	LButton destroy_AV_DeepIronMine(31, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_3, "destroy_av.png");
	// GoldMine
	LButton build_NAV_GoldMine(32, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_3, "build_nav.png");
	LButton destroy_NAV_GoldMine(32, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_3, "destroy_nav.png");
	LButton build_AV_GoldMine(32, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_3, "build_av.png");
	LButton destroy_AV_GoldMine(32, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_3, "destroy_av.png");
	// FishersHut
	LButton build_NAV_FishersHut(33, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_nav.png");
	LButton destroy_NAV_FishersHut(33, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_nav.png");
	LButton build_AV_FishersHut(33, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_av.png");
	LButton destroy_AV_FishersHut(33, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_av.png");

	// Processing
	// Bakery
	LButton build_NAV_Bakery(34, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_nav.png");
	LButton destroy_NAV_Bakery(34, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_Bakery(34, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_av.png");
	LButton destroy_AV_Bakery(34, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_av.png");
	// OreRafinery
	LButton build_NAV_OreRafinery(35, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_nav.png");
	LButton destroy_NAV_OreRafinery(35, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_OreRafinery(35, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_av.png");
	LButton destroy_AV_OreRafinery(35, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_av.png");
	// GoldSmith
	LButton build_NAV_GoldSmith(36, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_3, "build_nav.png");
	LButton destroy_NAV_GoldSmith(36, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_3, "destroy_nav.png");
	LButton build_AV_GoldSmith(36, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_3, "build_av.png");
	LButton destroy_AV_GoldSmith(36, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_3, "destroy_av.png");
	// ButchersShop
	LButton build_NAV_ButchersShop(37, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_nav.png");
	LButton destroy_NAV_ButchersShop(37, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_nav.png");
	LButton build_AV_ButchersShop(37, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_av.png");
	LButton destroy_AV_ButchersShop(37, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_av.png");
	// RumDistillery
	LButton build_NAV_RumDistillery(38, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_nav.png");
	LButton destroy_NAV_RumDistillery(38, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_nav.png");
	LButton build_AV_RumDistillery(38, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_av.png");
	LButton destroy_AV_RumDistillery(38, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_av.png");
	// Clothiers
	LButton build_NAV_Clothiers(39, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_nav.png");
	LButton destroy_NAV_Clothiers(39, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_Clothiers(39, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_av.png");
	LButton destroy_AV_Clothiers(39, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_av.png");
	// StoneMason
	LButton build_NAV_StoneMason(40, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_nav.png");
	LButton destroy_NAV_StoneMason(40, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_nav.png");
	LButton build_AV_StoneMason(40, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_av.png");
	LButton destroy_AV_StoneMason(40, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_av.png");
	// TobaccoProduction
	LButton build_NAV_TobaccoProduction(41, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_nav.png");
	LButton destroy_NAV_TobaccoProduction(41, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_nav.png");
	LButton build_AV_TobaccoProduction(41, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_av.png");
	LButton destroy_AV_TobaccoProduction(41, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_av.png");
	// WeavingMill
	LButton build_NAV_WeavingMill(42, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_nav.png");
	LButton destroy_NAV_WeavingMill(42, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_WeavingMill(42, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_av.png");
	LButton destroy_AV_WeavingMill(42, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_av.png");
	// WeavingHut
	LButton build_NAV_WeavingHut(43, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_nav.png");
	LButton destroy_NAV_WeavingHut(43, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_nav.png");
	LButton build_AV_WeavingHut(43, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_av.png");
	LButton destroy_AV_WeavingHut(43, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_av.png");
	// ToolSmith
	LButton build_NAV_ToolSmith(44, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_nav.png");
	LButton destroy_NAV_ToolSmith(44, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_ToolSmith(44, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_av.png");
	LButton destroy_AV_ToolSmith(44, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_av.png");
	// WindMill
	LButton build_NAV_WindMill(45, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_nav.png");
	LButton destroy_NAV_WindMill(45, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_WindMill(45, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_av.png");
	LButton destroy_AV_WindMill(45, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_av.png");

	// Industrial
	// Doctor
	LButton build_NAV_Doctor(2, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_nav.png");
	LButton destroy_NAV_Doctor(2, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_Doctor(2, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_2, "build_av.png");
	LButton destroy_AV_Doctor(2, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_2, "destroy_av.png");
	// PublicBath
	LButton build_NAV_PublicBath(3, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_nav.png");
	LButton destroy_NAV_PublicBath(3, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_PublicBath(3, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_2, "build_av.png");
	LButton destroy_AV_PublicBath(3, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_2, "destroy_av.png");
	// FireDepartment
	LButton build_NAV_FireDepartment(4, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_nav.png");
	LButton destroy_NAV_FireDepartment(4, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_nav.png");
	LButton build_AV_FireDepartment(4, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_1, "build_av.png");
	LButton destroy_AV_FireDepartment(4, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_1, "destroy_av.png");
	// Gallows pojbalo?
	// University
	LButton build_NAV_University(6, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_nav.png");
	LButton destroy_NAV_University(6, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_University(6, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4, W_2, "build_av.png");
	LButton destroy_AV_University(6, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_4 + R_R, W_2, "destroy_av.png");
	// Chapel
	LButton build_NAV_Chapel(7, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_nav.png");
	LButton destroy_NAV_Chapel(7, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_nav.png");
	LButton build_AV_Chapel(7, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_1, "build_av.png");
	LButton destroy_AV_Chapel(7, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_1, "destroy_av.png");
	// Church
	LButton build_NAV_Church(8, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_nav.png");
	LButton destroy_NAV_Church(8, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_Church(8, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_av.png");
	LButton destroy_AV_Church(8, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_av.png");
	// MarketPlace
	LButton build_NAV_MarketPlace(10, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_nav.png");
	LButton destroy_NAV_MarketPlace(10, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_nav.png");
	LButton build_AV_MarketPlace(10, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1, W_1, "build_av.png");
	LButton destroy_AV_MarketPlace(10, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_1 + R_R, W_1, "destroy_av.png");
	// Palace
	LButton build_NAV_Palace(11, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_nav.png");
	LButton destroy_NAV_Palace(11, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_Palace(11, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2, W_2, "build_av.png");
	LButton destroy_AV_Palace(11, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_2 + R_R, W_2, "destroy_av.png");
	// School
	LButton build_NAV_School(12, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_nav.png");
	LButton destroy_NAV_School(12, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_nav.png");
	LButton build_AV_School(12, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5, W_1, "build_av.png");
	LButton destroy_AV_School(12, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_5 + R_R, W_1, "destroy_av.png");
	// Theatre
	LButton build_NAV_Theatre(13, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_nav.png");
	LButton destroy_NAV_Theatre(13, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_nav.png");
	LButton build_AV_Theatre(13, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_2, "build_av.png");
	LButton destroy_AV_Theatre(13, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_2, "destroy_av.png");
	// Tavern
	LButton build_NAV_Tavern(14, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_nav.png");
	LButton destroy_NAV_Tavern(14, NONE, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_nav.png");
	LButton build_AV_Tavern(14, BUILD, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3, W_1, "build_av.png");
	LButton destroy_AV_Tavern(14, DESTROY, BUILD_BUTTON_WIDTH, BUILD_BUTTON_HEIGHT, C_3 + R_R, W_1, "destroy_av.png");

