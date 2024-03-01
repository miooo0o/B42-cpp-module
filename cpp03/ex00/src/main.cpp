/// @file   main.cpp
/// @author minakim
/// @date   28-Feb-2024

#include "ClapTrap/ClapTrap.h"

int	main(void)
{
	ClapTrap	claptrap("Me");

	claptrap.attack("Target");
	claptrap.takeDamage(4);
	claptrap.beRepaired(20);
	claptrap.takeDamage(10);
	claptrap.attack("Target");
	
	return (EXIT_SUCCESS);
}