// ConsoleApplication5.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <ctime>
#include <string>

#include "Objects.h"

using namespace std;

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
	
	Production* tProduction[20];					// tablica wskaznikow do obiektow Production
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
	tProduction[19] = &StoneMason;

	Processing* tProcessing[11];					// tablica wskaznikow do obiektow Processing
	tProcessing[0] = &Bakery;
	tProcessing[1] = &OreRefenery;
	tProcessing[2] = &GoldSmith;
	tProcessing[3] = &ButchersShop;
	tProcessing[4] = &RumDistillery;
	tProcessing[5] = &Clothiers;
	tProcessing[6] = &TobaccoProduction;
	tProcessing[7] = &WeavingMill;
	tProcessing[8] = &WeavingHut;
	tProcessing[9] = &ToolSmithy;
	tProcessing[10] = &WindMill;

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
	
	int menu = 0;				// wybor dzialania z menu
	int decyzja = 0;			// wybor numeru budynku z menu

	while (1)	// petla gry
	{
		// ZLICZANIE CZASU

		system("CLS");
		obecny = clock() / CLOCKS_PER_SEC;
		cout << "Od poczatku programu uplynelo " << obecny << " sekund " << endl;
		cout << "Od ostatniej aktualizacji uplynelo " << obecny - poprzedni << endl << endl;
		poprzedni = obecny;

		// AKTUALIZACJA STANU SUROWCOW

		for (int i = 4; i < 20; ++i)			// nie sprawdzane dla i = 21 czyli bricks
			for (int j = 1; j < 20; ++j)
			{
				if (tProduction[i]->getProductID() == j)
					tResource[j]->increase(tProduction[i]->getNumber());
			}

		for (int i = 0; i < 11; ++i)
			for (int j = 1; j < 21; ++j)
			{
				if (tProcessing[i]->getProductID() == j)
					tResource[j]->increase(tProcessing[i]->getNumber());
			}

		// SPRAWDZENIE WARUNKU DOSTEPNOSCI BUDYNKOW
		
		for (int i = 0; i < 12; ++i)
			for (int j = 0; j < 5; ++j)
			{
				if (tIndustrial[i]->getClass() == j)
				{
					tIndustrial[i]->checkStatus(*tPeople[j]);
					break;
				}
			}

		for (int i = 0; i < 20; ++i)
			for (int j = 0; j < 5; ++j)
			{
				if (tProduction[i]->getClass() == j)
				{
					tProduction[i]->checkStatus(*tPeople[j]);
					break;
				}
			}

		for (int i = 0; i < 11; ++i)
			for (int j = 0; j < 5; ++j)
			{
				if (tProcessing[i]->getClass() == j)
				{
					tProcessing[i]->checkStatus(*tPeople[j]);
					break;
				}
			}

		// MENU (TYMCZASOWE DLA KONSOLI)
		// WYSWIETLANIE STANU SUROWCOW

		cout << "Pieniadze: " << Money.getNumber();
		cout << "   Cegly: " << Bricks.getNumber();
		cout << "   Narzedzia : " << Tools.getNumber();
		cout << "   Drewno : " << Wood.getNumber() << endl << endl;
		
		// PODEJMOWANIE DECYZJI

		cout << "MENU:" << endl;
		cout << "[1] - zbuduj budynek" << endl;
		cout << "[2] - zburz budynek" << endl;
		cout << "[3] - wyswietl stan zabudowy" << endl;
		cout << "[4] - wyswietl parametry budynku" << endl;
		cout << "[5] - wyswietl stan surowcow" << endl;
		cout << "[6] - odswiez" << endl;
		cout << "[0] - zakoncz program" << endl << endl;
		cout << "Decyzja? ";
		
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

				else if (decyzja >= 12 && decyzja < 32)
					Build(*tProduction[decyzja - 12]);

				else if (decyzja >= 32 && decyzja < 43)
					Build(*tProcessing[decyzja - 32]);

				else if (decyzja == 43)
				{
					if (hPioneers.Build(Bricks, Tools, Wood) == false)
						cout << "\n    Nie masz wystarczajacej ilosci surowcow." << endl;
					else
						cout << "\n    Wybudowano budynek." << endl;
				}
				
				break;

    	//BURZENIE BUDYNKOW----------------------------------------------------------------------------------------------------------------------------------------------------

			case 2:
				menuBuilding();
				cout << "  Co chcesz zniszczyc? ";
				cin >> decyzja;
				
				if (decyzja >= 0 && decyzja < 12)
					Destroy(*tIndustrial[decyzja]);

				else if (decyzja >= 12 && decyzja < 32)
					Destroy(*tProduction[decyzja - 12]);

				else if (decyzja >= 32 && decyzja < 43)
					Destroy(*tProcessing[decyzja - 32]);

				else if (decyzja == 43)
					if (hPioneers.Destroy() == true)
						cout << "Zburzono budynek";
					else
						cout << "Nie posiadasz takiego budynku";

				break;
			
		//WYSWIETLANIE STANU ZABUDOWY------------------------------------------------------------------------------------------------------------------------------------------

			case 3:
				menuBuilding();
				cout << "\nIndustrial:\n\n";
				for (int i = 0; i < 12; ++i)
					cout << "[" << i << "]=" << tIndustrial[i]->getNumber() << "\t";
				
				cout << "\n\nProduction:\n\n";
				for (int i = 0; i < 20; ++i)
				{
					cout << "[" << i + 12 << "]=" << tProduction[i]->getNumber() << "\t";
					if (i == 11) cout << endl;
				}

				cout << "\n\nProcessing:\n\n";
				for (int i = 0; i < 11; ++i)
					cout << "[" << i+32 << "]=" << tProcessing[i]->getNumber() << "\t";

				break;
		
		//WYSWIETLANIE PARAMETROW BUDYNKU--------------------------------------------------------------------------------------------------------------------------------------
		
			case 4:
				menuBuilding();
				cout << "  Wybierz budynek ";
				cin >> decyzja;
				cout << endl;

				if (decyzja >= 0 && decyzja < 12)
					tIndustrial[decyzja]->test();

				else if (decyzja >= 12 && decyzja < 32)
					tProduction[decyzja - 12]->test();

				else if (decyzja >= 32 && decyzja < 43)
					tProcessing[decyzja - 32]->test();

				break;

		//WYSWIETLANIE STANU WSZYSTKICH BUDYNKU--------------------------------------------------------------------------------------------------------------------------------
		
			case 5:
				cout << "\n  [0] - pieniadze\t[1] - ruda zelaza\t[2] - zloto" << endl;
				cout << "  [3] - welna\t\t[4] - cukier\t\t[5] - tabaka" << endl;
				cout << "  [6] - bydlo\t\t[7] - zboze\t\t[8] - maka" << endl;
				cout << "  [9] - zelazo\t\t[10] - jedzenie\t\t[11] - cygara" << endl;
				cout << "  [12] - przyprawy\t[13] - kakao\t\t[14] - trunek" << endl;
				cout << "  [15] - plotno\t\t[16] - ubrania\t\t[17] - bizuteria" << endl;
				cout << "  [18] - narzedzia\t[19] - drewno\t\t[20] - cegly" << endl << endl;

				for (int i = 0; i < 21; ++i)
				{
					cout << "\t[" << i << "]=" << tResource[i]->getNumber();
					if (i == 0 || i == 7 || i == 14) cout << endl;
				}
				break;
			
		//ODSWIEZANIE EKRANU
			case 6:
				break;

		//WYJSCIE Z GRY
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
	if(Name.getStatus() == false)
		cout << "\n    Budynek niedostepny." << endl;
	else if (Name.Build(Money, Bricks, Tools, Wood) == false)
		cout << "\n    Nie masz wystarczajacej ilosci surowcow." << endl;
	else
		cout << "\n    Wybudowano budynek." << endl;
}

void Destroy(Industrial & Name)
{
	if(Name.Destroy() == true)
		cout << "\n    Zburzono budynek." << endl;
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
	cout << "  [31] - kamieniarz\t\t";
	cout << "  [32] - piekarnia\t\t";
	cout << "  [33] - kuznia zelaza" << endl;
	cout << "  [34] - jubiler\t\t";
	cout << "  [35] - rzeznik\t\t";
	cout << "  [36] - gorzelnia" << endl;
	cout << "  [37] - sklep odziezowy\t";
	cout << "  [38] - wytwornia prod. tyton\t";
	cout << "  [39] - szwalnia mala" << endl;
	cout << "  [40] - szwalnia duza\t\t";
	cout << "  [41] - wytworca narzedzi\t";
	cout << "  [42] - wiatrak" << endl;
	cout << "  [43] - budynek mieszkalny" << endl << endl;
}

