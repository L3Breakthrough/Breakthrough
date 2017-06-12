#include "Plateau.hpp"
#include <iostream>
#include <utility>

Plateau::Plateau()
{
	initialisation();
}

Plateau::Plateau(const Plateau & copiePlateau)
{
	_tabPions=copiePlateau._tabPions;
	_joueurCourant=copiePlateau._joueurCourant;
	_joueurAdverse=copiePlateau._joueurAdverse;
}

Plateau& Plateau::operator=(const Plateau & PlateauCopie)
{
	if ( this != &PlateauCopie)
	{
		_tabPions=PlateauCopie._tabPions;
		_joueurCourant=PlateauCopie._joueurCourant;
		_joueurAdverse=PlateauCopie._joueurAdverse;
	}
	return *this;
}
void Plateau::setPion(int i,Pion typePion)
{
	_tabPions[i]=typePion;
}
		
Plateau::Pion Plateau::getPion(int i){
	return _tabPions[i];
}

void Plateau::initialisation()
{
	for ( int i=0; i<TAILLE*2; i++ )
		setPion(i, Pion::HAUT);
	for ( int i=TAILLE*2; i<TAILLE*TAILLE-(TAILLE*2); i++ ) 
		setPion(i, Pion::VIDE);
	for ( int i=TAILLE*TAILLE-(TAILLE*2); i<TAILLE*TAILLE; i++ )
		setPion(i, Pion::BAS);

	_joueurCourant=Pion::HAUT;
	_joueurAdverse=Pion::BAS;
}

Plateau::Pion Plateau::getJoueurCourant()
{
	return _joueurCourant;
}
		
void Plateau::prochainJoueur()
{
	std::swap(_joueurCourant, _joueurAdverse);	
}
void Plateau::afficherPlateau()
{	
	std::cout<<" //// BREAKTHROUGH //// "<<std::endl;
	for ( int i=0; i<TAILLE*TAILLE; i++ )
	{
		if ( getPion(i) == Pion::VIDE )
			std::cout<<" . ";
		if ( getPion(i) == Pion::HAUT )
			std::cout<<" h ";
		if ( getPion(i) == Pion::BAS )
			std::cout<<" b ";

		if ( i%TAILLE == TAILLE-1 )
			std::cout<<std::endl;
	}

	if( _joueurCourant == Pion::HAUT && _joueurAdverse == Pion::BAS )
	{
		std::cout<<" Joueur courant = Haut "<<std::endl;
		std::cout<<" Joueur adverse = Bas "<<std::endl;
	}
	else
	{
		if ( _joueurCourant == Pion::BAS && _joueurAdverse == Pion::HAUT )
		{
			std::cout<<" Joueur courant = Bas "<<std::endl;
			std::cout<<" Joueur adverse = Haut "<<std::endl;
		}
	}	
}

