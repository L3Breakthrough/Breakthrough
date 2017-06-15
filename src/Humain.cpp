#include "Humain.hpp"
#include <vector>

using namespace std;

Humain::Humain(string nomJ):_nomHumain(nomJ){}

//deplacement de l'humain avec choix points de departs et points d'arrivees
Coups Humain::coup_Move(vector<Coups> coupsHumain,Plateau & p){
	
	Coups c;
	unsigned i=0;
    while(!(coupsHumain[i]==c)){
	    c._depart=p.getd();
	    c._arrivee=p.getf();	
        for(i=0;i<coupsHumain.size();i++){
		   if(coupsHumain[i] == c){
                break;
           }
	    }
	}
	return c;
}
