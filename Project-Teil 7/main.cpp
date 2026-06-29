/** @mainpage
 *
 * Praktikum Informatik 1 MMXXV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include "Student.h"

int main()
{
	//use class vector to insert student
	std::vector<Student> studentenListe;

	//Liste studentenListe;
    Student student;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(12, '\n');

    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.push_back(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
        studentenListe.push_back(student);
    }

    /* (1): push
     * (2): delete front
     * (3): in order output
     * (4): reverse ouput
     * (5): erase
     * (7): pop
     * (8): insert
     */
    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne loeschen" << std::endl
                  << "(3): Datenbank ausgeben in Vorwaerts" << std::endl
				  << "(4): Datenbank ausgeben in Rueckwarts"<< std::endl
				  << "(5): Datenelement loeschen" <<std::endl
				  << "(6): Datenelement vorne hinzufuegen"<<std::endl
				  << "(7): Datenelement hinten entfernen" <<std::endl
				  << "(8): Daten hinzufuegen" <<std::endl
				  << "(9): Daten aus einer Datei einlesen" <<std::endl
				  << "(a): Daten in eine Datei sichern" <<std::endl
				  << "(b): Liste sortieren und ausgeben" <<std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(12,'\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            // Datenelement vorne loeschen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                    	student = studentenListe.front();
                    	std::cout << "Der geloeschte Student: " << std::endl;
                    	std::cout<<student;
                    	studentenListe.erase(studentenListe.begin());
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                for(auto it = studentenListe.begin(); it != studentenListe.end(); it++)
                {
                	std::cout<< *it << std::endl;
                }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n";
                }
                break;
            // Datenbank rueckwaerts ausgeben
            case '4':
            	if(!studentenListe.empty())
            	{
            		std::cout<< "Inhalt der Liste in ruecklaufender Reihenfolge:" << std::endl;
            		for(auto rev = studentenListe.rbegin(); rev != studentenListe.rend(); rev++)
            		{
            			std::cout<<*rev;
            		}
            	}
            	break;
            // Daten loeschen
            case '5':
            	if(!studentenListe.empty())
            	{
            		std::cout<< "Matrikelnummer vom Student, der geloescht werden soll:" << std::endl;
            		unsigned int matNr;
            		std::cin>>matNr;
            		Student temp = {matNr,"","",""};
            		auto it = studentenListe.begin();
            		it = std::find (studentenListe.begin(), studentenListe.end(), temp);
            		Student& student = *it;
            		unsigned int itMatNr = student.getMatNr();
            		if(itMatNr == matNr)
            		{

            		std::cout << "Der geloeschte Student: " << std::endl<<student<<std::endl;
            		studentenListe.erase(it);
            		break;
            		}
            		else std::cout<<"Matrikelnummer nicht gefunden"<<std::endl;

//            		for(auto it = studentenListe.begin(); it != studentenListe.end(); it++){
//            			if (it->getMatNr() == matNr){
//            				studentenListe.erase(it);
//            				break;
//            			}

            	}
            	else{
            		std::cout<<"Liste ist leer!"<<std::endl;
            		}
            	break;
            // Datenelement vorne hinzufuegen
            case '6':
            	{
            		std::string name, geburtstag, adresse;
            		unsigned int matNr;
            		std::cout<<"Daten der Student eingeben"<<std::endl;
            		std::cout<<"Name:"<<std::endl;
            		getline(std::cin, name);
            		std::cout<<"Geburtsdatum:"<<std::endl;
            		getline(std::cin, geburtstag);
            		std::cout<<"Adresse:"<<std::endl;
            		getline(std::cin, adresse);
            		std::cout<<"Matrikelnummer:"<<std::endl;
            		std::cin>>matNr;
            		std::cin.ignore(10, '\n');

            		student = Student(matNr,name,geburtstag,adresse);
            		studentenListe.insert(studentenListe.begin(),student);
            	}
            	break;
            //Datenelement hinten entfernen
            case '7':
            	{
            		if(!studentenListe.empty())
            		{
            			student = studentenListe.back();
            			std::cout << "Der geloeschte Student: " << std::endl<<student<<std::endl;
            			studentenListe.pop_back();
            		}
            		else
            			std::cout<<"Die Liste ist leer!"<<std::endl;
            	}
            	break;

            //Daten hinzufuegen
            case '8':
            {
            	std::cout<<"Position (start from 0), die der Student hinzugefuegt werden soll: ";
            	int position;
            	std::cin>>position;
            	if(!studentenListe.empty())
            	{
            		std::string name, geburtstag, adresse;
            		unsigned int matNr;
            		std::cout<<"Daten der Student eingeben"<<std::endl;
            		std::cout<<"Name:"<<std::endl;
            		std::cin>> name;
            		std::cout<<"Geburtsdatum:"<<std::endl;
            		std::cin>>geburtstag;
            		std::cout<<"Adresse:"<<std::endl;
            		std::cin>> adresse;
            		std::cout<<"Matrikelnummer:"<<std::endl;
            		std::cin>>matNr;
            		std::cin.ignore(10, '\n');

            		student = Student(matNr,name,geburtstag,adresse);
            		auto it = studentenListe.begin() + position;
            		studentenListe.insert(it, student);
            	}
            }
            break;

            //Daten aus einer Datei einlesen
            case '9':
            {
            	std::string dateiName = "";
            	std::cout<< "Name der Datei eingeben: ";
            	std::cin>>dateiName;
            	studentenListe.clear();
				unsigned int matNr = 0;
            	std::string name = "";
            	std::string geburtsdatum = "";
            	std::string adresse = "";
            	std::ifstream eingabe(dateiName);
            	if(!eingabe)
            	 {
            		 std::cout << "Datei nicht gefunden!";
            	 }

            	 while (eingabe >> matNr)
            	 {
            	 eingabe.ignore(1,'\n');
            	 std::getline(eingabe, name);
            	 eingabe>> geburtsdatum;
            	 eingabe.ignore(1,'\n');
            	 std::getline(eingabe, adresse);
            	 student = Student(matNr,name,geburtsdatum,adresse);
            	 studentenListe.push_back(student);
            	 }
		}
            break;

            //Daten in eine Datei sichern
            case 'a':
            {
            	if(!studentenListe.empty())
            	{
            		std::string dateiName;
            		std::cout<<"Name der Datei eingeben: ";
            		std::cin>>dateiName;
            		std::ofstream ausgabe;
            		ausgabe.open(dateiName);
            		for (auto it = studentenListe.begin(); it != studentenListe.end(); it++)
            		{
            			Student& student = *it;
            			unsigned int matNr = student.getMatNr();
            			std::string name = student.getName();
            			std::string geburtsdatum = student.getGeburtstag();
            			std::string adresse = student.getAdresse();

            			ausgabe << matNr << std::endl;
            			ausgabe << name << std::endl;
            			ausgabe << geburtsdatum << std::endl;
            			ausgabe << adresse << std::endl;
            		}
            		ausgabe.close();
            	  }
            	else
            	{
            	  	std::cout << "Leere Liste!" << std::endl;
            	}
            }
            break;

            //Liste sortieren und ausgeben
            case 'b':
            {
            	if(!studentenListe.empty())
            	{
            		std::sort(studentenListe.begin(),studentenListe.end());
            		for(auto it = studentenListe.begin(); it != studentenListe.end(); it++)
            		                {
            		                	std::cout<< *it <<std::endl;
            		                }
            	}
            	else
            		std::cout << "Leere Liste!" << std::endl;
            }
            break;

            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
