// ConsoleApplication5.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <ctime>
#include <string>

#include "Building.h"
#include "House.h"
#include "Industrial.h"
#include "Production.h"
#include "Processing.h"
#include "Resource.h"
#include "People.h"

using namespace std;

// TWORZENIE OBIEKTOW-------------------------------------------------------------------------------------------------------------------------------------------------------

//House(bricksToBuild, toolsToBuild, woodToBuild, inhabitants)
House hPioneers(0, 0, 3, 2);
House hSettlers(0, 1, 3, 6);
House hCitizens(6, 2, 2, 15);
House hMerchants(9, 3, 3, 25);
House hAristocrats(12, 3, 3, 40);

//Industrial(goldToBuild, bricksToBuild, toolsToBuild, woodToBuild, maintenanceCost, size, peopleToBuild, peopleClass)
Industrial Doctor(450, 9, 4, 4, 30, 4, 50, 3);
Industrial PublicBath(1200, 19, 6, 5, 60, 12, 210, 3);
Industrial FireDepartment(150, 0, 3, 5, 15, 4, 15, 2);
Industrial University(750, 19, 6, 5, 60, 9, 250, 4);
Industrial Chapel(100, 0, 2, 5, 5, 2, 0, 0);
Industrial Cathedral(7500, 70, 25, 25, 90, 24, 2500, 5);
Industrial Church(1600, 25, 7, 7, 50, 12, 150, 3);
Industrial MarketPlace(200, 0, 4, 10, 10, 12, 0, 0);
Industrial Palace(5000, 50, 15, 20, 40, 35, 1500, 5);
Industrial School(450, 9, 4, 4, 30, 4, 100, 2);
Industrial Theatre(1200, 19, 2, 5, 80, 9, 300, 4);
Industrial Tavern(250, 6, 3, 4, 15, 6, 50, 2);

//Production(goldToBuild, bricksToBuild, toolsToBuild, woodToBuild, maintenanceActiveCost, maintenancePassiveCost, size, magazineCapacity, peopleToBuild, peopleClass)
Production WarehouseI(100, 0, 3, 6, 15, 15, 6, 30, 0, 0);
Production WarehouseII(180, 0, 3, 7, 15, 15, 6, 50, 30, 2);
Production WarehouseIII(250, 6, 4, 4, 15, 15, 6, 75, 100, 3);
Production WarehouseIV(250, 10, 5, 4, 15, 15, 6, 100, 250, 4);
Production CottonPlantation(200, 6, 2, 3, 25, 10, 26, 9, 200, 3);
Production ForestersLodge(50, 0, 2, 0, 5, 0, 4, 10, 0, 0);
Production GrainFarm(100, 0, 2, 5, 5, 0, 11, 6, 75, 2);
Production SpiceFarm(300, 8, 2, 3, 35, 15, 26, 4, 75, 2);
Production HuntersHut(50, 0, 2, 2, 5, 0, 4, 3, 0, 0);
Production CocoaPlantation(300, 8, 2, 3, 35, 15, 26, 6, 200, 3);
Production CattleFarm(100, 0, 1, 4, 5, 0, 26, 4, 30, 1);
Production SheepFarm(200, 0, 2, 4, 5, 0, 26, 8, 0, 0);
Production Winery(300, 8, 2, 3, 35, 15, 26, 6, 40, 2);
Production TobaccoPlantation(300, 8, 2, 3, 35, 15, 26, 6, 40, 2);
Production SugarcanePlantation(300, 8, 2, 3, 25, 10, 26, 6, 40, 2);
Production IronMine(1000, 5, 10, 20, 60, 20, 3, 4, 120, 2);
Production DeepIronMine(1800, 7, 15, 30, 60, 20, 3, 4, 450, 3);
Production GoldMine(1000, 5, 10, 20, 60, 20, 3, 4, 150, 3);
Production FistersHut(100, 0, 3, 5, 5, 0, 1, 4, 0, 0);

