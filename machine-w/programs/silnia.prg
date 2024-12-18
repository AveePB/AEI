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
    ...