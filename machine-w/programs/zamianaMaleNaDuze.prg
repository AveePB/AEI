Pêtla: POB n // Wczytaj zw. n do Ak
       ODE Jeden // Odejmij Jeden od Ak. (Ak - 1)
       SOM Koniec // Skok do etykiety Koniec, gdy AK < 0
       £AD n // Zapisz zw. Ak do n

Rozkaz: POB zdanie // Wczytaj zw. zdanie[i] do Ak
        DNS // Wrzuæ zw. Ak na stos
        
        SDP ZamienMaleNaDuze
        PZS // Zwolnij ostatni el. stosu i zapisz do Ak
        ZapisTab: £AD zdanie // Zapisz zw. Ak do zdanie[i]
        
        POB Rozkaz // Wczytaj zw. Rozkaz do Ak
        DOD Jeden // Dodaj Jeden do Ak. (Ak + 1)
        £AD Rozkaz // Zapisz zw. Ak do Rozkaz
        
        POB ZapisTab // Wczytaj zw. Zapis do Ak
        DOD Jeden // Dodaj Jeden do Ak. (Ak + 1)
        £Ad ZapisTab // Zapisz zw. Ak do ZapisTab
        
        SOB Pêtla // Skok do etykiety Pêtla

Koniec:
       POB zdanie
       STP

Jeden: RST 1
Korekta: RST 32
ZnakP: RST 96 // Wartoœæ ASCII 'a' - 1
ZnakK: RST 123 // Wartoœæ ASCII 'z' + 1
n: RST 6
zdanie: RST 'x'
        RST 'a'
        RST 'b'
        RST '%'
        RST 'Z'
        RST 'u'

ZamienMaleNaDuze:
       PZS // Zwolnij ostatni el. stosu i zapisz do Ak
       £AD adresPowrotu // Zapisz zw. Ak do adresPowrotu
       
       PZS // Zwolnij ostatni el. stosu i zapisz do Ak
       £AD znak // Zapisz zw. Ak do znak
       
       POB ZnakP // Wczytaj zw. ZnakP do Ak
       ODE znak // Odejmij znak od Ak. (Ak - znak)
       
       SOM DrugieSprawdzenie // Skok do etykiety DrugieSprawdzenie jeœli Ak < 0
       SOB zmndKoniec // Skok do etykiety zmndKoniec
       
       DrugieSprawdzenie:
               POB znak // Wczytaj zw. znak do Ak
               ODE ZnakK // Odejmij ZnakK od Ak. (Ak - ZnakK)
               SOM ZastosujKorekte // Skok do etykiety ZastosujKorekte jeœli Ak < 0
               SOB zmndKoniec // Skok do etykiety zmndKoniec
       
       ZastosujKorekte:
               POB znak // Wczytaj zw. znak do Ak
               ODE Korekta // Odejmij Korekta do Ak. (Ak - Korekta)
               £AD znak // Zapisz zw. Ak do znak
       
       zmndKoniec:
               POB znak // Wczytaj zw. znak do Ak
               DNS // Wrzuæ zw. Ak na stos
               
               POB adresPowrotu // Wczytaj zw. adresPowrotu do Ak
               DNS // Wrzuæ zw. Ak na stos
               
               PWR // Koniec podprogramu
               
               adresPowrotu: RPA
               znak: RPA 
       
       
        