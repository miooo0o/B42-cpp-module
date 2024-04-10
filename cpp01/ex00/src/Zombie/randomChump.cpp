#include "Zombie.h"

/// @brief It creates a zombie, name it, and the zombie announces itself.
void	randomChump(string name)
{
	Zombie	new_zombie(name);

	new_zombie.announce();
}