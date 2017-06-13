#include "Minmax.hpp"
#include <iostream>
using namespace std;

Minmax::Minmax(std::string nomH) : _nomHumain(nomH)
{
 
}

int Minmax::eval_Plateau(Plateau & copiePlateau)
{
    int somme=0;
    
    if ( copiePlateau.getJoueurCourant() == copiePlateau.courantVainqueur() )
        return 1000;

    if ( copiePlateau.getJoueurAdverse() ==copiePlateau.courantVainqueur()  )
        return -1000;
    
    for ( int i=0; i<copiePlateau.TAILLE; i++ )
    {
        for ( int j=0; j<copiePlateau.TAILLE; j++)
        {
            if ( copiePlateau.getPion2D(i,j) == copiePlateau.getJoueurCourant() )
            {
                somme+=10;
            }
            else
            {
               if ( copiePlateau.getPion2D(i,j) == copiePlateau.getJoueurAdverse() ) 
               {
                    somme-=10;
               }
            }
    
        }
    
    }
        
	const int coefsPlateau[8][8]={
								 {5,15,15,5,5,15,15,5},
								 {2,3,3,3,3,3,3,2},
								 {4,6,6,6,6,6,6,4},
								 {7,10,10,10,10,10,10,7},
								 {11,15,15,15,15,15,15,11},
								 {16,21,21,21,21,21,21,16},
								 {20,28,28,28,28,28,28,20},
								 {36,36,36,36,36,36,36,36}
				                 };
        
				                 
				                 


	int coefPion = Plateau::Pion::HAUT==copiePlateau.getJoueurCourant() ? 1 : -1;

    for (int i=0; i<8 ;i++) {
		 for(int j=0;j<8;j++){
			if (copiePlateau.getPion2D(i,j)==Plateau::Pion::HAUT){
				somme += coefsPlateau[i][j] * coefPion;
			}else{
				if (copiePlateau.getPion2D(i,j)==Plateau::Pion::BAS){
					somme -= coefsPlateau[7-i][j] * coefPion;
				}
		     }
		 }
	}
     return somme;   
}

int Minmax::getMoveAlphaBetaAux(Plateau p, int depth_max,Coups &best, int  alpha, int  beta){
	if ((p.courantVainqueur()!=p.Pion::VIDE) or (depth_max ==0)){
		return eval_Plateau(p);
	}	

	int valeur;
	Coups meilleur;
	vector<Coups> Va=p.coupspossibles();
    
	for (unsigned i=0;i<Va.size();i++){
        Plateau pcopie=p;
		pcopie.maj_Plateau(Va[i]);
		valeur=-getMoveAlphaBetaAux(pcopie,depth_max-1,best, -beta, -alpha);
		if(valeur>alpha){
			alpha=valeur;
			meilleur=Va[i];
            if( alpha >= beta)
               break;
		 }
	 }
	best=meilleur;
	return alpha;
    //~ std::cout<<"Best = "<<best._depart<<std::endl;
}
Coups Minmax::coup_Move(std::vector<Coups> coupsPossibles, int d, int f,  Plateau & p)
{
    Coups c;
    getMoveAlphaBetaAux(p,3,c, -10000, 10000);
    return c;
}
