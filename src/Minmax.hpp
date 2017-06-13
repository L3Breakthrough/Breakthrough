#ifndef _MINMAX_HPP_
#define _MINMAX_HPP_

#include "Joueur.hpp"
#include "array"

class Minmax : public Joueur
{
	private :
		std::string _nomHumain;
	public :
		Minmax(std::string nomH);
		~Minmax(){};	
		Coups coup_Move(std::vector<Coups> coupsPossibles, int d, int f, Plateau & p) override ;
        int eval_Plateau(Plateau & copiePlateau);
        int getMoveAlphaBetaAux(Plateau p, int depth_max,Coups &best, int alpha, int beta);
};
#endif
