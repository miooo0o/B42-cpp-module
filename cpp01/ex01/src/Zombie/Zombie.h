
#ifndef ZOMBIE_H
#define ZOMBIE_H

# include <iostream>
# include <string>
# include <cstdlib>

using	std::cout;
using	std::endl;
using	std::flush;
using	std::string;
using	std::cerr;
using	std::cin;


class Zombie {
public:
	Zombie();
	Zombie(string);
	~Zombie();
	
	void	announce(void);
	void	named(string name);

private:
	string _name;
};

Zombie*	newZombie(string name);
void    randomChump(string name);
Zombie*	zombieHorde(int N, string name);

#endif
