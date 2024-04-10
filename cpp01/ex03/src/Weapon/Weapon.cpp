#include "Weapon.h"

/// @note constructor
Weapon::Weapon(void) : _type("unfinished magic sword") {};

Weapon::Weapon(string weapon) : _type(weapon) {};

Weapon::~Weapon(void) {};

string	Weapon::getType(void) const
{
	return (_type);
}

void	Weapon::setType(string pram)
{
	_type = pram;
}