#include "Fenetre.hpp"

Fenetre::Fenetre(std::string nomFenetre, unsigned largeurEcran, unsigned longueurEcran) 
: _nomFenetre(nomFenetre), _largeurEcran(largeurEcran), _longueurEcran(longueurEcran),
window(sf::VideoMode(_largeurEcran,_longueurEcran), _nomFenetre,sf::Style::Close)
{}


void Fenetre::ajouterImage(char ident,std::string cheminImage,sf::Texture & t_image,sf::Sprite image){
	if(!t_image.loadFromFile(cheminImage)){
		std::cout<<"Error"<<std::endl;
		
	}else{
		image.setTexture(t_image);	
		image=positionImage(ident,image);
		S_image.push_back(image);
	}
}


sf::Sprite Fenetre::positionImage(char ident,sf::Sprite image){	
	if(ident=='p'){	
		image.setPosition(0.5*(xW+z-t_X),0.25*(w-2*t_Y));	
	}else{
		if(ident=='e'){	
			image.setPosition(0.5*(xW+z-t_X),0.25*(3*w-2*t_Y));	
		}
	}
	return image;
}


void Fenetre::tab_coord(){
	Coordonnee c;
	c.y=0;
	c.y1=z/8;
	for(int i=0;i<8;i++){
		c.x=0;
		c.x1=z/8;
		for(int j=0;j<8;j++){
			Tab.push_back(c);
			c.x+=z/8;
			c.x1+=z/8;
		}
		c.y+=z/8;
		c.y1+=z/8;
	}
}

void Fenetre::initialiserEcran(){
	int i;
	
	for(i=0;i<taille*2;i++)  {
		maPaire.first=sf::RectangleShape (sf::Vector2f(25, 25));
		maPaire.second=Plateau::Pion::HAUT;
		rectangle.push_back(maPaire);	
	}
	
	for(i=taille*2;i<taille*taille-(taille*2);i++) { 
		maPaire.first=sf::RectangleShape (sf::Vector2f(25, 25));
		maPaire.second=Plateau::Pion::VIDE;
		rectangle.push_back(maPaire);		       	
	}
	
	for(i=taille*taille-(taille*2);i<taille*taille;i++)  { 
	   maPaire.first=sf::RectangleShape (sf::Vector2f(25, 25));
		maPaire.second=Plateau::Pion::BAS;
		rectangle.push_back(maPaire);	
	}	
	setPositionR();
	setCouleur();
}

void Fenetre::setPositionR(){
	for(int i=0;i<taille*taille;i++)  { 
		rectangle[i].first.setPosition(Tab[i].x+25,Tab[i].y+25);	
	}
}


void Fenetre::setCouleur(){
	int i;
	
	for(i=0;i<taille*2;i++)  { 
		rectangle[i].first.setFillColor(sf::Color(255,0,0,255));	
	}
	for(i=taille*2;i<taille*taille-(taille*2);i++) { 
		rectangle[i].first.setFillColor(sf::Color(0,0,0,0));	       	
	}
	for(i=taille*taille-(taille*2);i<taille*taille;i++)  { 
		rectangle[i].first.setFillColor(sf::Color(0,0,255,255));	
	}		
}

void Fenetre::miseAjourInterface(Plateau & p){
	//~ std::vector<Plateau::Pion> _tabPions=p.get_();
	for(int i=0; i<taille*taille; i++){
		if(p.getPion(i)==p.Pion::HAUT){
			rectangle[i].first.setFillColor(sf::Color(255,0,0,255));
			rectangle[i].second=p.Pion::HAUT;
		}else{	
			if(p.getPion(i)==p.Pion::BAS){
				rectangle[i].first.setFillColor(sf::Color(0,0,255,255));
				rectangle[i].second=p.Pion::BAS;
			}else{
				rectangle[i].first.setFillColor(sf::Color(0,0,0,0));
				rectangle[i].second=p.Pion::VIDE;
			}
		}
	}
}

int Fenetre::recherche1(sf::Vector2i localPo){
	int f=0;
	int j=0;
	
	while(f<(int)Tab.size()){
		if(localPo.x>=Tab[f].x && localPo.x<=Tab[f].x1
			&& localPo.y>=Tab[f].y && localPo.y<=Tab[f].y1 ){
			j=f;
			f=(int)Tab.size();
		}else{
			f++;
		}
	}
	return j;
}


			
bool Fenetre::jouerCoup(std::vector<Coups> Ve){
	bool verif=true;
	verif=clicG(Ve);
	if(verif){
		return 1;
	}else{
		return 0;
	}
}


