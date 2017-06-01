#ifndef Ia
#define _Ia_


class Ia : public Joueur{
	public :
		Ia(string nomJ);
		Coups coup_Move(std::vector<Coups>) override ;	
		void setIdentifiant() override;
}

#endif
