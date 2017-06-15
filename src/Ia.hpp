#ifndef Ia_HPP
#define Ia_HPP

#include "Plateau.hpp"
#include "Joueur.hpp"

class Ia : public Joueur{
	private :
		std::string _nomIa;
	public :
		Ia(std::string nomJ);
		Coups coup_Move(std::vector<Coups>,Plateau & P) override ;
		
		
};

#endif

