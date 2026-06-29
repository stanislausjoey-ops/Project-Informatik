//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <iomanip>


int main()
{
    
    Vektor vector1(1, 2, 3);
    Vektor vector2(3, 2, 1);

    vector1.ausgabe();
    vector2.ausgabe();

    Vektor erdRadius(0, 6371, 0); //from earth center to ground (y-axis)
    Vektor aussichtsPunkt(0, 6371.5574, 0); //distance of person from earth center
    Vektor sicht = erdRadius.sub(aussichtsPunkt); //vector point from aussichtspunkt towards earth radius

    //code implement
    std::cout << std::fixed;
    std::cout << std::setprecision(4);

/*
    std::cout <<"Laenge Vektor 1: " << vector1.laenge() << std::endl;
    std::cout <<"Laenge Vektor 2: " << vector2.laenge() << std::endl << std::endl;

    std::cout <<"Vektor 1 - Vektor 2:" << std::endl;
    vector1.sub(vector2);
    std::cout <<"Vektor 2 - Vektor 1:" << std::endl;
    vector2.sub(vector1);

	std::cout <<"Skalarprodukt v1 und v2 = " << vector1.skalarProd(vector2) << std::endl << std::endl;
    std::cout <<"Winkel zwischen v1 und v2 = " << vector1.winkel(vector2) <<""<< std::endl << std::endl;
    std::cout <<"Vektor, der von v1 um z-Achse rotiert: " << std::endl;

    vector1.rotiereUmZ(2*M_PI);
    vector1.ausgabe();

    std::cout <<"Vektor, der von v2 um z-Axe rotiert: " << std::endl;
    vector2.rotiereUmZ(2*M_PI);
    vector2.ausgabe();
*/
    //Aufgabe: wie weit horizon
    double hoehe = 555.7 + 1.70;
    double rad = 0.0000001; //rotate on z-axis
    double winkelRad;
    int schritt = 0;
    while(erdRadius.winkel(sicht) >= 90.0){ // condition: angle between radius and sight line >= 90 -> still see
    	aussichtsPunkt.rotiereUmZ(rad);
    	sicht = erdRadius.sub(aussichtsPunkt); //update the position
    	winkelRad = erdRadius.winkel(aussichtsPunkt);
    	schritt++;
    }
    std::cout<< "Sie können "<<sicht.laenge()<<" Km weit sehen."<<std::endl;
    std::cout<< "Sie sind " << hoehe << " Meter hoch." << std::endl;
    std::cout << "Der Winkel betraegt " << winkelRad << " Grad." << std::endl;
    std::cout << "Anzahl Schritte: " << schritt << std::endl;

    return 0;

}
