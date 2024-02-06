#include "Zombie.h"

Zombie::Zombie(void) : _name("noname")
{
	cout << "Wild " << _name << " appeared!" << endl;
}

Zombie::Zombie(string name) : _name(name)
{
	cout << "Wild " << _name << " appeared!" << endl;
}

Zombie::~Zombie(void)
{
	cout << "Oh no! The wild " << _name << " fled!" << endl;

}

void	Zombie::announce(void)
{
	cout << _name << ": BraiiiiiiinnnzzzZ..." << endl;
}

void	Zombie::named(string name)
{
	_name = name;
}