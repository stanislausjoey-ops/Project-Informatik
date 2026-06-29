/*
 * Buch.h
 *
 *  Created on: Jul 1, 2025
 * 
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"

/*! \brief Class Buch
*
*/

class Buch: public Medium //inherit from class Medium
{
public:
	/**
	     *@brief Konstruktor
	     *@param Autor
	     *@param Titel
	     */
	Buch(std::string  initTitel, std::string initAutor);
	/**
	 * @brief virtual Destruktor
	 */
	virtual ~Buch();

	/**
	 * @brief Ausgabe Funktion
	 * @param ausgabe
	 */
	virtual void ausgabe(std::ostream& output) const; //runtime polymorphism

private:
	std::string autor;
};

#endif /* BUCH_H_ */
