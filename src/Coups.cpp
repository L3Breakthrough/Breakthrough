#include "Coups.hpp"

Coups::Coups() : _depart(-1), _arrivee(-1) {}

bool operator==(const Coups& coup1, const Coups& coup2)
{
	return ((coup1._depart == coup2._depart) && (coup1._arrivee == coup2._arrivee));
}
