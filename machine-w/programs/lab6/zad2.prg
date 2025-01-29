// Skoki bezwarunkowe
SOB program
SOB PRZERW1
SOB PRZERW2
SOB PRZERW3
SOB PRZERW4

// Punkt startowy programu                 
program:        POB MinusJeden
                DNS
                
petla:          POB znak
                WYP 2
                SOB petla

// I Przerwanie                
PRZERW1:        CZM maska
                MAS 15 //maska 1111
                DNS
                POB Dwa
                £AD Licznik1 
petla1:         ODE Jeden
                £ad Licznik1               
                POB Jedynka
                WYP 2
                POB Licznik1
SOZ dalej1
SOB petla1

dalej1:         
    POB P1
    ODE Jeden
    £AD P1
    SOZ Koniec 
    PZS
    MSK maska
    PWR

// II Przerwanie            
PRZERW2:        
    CZM maska
    MAS 7 // Maska 0111                 
    DNS
    POB Cztery
    £AD Licznik2

petla2:         
    ODE Jeden
    £AD Licznik2
    POB Dwójka
    WYP 2
    POB Licznik2
    SOZ dalej2
    SOB petla2

dalej2:         
    POB P2
    ODE Jeden
    £AD P2
    SOZ Koniec       
    PZS
    MSK maska
    PWR

// III Przerwanie
Przerw3:        
    CZM maska
    MAS 3 // Maska 0011               
    DNS            
    POB Szesc
    £AD Licznik3

petla3:         
    ODE Jeden
    £AD Licznik3                
    POB Trójka
    WYP 2
    POB Licznik3
    SOZ dalej3
    SOB petla3

dalej3:         
    POB P3
    ODE Jeden
    £AD P3
    SOZ Koniec
    PZS                                
    MSK maska
    PWR

// IV Przerwanie            
PRZERW4:        
    CZM maska
    MAS 1 // Maska 0001                
    DNS
    POB Osiem
    £AD Licznik4

petla4:         
    ODE Jeden
    £AD Licznik4
    POB Czwórka
    WYP 2
    POB Licznik4
    SOZ dalej4
    SOB petla4
    
dalej4:        
    POB P4
    ODE Jeden
    £AD P4
    SOZ Koniec
    PZS                
    MSK maska
    PWR      

Koniec:
    PZS
    SOM Koniec2
    SOB Koniec

// Punkt wyjœciowy programu               
Koniec2:        
    MAS 0
    STP

MinusJeden: RST -1

// Krotnoœci zg³oszeñ
P1: RST 3
P2: RST 3
P3: RST 6
P4: RST 6

maska: RPA                
znak: RST '%'

// Licznik powtórzeñ dla 1-4
Licznik1: RST 2
Licznik2: RST 4
Licznik3: RST 6
Licznik4: RST 8

// Sta³e numeryczne
Jeden: RST 1
Dwa: RST 2
Cztery: RST 4
Szesc: RST 6
Osiem: RST 8

Jedynka: RST 49
Dwójka: RST 50
Trójka: RST 51
Czwórka: RST 52

       