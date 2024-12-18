// Kod C++:
// int NWW (int a, int b) {
//     int a1 = a, b1 = b;
//     while (a1 != b1) {
//           if (a1 > b1)
//               b1 = b1 + b;
//           else
//               a1 = a1 + a;
//     }
//     return a1;
// }

// a1 = a, b1 = b
POB a 
LAD a1
POB b    
LAD b1

petla:
    // (AK) = a1 - b1
    POB a1
    ODE b1
    
    // Skok jesli (AK) = 0
    SOZ koniec
    
    // Skok jesli (AK) < 0
    SOM a1MniejszeOdb1
        POB b1
        DOD b
        LAD b1
        
        // Skok do poczatku petli
        SOB petla
    
    a1MniejszeOdb1:
        POB a1
        DOD a
        LAD a1
        
        // Skok do poczatku petli
        SOB petla

// Zapisz wartosc do AK
koniec: POB a1
STP

// Wartosci        
a: RST 10
b: RST 7
a1: RPA
b1: RPA