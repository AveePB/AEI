Pêtla: POB n // Wczytaj zw. n do Ak
       ODE Jeden // Odejmij Jeden od Ak. (Ak - 1)
       SOM Koniec // Skok do etykiety Koniec, gdy Ak = 0
       £AD n // Zapisz zw. Ak do n
       POB Suma // Wczytaj zw. suma do Ak

Rozkaz: DOD Tablica // Dodaje el. tablicy
       £AD Suma // Zapisz zw. Ak do Suma
       POB Rozkaz // Wczytaj zw. Rozkaz do Ak
       DOD Jeden // Dodaj Jeden do Ak. (Ak + 1)
       £AD Rozkaz // Zapisz zw. Ak do Rozkaz
       SOB Pêtla // Skok do etykiety Pêtla 

Koniec: 
       POB Suma // Wczytaj zw. Suma do Ak
       STP

n: RST 4
Tablica: RST 1
         RST 2
         RST 6
         RST 4
Suma: RST 0
Jeden: RST 1
       