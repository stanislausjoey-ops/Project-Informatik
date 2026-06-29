/*!
 * Praktikum Informatik 1 
 * 
 *
 * @file Medium.cpp
 */
 
#include "Medium.h"

#include <string>
#include <iostream>

unsigned int Medium::currentID = 1;

Medium::Medium(std::string initTitel)
: titel(initTitel)
, status(false)
{
    ID = currentID++;
}

Medium::~Medium(void)
{
}

/**
	 * @brief check if medium is already rent
	 */
void Medium::ausgabe(std::ostream& output) const
{
    output << "ID: " << ID << std::endl;
    output << "Titel: " << titel << std::endl;

    if (status)
    {
        std::cout << "Status : Das Medium ist seit dem " << datumAusgeliehen << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
    }
    else
    {
        std::cout << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
    }
}

/**
	 * @brief check if rentable or not
	 */
bool Medium::ausleihen(Person person,Datum ausleihdatum)
{
    if (status)
    {
        std::cout << "Das Medium \"" << titel << "\" ist bereits verliehen!" << std::endl;
        return false;
    }
    else
    {
        status = true;
        personAusgeliehen = person;
        datumAusgeliehen = ausleihdatum;
        std::cout << "Das Medium \"" << titel << "\" wird an " << person.getName() << " verliehen." << std::endl;
        return true;
    }
}

void Medium::zurueckgeben()
{
    if (status)
    {
        status = false;
        std::cout << "Das Medium \"" << titel << "\" wurde zur�ckgegeben." << std::endl;
    }
    else
    {
        std::cout << "Das Medium \"" << titel << "\" ist nicht verliehen!" << std::endl;
    }
}

unsigned int Medium::getID()
{
    return ID;
}

std::ostream& operator<<(std::ostream& output, const Medium& medium)
{
	medium.ausgabe(output);
	return output;
}

bool Medium::getstatus()
{
	return status;
}
