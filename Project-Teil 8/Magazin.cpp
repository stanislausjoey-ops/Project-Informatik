/*
 * Magazin.cpp
 *
 *  Created on: Jul 1, 2025
 * 
 */

#include "Magazin.h"

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte):
	Medium::Medium(initTitel), datumAusgabe(initDatumAusgabe), sparte(initSparte)
{
	// TODO Auto-generated constructor stub

}

Magazin::~Magazin()
{
	// TODO Auto-generated destructor stub
}

void Magazin::ausgabe(std::ostream& output) const
{
	Medium::ausgabe(output);
	output << "Datum Ausgabe: " << datumAusgabe << std::endl;
	output << "Sparte: " << sparte << std::endl;
}

bool Magazin::ausleihen (Person person, Datum ausleihDatum)
{
	if (ausleihDatum - datumAusgabe == 0){
		std::cout << "Neueste Ausgabe kann nicht ausgeliehen werden.";
		return false;
	}
	return Medium::ausleihen(person, ausleihDatum);
}
