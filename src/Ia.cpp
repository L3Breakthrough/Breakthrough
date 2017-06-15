#include "Ia.hpp"
#include <random>
using namespace std;

Ia::Ia(string nomJ):_nomIa(nomJ){}


//deplacement de l'intelligence artificielle 
Coups Ia::coup_Move(vector<Coups> coupsIa,Plateau & p){
	random_device device; 
	mt19937 generator(device());
	uniform_int_distribution<int> distribution(0,coupsIa.size()-1);
	p.setd(distribution(generator));
		
	Coups c;
	c._depart=coupsIa[p.getd()]._depart;
	c._arrivee=coupsIa[p.getd()]._arrivee;
	return c;	
}
