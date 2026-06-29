/*
 * DVD.h
 *
 *  Created on: Jul 1, 2025
 * 
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"

/*! \brief Class DVD
*
*/

class DVD: public Medium
{
public:
	/**
	 * @brief Konstruktor
	 * @param Titel
	 * @param Altersfreigabe
	 * @param Genre
	 *
	 */
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
	virtual ~DVD();

	/**
	 * @brief Ausgabe Funktion
	 * @param Person
	 * @param ausleihDatum
	 *
	 */
	virtual void ausgabe(std::ostream& output) const;

	/**
	 * @brief Alterbeschraenkung
	 * @return false, when person's age < Alterfreigabe; otherwise true
	 */
	bool ausleihen(Person, Datum);

private:
	int altersFreigabe;
	std::string genre;
};

#endif /* DVD_H_ */
