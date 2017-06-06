#include <iostream>
#include <string>
#include <unistd.h>
#include "Plateau.hpp"
#include "Humain.hpp"
#include "Ia.hpp"
using namespace std;

int main(){
	cout<<"Taille Plateau : "<<endl;
	int taille;
	cin>>taille;
	cout<<"                      _________________________"<<endl<<endl;
	cout<<"                         Choisir type de jeu"<<endl;
	cout<<"                      _________________________"<<endl<<endl;
	cout<<"                         1. Joueur vs Joueur"<<endl<<endl;
	cout<<"                         2. Joueur vs Ia"<<endl<<endl;
	cout<<"                         3. Ia vs Ia"<<endl<<endl;
	cout<<"                         Quel est ton choix ?"<<endl<<endl;
	int choix;
	cin>>choix;
	cout<<"Nom Joueur 1 : "<<endl;
	string j1;
	cin>>j1;
	
	cout<<"Nom Joueur 2 : "<<endl;
	string j2;
	cin>>j2;
	Joueur * joueur1;
	Joueur * joueur2;
	switch(choix){
		case 1:
			
			joueur1=new Humain(j1);
			joueur1->setIdentifiant(0);
			
			
			joueur2=new Humain(j2);
			joueur2->setIdentifiant(1);
			
			break;
		case 2:
			
			joueur1=new Humain(j1);
			joueur1->setIdentifiant(0);
			
		
			joueur2=new Ia(j2);
			joueur2->setIdentifiant(1);
			
			break;
		case 3:
			
			joueur1=new Ia(j1);
			joueur1->setIdentifiant(0);
			
			
			joueur2=new Ia(j2);
			joueur2->setIdentifiant(1);
			
			break;
	}
			
		
	Plateau p(*joueur1,*joueur2,taille) ;
	p.initialiser();
	p.afficher();
	vector<Coups> V;
	

	int i=joueur1->getIdentifiant();
	
	while(p.j_courantgagne()==0){
		if(i==0){
			V = p.coupspossibles(joueur1->getIdentifiant());
			
			p.maj_Plateau(joueur1->coup_Move(V),*joueur1);

			
			i++;
		}else{
			if(i==1){
				V = p.coupspossibles(joueur2->getIdentifiant());
			
				p.maj_Plateau(joueur2->coup_Move(V),*joueur2);
			
				i--;
			}
		}
		if(choix==3){
			sleep(3);
		}
			
	}
	
	
	
return 0;
}
