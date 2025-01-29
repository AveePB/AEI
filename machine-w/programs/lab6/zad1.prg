// Skoki bezwarunkowe 
SOB Program
SOB Przerw1
SOB Przerw2
SOB Przerw3
SOB Przerw4

// Punkt startowy programu                
Program:        
    POB Wielkosc_P
    £AD Dlugosc
    £AD Szerokosc

// I Pêtla     
PetlaNr1:       
    POB Dlugosc
    ODE Jeden
    £AD Dlugosc
    SOM Koniec
    POB Wielkosc_P
    £AD Szerokosc
    POB Znak_NL
    WYP 2

// II Pêtla                
PetlaNr2:       
    POB Szerokosc
    ODE Jeden
    £AD Szerokosc
    SOM PetlaNr1
    POB Znak_PR
    WYP 2
    SOB PetlaNr2

// Punkt wyjœciowy programu           
Koniec:         
    POB Znak_NL
    WYP 2
    STP

// I Przerwanie                         
Przerw1:        
    CZM MASKA
    MAS 15
    DNS
    POB Znak_Jeden
    WYP 2
    PZS
    MSK MASKA
    PWR

// II Przerwanie
Przerw2:        
    CZM MASKA
    MAS 15
    POB Znak_Dwa
    WYP 2
    PZS
    MSK MASKA
    STP

// III Przerwanie                
Przerw3:        
    CZM MASKA
    MAS 15
    DNS
    POB Znak_Trzy
    WYP 2
    PZS
    MSK MASKA
    PWR

// IV Przerwanie                
Przerw4:        
    CZM MASKA
    MAS 15
    DNS
    POB Znak_Cztery
    WYP 2
    PZS
    MSK MASKA
    PWR

// Wa¿ne sta³e
Wielkosc_P:     RST 10
Jeden:          RST 1

// Znaki     
Znak_PR:        RST '%'
Znak_NL:        RST 10
Znak_Jeden:     RST '1'
Znak_Dwa:       RST '2'
Znak_Trzy:      RST '3'
Znak_Cztery:    RST '4'

// Parametry
Dlugosc:        RPA
Szerokosc:      RPA
MASKA:          RPA