//Processing(goldToBuild, bricksToBuild, toolsToBuild, woodToBuild, maintenanceActiveCost, maintenancePassiveCost, magazineCapacity, peopleToBuild, peopleClass)
Processing Bakery(150, 0, 2, 6, 5, 0, 4, 75, 2);
Processing OreRefenery(200, 4, 3, 1, 25, 10, 5, 120, 2);
Processing GoldSmith(1500, 10, 7, 2, 45, 20, 4, 250, 4);
Processing ButchersShop(150, 10, 3, 4, 5, 0, 4, 30, 1);
Processing RumDistillery(200, 5, 3, 2, 25, 7, 4, 40, 2);
Processing Clothiers(150, 2, 3, 6, 10, 5, 4, 200, 3);
Processing StoneMason(100, 0, 5, 5, 5, 0, 8, 15, 2);
Processing TobaccoProduction(200, 5, 3, 2, 20, 10, 4, 40, 2);
Processing WeavingMill(200, 7, 4, 3, 20, 10, 4, 75, 2);
Processing WeavingHut(200, 0, 3, 6, 10, 5, 4, 0, 0);
Processing ToolSmithy(150, 5, 3, 2, 25, 10, 4, 100, 2);
Processing WindMill(100, 0, 3, 6, 5, 0, 6, 75, 2);

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

// FUNKCJE---------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Build(Industrial &);		// Funkcja do budowy budynkow.
void Destroy(Industrial &);		// Funkcja do niszczenia budynkow.
void menuBuilding();			// Funkcja wyswietla menu: spis budynkow

// GLOWNY PROGRAM--------------------------------------------------------------------------------------------------------------------------------------------------------------

