#ifndef _Humain_HPP
#define _Humain_HPP

#include "Joueur.hpp"

class Humain : public Joueur{
	private :
		string _nomH;
		
	public :
		Humain(string nomJ);
		~Humain();
		Coups coup_Move(std::vector<Coups>) override ;
		void setIdentifiant(int ident) override;
		int getIdentifiant();
};

#endif
