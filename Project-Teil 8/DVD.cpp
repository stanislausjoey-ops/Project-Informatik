/*
 * DVD.cpp
 *
 *  Created on: Jul 1, 2025
 *
 */

#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre):
		Medium::Medium(initTitel), altersFreigabe(initAltersfreigabe), genre(initGenre)

{
	// TODO Auto-generated constructor stub

}

DVD::~DVD()
{
	// TODO Auto-generated destructor stub
}

void DVD::ausgabe(std::ostream& output) const
{
	Medium::ausgabe(output);
	output << "Genre: " << genre << std::endl;
	output << "alters Freigabe: ab " << altersFreigabe << " Jahre" << std::endl;
}

bool DVD::ausleihen(Person person, Datum ausleihDatum)
{
 if (ausleihDatum - person.getGeburtsdatum() >= altersFreigabe*12) //compare in months
 {
	 return Medium::ausleihen (person, ausleihDatum);
 }
 std::cout << "Alter nicht erfuellt" << std::endl;
 return false;
}