int _tmain(int argc, _TCHAR* argv[])
{
	Industrial* tIndustrial[12];					// tablica wskaznikow do obiektow Industrial
	tIndustrial[0] = &Doctor;
	tIndustrial[1] = &PublicBath;
	tIndustrial[2] = &FireDepartment;
	tIndustrial[3] = &University;
	tIndustrial[4] = &Chapel;
	tIndustrial[5] = &Cathedral;
	tIndustrial[6] = &Church;
	tIndustrial[7] = &MarketPlace;
	tIndustrial[8] = &Palace;
	tIndustrial[9] = &School;
	tIndustrial[10] = &Theatre;
	tIndustrial[11] = &Tavern;
	
	Production* tProduction[19];					// tablica wskaznikow do obiektow Production
	tProduction[0] = &WarehouseI;
	tProduction[1] = &WarehouseII;
	tProduction[2] = &WarehouseIII;
	tProduction[3] = &WarehouseIV;
	tProduction[4] = &CottonPlantation;
	tProduction[5] = &ForestersLodge;
	tProduction[6] = &GrainFarm;
	tProduction[7] = &SpiceFarm;
	tProduction[8] = &HuntersHut;
	tProduction[9] = &CocoaPlantation;
	tProduction[10] = &CattleFarm;
	tProduction[11] = &SheepFarm;
	tProduction[12] = &Winery;
	tProduction[13] = &TobaccoPlantation;
	tProduction[14] = &SugarcanePlantation;
	tProduction[15] = &IronMine;
	tProduction[16] = &DeepIronMine;
	tProduction[17] = &GoldMine;
	tProduction[18] = &FistersHut;

	Processing* tProcessing[12];					// tablica wskaznikow do obiektow Processing
	tProcessing[0] = &Bakery;
	tProcessing[1] = &OreRefenery;
	tProcessing[2] = &GoldSmith;
	tProcessing[3] = &ButchersShop;
	tProcessing[4] = &RumDistillery;
	tProcessing[5] = &Clothiers;
	tProcessing[6] = &StoneMason;
	tProcessing[7] = &TobaccoProduction;
	tProcessing[8] = &WeavingMill;
	tProcessing[9] = &WeavingHut;
	tProcessing[10] = &ToolSmithy;
	tProcessing[11] = &WindMill;

	People* tPeople[5];
	tPeople[0] = &Pioneers;
	tPeople[1] = &Settlers;
	tPeople[2] = &Citizens;
	tPeople[3] = &Merchants;
	tPeople[4] = &Aristocrats;

	Resource* tResource[21];
	tResource[0] = &Money;
	tResource[1] = &IronOre;
	tResource[2] = &Gold;
	tResource[3] = &Wool;
	tResource[4] = &Sugar;
	tResource[5] = &Tobacco;
	tResource[6] = &Cattle;
	tResource[7] = &Grain;
	tResource[8] = &Flour;
	tResource[9] = &Iron;
	tResource[10] = &Food;
	tResource[11] = &TobaccoProducts;
	tResource[12] = &Spices;
	tResource[13] = &Cocoa;
	tResource[14] = &Liquor;
	tResource[15] = &Cloth;
	tResource[16] = &Clothes;
	tResource[17] = &Jewelry;
	tResource[18] = &Tools;
	tResource[19] = &Wood;
	tResource[20] = &Bricks;

	clock_t obecny = 0;
	clock_t poprzedni = 0;

	while (1)	// petla gry
	{
		// ZLICZANIE CZASU

		system("CLS");
		obecny = clock() / CLOCKS_PER_SEC;
		cout << "Od poczatku programu uplynelo " << obecny << " sekund " << endl;
		cout << "Od ostatniej aktualizacji uplynelo " << obecny - poprzedni << endl << endl;
		poprzedni = obecny;

		// AKTUALIZACJA STANU SUROWCOW


		// MENU (TYMCZASOWE DLA KONSOLI)
		// WYSWIETLANIE STANU SUROWCOW

		cout << "Pieniadze: " << Money.get();
		cout << "   Cegly: " << Bricks.get();
		cout << "   Narzedzia : " << Tools.get();
		cout << "   Drewno : " << Wood.get() << endl << endl;
		
		// PODEJMOWANIE DECYZJI

		cout << "MENU:" << endl;
		cout << "[1] - zbuduj budynek" << endl;
		cout << "[2] - zburz budynek" << endl;
		cout << "[3] - wyswietl stan zabudowy" << endl;
		cout << "[4] - wyswietl parametry budynku" << endl;
		cout << "[0] - zakoncz program" << endl << endl;
		cout << "Decyzja? ";
		
		int menu, decyzja;
		cin >> menu;
		switch(menu)
		{
		//BUDOWA BUDYNKOW----------------------------------------------------------------------------------------------------------------------------------------------------

			case 1:
				menuBuilding();
				cout << "  Co chcesz zbudowac? ";
				cin >> decyzja;

				if (decyzja >= 0 && decyzja < 12)
					Build(*tIndustrial[decyzja]);

				else if(decyzja >= 12 && decyzja < 31)
					Build(*tProduction[decyzja - 12]);

				else if(decyzja >= 31 && decyzja < 43)
					Build(*tProcessing[decyzja - 31]);

				break;

    	//BURZENIE BUDYNKOW----------------------------------------------------------------------------------------------------------------------------------------------------

			case 2:
				menuBuilding();
				cout << "  Co chcesz zbudowac? ";
				cin >> decyzja;
				
				if (decyzja >= 0 && decyzja < 12)
					Destroy(*tIndustrial[decyzja]);

				else if (decyzja >= 12 && decyzja < 31)
					Destroy(*tProduction[decyzja - 12]);

				else if (decyzja >= 31 && decyzja < 43)
					Destroy(*tProcessing[decyzja - 31]);

				break;
			
		//WYSWIETLANIE STANU ZABUDOWY------------------------------------------------------------------------------------------------------------------------------------------

			case 3:
				menuBuilding();
				cout << "\n\nIndustrial: ";
				for (int i = 0; i < 12; ++i)
					cout << i << "-" << tIndustrial[i]->getNumber() << "  ";
				
				cout << "\nProduction: ";
				for (int i = 0; i < 19; ++i)
					cout << i+12 << "-" << tProduction[i]->getNumber() << "  ";

				cout << "\nProcessing: ";
				for (int i = 0; i < 12; ++i)
					cout << i+31 << "-" << tProcessing[i]->getNumber() << "  ";

				break;
		
		//WYSWIETLANIE PARAMETROW BUDYNKU--------------------------------------------------------------------------------------------------------------------------------------
			case 4:
				menuBuilding();
				cout << "  Wybierz budynek ";
				cin >> decyzja;
				cout << endl;

				if (decyzja >= 0 && decyzja < 12)
					tIndustrial[decyzja]->test();

				else if (decyzja >= 12 && decyzja < 31)
					tProduction[decyzja - 12]->test();

				else if (decyzja >= 31 && decyzja < 43)
					tProcessing[decyzja - 31]->test();

				break;

			case 0:
				exit(1);
				break;
			
			default:
				cout << "\n  Podano bledny numer komendy.";
				break;
		}

		_getch();
	}

	_getch();
	return 0;
}

