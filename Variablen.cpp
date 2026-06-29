//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
    int iErste = 0;
    int iZweite = 0;
    // Hier folgt Ihr eigener Code
    std::cout<<"Geben Sie zwei ganze Zahlen ein:"<<std::endl;
    std::cin>>iErste;
    std::cin>>iZweite;
    int iSumme= iErste + iZweite;
    int iQuotient=iErste/iZweite;
    std::cout<<"Die Summe von der angegebenen Zahlen ist: "<<iSumme<<std::endl;
    std::cout<<"Die Quotient von der angegebenen Zahlen ist: "<<iQuotient<<std::endl;

    //result in double
    double dSumme= iErste + iZweite;
    double dQuotient=iErste/iZweite;
    std::cout<<"Die Summe von der angegebenen Zahlen ist jetzt: "<<dSumme<<std::endl;
    std::cout<<"Die Quotient von der angegebenen Zahlen ist jetzt: "<<dQuotient<<std::endl;

    //Umwandlung Typecasting
    double dErste = (double) iErste;
    double dZweite = (double) iZweite;
    double dSummeCast= dErste + dZweite;
    double dQuotientCast=dErste/dZweite;
    std::cout<<"Die Summe von der angegebenen Zahlen ist jetzt: "<<dSummeCast<<std::endl;
    std::cout<<"Die Quotient von der angegebenen Zahlen ist jetzt: "<<dQuotientCast<<std::endl;

    //Name eingeben
    std::string sVorname, sNachname;
    std::cout<<"Geben Sie Ihre Vornamen ein: \n";
    std::cin>> sVorname;
    std::cout<<"Geben Sie Ihre Nachnamen ein: \n";
    std::cin>> sNachname;
    std::string sVornameName = sVorname +" "+ sNachname;
    std::string sNameVorname =sNachname +" "+ sVorname;
    std::cout<<"Name im Form Vorname Nachname: "<<sVornameName<<std::endl;
    std::cout<<"Name im Form Nachname Vorname: "<<sNameVorname<<std::endl;

    //Feld
    {
    	int iFeld[2]={1,2};
    	std::cout<<iFeld[0]<<"\n"<<iFeld[1]<<"\n";
    	//spielfeld
    	int spielfeld[3][3] = { {1,2,3},
    			{4,5,6} };
    	std::cout<<spielfeld[0][0]<<" "<<spielfeld[0][1]<<" "<<spielfeld[0][2]<<"\n";
    	std::cout<<spielfeld[1][0]<<" "<<spielfeld[1][1]<<" "<<spielfeld[1][2]<<"\n";
    	const int iZweite = 1;
    	std::cout<<iZweite<<"\n";
    }
    std::cout<<iZweite<<"\n";

    //buchstaben umwandeln
    int iName1=sVorname[0];
    int iName2=sVorname[1];
    std::cout<<iName1<<"\n"<<iName2<<"\n";
    int iLetter1 = (iName1 - 'A'+1)%26; //ensure result in range 0-26
    int iLetter2 = (iName2 - 'a'+1)%26;
    std::cout << "Position der ersten Buchstaben im deutschen Alphabet ist: " << iLetter1 <<"\n";
    std::cout << "Position der zweiten Buchstaben im deutschen Alphabet ist: " << iLetter2 <<"\n";
    return 0;
    
}
