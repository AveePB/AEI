// Wyznacz najmniejszy element tablicy

// i = 1, n = rozmiar
POB jeden
LAD i
POB rozmiar
LAD n

// Ustaw min. wartosc
POB rozkaz
LAD tab_poz
POB tab
LAD min

petla:
    tab_poz: POB tab
    ODE min
    
    // Skok jesli, (AK) < 0
    SOM nowy_min
    
    SOB inkrementacja
    
    // Etykieta nowego min
    nowy_min:
        DOD min
        LAD min
   
   inkrementacja:
	// (AK) = n - i
	POB n
	ODE i
	LAD n
	
	// Skok jesli n = 0
	SOZ koniec
	
	// Inkrementuj adres pamieci (wskaznik)
	POB tab_poz
	DOD i
	LAD tab_poz
	SOB petla

koniec:
POB min
STP


// Wartosci
rozkaz: POB tab
rozmiar: RST 6
tab: RST 4
     RST 3
     RST -2
     RST 12
     RST 5
     RST 23
min: RPA
n: RPA
i: RST 0
jeden: RST 1
