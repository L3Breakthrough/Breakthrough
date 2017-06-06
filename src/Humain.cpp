#include "Humain.hpp"

using namespace std;

Humain::Humain(string nomJ):_nomH(nomJ){}

Coups Humain::coup_Move(vector<Coups> coupsHumain){
	Coups c;
	for(unsigned i=0;i<coupsHumain.size();i++){
		cout<<coupsHumain[i].depart<<"  "<<coupsHumain[i].arrivee<<endl;
	}
	cout<<"depart : "<<endl;
	cin>>c.depart;
	cout<<"Arrivée : "<<endl;
	cin>>c.arrivee;
	
	return c;
}

void Humain::setIdentifiant(int ident){
	identifiant=ident;
}

int Humain::getIdentifiant(){
	return identifiant;
}

Humain::~Humain(){
	delete this;
}

