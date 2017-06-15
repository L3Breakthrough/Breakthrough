#ifndef FENETRE_HPP
#define FENETRE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <random>
#include "Coordonnee.hpp"
#include "Plateau.hpp"
#include "Joueur.hpp"
#include <unistd.h>
#include "Humain.hpp"
#include "AlphaBeta.hpp"
#include "Ia.hpp"

#define xW 1000
#define z 600
#define w 600
#define t_X 150
#define t_Y 50
#define taille 8
 using namespace std;
class Fenetre{
	private :
		std::string _nomFenetre;
		unsigned _largeurEcran;
		unsigned _longueurEcran;
		std::pair<sf::RectangleShape,Plateau::Pion> maPaire;
		std::vector<std::pair<sf::RectangleShape,Plateau::Pion>> rectangle;
		std::vector<sf::Sprite> S_image;
		sf::Vector2i localPosition;
		std::vector<Coordonnee> Tab;
		std::vector<int> arrive;
		int choix;
		Joueur * joueur1;
		Joueur * joueur2;
		sf::RenderWindow window;
		sf::Event event;
	public:
		Fenetre(std::string nomFenetre,unsigned largeurEcran,unsigned longueurEcran,int choix);
		void ajouterImage(char ident,std::string cheminImage,sf::Texture & t_image,sf::Sprite image);
		sf::Sprite positionImage(char ident,sf::Sprite image);
		void tab_coord();
		void initialiserEcran();
		void setCouleur();
		void setPositionR();
		bool jouerCoup(std::vector<Coups> Ve);
		bool clicG(std::vector<Coups> Ve);
		int clicD();
		bool JoueurHumainG(std::vector<Coups> & Ve,Plateau &  p);
		void JoueurHumainD(Joueur * joueur,std::vector<Coups> & Ve,Plateau &  p);
		void IntelligenceA(Joueur * joueur1,std::vector<Coups> & Ve,Plateau &  p);
		int aleatoire(std::vector<Coups> coupsIa);
		int recherche1(sf::Vector2i localPo);
		void miseAjourInterface(Plateau & p);
		void run(vector<Coups> & Ve,Plateau &  p);
		
};
		
#endif
