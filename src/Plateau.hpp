#ifndef _PLATEAU_HPP
#define _PLATEAU_HPP
#include "Coups.hpp"
#include <array>
#include <vector>

class Plateau{
	public :
		enum class Pion {HAUT=1,BAS=2,VIDE=0};

	private :
		static const int TAILLE=8;
		std::array<Pion,TAILLE*TAILLE> _tabPions;
		Pion _joueurCourant;
		Pion _joueurAdverse;
		
	public :
		
		Plateau();
		Plateau(const Plateau & copiePlateau);
		Plateau & operator=(const Plateau & copiePlateau);
		void initialisation();
		void setPion(int i, Pion typePion);
		Pion getPion(int i);
		Pion getJoueurCourant();
		void prochainJoueur();
		void afficherPlateau();
		std::vector<Coups> coupspossibles();
		
		void maj_Plateau(Coups coup);
		int compterPions();
		Pion courantVainqueur();
};
#endif
