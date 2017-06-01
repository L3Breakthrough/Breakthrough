#ifndef _Joueur_
#define _Joueur_

#include <string>
#include <vector>
#include <Coups.hpp>
class Joueur{
	private :
		std::string nomJoueur;
		
	public :
		static int identifiant;
		virtual ~Joueur();
		virtual Coups coup_Move(std::vector<Coups>)=0;
		virtual void setIdentifiant()=0;
}

#endif
