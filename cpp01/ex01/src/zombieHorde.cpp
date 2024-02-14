#include "Zombie/Zombie.h"
#include <stdexcept>

/// @note try-catch, if-else NUll/nullptr
Zombie*	zombieHorde(int N, string name)
{
	Zombie	*horde;

	if (N < 1)
	{
		cerr << "number of zombie can not be under 1." << endl;
		return (nullptr);
	}
	try
	{
		horde = new Zombie[N];
		for (int i = 0; i < N; i++)
			horde[i].named(name);
		return (horde);
	}
	catch (std::bad_alloc& ex)
	{
		cerr << "allocation failed: " << ex.what() << endl;
		return (nullptr);
	}
}