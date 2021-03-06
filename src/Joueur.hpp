#ifndef _JOUEUR_HPP_
#define _JOUEUR_HPP_

#include <vector>
#include <string>
#include "Coups.hpp"
#include "Plateau.hpp"

class Joueur
{
	public :
		Joueur(){};
		virtual ~Joueur(){};
		virtual Coups coup_Move(std::vector<Coups> coupsPossibles,Plateau & p)=0;
};

#endif
