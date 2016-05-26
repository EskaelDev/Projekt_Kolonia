//Dziennik uwag do rozwiazan zastosowanych w kodzie zrodlowym programu:

/*
05.26 16:20
Przez przekazanie do funkcji obiektu typu klasa zdefiniowana przez developera i wywolanie do niej metody latwiej wskazac innym programista, ktorzy w przyszlosci moga rozwijac kod zrodlowy 
programu, co nalezy przekazac do funkcji jako argument, niz funkcja przyjmuja typ int, ktory moze byc dowolna liczba, ktora przekazana do funkcji moze nie miec kompletnie zadnego sensu.
Przekazanie referencji do danej klasy zapewnia, ze przekazemy wylacznie zdefiniowane przez developera wczesniej wartosci.

Dr Polomski twierdzi, ze developer rozwijajacy taki kod moze sie zastanawiac, czy metoda ktory przyjmuje referencje do obiektu klasy moze nie pobierac innych pol ale wydaje mi sie, ze to
slabszy argument, niz w/w, wiec na razie zostawiam taki jak mam.
*/


/*
05.26 16:45
Dla uproszczenia pisania kodu zrodlowego i wykorzystania wszystkich dostepnych surowcow i budynkow publicznych wprowadzam wymagania do budowania budynkow dla mieszkancow. W przypadku 
budynkow publicznych wystarczy posiadanie jednego budynku aby umozliwic budowe budynku mieszkalnego, przy czym budynek dla Pioneerow nie wymaga zadnego budynku pulicznego:

	Settlers - chapel, market place, tavern
	Citizens - school, doctor, fire department
	Merchants - church, public bath, theatre
	Aristocratz - jevelry, university, cathedral

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
Potrzeba stworzenia klasy Magazine zainicjowala stworzenie klasy public bedacej lacznikiem miedzy klasa Industrial a klasa Production. Klasa Magazine rowinez wywodzi sie z klasy Industrial
ale z innej galezi, niz klasa Producton.
*/



