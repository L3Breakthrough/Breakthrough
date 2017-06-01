#ifndef _Humain_
#define _Humain_


class Humain : public Joueur{
	public :
		Humain(string nomJ);
		Coups coup_Move(std::vector<Coups>) override;
		void setIdentifiant() override;
}

#endif
