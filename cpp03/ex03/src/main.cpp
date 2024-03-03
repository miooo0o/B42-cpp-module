/// @file   main.cpp
/// @author minakim
/// @date   28-Feb-2024

#include "FragTrap/FragTrap.h"
#include "ScavTrap/ScavTrap.h"
#include "DiamondTrap/DiamondTrap.h"

int	main(void)
{
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "constructor:" << std::endl;
	
	ClapTrap	clap("clap");
	ScavTrap	scav("scav");
	FragTrap	frag("frag");
	DiamondTrap	diamond("diamond");
	
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << std::endl
			<< "| Clap Trap |"
			<< std::endl << std::endl;
	clap.attack("Target");
	clap.takeDamage(4);
	clap.beRepaired(20);
	clap.takeDamage(10);
	clap.attack("Target");
	clap.takeDamage(20);
	clap.attack("Target");
	clap.beRepaired(0);
	
	
	std::cout << std::endl << std::endl
			<< "| Scav Trap |"
			<< std::endl << std::endl;
	
	scav.attack("Target");
	scav.takeDamage(4);
	scav.beRepaired(20);
	scav.takeDamage(10);
	scav.guardGate();
	scav.takeDamage(110);
	scav.guardGate();
	
	std::cout << std::endl << std::endl
			<< "| Frag Trap |"
			<< std::endl << std::endl;
	
	frag.attack("Target");
	frag.takeDamage(4);
	frag.beRepaired(20);
	frag.takeDamage(10);
	frag.highFivesGuys();
	frag.takeDamage(130);
	frag.highFivesGuys();
	
	std::cout << std::endl << std::endl
			  << "| Diamond Trap |"
			  << std::endl << std::endl;
	diamond.print_status();
	diamond.attack("Target");
	diamond.whoAmI();
	diamond.print_status();
	
	std::cout << std::endl
			<< "------------------------------------------------------------" << std::endl;
	std::cout << "destructor call:" << std::endl;
	return (EXIT_SUCCESS);
}