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

//House(id, bricksToBuild, toolsToBuild, woodToBuild, inhabitants, peopleToBuild)
House hPioneers(1, 0, 0, 3, 2);
House hSettlers(0, 0, 1, 3, 6);
House hCitizens(0, 6, 2, 2, 15);
House hMerchants(0, 9, 3, 3, 25);
House hAristocrats(0, 12, 3, 3, 40);

//Industrial(id, goldToBuild, bricksToBuild, toolsToBuild, woodToBuild, maintenanceCost, size, peopleToBuild)
Industrial Doctor(2, 450, 9, 4, 4, 30, 4, 50);
Industrial PublicBath(3, 1200, 19, 6, 5, 60, 12, 210);
Industrial FireDepartment(4, 150, 0, 3, 5, 15, 4, 15);
Industrial University(5, 750, 19, 6, 5, 60, 9, 250);
Industrial Chapel(6, 100, 0, 2, 5, 5, 2, 0);
Industrial Cathedral(7, 7500, 70, 25, 25, 90, 24, 2500);
Industrial Church(8, 1600, 25, 7, 7, 50, 12, 150);
Industrial MarketPlace(9, 200, 0, 4, 10, 10, 12, 0);
Industrial Palace(10, 5000, 50, 15, 20, 40, 35, 1500);
Industrial School(11, 450, 9, 4, 4, 30, 4, 100);
Industrial Theatre(12, 1200, 19, 2, 5, 80, 9, 300);
Industrial Tavern(13, 250, 6, 3, 4, 15, 6, 50);

//Production(id, goldToBuild, bricksToBuild, toolsToBuild, woodToBuild, maintenanceActiveCost, maintenancePassiveCost, size, magazineCapacity, peopleToBuild)
Production WarehouseI(14, 100, 0, 3, 6, 15, 15, 6, 30, 0);
Production WarehouseII(15, 180, 0, 3, 7, 15, 15, 6, 50, 30);
Production WarehouseIII(16, 250, 6, 4, 4, 15, 15, 6, 75, 100);
Production WarehouseIV(17, 250, 10, 5, 4, 15, 15, 6, 100, 250);
Production CottonPlantation(18, 200, 6, 2, 3, 25, 10, 26, 9, 200);
Production ForestersLodge(19, 50, 0, 2, 0, 5, 0, 4, 10, 0);
Production GrainFarm(20, 100, 0, 2, 5, 5, 0, 11, 6, 75);
Production SpiceFarm(21, 300, 8, 2, 3, 35, 15, 26, 4, 75);
Production HuntersHut(22, 50, 0, 2, 2, 5, 0, 4, 3, 0);
Production CocoaPlantation(23, 300, 8, 2, 3, 35, 15, 26, 6, 200);
Production CattleFarm(24, 100, 0, 1, 4, 5, 0, 26, 4, 30);
Production SheepFarm(25, 200, 0, 2, 4, 5, 0, 26, 8, 0);
Production Winery(26, 300, 8, 2, 3, 35, 15, 26, 6, 40);
Production TobaccoPlantation(27, 300, 8, 2, 3, 35, 15, 26, 6, 40);
Production SugarcanePlantation(28, 300, 8, 2, 3, 25, 10, 26, 6, 40);
Production IronMine(29, 1000, 5, 10, 20, 60, 20, 3, 4, 120);
Production DeepIronMine(30, 1800, 7, 15, 30, 60, 20, 3, 4, 450);
Production GoldMine(31, 1000, 5, 10, 20, 60, 20, 3, 4, 150);
Production FistersHut(32, 100, 0, 3, 5, 5, 0, 1, 4, 0);

//Processing(id, goldToBuild, bricksToBuild, toolsToBuild, woodToBuild, maintenanceActiveCost, maintenancePassiveCost, magazineCapacity, peopleToBuild)
Processing Bakery(33, 150, 0, 2, 6, 5, 0, 4, 75);
Processing OreRefenery(34, 200, 4, 3, 1, 25, 10, 5, 120);
Processing GoldSmith(35, 1500, 10, 7, 2, 45, 20, 4, 250);
Processing ButchersShop(36, 150, 10, 3, 4, 5, 0, 4, 30);
Processing RumDistillery(37, 200, 5, 3, 2, 25, 7, 4, 40);
Processing Clothiers(38, 150, 2, 3, 6, 10, 5, 4, 200);
Processing StoneMason(39, 100, 0, 5, 5, 5, 0, 8, 15);
Processing TobaccoProduction(40, 200, 5, 3, 2, 20, 10, 4, 40);
Processing WeavingMill(41, 200, 7, 4, 3, 20, 10, 4, 75);
Processing WeavingHut(42, 200, 0, 3, 6, 10, 5, 4, 0);
Processing ToolSmithy(43, 150, 5, 3, 2, 25, 10, 4, 100);
Processing WindMill(44, 100, 0, 3, 6, 5, 0, 6, 75);

