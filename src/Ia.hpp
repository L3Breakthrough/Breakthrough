#ifndef Ia_HPP
#define Ia_HPP

#include "Plateau.hpp"
#include "Joueur.hpp"

class Ia : public Joueur{
	private :
		std::string _nomIa;
	public :
		Ia(std::string nomJ);
		Coups coup_Move(std::vector<Coups>,int d,int f,Plateau & P) override ;
		//int aleatoire(vector<Coups> coupsIa);	
		//~ int eval(Plateau & copiePlateau) ;
		//~ int getMoveAlphaBetaAux(Plateau p, int depth_max,Coups &best);
		
};

#endif

