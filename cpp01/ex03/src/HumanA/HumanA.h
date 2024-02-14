#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon/Weapon.h"

class HumanA {
public:
	HumanA(string name, Weapon weapon);
	~HumanA(void);
	
	void	attack(void);
private:
	string	_name;
	Weapon	_weapon;
	bool	_is_armed;
};

#endif