//Dziennik uwag do rozwiazan zastosowanych w kodzie zrodlowym programu:

/*
05.26 16:20
Przez przekazanie do funkcji obiektu typu klasa zdefiniowana przez developera i wywolanie do niej metody latwiej wskazac innym programista, ktorzy w przyszlosci moga rozwijac kod zrodlowy 
programu, co nalezy przekazac do funkcji jako argument, niz funkcja przyjmuja typ int, ktory moze byc dowolna liczba, ktora przekazana do funkcji moze nie miec kompletnie zadnego sensu.
Przekazanie referencji do danej klasy zapewnia, ze przekazemy wylacznie zdefiniowane przez developera wczesniej wartosci.

Dr Polomski twierdzi, ze developer rozwijajacy taki kod moze sie zastanawiac, czy metoda ktory przyjmuje referencje do obiektu klasy moze nie pobierac innych pol ale wydaje mi sie, ze to
slabszy argument, niz w/w, wiec na razie zostawiam tak jak mam.
*/


/*
05.26 16:45
Dla uproszczenia pisania kodu zrodlowego i wykorzystania wszystkich dostepnych surowcow i budynkow publicznych wprowadzam wymagania do budowania budynkow dla mieszkancow. W przypadku 
budynkow publicznych wystarczy posiadanie jednego budynku aby umozliwic budowe budynku mieszkalnego, przy czym budynek dla Pioneerow nie wymaga zadnego budynku pulicznego:

	Settlers - chapel, market place
	Citizens - school, doctor, tavern
	Merchants - church, public bath, fire department
	Aristocratz - theatre, university, cathedral

Aby do naszej wyspy wprowadzali sie kolejni mieszancy nalezy ciagle zaspokajac ich potrzeby, ktore wzrastaja wraz z poziomem spolecznym. Mieszkancy wymagaja glownie surowcow przetworzonych, 
tj. pochodzacych z budynkow typu Processing. Np. nikomu nie jest porzebna maka ale kazdy potrzebuje jedzenia wytwarzanego z maki. Kazda kolejna klasa spoleczna wymaga wlasnych surowcow oraz 
wszystkich nizszych klas do zaspokojenia potrzeb.

	Pionners - food
	Settlers - cloth, sugar
	Citizens - liquor, spices
	Merchants - cocoa, tobacco products
	Aristocratz - jeverly, clothes

Planuje sie, ze jeden mieszkaniec bedzie pobieral niewielka liczbe surowca np. typu float 0.1 co dana jednostke czasu np. 5 sek, jezeli po 5 sek suma potrzeb wszystkich posiadanych przez
gracza mieszkancow bedzie mniejsza niz jeden to suma ta nie zostanie odjeta od stanu surowca wyswietlanego dla gracza ale zostanie zapamietana i po kolejnych 5 sek dodana do sumy potrzeb. 
Przy kolejnym wyswietlaniu jezeli bedzie wieksza od jeden, to na ekranie dostepnym dla gracza stan surowcow zmaleje o 1 jednostke, jesli ponownie zapisujemy i dodajemy przy kolejnej 
aktualizacji stanu surowcow.
*/


/*
05.26 17:58
Zmieniono organizacje dziedziczenia klas. Dodano klase Magazine. Do tej pory budynek Warehouse byl reprezentowany przez obiekt typu Industrial. Klasa Magazine nie bedzie posiadala kilku 
metod i pol z klasy Industrial, bedzie natomist miala kilka innych pol i metod wlasnych dodatkowo. Wymagana jest równie¿ reorganiazcja klasy Building i People.
*/


/*
05.26 18:43
Potrzeba stworzenia klasy Magazine zainicjowala stworzenie klasy Public bedacej lacznikiem miedzy klasa Industrial a klasa Production. Klasa Magazine rowinez wywodzi sie z klasy Industrial
ale z innej galezi, niz klasa Producton.
*/


/*
05.26 22:43
Konieczne jest ustalenie priorytetu w momencie nadprodukcji surowcow i zapelnienia magazynu, ktore produkty maja w pierwszej kolejnosci zapelniac magazyn.
*/


/*
05.27 23:31
Dokonano zmiany wymagan klasy ludnosci wymaganej do budowy budynku Cathedral z Aristocrats na Merchants, tak aby budynek Cathedral mogl byc warunkiem budowy budynku dla Aristocrats.
Aby wybudowac Cathedral wystarczy posiadac mieszkancow Merchants. Wymagania co do konkretnych budynkow i dostepni mieszkancy nie moga wzajemnie siebie wykluczac, zaktualizowano warunki:

	Settlers - chapel, market place
	Citizens - school, tavern, fire department
	Merchants - doctor, church, public bath
	Aristocratz - theatre, university, cathedral

Zwiekszono rowniez koszt budowy bydunku Palace, ktory do tej pory byl tanszy od budynku Cathdral. Zamieniono wzajemnie wartosci pol Cathedral i Palace.
*/


/*
05.28 13:44
Jezeli dane pole reprezentuje indeks tablicy to przyjmowanie, ze -1 nie reprezentuje zadnego indeksu jest niebezpieczne, proba odwolania sie do takiego indeksu spowoduje oczywiscie
blad krytyczny, dlatego zawsze nalezy uwzglednic warunek, ze przeszukujemy tablice o indeksach > -1.
*/


/*
05.28 15:56
Na naszym etapie zaawansowania mechaniki gry potrzbny jest tester, ktory nie tylko bedzie wykrywal bledy w prowadzeniu rozgrywki ale rowniez zajmowal sie optymalizacja zmiennych 
zawartych w grze, tak aby rozgrywka byla w maksymalnym stopniu grywalna i przeprowadzana optymalizacje przestawial developerom do wdrozenia.
*/