// Silnia z n

// silnia = n, b = n
POB n
LAD silnia
LAD b

// silnia z 0 to 1
SOZ ustaw_jeden

petla:
    // Dekrementuj b
    POB b
    ODE jeden
    SOZ koniec
    LAD b

    // Oblicz elem. silni
    DNS // a
    POB silnia 
    DNS // b

    SDP mnozenie
    PZS // silnia
    LAD silnia

    // Wroc do petli
    SOB petla

ustaw_jeden:
POB silnia
LAD silnia

// Zakonczenie programu
koniec: POB silnia
STP

// Wartosci programu 
b: RPA
n: RST 5
silnia: RPA
jeden: RST 1
zero: RST 0

mnozenie:
    // Zaladuj slad
    PZS
    LAD slad

    // Zaladuj b
    PZS
    LAD b1

    // Zaladuj a
    PZS
    LAD a1

    // Ustaw c
    POB zero
    LAD c1

    mnpetla:
        // c1 = c1 + b1
        POB c1
        DOD b1
        LAD c1 

        // Dekrementuj a1
        POB a1
        ODE jeden

        // Skok, jesli koniec
        SOZ mnkoniec
        LAD a1

        SOB mnpetla

    mnkoniec:
        // Zapisz dane na stos
        POB c1
        DNS
        POB slad
        DNS
        PWR
        
        // Wartosci podprogramu
        a1: RPA
        b1: RPA
        c1: RPA
        slad: RPA

    