//People(tax)
People Pioneers(1);
People Settlers(1);
People Citizens(1);
People Merchants(2);
People Aristocrats(2);

//Resource(id, price)
Resource Money(0, 50000, 1);
Resource IronOre(1, 0, 60);
Resource Gold(2, 0, 465);
Resource Wool(3, 0, 16);
Resource Sugar(4, 0, 19);
Resource Tobacco(5, 0, 23);
Resource Cattle(6, 0, 6);
Resource Grain(7, 0, 3);
Resource Flour(8, 0, 3);
Resource Iron(9, 0, 84);
Resource Food(10, 0, 17);
Resource TobaccoProducts(11, 0, 65);
Resource Spices(12, 0, 40);
Resource Cocoa(13, 0, 33);
Resource Liquor(14, 0, 52);
Resource Cloth(15, 0, 32);
Resource Clothes(16, 0, 130);
Resource Jewelry(17, 0, 590);
Resource Tools(18, 30, 80);
Resource Wood(19, 30, 20);
Resource Bricks(20, 30, 30);

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
	
	Production* tProduction[19];
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

	Processing* tProcessing[12];					// tablica wskaznikow do obiektow Industrial
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
		cout << "[4] - zakoncz program" << endl << endl;
		cout << "Decyzja? ";
		
		int menu, decyzja;
		cin >> menu;
		switch(menu)
		{
		//BUDOWA BUDYNKOW----------------------------------------------------------------------------------------------------------------------------------------------------

			case 1:
				menuBuilding();
				cin >> decyzja;

				if (decyzja >= 0 && decyzja < 12)
					Build(*tIndustrial[decyzja]);

				else if(decyzja >= 12 && decyzja < 31)
					Build(*tProduction[decyzja - 12]);

				else if(decyzja >= 31 && decyzja < 45)
					Build(*tProcessing[decyzja - 31]);

				break;

    	//BURZENIE BUDYNKOW----------------------------------------------------------------------------------------------------------------------------------------------------

			case 2:
				menuBuilding();
				cin >> decyzja;
				switch (decyzja)
				{
					case 0: cout << "\n  Anulowano burzenie."; break;
					case 1: break;
					case 2: Destroy(Doctor); break;
					case 3: Destroy(PublicBath); break;
					case 4: Destroy(FireDepartment); break;
					case 5: Destroy(University); break;
					case 6: Destroy(Chapel); break;
					case 7: Destroy(Cathedral); break;
					case 8: Destroy(Church); break;
					case 9: Destroy(MarketPlace); break;
					case 10: Destroy(Palace); break;
					case 11: Destroy(School); break;
					case 12: Destroy(Theatre); break;
					case 13: Destroy(Tavern); break;
					case 14: Destroy(WarehouseI); break;
					case 15: Destroy(WarehouseII); break;
					case 16: Destroy(WarehouseIII); break;
					case 17: Destroy(WarehouseIV); break;
					case 18: Destroy(CottonPlantation); break;
					case 19: Destroy(ForestersLodge); break;
					case 20: Destroy(GrainFarm); break;
					case 21: Destroy(SpiceFarm); break;
					case 22: Destroy(HuntersHut); break;
					case 23: Destroy(CocoaPlantation); break;
					case 24: Destroy(CattleFarm); break;
					case 25: Destroy(SheepFarm); break;
					case 26: Destroy(Winery); break;
					case 27: Destroy(TobaccoPlantation); break;
					case 28: Destroy(SugarcanePlantation); break;
					case 29: Destroy(IronMine); break;
					case 30: Destroy(DeepIronMine); break;
					case 31: Destroy(GoldMine); break;
					case 32: Destroy(FistersHut); break;
					case 33: Destroy(Bakery); break;
					case 34: Destroy(OreRefenery); break;
					case 35: Destroy(GoldSmith); break;
					case 36: Destroy(ButchersShop); break;
					case 37: Destroy(RumDistillery); break;
					case 38: Destroy(Clothiers); break;
					case 39: Destroy(StoneMason); break;
					case 40: Destroy(TobaccoProduction); break;
					case 41: Destroy(WeavingMill); break;
					case 42: Destroy(WeavingHut); break;
					case 43: Destroy(ToolSmithy); break;
					case 44: Destroy(WindMill); break;
					default: cout << "\n  Podano bledny numer komendy."; break;
				}
				break;

			case 4:
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

	cout << "  Co chcesz zbudowac? ";
}