#ifndef PLATEAU_HPP
#define PLATEAU_HPP
#include <iostream>
#include <string>
#include <vector>
#include <fstream> //librairie pour la gestion du fichier

#include "Coups.hpp"
#include "Joueur.hpp"

const char n ='n'; //la lettre symbolise les pions noir
const char v = '.'; //symbolise les pions vides 
const char b = 'b'; //symbolise les pions blancs

class Plateau{
	private:
		std::vector<char> plateau;
		Joueur * _ptr_Joueur1;
		Joueur * _ptr_Joueur2;
		int _taille;
		//int _mode;
		//vector<Coups> coups_Possible;
	public:
		Plateau();
		Plateau( Joueur & j1, Joueur & j2,int taille);
		//~ Plateau(int taille);
		void initialiser();
		void afficher();
		char getPion(int i);
		int compterPions(char couleur); 
		const std::vector<Coups> coupspossibles(int ident);
		//~ void lireFichier(const string & nomFichier);
		//~ void const ecrireFichier(const string & nomFichier);
		//~ istream &operator>>(istream & is, Joueur & j_courant);
		//~ ostream &operator<<(ostream & os, Joueur & j_courant);
		void maj_Plateau(Coups  coup,Joueur & j);
		int j_courantgagne();
	};
#endif
