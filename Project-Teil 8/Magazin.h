/*
 * Magazin.h
 *
 *  Created on: Jul 1, 2025
 * 
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"

/*! \brief Class Magazin
*
*/

class Magazin: public Medium
{
public:
	/**
	 * @brief Kontrusktor
	 * @param Titel
	 * @param DatumAusgabe
	 * @param Sparte
	 */
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
	virtual ~Magazin();

	/**
	 * @brief Ausgabe Funktion
	 * @param Person
	 * @param ausleihdatum
	 */
	virtual void ausgabe(std::ostream& output) const;

	/**
	 * @brief Ausleihbeschraenkungen
	 * @return false, when Magazin is the latest; otherwise true
	 */
	bool ausleihen(Person, Datum);

private:
	Datum datumAusgabe;
	std::string sparte;
};

#endif /* MAGAZIN_H_ */
