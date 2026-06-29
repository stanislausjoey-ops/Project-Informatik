/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

struct Person
	{
		std::string sNachname;
		std::string sVorname;
		int iGeburtsjahr;
		int iAlter;
	};

int main()
{
	Person nBenutzer;
	std::cout<<"Nachname eingeben: "<<"\n";
	std::cin>>nBenutzer.sNachname;
	std::cout<<"Vorname eingeben: "<<"\n";
	std::cin>>nBenutzer.sVorname;
	std::cout<<"Geburtsjahr eingeben: "<<"\n";
	std::cin>>nBenutzer.iGeburtsjahr;
	std::cout<<"Alter eingeben: "<<"\n";
	std::cin>>nBenutzer.iAlter;
	std::cout<<"Nachname: "<<nBenutzer.sNachname<<"\n";
	std::cout<<"Vorname: "<<nBenutzer.sVorname<<"\n";
	std::cout<<"Geburtsjahr: "<<nBenutzer.iGeburtsjahr<<"\n";
	std::cout<<"Alter: "<<nBenutzer.iAlter<<"\n";

	//Kopieren
	Person nKopieEinzeln;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;

	Person nKopieGesamt;
	nKopieGesamt = nBenutzer;

	//output
	std::cout<<"KopieEinzel"<<"\n";
	std::cout << "Nachname: " << nKopieEinzeln.sNachname << "\n";
	std::cout << "Vorname: " << nKopieEinzeln.sVorname << "\n";
	std::cout << "Geburtsjahr: " << nKopieEinzeln.iGeburtsjahr << "\n";
	std::cout << "Alter: " << nKopieEinzeln.iAlter << "\n";

	std::cout<<"KopieGesamt"<<"\n";
	std::cout << "Nachname: " << nKopieGesamt.sNachname << "\n";
	std::cout << "Vorname: " << nKopieGesamt.sVorname << "\n";
	std::cout << "Geburtsjahr: " << nKopieGesamt.iGeburtsjahr << "\n";
	std::cout << "Alter: " << nKopieGesamt.iAlter << "\n";

    return 0;
    
}