void Build(Industrial & Name)
{
	if (Name.checkRequirements(Money.get(), Bricks.get(), Tools.get(), Wood.get()) == -1)
		cout << "\n    Budynek niedostepny." << endl;
	else if (Name.checkRequirements(Money.get(), Bricks.get(), Tools.get(), Wood.get()) == 0)
		cout << "\n    Nie masz wystarczajacej ilosci surowcow." << endl;
	else
	{
		cout << "\n    Wybudowano budynek." << endl;
		Name.Build(Money, Bricks, Tools, Wood);
	}
}

void Destroy(Industrial & Name)
{
	if (Name.getNumber() > 0)
	{
		cout << "\n    Zburzono budynek." << endl;
		Name.Destroy();
	}
	else
		cout << "\n    Nie posiadasz takiego budynku." << endl;
}

void menuBuilding()
{
	cout << "\n  MENU BUDYNEK:" << endl;
	cout << "  [0] - przychodnia lekarska" << endl;
	cout << "  [1] - laznia publiczna\t";
	cout << "  [2] - straz ogniowa\t\t";
	cout << "  [3] - uniwersytet" << endl;
	cout << "  [4] - kaplica\t\t\t";
	cout << "  [5] - katedra\t\t\t";
	cout << "  [6] - kosciol" << endl;
	cout << "  [7] - plac targowy\t\t";
	cout << "  [8] - palac\t\t\t";
	cout << "  [9] - szkola" << endl;
	cout << "  [10] - teatr\t\t\t";
	cout << "  [11] - tawerna\t\t";
	cout << "  [12] - magazyn I" << endl;
	cout << "  [13] - magazyn II\t\t";
	cout << "  [14] - magazyn III\t\t";
	cout << "  [15] - magazyn IV" << endl;
	cout << "  [16] - plantacja bawelny\t";
	cout << "  [17] - chata drwala\t\t";
	cout << "  [18] - plantacja zboza" << endl;
	cout << "  [19] - plantacja przypraw\t";
	cout << "  [20] - domek mysliwski\t";
	cout << "  [21] - plantacja koki" << endl;
	cout << "  [22] - farma krow\t\t";
	cout << "  [23] - farma owiec\t\t";
	cout << "  [24] - winiarnia" << endl;
	cout << "  [25] - plantacja tytoniu\t";
	cout << "  [26] - plantacja trzciny cukr.";
	cout << "  [27] - kopalnia zelaza" << endl;
	cout << "  [28] - gleboka kopalnia zelaza";
	cout << "  [29] - kopalnia zlota\t\t";
	cout << "  [30] - chatka rybacka" << endl;
	cout << "  [31] - piekarnia\t\t";
	cout << "  [32] - kuznia zelaza\t\t";
	cout << "  [33] - jubiler" << endl;
	cout << "  [34] - rzeznik\t\t";
	cout << "  [35] - gorzelnia\t\t";
	cout << "  [36] - sklep odziezowy" << endl;
	cout << "  [37] - kamieniarz\t\t";
	cout << "  [38] - wytwornia prod. tyton\t";
	cout << "  [39] - szwalnia mala" << endl;
	cout << "  [40] - szwalnia duza\t\t";
	cout << "  [41] - wytworca narzedzi\t";
	cout << "  [42] - wiatrak" << endl << endl;
}