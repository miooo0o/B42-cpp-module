#include "Zombie.h"

/// @brief It creates a zombie,
/// name it, and return it so you can use it outside of the function scope.
Zombie* newZombie(string name)
{
	return (new Zombie(name));
}