#include "HumanA.h"

HumanA::HumanA(string name, Weapon weapon)
: _name(name), _weapon(weapon), _is_armed(true) {};

HumanA::~HumanA(void) {};

void	HumanA::attack(void)
{
	if (!_name.empty() && _name.size() > 0)
	{
		if (_is_armed)
			cout << _name << " attacks with their " << _weapon.getType() << endl;
		else
			cout << _name << " attacks with their " << _weapon.getType() << endl;
		return ;
	}
	cerr << "error: human A: name non set" <<endl;
}