/// @file   DiamondTrap.cpp
/// @author minakim
/// @date   03-Mar-2024

#include "DiamondTrap.h"


/// @brief	constructor
DiamondTrap::DiamondTrap(void)
		: ClapTrap(), FragTrap(), ScavTrap(), _name("default")
{
	ClapTrap::_name += "_clap_name";
	announce("constructor called");
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(), FragTrap(), ScavTrap(), _name(name)
{
	ClapTrap::_name = name + "_clap_name";
	announce("the constructor is called."
			 "this values initialized from [FragTrap] and [ScavTrap].");
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	*this = other;
	announce("copy constructor called");
}

/// @brief	destructor
DiamondTrap::~DiamondTrap(void)
{
	announce("destructor called");
}

/// @brief	operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hit_point = other._hit_point;
		_energy_point = other._energy_point;
		_attack_damage = other._attack_damage;
	}
	return (*this);
}

/// @brief	public
void	DiamondTrap::announce(std::string msg)
{
	std::cout << "[ DiamondTrap, "<< _name << " ]: " << msg << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	announce("I am a DiamondTrap!");
	std::cout << "		and my ClapTrap name is " << ClapTrap::_name << "!" << std::endl;
}

void	DiamondTrap::print_status(void)
{
	announce("\nstatus:");
	std::cout << " - name: " << _name << std::endl;
	std::cout << " - hit point: " << _hit_point << std::endl;
	std::cout << " - energy point: " << _energy_point << std::endl;
	std::cout << " - attack damage: " << _attack_damage << std::endl;
}
