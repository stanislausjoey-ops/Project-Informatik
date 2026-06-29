/**
 * Praktikum Informatik 1
 *
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Othello
 */

/**
* @mainpage Othello
*
* Dokumentation des Spiels Othello im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "othelloKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i
        std::cout <<  std::endl;
    }  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{
    // Hier erfolgt jetzt Ihre Implementierung ...
	if (0 <= posX && posX < (GROESSE_X) && 0 <= posY && posY < GROESSE_Y)  //Conditions for coordinate x,y (8x8)
			{
			return true;
			}
	else return false;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return true if Zug ist gueltig
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1

    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // Hier erfolgt jetzt Ihre Implementierung ...

        	if (i==0 && j==0) //center -> continue
        	        	{
        	        		continue;
        	        	}
        	        		int neuX = posX + i; //move step in direction (i,j) //use variables to ensure go specific direction
        	        		int neuY = posY + j;
        	        		bool gegnerStein = false; //check if theres stone from opponent on the field

        	        		while (neuX >= 0 && neuX < GROESSE_X && neuY >= 0 && neuY < GROESSE_Y && spielfeld[neuY][neuX] == gegner)
        	        		{
        	        			gegnerStein = true; //this field has opponents stone
        	        			neuX += i; //go same direction
        	        			neuY += j;
        	        		}
        	        		if (neuX >= 0 && neuX < GROESSE_X && neuY >= 0 && neuY < GROESSE_Y && gegnerStein == true && spielfeld[neuY][neuX] == aktuellerSpieler)
        	        		{
        	        		return true; //till find own stone => stop and return true
        	        	    }
        }
    }
    return false;

}


/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler;

    //Alle Richtungen bearbeiten
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
            // allen Richtungen in Ihre eigenen Steine umgewandelt werden
            //
            // Hier erfolgt jetzt Ihre Implementierung ...

        	if (i==0 && j==0)
        	        	{
        	        		continue;
        	        	}
        	        		int neuX = posX + i;
        	        		int neuY = posY + j;
        	        		bool gegnerStein = false;

        	        		while (neuX >= 0 && neuX < GROESSE_X && neuY >= 0 && neuY < GROESSE_Y && spielfeld[neuY][neuX] == gegner)
        	        		{
        	        			gegnerStein = true;
        	        			neuX += i;
        	        			neuY += j;
        	        		}
        	        		if (neuX >= 0 && neuX < GROESSE_X && neuY >= 0 && neuY < GROESSE_Y && gegnerStein == true && spielfeld[neuY][neuX] == aktuellerSpieler)
        	        		{
        	        		while (neuX != posX || neuY != posY) //go backwards till original position
        	        		{
        	            	neuX -= i; //go 1 by 1 backwards
        	            	neuY -= j;
        	        		spielfeld [neuY][neuX] = aktuellerSpieler; //flip to aktueller spieler stone
        	        		}
        	        		spielfeld[posY][posX] = aktuellerSpieler; //place a stone of aktueller spieler to the move just be made
        	        		}
        }
    }

}

/**
 * @brief Funktion, die Anzahl den moeglichen Zuegen berechnen
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 *
 * @return anzahl
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    // Hier erfolgt jetzt Ihre Implementierung ...

	int anzahl = 0;
	for(int j = 0; j< GROESSE_Y; j++){
		for(int i = 0; i<GROESSE_X; i++){
			if(zugGueltig(spielfeld,aktuellerSpieler,i,j)){
				anzahl ++;
			}
		}
	}
    return anzahl;
}


bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    return true;
}

/**
 * @brief Funktion, die das Spiel laueft
 *
 * @param spielerTyp[] determine if player is human or computer
 * @param keinZugmoeglich track how many players cannot move
 * once keinZugmoeglich = 0 (both player have no valid moves) loop ends and game ends
 *
 * @param zugGemacht determine to use function for human (menschlicherZug) or computer (computerZug)
 *
 */
void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    zeigeSpielfeld(spielfeld);

    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //
    // Hier erfolgt jetzt Ihre Implementierung ...

    int keinZugmoeglich = 2; //track how many players cannot move
    while(keinZugmoeglich > 0){
    	std::cout << std::endl << "Spieler " << aktuellerSpieler << " ist dran." << std::endl;
    	bool zugGemacht;
    	if(spielerTyp[aktuellerSpieler - 1] == 1){
    		zugGemacht = menschlicherZug(spielfeld, aktuellerSpieler);
    	}
    	else if (spielerTyp[aktuellerSpieler-1]== 2 ){
    		zugGemacht = computerZug(spielfeld, aktuellerSpieler);
    	}
    	if(aktuellerSpieler == 1 && zugGemacht == false){
    		keinZugmoeglich --; //current player cannot move => decrease keinZugmoeglich
    	}
    	else if(aktuellerSpieler == 2 && zugGemacht == false){
    		keinZugmoeglich --;
    	}
    	else if(aktuellerSpieler == 1 && zugGemacht == true){
    	    keinZugmoeglich = 2; // if a move is valid/made => reset keinZugmoeglich to 2
    	    zeigeSpielfeld(spielfeld); //update board and show
    	}
    	else if(aktuellerSpieler == 2 && zugGemacht == true){
    		keinZugmoeglich = 2;
    		zeigeSpielfeld(spielfeld);
    	}

    	if (aktuellerSpieler == 1) /// switch turns from player 1 to player 2 and otherwise
    	{
    		aktuellerSpieler++;
    	}
    	else
    	{
    		aktuellerSpieler--;
    	}
    	while(keinZugmoeglich == 0){
    		std::cout << "Kein mehr moegliche Zug fuer beiden"<< std::endl;
    		break;
    	}
    }

    switch (gewinner(spielfeld)) //count stones from each party on playfield
    {
        // Hier erfolgt jetzt Ihre Implementierung ...
    case 1:
    	std::cout<<"Spieler 1 gewonnen";
    	break;
    case 2:
    	std::cout<<"Spieler 2 gewonnen";
    	break;
    default: std::cout<<"Kein Gewinner";
    }
}

int main()
{
	//Test Funktion Menschen spielen
//	{
//	int spielerTyp[2] = { MENSCH, MENSCH };
//	 spielen(spielerTyp);
//	 return 0;
//	}

    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl << std::endl;
    }

    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
    // int spielerTyp[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
    // spielen(spielerTyp);
    //
    // Hier erfolgt jetzt Ihre Implementierung ...

    //Erzeuge Startaufstellung
    int spielfeld[GROESSE_Y][GROESSE_X];
    initialisiereSpielfeld(spielfeld);
    zeigeSpielfeld(spielfeld);

    int spielerTyp[2] = {1,2};
    std::cout << "Player 1 eingeben (1 ist Mensch / 2 ist Computer)" <<std::endl;
    std::cin >> spielerTyp[0];
    std::cout << "Player 2 eingeben (1 ist Mensch / 2 ist ComputerI)" <<std::endl;
    std::cin >> spielerTyp[1];

    spielen(spielerTyp);

    return 0;
}
