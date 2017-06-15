#include "Fenetre.hpp"
#include <iostream>
#include <string>

#include "Plateau.hpp"
#include "Humain.hpp"
#include "AlphaBeta.hpp"
#include "Ia.hpp"
using namespace std;

int main(){

	
	
			
		
	Plateau p ;
	vector<Coups> V;
			
	Fenetre Ecran_Principal("Breakthrough", 1000, 600,0);
	sf::Texture tex_image;
	sf::Texture tex1_image;
	sf::Texture tex2_image;
	sf::Texture tex3_image;
	sf::Texture tex4_image;
	sf::Texture tex5_image;
	sf::Texture bleugagne;
	sf::Texture rougegagne;
	sf::Texture tex6_image;
	sf::Sprite j_image;

	
	Ecran_Principal.tab_coord();
	Ecran_Principal.ajouterImage('d',"../Images/damier8.png",tex2_image,j_image);
	Ecran_Principal.ajouterImage('p',"../Images/jouer.png",tex_image,j_image);
	Ecran_Principal.ajouterImage('j',"../Images/HvsH.png",tex3_image,j_image);
	Ecran_Principal.ajouterImage('i',"../Images/HvsIA.png",tex4_image,j_image);
	Ecran_Principal.ajouterImage('a',"../Images/RvsIA.png",tex6_image,j_image);
	Ecran_Principal.ajouterImage('e',"../Images/exit.png",tex1_image,j_image);
	Ecran_Principal.ajouterImage('g',"../Images/rougegagne.png",rougegagne,j_image);;
	Ecran_Principal.ajouterImage('g',"../Images/bleugagne.png",bleugagne,j_image);
	Ecran_Principal.initialiserEcran();
	
	Ecran_Principal.run(V,p);
	return 0;
}	
