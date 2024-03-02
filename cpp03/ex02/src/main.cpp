/// @file   main.cpp
/// @author minakim
/// @date   28-Feb-2024

#include "FragTrap/FragTrap.h"
#include "ScavTrap/ScavTrap.h"

int	main(void)
{
	ClapTrap	clap("Clap");
	ScavTrap	scav("scav");
	FragTrap	frag("frag");

	clap.attack("Target");
	clap.takeDamage(4);
	clap.beRepaired(20);
	clap.takeDamage(10);
	clap.attack("Target");
	
	scav.attack("Target");
	scav.guardGate();
	
	frag.attack("Target");
	frag.highFivesGuys();
	
	return (EXIT_SUCCESS);
}