Pêtla: POB n // Wczytaj zw. n do Ak
       ODE Jeden // Odejmij Jeden od Ak. (Ak - 1)
       SOM Koniec // Skok do etykiety Koniec, gdy Ak < 0       
       £AD n // Zapisz zw. Ak do n
       POB Znak // Wczytaj zw. Znak do Ak
       
Rozkaz: ODE zdanie // Odejmij el. zdania od Ak. (Ak - zdanie[i])
        SOZ ZliczWyst¹pienie // Skok do etykiety ZliczWyst¹pienie, gdy Ak = 0 

Rozkaz_reszta:
        POB Rozkaz // Wczytaj zw. Rozkaz do Ak
        DOD Jeden // Dodaj Jeden do Ak. (Ak + 1)
        £AD Rozkaz // Zapisz zw. Ak do Rozkaz
        SOB Pêtla // Skok do etykiety Pêtla

ZliczWyst¹pienie:
        POB Licznik // Wczytaj zw. Licznik do Ak
        DOD Jeden // Dodaj Jeden do Ak. (Ak + 1)
        £AD Licznik // Zapisz zw. Ak do Licznik
        SOB Rozkaz_reszta // Skok do etykiety Rozkaz_reszta
Koniec:
       POB Licznik // Wczytaj zw. Licznik do Ak
       STP
       
Licznik: RST 0
Jeden: RST 1
Znak: RST ' '
n: RST 6
zdanie: RST ' '
        RST ' '
        RST 'B'
        RST ' '
        RST 'C'
        RST ' '