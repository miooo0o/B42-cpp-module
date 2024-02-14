# include "Zombie/Zombie.h"

int main(void)
{
	Zombie	*horde;
	int		n;
	
	n = 3;
	horde = zombieHorde(n, "Pikachu");
	if (horde == nullptr)
		return (EXIT_FAILURE);
	for (int i = 0; i < n; i++)
	{
		cout << "Zombie " << i << ": ";
		horde[i].announce();
	}
	delete[] horde;
	return (EXIT_SUCCESS);
}