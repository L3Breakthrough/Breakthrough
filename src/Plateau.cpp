#include "Plateau.hpp"

using namespace std;

Plateau::Plateau(Joueur & j1, Joueur & j2,int taille):_ptr_Joueur1(&j1),_ptr_Joueur2(&j2),_taille(taille){}

void Plateau::initialiser(){
	int i;
	
	for(i=0;i<_taille*2;i++)  { // boucle pour remplir les deux premieres lignes du plateau de pions noirs
		plateau.push_back(n);
	}
	
	for(i=_taille*2;i<_taille*_taille-(_taille*2);i++) { //Remplir les lignes vides par un point 
		plateau.push_back(v);		        	
	}
	
	for(i=_taille*_taille-(_taille*2);i<_taille*_taille;i++)  { // boucle pour remplir les deux dernieres lignes du plateau de pions blancs  
	    plateau.push_back(b);
	}		
}

char Plateau::getPion(int i){
	return plateau[i];
}


void Plateau::afficher(){
	cout<<" //////Breakthrough////// "<< endl;
	for(int i=0; i<_taille*_taille; i++){
		cout <<" "<<plateau[i];
		
		if(i%_taille==_taille-1){
			cout << "\n";	
		}
	}
}

int Plateau::compterPions(char couleur){
	int nbPion = 0;
	int i;
	for(i=0; i<_taille*_taille; i++){
		if(plateau[i] == couleur){
			nbPion = nbPion + 1;
		}
	}
		return nbPion;
}

const vector<Coups> Plateau::coupspossibles(int identifiant){
	Coups c;
	vector<Coups> vecCoups; 
	//On cherche le _taille du plateau
	for(unsigned int i=0; i<plateau.size(); i++){
		///////////Pour les pions noirs
	if(identifiant==0){
		if(plateau[i] == n){		
			c.depart = i;					//On met la case de départ dans le vecteur
			c.arrivee = i+_taille-1;
			if(c.depart % _taille ==0){ //gestion de l'avancement des pions pour l'angle en haut a gauche
				c.arrivee=i+_taille;
				if(plateau[i+_taille]==v){
					vecCoups.push_back(c);
				}
				
				c.arrivee=i+_taille+1;
				if(plateau[i+_taille+1]!=n){
					vecCoups.push_back(c);
				}
			}else{
				if(c.depart % _taille ==_taille-1){ //gestion de l'avancement des pions pour l'angle en haut a droite
					c.arrivee=i+_taille-1;
					if(plateau[i+_taille-1]==v){
						vecCoups.push_back(c);
					}
				
					c.arrivee=i+_taille;
					if(plateau[i+_taille]!=n){
						vecCoups.push_back(c);
					}
				}else{ //sinon avancee basique soit diagonale gauche/droite ou avance devant
					c.arrivee = i+_taille-1;				//Diagonale gauche
					if(plateau[i+_taille-1] != n){			//Si différent de noir on push
						vecCoups.push_back(c);
					}
			
					c.arrivee = i+_taille;					//Case devant
					if(plateau[i+_taille] == v){				//Si c'est vide on push
						vecCoups.push_back(c);
					}
			
					c.arrivee = i+_taille+1;			//Diagonale droite
					if(plateau[i+_taille+1] != n){		//Si différent de noir on push
						vecCoups.push_back(c);
					}
				}
			}
		}
	}else{
		
			
	////////////Pour les pions blancs
			
		if(plateau[i] == b){		
			c.depart = i;					//On met la case de départ dans le vecteur
			c.arrivee = i-_taille-1;
			if(c.depart % _taille == 0){ //gestion de l'avancement des pions pour l'angle en bas a gauche
				c.arrivee=i-_taille;
				if(plateau[i-_taille]==v){
					vecCoups.push_back(c);
				}
			
				c.arrivee=i-_taille+1;
				if(plateau[i-_taille+1]!=b){
					vecCoups.push_back(c);
				}
			}else{
				if(c.depart % _taille == _taille-1){ //gestion de l'avancement des pions pour l'angle en bas a droite
					c.arrivee=i-_taille-1;
					if(plateau[i-_taille-1]==v){
						vecCoups.push_back(c);
					}
				
					c.arrivee=i-_taille;
					if(plateau[i-_taille]!=b){
						vecCoups.push_back(c);
					}
				}else{ //sinon avancee basique soit diagonale gauche/droite ou avance devant
					c.arrivee = i-_taille-1;				//Diagonale gauche
					if(plateau[i-_taille-1] != b){			//Si différent de noir on push
						vecCoups.push_back(c);
					}
	
					c.arrivee = i-_taille;					//Case devant
					if(plateau[i-_taille] == v){				//Si c'est vide on push
						vecCoups.push_back(c);
					}
		
					c.arrivee = i-_taille+1;			//Diagonale droite
					if(plateau[i-_taille+1] != b){		//Si différent de noir on push
						vecCoups.push_back(c);
					}
				}
			}
		}
	}
}
	return vecCoups;
	
}
	
		
	//~ 
//~ void Plateau::lireFichier(const string & nomFichier){
	//~ 
        //~ ifstream fichier("test.txt", ios::in);  // on ouvre en lecture
 //~ 
        //~ if(fichier)  // si l'ouverture a fonctionné
        //~ {
			  //~ string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
			//~ while(getline(fichier, contenu)){
                //~ cout << contenu;  // on affiche la ligne
		//~ }
                //~ fichier.close();
        //~ }
        //~ else
                //~ cerr << "Impossible d'ouvrir le fichier !" << endl;
 //~ 
 //~ }
		//~ 
//~ void const Plateau::ecrireFichier(const string & nomFichier){
	//~ ofstream fichier("test.txt", ios::app);
	//~ if(fichier){
		//~ for(int i=0; i<2; i++){
			//~ for(int j=0 ; j<this->_taille; j++){
				//~ fichier << b << endl;
			//~ }
			//~ fichier << '\n' << endl;
		//~ }
		//~ 
		//~ for (int k=0; k< this->_taille-4 ; k++){
			//~ for(int l=0 ; l< this->_taille; l++){
				//~ fichier << v << endl;
			//~ }
			//~ fichier << '\n' << endl;
		//~ }
		//~ 
		//~ for(int m = 0; m<2; m++){
			//~ for(int n =0; n<this->_taille; n++){
				//~ fichier << b << endl;
			//~ }
			//~ fichier << '\n' << endl;
		//~ }
		//~ 
	//~ }
	

		
//~ istream Plateau::&operator>>(istream & is, Joueur & j_courant)
		//~ 
//~ ostream Plateau::&operator<<(ostream & os, Joueur & j_courant)
		//~ 

void Plateau::maj_Plateau(Coups coup,Joueur & j){
	
	if(j.getIdentifiant()==0){
		plateau[coup.depart]=v;
		plateau[coup.arrivee]=n;
	}else{
		plateau[coup.depart]=v;
		plateau[coup.arrivee]=b;
	}
	afficher();
	
}
		
		
		
int Plateau::j_courantgagne(){
	for(int i=_taille*_taille-_taille;i<_taille*_taille;i++){
		if(compterPions(b)==0 || getPion(i)==n ){
		//si pions adverses a zeros ou derniere ligne 
			cout << "Le joueur noir a gagne !"<<endl;
			return 1;
		}
	}
	for(int i=0;i<_taille;i++){
		if(compterPions(n)==0 || getPion(i)==b){
		//si pions adverses a zeros ou derniere ligne 
			cout << "Le joueur blanc a gagne !"<<endl;
			return 1;
		}
	}
	return 0;
}
