#ifndef Objects_h
#define Objects_h

#include "House.h"
#include "Industrial.h"
#include "Production.h"
#include "Processing.h"
#include "Resource.h"
#include "People.h"

//House(bricksToBuild, toolsToBuild, woodToBuild, inhabitants)
House hPioneers(0, 0, 3, 2);
//House hSettlers(0, 1, 3, 6);
//House hCitizens(6, 2, 2, 15);
//House hMerchants(9, 3, 3, 25);
//House hAristocrats(12, 3, 3, 40);

//Industrial(goldToBuild, bricksToBuild, toolsToBuild, woodToBuild, maintenanceCost, size, peopleToBuild, peopleClass)
Industrial Doctor(450, 9, 4, 4, 30, 4, 50, 2);
Industrial PublicBath(1200, 19, 6, 5, 60, 12, 210, 2);
Industrial FireDepartment(150, 0, 3, 5, 15, 4, 15, 1);
Industrial University(750, 19, 6, 5, 60, 9, 250, 3);
Industrial Chapel(100, 0, 2, 5, 5, 2, 0, -1);
Industrial Cathedral(7500, 70, 25, 25, 90, 24, 2500, 4);
Industrial Church(1600, 25, 7, 7, 50, 12, 150, 2);
Industrial MarketPlace(200, 0, 4, 10, 10, 12, 0, -1);
Industrial Palace(5000, 50, 15, 20, 40, 35, 1500, 4);
Industrial School(450, 9, 4, 4, 30, 4, 100, 1);
Industrial Theatre(1200, 19, 2, 5, 80, 9, 300, 3);
Industrial Tavern(250, 6, 3, 4, 15, 6, 50, 1);

//Production(goldToBuild, bricksToBuild, toolsToBuild, woodToBuild, maintenanceActiveCost, maintenancePassiveCost, size, magazineCapacity, peopleToBuild, peopleClass, productID)
Production WarehouseI(100, 0, 3, 6, 15, 15, 6, 30, 0, -1, -1);
Production WarehouseII(180, 0, 3, 7, 15, 15, 6, 50, 30, 1, -1);
Production WarehouseIII(250, 6, 4, 4, 15, 15, 6, 75, 100, 2, -1);
Production WarehouseIV(250, 10, 5, 4, 15, 15, 6, 100, 250, 3, -1);
Production CottonPlantation(200, 6, 2, 3, 25, 10, 26, 9, 200, 2, 3);
Production ForestersLodge(50, 0, 2, 0, 5, 0, 4, 10, 0, -1, 19);
Production GrainFarm(100, 0, 2, 5, 5, 0, 11, 6, 75, 1, 7);
Production SpiceFarm(300, 8, 2, 3, 35, 15, 26, 4, 75, 1, 12);
Production HuntersHut(50, 0, 2, 2, 5, 0, 4, 3, 0, -1, 10);
Production CocoaPlantation(300, 8, 2, 3, 35, 15, 26, 6, 200, 2, 13);
Production CattleFarm(100, 0, 1, 4, 5, 0, 26, 4, 30, 0, 6);
Production SheepFarm(200, 0, 2, 4, 5, 0, 26, 8, 0, -1, 3);
Production Winery(300, 8, 2, 3, 35, 15, 26, 6, 40, 1, 14);
Production TobaccoPlantation(300, 8, 2, 3, 35, 15, 26, 6, 40, 1, 5);
Production SugarcanePlantation(300, 8, 2, 3, 25, 10, 26, 6, 40, 1, 4);
Production IronMine(1000, 5, 10, 20, 60, 20, 3, 4, 120, 1, 1);
Production DeepIronMine(1800, 7, 15, 30, 60, 20, 3, 4, 450, 2, 1);
Production GoldMine(1000, 5, 10, 20, 60, 20, 3, 4, 150, 2, 2);
Production FistersHut(100, 0, 3, 5, 5, 0, 1, 4, 0, -1, 10);
Production StoneMason(100, 0, 5, 5, 5, 0, 4, 8, 15, 1, 20);

//Processing(goldToBuild, bricksToBuild, toolsToBuild, woodToBuild, maintenanceActiveCost, maintenancePassiveCost, magazineCapacity, peopleToBuild, peopleClass, productID, materialID)
Processing Bakery(150, 0, 2, 6, 5, 0, 4, 75, 1, 10, 8);
Processing OreRefenery(200, 4, 3, 1, 25, 10, 5, 120, 1, 9, 1);
Processing GoldSmith(1500, 10, 7, 2, 45, 20, 4, 250, 3, 17, 2);
Processing ButchersShop(150, 10, 3, 4, 5, 0, 4, 30, 0, 10, 6);
Processing RumDistillery(200, 5, 3, 2, 25, 7, 4, 40, 1, 14, 4);
Processing Clothiers(150, 2, 3, 6, 10, 5, 4, 200, 2, 16, 15);
Processing TobaccoProduction(200, 5, 3, 2, 20, 10, 4, 40, 1, 11, 5);
Processing WeavingMill(200, 7, 4, 3, 20, 10, 4, 75, 1, 15, 3);
Processing WeavingHut(200, 0, 3, 6, 10, 5, 4, 0, -1, 15, 3);
Processing ToolSmithy(150, 5, 3, 2, 25, 10, 4, 100, 1, 18, 9);
Processing WindMill(100, 0, 3, 6, 5, 0, 6, 75, 1, 10, 7);

//People(tax)
People Pioneers(1);
People Settlers(1);
People Citizens(1);
People Merchants(2);
People Aristocrats(2);

//Resource(quantity, price)
Resource Money(50000, 1);
Resource IronOre(0, 60);
Resource Gold(0, 465);
Resource Wool(0, 16);
Resource Sugar(0, 19);
Resource Tobacco(0, 23);
Resource Cattle(0, 6);
Resource Grain(0, 3);
Resource Flour(0, 3);
Resource Iron(0, 84);
Resource Food(0, 17);
Resource TobaccoProducts(0, 65);
Resource Spices(0, 40);
Resource Cocoa(0, 33);
Resource Liquor(0, 52);
Resource Cloth(0, 32);
Resource Clothes(0, 130);
Resource Jewelry(0, 590);
Resource Tools(30, 80);
Resource Wood(30, 20);
Resource Bricks(30, 30);

#endif