//fonction gerant la liste des coups vers l'avant et diagonales(gauche/droite)
std::vector<Coups> Plateau::coupspossibles(){
	Coups c;
	std::vector<Coups> vecCoups; 
	//On cherche le TAILLE du _tabPions
	for(unsigned int i=0; i<_tabPions.size(); i++){
		///////////Pour les pions Pion::HAUTs
	if(getJoueurCourant()== Pion::HAUT){
		if(_tabPions[i] == Pion::HAUT){		
			c._depart = i;					//On met la case de départ dans le vecteur
			c._arrivee = i+TAILLE-1;
			//gestion de l'avancement des pions pour les bord gauches et droites
			if(c._depart % TAILLE ==0){ 
				c._arrivee=i+TAILLE;
				if(_tabPions[i+TAILLE]==Pion::VIDE){
					vecCoups.push_back(c);
				}
				
				c._arrivee=i+TAILLE+1;
				if(_tabPions[i+TAILLE+1]!=Pion::HAUT){
					vecCoups.push_back(c);
				}
			}else{
				if(c._depart % TAILLE ==TAILLE-1){ //gestion de l'avancement des pions pour l'angle en haut a droite
					c._arrivee=i+TAILLE-1;
					if(_tabPions[i+TAILLE-1]==Pion::VIDE){
						vecCoups.push_back(c);
					}
				
					c._arrivee=i+TAILLE;
					if(_tabPions[i+TAILLE]!=Pion::HAUT){
						vecCoups.push_back(c);
					}
				}else{ //sinon avancee basique soit diagonale gauche/droite ou avance devant
					c._arrivee = i+TAILLE-1;				//Diagonale gauche
					if(_tabPions[i+TAILLE-1] != Pion::HAUT){			//Si différent de Pion::HAUT on push
						vecCoups.push_back(c);
					}
			
					c._arrivee = i+TAILLE;					//Case devant
					if(_tabPions[i+TAILLE] == Pion::VIDE){				//Si c'est Pion::VIDE on push
						vecCoups.push_back(c);
					}
			
					c._arrivee = i+TAILLE+1;			//Diagonale droite
					if(_tabPions[i+TAILLE+1] != Pion::HAUT){		//Si différent de Pion::HAUT on push
						vecCoups.push_back(c);
					}
				}
			}
		}
	}else{
		
			
	////////////Pour les pions Pion::BASs
			
		if(_tabPions[i] == Pion::BAS){		
			c._depart = i;					//On met la case de départ dans le vecteur
			c._arrivee = i-TAILLE-1;
			if(c._depart % TAILLE == 0){ //gestion de l'avancement des pions pour l'angle en bas a gauche
				c._arrivee=i-TAILLE;
				if(_tabPions[i-TAILLE]==Pion::VIDE){
					vecCoups.push_back(c);
				}
			
				c._arrivee=i-TAILLE+1;
				if(_tabPions[i-TAILLE+1]!=Pion::BAS){
					vecCoups.push_back(c);
				}
			}else{
				if(c._depart % TAILLE == TAILLE-1){ //gestion de l'avancement des pions pour l'angle en bas a droite
					c._arrivee=i-TAILLE-1;
					if(_tabPions[i-TAILLE-1]==Pion::VIDE){
						vecCoups.push_back(c);
					}
				
					c._arrivee=i-TAILLE;
					if(_tabPions[i-TAILLE]!=Pion::BAS){
						vecCoups.push_back(c);
					}
				}else{ //sinon avancee basique soit diagonale gauche/droite ou avance devant
					c._arrivee = i-TAILLE-1;				//Diagonale gauche
					if(_tabPions[i-TAILLE-1] != Pion::BAS){			//Si différent de Pion::BAS on push
						vecCoups.push_back(c);
					}
	
					c._arrivee = i-TAILLE;					//Case devant
					if(_tabPions[i-TAILLE] == Pion::VIDE){				//Si c'est Pion::VIDE on push
						vecCoups.push_back(c);
					}
		
					c._arrivee = i-TAILLE+1;			//Diagonale droite
					if(_tabPions[i-TAILLE+1] != Pion::BAS){		//Si différent de Pion::BAS on push
						vecCoups.push_back(c);
					}
				}
			}
		}
	}
}
	return vecCoups;
	
}

void Plateau::maj_Plateau(Coups coup)
{
	if ( _joueurCourant == Pion::HAUT )
	{
		_tabPions[coup._depart]=Pion::VIDE;
		_tabPions[coup._arrivee]=Pion::HAUT;
	}
	else
	{
		_tabPions[coup._depart]=Pion::VIDE;
		_tabPions[coup._arrivee]=Pion::BAS;
	}
	afficherPlateau();
}

int Plateau::compterPions()
{
	int nbPion=0;
	for (int i=0; i<TAILLE*TAILLE; i++)
	{
		if (_tabPions[i] == _joueurAdverse )
			nbPion+=1;
	}	
	return nbPion;
}

Plateau::Pion Plateau::courantVainqueur()
{
	for ( int i=TAILLE*TAILLE-TAILLE; i<TAILLE*TAILLE; i++ )
	{
		if( _tabPions[i] == Pion::HAUT || compterPions() == 0)
			return Pion::HAUT;
	}
	for ( int i=0; i<TAILLE ; i++ )
	{
		if( _tabPions[i] == Pion::BAS || compterPions() == 0 )
			return Pion::BAS;
	}
	return Pion::VIDE;
}
