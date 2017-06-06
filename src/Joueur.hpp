#ifndef Joueur_HPP
#define Joueur_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Coups.hpp"

using namespace std;
class Joueur{
	protected :
		string _nomJoueur;
		int identifiant;
	public :
		Joueur(){}
		virtual ~Joueur(){}
		virtual Coups coup_Move(vector<Coups>)=0;
		
		virtual void setIdentifiant(int ident)=0;
		virtual int getIdentifiant()=0;
		
};

#endif
