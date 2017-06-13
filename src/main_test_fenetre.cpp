#include "Fenetre.hpp"
#include <iostream>
#include <string>

#include "Plateau.hpp"
#include "Humain.hpp"
#include "Minmax.hpp"
#include "Ia.hpp"
using namespace std;

int main(){
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
			
			joueur1= new Humain(j1);	
			joueur2=new Humain(j2);
			
			
			break;
		case 2:
	
			joueur1=new Humain(j1);
			joueur2=new Minmax(j2);			
			break;
		case 3:
			
			joueur1=new Minmax(j1);
			joueur2=new Minmax(j2);
			break;
	}
			
		
	Plateau p ;
	//p.afficherPlateau();
	vector<Coups> V;
			
	Fenetre Ecran_Principal("Breakthrough", 1000, 600);
	sf::Texture tex_image;
	sf::Texture tex1_image;
	sf::Texture tex2_image;
	sf::Sprite j_image;

	
	Ecran_Principal.tab_coord();
	Ecran_Principal.ajouterImage('d',"../Images/damier8.png",tex2_image,j_image);
	Ecran_Principal.ajouterImage('p',"../Images/jouer.png",tex_image,j_image);
	Ecran_Principal.ajouterImage('e',"../Images/exit.png",tex1_image,j_image);
	Ecran_Principal.initialiserEcran();
	Ecran_Principal.run(V,p,joueur1,joueur2,choix);
	return 0;
}	
