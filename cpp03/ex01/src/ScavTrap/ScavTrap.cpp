/// @file   ScavTrap.cpp
/// @author minakim
/// @date   01-Mar-2024

#include "ScavTrap.h"

/// @brief	constructor
ScavTrap::ScavTrap(void)
{
	announce("constructor called");
}

ScavTrap::ScavTrap(std::string name)
{
	_name = name;
	_hit_point = 100;
	_energy_point = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;
}

/// @brief	destructor
ScavTrap::~ScavTrap(void)
{
}

/// @brief	operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
	}
	return *this;
}

/// @brief	public
void	ScavTrap::guardGate(void)
{

}

/// @brief	private
void	ScavTrap::announce(std::string msg)
{
	std::cout << "[ ScavTrap, "<< _name << " ]: " << msg << std::endl;
}