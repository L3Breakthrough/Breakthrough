#include "Ia.hpp"

using namespace std;

Ia::Ia(string nomJ):_nomIa(nomJ){}

Coups Ia::coup_Move(vector<Coups> coupsIa){
	Coups c;
	random_device device;
	mt19937 generator(device());
	uniform_int_distribution<int> distribution(0,coupsIa.size()-1);
	int aleatoire=distribution(generator);
	c.depart=coupsIa[aleatoire].depart;
	c.arrivee=coupsIa[aleatoire].arrivee;

	return c;
}

void Ia::setIdentifiant(int ident){
	identifiant=ident;
}

int Ia::getIdentifiant(){
	return identifiant;
}

Ia::~Ia(){
	delete this;
}


