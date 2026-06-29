//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Function subtract 2 vectors (1 is input vector)
 * @param input vector
 *
 * @return result vector after subtraction
 */
Vektor Vektor::sub(const Vektor& input) const
{
	Vektor sub= Vektor(x - input.x, y - input.y, z - input.z);
	sub.ausgabe();
	return sub;
}

/**
 * @brief Function calculate length of a vector
 *
 * @return length of vector
 */
double Vektor::laenge() const
{
	double laenge = sqrt (x*x + y*y + z*z);
	return laenge;
}

/**
 * @brief Function calculate skalar product of 2 vectors
 * @param input vector
 *
 * @return skalar product
 */
double Vektor::skalarProd(const Vektor& input) const
{
	double skalarProd;
	skalarProd = x*input.x + y*input.y + z*input.z;
	return skalarProd;
}

/**
 * @brief Function calculate angle between 2 vectors
 * @param input vector
 *
 * @return angle in degree
 */
double Vektor::winkel(const Vektor& input) const
{
	double skalarProd = x*input.x + y*input.y + z*input.z;
	double laenge1 = sqrt (x*x + y*y + z*z);
	double laenge2 = sqrt (input.x*input.x + input.y*input.y + input.z*input.z);
	double winkel = (acos(skalarProd/(laenge1*laenge2)))*180/M_PI;
	return winkel;
}

/**
 * @brief Function rotates vector around z-axis
 * @param input angle (in rad) to rotate vector by
 */
void Vektor::rotiereUmZ(const double rad)
{
	double cosX, cosY, sinX, sinY;
	cosX = x*cos(rad);
	cosY = y*cos(rad);
	sinX = x*sin(rad);
	sinY = y*sin(rad);

	x = cosX - sinY;
	y = cosY + sinX;
}
