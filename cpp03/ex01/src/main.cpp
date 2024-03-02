/// @file   main.cpp
/// @author minakim
/// @date   28-Feb-2024

#include "ScavTrap/ScavTrap.h"

int	main(void)
{
	ClapTrap	clap("Clap");
	ScavTrap	scav("scav");
	
	clap.attack("Target");
	clap.takeDamage(4);
	clap.beRepaired(20);
	clap.takeDamage(10);
	clap.attack("Target");
	
	scav.attack("Target");
	scav.guardGate();
	return (EXIT_SUCCESS);
}