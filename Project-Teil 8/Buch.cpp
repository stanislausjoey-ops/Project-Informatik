/*
 * Buch.cpp
 *
 *  Created on: Jul 1, 2025
 *
 */

#include "Buch.h"

Buch::Buch(std::string  initTitel, std::string initAutor):
	Medium::Medium(initTitel), autor(initAutor) // call base class constructor and pass initTitel to Buch
{
	// TODO Auto-generated constructor stub

}

Buch::~Buch()
{
	// TODO Auto-generated destructor stub
}

void Buch::ausgabe(std::ostream& output) const
{
	Medium::ausgabe(output); // call from base class so print both base class info (title) and Buch-info (author)
	output << "Autor: " << autor << std::endl;

}

