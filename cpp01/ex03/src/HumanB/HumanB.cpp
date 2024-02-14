#include "HumanB.h"

HumanB::HumanB(string name)
		: _name(name), _weapon("unset"), _is_armed(false) {};

HumanB::~HumanB(void) {};

void	HumanB::setWeapon(Weapon new_weapon)
{
		_weapon = new_weapon.getType();
		_is_armed = true;
}

void	HumanB::attack(void)
{
	if (!_name.empty() && _name.size() > 0)
	{
		if (_is_armed)
			cout << _name << " attacks with their " << _weapon.getType() << endl;
		else
			cout << _name << " attacks with their " << _weapon.getType() << endl;
		return ;
	}
	cerr << "error: human B: name non set" <<endl;
}