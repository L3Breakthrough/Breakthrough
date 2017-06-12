#ifndef _JOUEUR_HPP_
#define _JOUEUR_HPP_

#include <vector>
#include <string>
#include "Coups.hpp"

class Joueur
{
	public :
		Joueur(){};
		virtual ~Joueur(){};
		virtual Coups coup_Move(std::vector<Coups> coupsPossibles,int d,int f)=0;
};

#endif
