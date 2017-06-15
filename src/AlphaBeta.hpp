#ifndef _ALPHABETA_HPP_
#define _ALPHABETA_HPP_

#include "Joueur.hpp"
#include "array"

class AlphaBeta : public Joueur
{
	private :
		std::string _nomHumain;
	public :
		AlphaBeta(std::string nomH);
		~AlphaBeta(){};	
		Coups coup_Move(std::vector<Coups> coupsPossibles, int d, int f, Plateau & p) override ;
        int eval_Plateau(Plateau & copiePlateau);
        int getMoveAlphaBetaAux(Plateau p, int depth_max,Coups &best, int alpha, int beta);
};
#endif
