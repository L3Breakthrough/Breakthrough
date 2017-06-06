#ifndef Ia_HPP
#define Ia_HPP
#include <random>
#include "Joueur.hpp"

class Ia : public Joueur{
	private :
		string _nomIa;
	public :
		Ia(string nomJ);
		~Ia();
		Coups coup_Move(std::vector<Coups>) override ;	
		void setIdentifiant(int ident) override;
		int getIdentifiant();
		
};

#endif
