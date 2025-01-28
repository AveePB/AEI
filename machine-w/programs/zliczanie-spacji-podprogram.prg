Pêtla: POB n // Wczytaj zw. n do Ak
       ODE Jeden // Odejmij Jeden od Ak. (Ak - 1)
       SOM Koniec // Skok do etykiety Koniec, gdy Ak < 0
       £AD n // Zapisz zw. Ak do n

Rozkaz: POB zdanie // Wczytaj zw. zdanie[i] do Ak  
       DNS // Wrzuæ zw. Ak na stos
       POB Licznik // Wczytaj zw. Licznik do Ak
       DNS // Wrzuæ zw. Ak na stos
       
       SDP ZliczSpacje
       PZS // Zwolnij ostatni el. stosu i zapisz do Ak
       £AD Licznik // Zapisz zw. Ak do Licznik
       
       POB Rozkaz // Wczytaj zw. Rozkaz do Ak
       DOD Jeden // Dodaj Jeden do Ak. (Ak + 1)
       £AD Rozkaz // Zapisz zw. Ak do Rozkaz   
       SOB Pêtla // Skok do etykiety Pêtla

Koniec:
       POB Licznik // Wczytaj zw. Licznik do Ak
       STP

Licznik: RST 0
Jeden: RST 1
Znak: RST ' '
n: RST 6
zdanie: RST ' '
        RST 'F'
        RST ' '
        RST 'C'
        RST ' '
        RST ' '

ZliczSpacje:
       PZS // Zwolnij ostatni el. stosu i zapisz do Ak
       £AD zsAdresPowrotu // Zapisz zw. Ak do zsAdresPowrotu
       
       PZS // Zwolnij ostatni el. stosu i zapisz do Ak
       £AD zsLicznik // Zapisz zw. Ak do zsLicznik
       
       PZS // Zwolnij ostatni el. stosu i zapisz do Ak
       £AD zsZnak // Zapisz zw. Ak do zsZnak
       
       POB Znak // Wczytaj zw. Znak do Ak
       ODE zsZnak // Odejmij zsZnak od Ak. (Ak - zsZnak)
       SOZ zsInkrementujLicznik // Skok do etykiety zsInkrementujLicznik
       SOB zsKoniec // Skok do etykiety zsKoniec
       
       zsInkrementujLicznik:
               POB zsLicznik // Wczytaj zw. zsLicznik do Ak
               DOD Jeden // Dodaj Jeden do Ak. (Ak + 1)
               £AD zsLicznik // Zapisz zw. Ak do zsLicznik
               
       zsKoniec:
                POB zsLicznik // Wczytaj zw. zsLicznik do Ak
                DNS // Wrzuæ zw. Ak na stos
                
                POB zsAdresPowrotu // Wcztyaj zw. zsAdresPowrotu do Ak 
                DNS // Wrzuæ zw. Ak na stos
                
                PWR // Koniec podprogramu
                
                zsAdresPowrotu: RPA
                zsLicznik: RPA
                zsZnak: RPA 