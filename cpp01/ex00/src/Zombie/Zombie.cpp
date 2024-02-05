#include "Zombie.h"

Zombie::Zombie(void) : _name("foo"){};
Zombie::Zombie(string name) : _name(name)
{
	cout << _name << "!" << endl;
};

Zombie::~Zombie(void){};

void	Zombie::announce(void)
{
	cout << _name << ": BraiiiiiiinnnzzzZ..." << endl;
}