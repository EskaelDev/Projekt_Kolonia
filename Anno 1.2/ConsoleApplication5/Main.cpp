// ConsoleApplication5.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <ctime>
#include <string>

#include "Objects.h"

using namespace std;

// FUNKCJE---------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Build(Public &);		// Funkcja do budowy budynkow.
void Destroy(Public &);		// Funkcja do niszczenia budynkow.
void menuBuilding();		// Funkcja wyswietla menu: spis budynkow
void menuResource();		// Funkcja wyswietla menu: spis surowcow

// STALE I ZMIENNE-------------------------------------------------------------------------------------------------------------------------------------------------------------

int menu;						// wybor dzialania z menu
int decision;					// wybor numeru budynku z menu
const int islandSize = 2000;	// liczba dostepnych pol na wyspie
int usedFields = 0;				// wykorzystane pola przez budynki
clock_t present = 0;
clock_t previous = 0;
Building* wskBuilding = 0;		
Production* wskProduction = 0;

// GLOWNY PROGRAM--------------------------------------------------------------------------------------------------------------------------------------------------------------

int _tmain(int argc, _TCHAR* argv[])
{
	House* tHouse[5];
	tHouse[0] = &hPioneers;
	tHouse[1] = &hSettlers;
	tHouse[2] = &hCitizens;
	tHouse[3] = &hMerchants;
	tHouse[4] = &hAristocrats;

	Public* tPublic[12];							// tablica wskaznikow do obiektow Public
	tPublic[0] = &Doctor;
	tPublic[1] = &PublicBath;		
	tPublic[2] = &FireDepartment;	
	tPublic[3] = &University;	
	tPublic[4] = &Chapel;		
	tPublic[5] = &Cathedral;		
	tPublic[6] = &Church;			
	tPublic[7] = &MarketPlace;		
	tPublic[8] = &Palace;
	tPublic[9] = &School;			
	tPublic[10] = &Theatre;			
	tPublic[11] = &Tavern;			
	
	Production* tProduction[16];					// tablica wskaznikow do obiektow Production
	tProduction[0] = &CottonPlantation;
	tProduction[1] = &ForestersLodge;
	tProduction[2] = &GrainFarm;
	tProduction[3] = &SpiceFarm;
	tProduction[4] = &HuntersHut;
	tProduction[5] = &CocoaPlantation;
	tProduction[6] = &CattleFarm;
	tProduction[7] = &SheepFarm;
	tProduction[8] = &Winery;
	tProduction[9] = &TobaccoPlantation;
	tProduction[10] = &SugarcanePlantation;
	tProduction[11] = &IronMine;
	tProduction[12] = &DeepIronMine;
	tProduction[13] = &GoldMine;
	tProduction[14] = &FistersHut;
	tProduction[15] = &StoneMason;

	Processing* tProcessing[11];					
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

	while (1)	// petla gry
	{
		system("CLS");

		// AKTUALIZACJA STANU SUROWCOW
		
		int totalResources = 0;

		for (int k = 1; k < 21; ++k)	// sumowanie liczby surowcow ktore posiada gracz
		{
			totalResources += tResource[k]->getNumber();
		}

			// NAJPIERW ZAPELNIAMY WEWNETRZNE MAGAZYNY BUDYNKOW

		for (int i = 0; i < 15; ++i)
		{
			if (tProduction[i]->getMagazineCapacity() * tProduction[i]->getNumber() > tResource[tProduction[i]->getProductID()]->getNumber())
			{
				tResource[tProduction[i]->getProductID()]->increase(tProduction[i]->getNumber());
				if (tProduction[i]->getMagazineCapacity() * tProduction[i]->getNumber() < tResource[tProduction[i]->getProductID()]->getNumber())
					tResource[tProduction[i]->getProductID()]->decrease(tResource[tProduction[i]->getProductID()]->getNumber() 
					- tProduction[i]->getMagazineCapacity() * tProduction[i]->getNumber());
			}
		}
																 
			

		
		//for (int i = 0; i < 15; ++i)
		//	if (totalResources < WareHouse.getmagazineCapacity())															// jesli w magazynie jest miejsce 
		//	{
		//		tResource[tProduction[i]->getProductID()]->increase(tProduction[i]->getNumber());							// to dodaj dany surowiec
		//		totalResources += tProduction[i]->getNumber();																// aktualizuj sume posiadanych surowcow
		//		if (totalResources > WareHouse.getmagazineCapacity())														// jezeli magazyn zostal przepelniony 
		//			tResource[tProduction[i]->getProductID()]->decrease(totalResources - WareHouse.getmagazineCapacity());	// to odejmij to co sie nie miesci
		//	}

		for (int i = 0; i < 11; ++i)
			for (int j = 0; j < tProcessing[i]->getNumber(); ++j)
				if (totalResources < WareHouse.getmagazineCapacity())
					if (tResource[tProcessing[i]->getMaterialID()]->getNumber() >= tProcessing[i]->getMaterialNumber())
					{
						tResource[tProcessing[i]->getProductID()]->increase(tProcessing[i]->getProductNumber());
						tResource[tProcessing[i]->getMaterialID()]->decrease(tProcessing[i]->getMaterialNumber());
						totalResources += (tProcessing[i]->getProductNumber() - tProcessing[i]->getMaterialNumber());
					}
		
		// AKTUALIZACJA LICZBY MIESZKANCOW

		for (int i = 0; i < 5; ++i)
		{
			if (tHouse[i]->getInhabitants() * tHouse[i]->getNumber() > tPeople[i]->getNumber())
				tPeople[i]->increase(tHouse[i]->getNumber());
			
			if (tHouse[i]->getInhabitants() * tHouse[i]->getNumber() < tPeople[i]->getNumber())
				tPeople[i]->setNumber(tHouse[i]->getInhabitants() * tHouse[i]->getNumber());
		}

		// SPRAWDZENIE WARUNKU DOSTEPNOSCI BUDYNKOW:
			// WYMAGANIA POSIADANIA KONKRETNEJ KLASY LUDNOSCI

		for (int i = 0; i < 12; ++i)
			if (tPublic[i]->getClass() > -1)		
				tPublic[i]->checkStatus(*tPeople[tPublic[i]->getClass()]);

		for (int i = 0; i < 16; ++i)
			if (tProduction[i]->getClass() > -1)
				tProduction[i]->checkStatus(*tPeople[tProduction[i]->getClass()]);

		for (int i = 0; i < 11; ++i)
			if (tProcessing[i]->getClass() > -1)
				tProcessing[i]->checkStatus(*tPeople[tProcessing[i]->getClass()]);

		if (WareHouse.getClass() > -1)
			WareHouse.checkStatus(*tPeople[WareHouse.getClass()]);

			// WYMAGANIA POSIADANIA KONRETNYCH BUDYNKOW 

		for (int i = 1; i < 5; ++i)
			for (int j = 0; j < 3; ++j)
			{
				if (tHouse[i]->getBuildingID(j) > -1)									// dla -1 warunek nie wystepuje
				{ 
					tHouse[i]->checkStatus(*tPublic[tHouse[i]->getBuildingID(j)]);
					if (false == tHouse[i]->getStatus())								// wystarczy, ze nie posiadamy jednego budynku i budowa jest niedostepna
						break;
				}
			}

		// MENU (TYMCZASOWE DLA KONSOLI)

		// ZLICZANIE CZASU

		present = clock() / CLOCKS_PER_SEC;
		cout << "Od poczatku programu uplynelo " << present << " sekund " << endl;
		cout << "Od ostatniej aktualizacji uplynelo " << present - previous << endl << endl;
		cout << "Wykorzystane pola wyspy: " << usedFields << "    Dostepne pola: " << islandSize - usedFields << endl;
		cout << "Pojemnosc magazynu: " << WareHouse.getmagazineCapacity() << "    Dostepne miejsce: " << endl;
		previous = present;

		// WYSWIETLANIE STANU SUROWCOW

		cout << "Pieniadze: " << Money.getNumber();
		cout << "   Cegly: " << Bricks.getNumber();
		cout << "   Narzedzia : " << Tools.getNumber();
		cout << "   Drewno : " << Wood.getNumber() << endl;
		cout << "Pionierzy: " << Pioneers.getNumber();
		cout << "   Osadnicy: " << Settlers.getNumber();
		cout << "   Mieszczanie: " << Citizens.getNumber();
		cout << "   Kupcy: " << Merchants.getNumber();
		cout << "   Arystokraci: " << Aristocrats.getNumber() << endl << endl;

		// PODEJMOWANIE DECYZJI

		cout << "MENU:" << endl;
		cout << "[0] - odswiez" << endl;
		cout << "[1] - zbuduj budynek" << endl;
		cout << "[2] - zburz budynek" << endl;
		cout << "[3] - wyswietl stan zabudowy" << endl;
		cout << "[4] - wyswietl parametry budynku" << endl;
		cout << "[5] - wyswietl stan surowcow" << endl;
		cout << "[6] - kupuj towary" << endl;
		cout << "[7] - sprzedawaj towary" << endl;
		cout << "[8] - zakoncz program" << endl << endl;
		cout << "Decyzja? ";
		
		cin >> menu;
		switch(menu)
		{
		//BUDOWA BUDYNKOW----------------------------------------------------------------------------------------------------------------------------------------------------

			case 1:
				menuBuilding();
				if (0 == WareHouse.getLevel())
					cout << "  [44] - Magazyn" << endl << endl;
				else if (0 < WareHouse.getLevel() < 4)
					cout << "  [44] - Ulepsz magazyn" << endl << endl;
				cout << "  Co chcesz zbudowac? ";
				cin >> decision;

				if (decision >= 0 && decision < 12)
					Build(*tPublic[decision]);

				else if (decision >= 12 && decision < 28)
					Build(*tProduction[decision - 12]);

				else if (decision >= 28 && decision < 39)
					Build(*tProcessing[decision - 32]);

				else if (decision >= 39 && decision < 44)
				{
					if (false == tHouse[decision - 39]->getStatus())
						cout << "\n    Budynek niedostepny." << endl;

					else if (usedFields + tHouse[decision - 39]->getSize() > islandSize)
						cout << "\n    Brakuje dostepnych pol na wyspie." << endl;

					else if (tHouse[decision - 39]->Build(Bricks, Tools, Wood) == false)
						cout << "\n    Nie masz wystarczajacej ilosci surowcow." << endl;

					else
					{
						cout << "\n    Wybudowano budynek." << endl;
						tPeople[decision - 39]->increase(tHouse[decision - 39]->getStartPeople());
						usedFields += tHouse[decision - 39]->getSize();
					}
				}

				else if (44 == decision)
				{
					if (WareHouse.getStatus() == false)
						cout << "\n    Budynek niedostepny." << endl;

					else if (usedFields + WareHouse.getSize() > islandSize)
						cout << "\n    Brakuje dostepnych pol na wyspie." << endl;

					else if (WareHouse.Build(Money, Bricks, Tools, Wood) == true)
					{
						cout << "\n    Wybudowano budynek." << endl;
						if(1 == WareHouse.getLevel())
							usedFields += WareHouse.getSize();
					}

					else
						cout << "\n    Nie masz wystarczajacej ilosci surowcow." << endl;
				}

				break;

    	//BURZENIE BUDYNKOW----------------------------------------------------------------------------------------------------------------------------------------------------

			case 2:
				menuBuilding();
				cout << "\n  Co chcesz zniszczyc? ";
				cin >> decision;
				
				if (decision >= 0 && decision < 12)
					Destroy(*tPublic[decision]);

				else if (decision >= 12 && decision < 28)
					Destroy(*tProduction[decision - 12]);

				else if (decision >= 28 && decision < 39)
					Destroy(*tProcessing[decision - 32]);

				else if (decision >= 39 && decision < 44)
				{
					if (tHouse[decision - 39]->Destroy() == true)
					{
						cout << "\n    Zburzono budynek";
						usedFields -= tHouse[decision - 39]->getSize();
					}
					else
						cout << "\n    Nie posiadasz takiego budynku";
				}

				break;
			
		//WYSWIETLANIE STANU ZABUDOWY------------------------------------------------------------------------------------------------------------------------------------------

			case 3:
				menuBuilding();
				cout << "  [44] - Magazyn" << endl;
				cout << "\nPublic:\n\n";
				for (int i = 0; i < 12; ++i)
					cout << "[" << i << "]=" << tPublic[i]->getNumber() << "\t";
				
				cout << "\n\nProduction:\n\n";
				for (int i = 0; i < 16; ++i)
				{
					cout << "[" << i + 12 << "]=" << tProduction[i]->getNumber() << "\t";
					if (i == 11) cout << endl;
				}

				cout << "\n\nProcessing:\n\n";
				for (int i = 0; i < 11; ++i)
					cout << "[" << i + 28 << "]=" << tProcessing[i]->getNumber() << "\t";

				cout << "\n\nHouse:\n\n";
				for (int i = 0; i < 5; ++i)
					cout << "[" << i + 39 << "]=" << tHouse[i]->getNumber() << "\t";

				cout << "[44]=" << WareHouse.getLevel() << " poziom" << endl;

				break;
		
		//WYSWIETLANIE PARAMETROW BUDYNKU--------------------------------------------------------------------------------------------------------------------------------------
		
			case 4:
				menuBuilding();
				cout << "  [44] - Magazyn" << endl << endl;
				cout << "  Wybierz budynek ";
				cin >> decision;
				cout << endl;

				if (decision >= 0 && decision < 12)
					tPublic[decision]->test();

				else if (decision >= 12 && decision < 28)
					tProduction[decision - 12]->test();

				else if (decision >= 28 && decision < 39)
					tProcessing[decision - 28]->test();

				else if (decision >= 39 && decision < 44)
					tHouse[decision - 39]->test();

				else if (44 == decision)
					WareHouse.test();

				break;

		//WYSWIETLANIE STANU WSZYSTKICH SUROWCOW------------------------------------------------------------------------------------------------------------------------------
		
			case 5:
				menuResource();

				for (int i = 0; i < 21; ++i)
				{
					cout << "\t[" << i << "]=" << tResource[i]->getNumber();
					if (i == 0 || i == 7 || i == 14) cout << endl;
				}
				break;

		//KUPOWANIE TOWAROW--------------------------------------------------------------------------------------------------------------------------------------------------

			case 6:
				menuResource();
				cout << "  Ktory towar chcesz kupic? ";
				cin >> decision;
				tResource[decision]->buy(Money);
				break;

		//SPRZEDAWANIE TOWAROW-----------------------------------------------------------------------------------------------------------------------------------------------

			case 7:
				menuResource();
				cout << "  Ktory towar chcesz sprzedac? ";
				cin >> decision;
				tResource[decision]->sell(Money);
				break;

		//WYJSCIE Z GRY
			case 8:
				exit(1);
				break;
			
		//ODSWIEZANIE EKRANU
			case 0:
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

void Build(Public & Name)
{
	if (Name.getStatus() == false)
		cout << "\n    Budynek niedostepny." << endl;
	
	else if (usedFields + Name.getSize() > islandSize)
		cout << "\n    Brakuje dostepnych pol na wyspie." << endl;
	
	else if (Name.Build(Money, Bricks, Tools, Wood) == false)
		cout << "\n    Nie masz wystarczajacej ilosci surowcow." << endl;
	
	else
	{
		cout << "\n    Wybudowano budynek." << endl;
		usedFields += Name.getSize();
	}
}

void Destroy(Public & Name)
{
	if (Name.Destroy() == true)
	{
		cout << "\n    Zburzono budynek." << endl;
		usedFields -= Name.getSize();
	}

	else
		cout << "\n    Nie posiadasz takiego budynku." << endl;
}

void menuBuilding() 
{
	cout << "\n  MENU BUDYNEK:" << endl;
	cout << "  [0] - przychodnia lekarska\t";
	cout << "  [1] - laznia publiczna\t";
	cout << "  [2] - straz ogniowa" << endl;
	cout << "  [3] - uniwersytet\t\t";
	cout << "  [4] - kaplica\t\t\t";
	cout << "  [5] - katedra" << endl;
	cout << "  [6] - kosciol\t\t\t";
	cout << "  [7] - plac targowy\t\t";
	cout << "  [8] - palac" << endl;
	cout << "  [9] - szkola\t\t\t";
	cout << "  [10] - teatr\t\t\t";
	cout << "  [11] - tawerna" << endl;
	cout << "  [12] - plantacja bawelny\t";
	cout << "  [13] - chata drwala" << endl;
	cout << "  [14] - plantacja zboza\t";
	cout << "  [15] - plantacja przypraw\t";
	cout << "  [16] - domek mysliwski" << endl;
	cout << "  [17] - plantacja koki\t\t";
	cout << "  [18] - farma krow\t\t";
	cout << "  [19] - farma owiec" << endl;
	cout << "  [20] - winiarnia\t\t";
	cout << "  [21] - plantacja tytoniu\t";
	cout << "  [22] - plantacja trzciny cukr." << endl;
	cout << "  [23] - kopalnia zelaza\t";
	cout << "  [24] - gleboka kopalnia zelaza";
	cout << "  [25] - kopalnia zlota" << endl;
	cout << "  [26] - chatka rybacka\t\t";
	cout << "  [27] - kamieniarz\t\t"; 
	cout << "  [28] - piekarnia" << endl;
	cout << "  [29] - kuznia zelaza\t\t";
	cout << "  [30] - jubiler\t\t";
	cout << "  [31] - rzeznik" << endl;
	cout << "  [32] - gorzelnia\t\t";
	cout << "  [33] - sklep odziezowy\t";
	cout << "  [34] - wytwornia prod. tyton" << endl;
	cout << "  [35] - szwalnia duza\t\t";
	cout << "  [36] - szwalnia mala\t\t";
	cout << "  [37] - wytworca narzedzi" << endl;
	cout << "  [38] - wiatrak\t\t";
	cout << "  [39] - dom Pionierow\t\t";
	cout << "  [40] - dom Osadnikow" << endl;
	cout << "  [41] - dom Mieszczan\t\t";
	cout << "  [42] - dom Kupcow\t\t";
	cout << "  [43] - dom Arytokratow" << endl;
}

void menuResource()
{
	cout << "\n  [0] - pieniadze\t[1] - ruda zelaza\t[2] - zloto" << endl;
	cout << "  [3] - welna\t\t[4] - cukier\t\t[5] - tabaka" << endl;
	cout << "  [6] - bydlo\t\t[7] - zboze\t\t[8] - maka" << endl;
	cout << "  [9] - zelazo\t\t[10] - jedzenie\t\t[11] - cygara" << endl;
	cout << "  [12] - przyprawy\t[13] - kakao\t\t[14] - trunek" << endl;
	cout << "  [15] - plotno\t\t[16] - ubrania\t\t[17] - bizuteria" << endl;
	cout << "  [18] - narzedzia\t[19] - drewno\t\t[20] - cegly" << endl << endl;
}