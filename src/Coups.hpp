#ifndef _COUPS_HPP_
#define _COUPS_HPP_

struct Coups
{
	int _depart;
	int _arrivee;
	Coups();
};

//Permet la comparaison entre deux Coups
bool operator==(const Coups& coup1, const Coups& coup2);
#endif
