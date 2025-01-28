POB zero
£AD licznik_proc
£AD size
POB ³ad_tab
£AD rzk

loop1:
   WPR 1
   £AD znak
   
   // Sprawdzamy czy pomiêdzy P - Z
   ODE znak_P
   SOM skip
   POB znak
   ODE znak_Z
   ODE jeden
   SOM wpisz
   SOB skip
   
   wpisz:
      // Wpisujemy znak do tablicy
      POB znak
      rzk: £AD tab
      POB rzk
      DOD jeden
      £AD rzk
      POB size
      DOD jeden
      £AD size   
   
   skip:
   POB znak
   ODE procent
   SOZ zwieksz_proc
   SOB skip2
   
   // Inkrementacja licznika %
   zwieksz_proc:
      POB licznik_proc
      DOD jeden
      £AD licznik_proc
      ODE cztery
      SOZ end
      
   skip2:
   SOB loop1
end:

// Wypisujemy rozmiar na wyjÅ›cie
POB size
SDP write
POB enter
WYP 2

// Liczymy X i Z
POB zero
£AD licznik_X
£AD licznik_Z
POB pob_tab
£AD rzk2
POB size
£AD i

loop2:
   POB i
   ODE jeden
   £AD i
   SOM end2
   rzk2: POB tab
   £AD znak
   POB rzk2
   DOD jeden
   £AD rzk2
   
   // Sprawdzamy czy X
   POB znak
   ODE znak_X
   SOZ zwieksz_X
   
   // Sprawdzamy czy Z
   POB znak
   ODE znak_Z
   SOZ zwieksz_Z
   SOB loop2
   
   zwieksz_X:
      POB licznik_X
      DOD jeden
      £AD licznik_X
      SOB loop2
   
   zwieksz_Z:
      POB licznik_Z
      DOD jeden
      £AD licznik_Z
      SOB loop2
end2:

// Wypisujemy licznik X
POB znak_X
WYP 2
POB dwukropek
WYP 2
POB spacja
WYP 2
POB licznik_X
SDP write
POB enter
WYP 2

// Wypisujemy licznik Z
POB znak_Z
WYP 2
POB dwukropek
WYP 2
POB spacja
WYP 2
POB licznik_Z
SDP write
POB enter
WYP 2

// KONIEC...
STP
znak: RPA
licznik_proc: RST 0
licznik_X: RST 0
licznik_Z: RST 0
jeden: RST 1
cztery: RST 4
procent: RST 37 // ASCII dla '%'
spacja: RST ' '
enter: RST 13 // \n
dwukropek: RST ':'
i: RST 0
znak_P: RST 'P'
znak_X: RST 'X'
znak_Z: RST 'Z'

// Podprogram WRITE skopiowany 
write: 
   £AD liczba
   POB zero
   // 0 = koniec liczby
   DNS
   POB liczba
   SOM abs
   SOB loop
   // Wypisuje minus na wyjÅ›cie, zamienia liczbÄ™ na wartoÅ›Ä‡ bezwzglÄ™dnÄ…
   abs:
      POB minus
      WYP 2
      POB zero
      ODE liczba
      £AD liczba
   // Dzieli liczbÄ™ na cyfry, zapisuje je na stosie
   loop:
      DZI dziesiec
      MNO dziesiec
      £AD tmp
      POB liczba
      ODE tmp
      DOD znak_0
      DNS
      POB tmp
      DZI dziesiec
      SOZ wypisz
      £AD liczba
      SOB loop
   
   // Wypisuje cyfry w poprawnej kolejnoÅ›ci
   wypisz:
      PZS
      
      // 0 = koniec liczby
      SOZ return
      WYP 2
      SOB wypisz
   return: PWR
   zero: RST 0
   liczba: RPA
   tmp: RPA
   dziesiec: RST 10
   znak_0: RST '0'
   minus: RST '-'

³ad_tab: ³ad tab
pob_tab: POB tab
size: RST 0
tab: RPA