bool Fenetre::clicG(std::vector<Coups> Ve){
	unsigned g;
	arrive.clear();
	localPosition = sf::Mouse::getPosition(window);
	int j=recherche1(localPosition);
	arrive.push_back(j);
	for(g=0;g<Ve.size();g++){
		if(j==Ve[g]._depart){
			rectangle[Ve[g]._arrivee].first.setFillColor(sf::Color(0,255,0,100));
			arrive.push_back(Ve[g]._arrivee);
		}
	}				
	if(arrive.size()==1){
		return 0;
	}else{
		return 1;
	}
}	


		
int Fenetre::clicD(){
	int retour;
	localPosition = sf::Mouse::getPosition(window);
	retour=recherche1(localPosition);
	return retour;		
}		

int Fenetre::aleatoire(std::vector<Coups> coupsIa){
	random_device device; //pour l'instant il s'agit d'un random
	mt19937 generator(device());
	uniform_int_distribution<int> distribution(0,coupsIa.size()-1);
	int aleatoire=distribution(generator);
	return aleatoire;
}

bool Fenetre::JoueurHumainG(std::vector<Coups> & Ve,Plateau &  p){
	bool a=false;
	Ve = p.coupspossibles();
	a=jouerCoup(Ve);
	miseAjourInterface(p);
	a=jouerCoup(Ve);
	return a;
}

void Fenetre::JoueurHumainD(Joueur * joueur,std::vector<Coups> & Ve,Plateau &  p){
	int r=clicD();
	p.maj_Plateau(joueur->coup_Move(Ve,arrive[0],r));
	miseAjourInterface(p);
	p.prochainJoueur();
}

void Fenetre::IntelligenceA(Joueur * joueur,std::vector<Coups> & Ve,Plateau &  p){
	Ve = p.coupspossibles();
	int alea = aleatoire(Ve);
	p.maj_Plateau(joueur->coup_Move(Ve,alea,alea));
	miseAjourInterface(p);
	p.prochainJoueur();
}

void Fenetre::run(vector<Coups> & Ve,Plateau & p,Joueur *joueur1,Joueur * joueur2,int choix){
	//Boucle de jeu
	bool a=false;
	while(window.isOpen())
	{
		//Gestion des événements
		sf::Event event;
		while(window.pollEvent(event))
		{
			
			
			//Fermeture de la fenêtre
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
			
			if (event.type == sf::Event::MouseButtonPressed){
				if (event.mouseButton.button == sf::Mouse::Left){
					if(event.mouseButton.x>=S_image[2].getPosition().x
						&& event.mouseButton.x<=S_image[2].getPosition().x+t_X
						&& event.mouseButton.y>=S_image[2].getPosition().y
						&& event.mouseButton.y<=S_image[2].getPosition().y+t_Y){
				
						window.close();
					}
				}
			}
		}
		window.clear(sf::Color(96, 96, 96, 255));
		for(int i=0;i<(int)S_image.size();i++){
			window.draw(S_image[i]);
		}
		
		
		for(int j=0;j<(int)rectangle.size();j++){
			window.draw(rectangle[j].first);
		}
	
		window.display();
		
		if(p.getJoueurCourant()==p.Pion::HAUT){	
			if(choix==1 || choix==2){
				//clic gauche
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
					if(rectangle[recherche1(sf::Mouse::getPosition(window))].second==p.getJoueurCourant()){
						a=JoueurHumainG(Ve,p);
					}
				}
				//clic droit
				if(a && sf::Mouse::isButtonPressed(sf::Mouse::Right) 
					&& rectangle[recherche1(sf::Mouse::getPosition(window))].first.getFillColor()==sf::Color(0,255,0,100)){
			
					JoueurHumainD(joueur1,Ve,p);
				}
			}else{
				//miseAjourInterface(p);
				sleep(2);
				IntelligenceA(joueur1,Ve,p);
			}	
				
		}else{
			if(p.getJoueurCourant()==p.Pion::BAS){
				if(choix==1){
					//clic gauche
					if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
						if(rectangle[recherche1(sf::Mouse::getPosition(window))].second==p.getJoueurCourant()){
							a=JoueurHumainG(Ve,p);
						}
					}
				//clic droit
					if(a && sf::Mouse::isButtonPressed(sf::Mouse::Right) 
						&& rectangle[recherche1(sf::Mouse::getPosition(window))].first.getFillColor()==sf::Color(0,255,0,100)){
						
						JoueurHumainD(joueur2,Ve,p);
					}
				}else{
					sleep(2);
					IntelligenceA(joueur2,Ve,p);
				}	
			}
		}
	
		if(p.courantVainqueur()!=p.Pion::VIDE){
			window.close();
		}
	}
}
