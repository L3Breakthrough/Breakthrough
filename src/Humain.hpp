#ifndef _HUMAIN_HPP_
#define _HUMAIN_HPP_

#include "Joueur.hpp"

class Humain : public Joueur
{
	private :
		std::string _nomHumain;
	public :
		Humain(std::string nomH);
		~Humain(){};	
		Coups coup_Move(std::vector<Coups> coupsPossibles,int d,int f) override ;
};
#endif
