#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon/Weapon.h"

class HumanB {
public:
	HumanB(string name);
	~HumanB(void);
	
	void	attack(void);
	void	setWeapon(Weapon new_weapon);
private:
	string	_name;
	Weapon	_weapon;
	bool	_is_armed;
};

#endif
