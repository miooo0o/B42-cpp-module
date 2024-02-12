#ifndef WEAPON_H
#define WEAPON_H

#include "macro.h"

class Weapon {

public:
	Weapon(void);
	Weapon(string);
	~Weapon(void);
	string	getType(void) const;
	void	setType(string pram);
private:
	string	_type;
};


#endif