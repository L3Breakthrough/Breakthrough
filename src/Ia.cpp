#include "Ia.hpp"

using namespace std;

Ia::Ia(string nomJ):_nomIa(nomJ){}


//deplacement de l'intelligence artificielle 
Coups Ia::coup_Move(vector<Coups> coupsIa,int d,int f,Plateau & p){
	Coups c;
	c._depart=coupsIa[d]._depart;
	c._arrivee=coupsIa[f]._arrivee;
	return c;	
}

/*int Ia::eval(const Plateau & copiePlateau){
    if(copiePlateau.getJoueurCourant()==copiePlateau.j_courantgagne())
        return 1000;
    else
        return -1000;
    
    int somme=0;
    

}*/


//~ int Ia::eval(Plateau & copiePlateau){
    //~ if(copiePlateau.getJoueurCourant()==copiePlateau.j_courantgagne())
        //~ return 1000;
    //~ else
        //~ return -1000;
    
    //~ int somme=0;
    //~ for (int i=0; i<8*8; i++) {
		//~ if (copiePlateau.getPion(i)==copiePlateau.Pion::NOIR){
			//~ somme+=10;
		//~ }else{
			//~ if (copiePlateau.getPion(i)==copiePlateau.Pion::BLANC){
				//~ somme-=10;
			//~ }
		//~ }
	//~ }
	//~ const int coefsPlateau[8][8]={
								//~ {5,15,15,5,5,15,15,5},
								//~ {2,3,3,3,3,3,3,2},
								//~ {4,6,6,6,6,6,6,4},
								//~ {7,10,10,10,10,10,10,7},
								//~ {11,15,15,15,15,15,15,11},
								//~ {16,21,21,21,21,21,21,16},
								//~ {20,28,28,28,28,28,28,20},
								//~ {36,36,36,36,36,36,36,36}
				   //~ };


	//~ int coefPion = Plateau::Pion::NOIR==copiePlateau.getJoueurCourant() ? 1 : -1;
	//~ for (int i=0; i<8 ;i++) {
		//~ for(int j=0;j<8;j++){
			//~ if (copiePlateau.getPion(i++)==Plateau::Pion::NOIR){
				//~ somme += coefsPlateau[i][j] * coefPion;
			//~ }else{
				//~ if (copiePlateau.getPion(i++)==Plateau::Pion::BLANC){
					//~ somme -= coefsPlateau[7-i][j] * coefPion;
				//~ }
			//~ }
		//~ }
	//~ }

	//~ return somme;
//~ }



//~ int Minmax::getMoveAlphaBetaAux(Plateau p, int depth_max,Coups &best){
	//~ if ((p.j_courantgagne()!=p.Pion::VIDE) or (depth_max <=0))
		//~ return eval(p);
	//~ int max = -100000;
	//~ int valeur;
	//~ Coups meilleur;
	//~ vector<Coups> Ve=p.coupspossibles();
	//~ Plateau p(*this);
	//~ for (unsigned i=0;i<Ve.size();i++){
		//~ Plateau pcopie=p;
		//~ pcopie.maj_Plateau(Ve[i]);
		//~ pcopie.prochainJoueurCourant();
		//~ valeur=-getMoveAlphaBetaAux(p,depth_max-1,best);
		//~ if(valeur>max){
			//~ max=valeur;
			 //~ meilleur=Ve[i];
		 //~ }
	 //~ }
	//~ best=meilleur;
	//~ return valeur;
//~ }


