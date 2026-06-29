//============================================================================
// Name        : Versuch02Teil3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>

std::string verschluss(std::string wort, char tabelle [2][26]){

	std::string geheim;
	for(unsigned int i=0; i < wort.length();i++){
		char buchstabe = wort[i];
		for (int j=0; j<26 ; j++){
			if(tabelle[0][j] == buchstabe){
				geheim += tabelle[1][j];
				break;
			}
		}
	}
	return geheim;
}

//entschluss fkt

std::string entschluss(std::string wort, char tabelle[2][26]){

	std::string klar;
	for(unsigned int i=0; i<wort.length();i++){
		char buchstabe = wort[i];
		for(int j=0;j<26;j++){
			if(tabelle[0][j] == buchstabe){
				klar += tabelle[1][j];
				break;
			}
		}
	}
	return klar;
}


int main() {

	char tabelle[2][26];
	char enttabelle[2][26];
	char substitute[26] = {'M','N','O','P','Q','R','S','T','U','V',
				'W','X','Y','Z','A','B','C','D','E','F',
				'G','H','I','J','K','L' };

	for(int i=0;i<26;i++){
		tabelle[0][i] = 'A'+i;
		tabelle[1][i] = substitute[i];

		enttabelle[0][i] = substitute[i];
		enttabelle[1][i] = 'A'+i;
	}


	std::string wort;
	std::cout<<"Text in Grossbuchstaben eingeben: ";
	std::cin>>wort;
	std::string geheim = verschluss(wort,tabelle);
	std::string klar = entschluss(geheim,enttabelle);
	std::cout<<"Klartext: "<<wort<<"\n";
	std::cout<<"Geheimtext: "<<geheim<<"\n";
	std::cout<<"Entschlusselt: "<<klar;
	return 0;
}
