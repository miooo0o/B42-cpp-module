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
	announce("constructor called");
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;
	announce("copy constructor called");
}

/// @brief	destructor
ScavTrap::~ScavTrap(void)
{
	announce("destructor called");
}

/// @brief	operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_attack_damage = other._attack_damage;
		_energy_point = other._energy_point;
		_hit_point = other._hit_point;
	}
	return *this;
}

/// @brief	public
void	ScavTrap::attack(const std::string &target)
{
	if (_hit_point > STATUS_EXHAUSTION && _energy_point > STATUS_EXHAUSTION)
	{
		std::cout << "[ ScavTrap, "<< _name << " ]: "
				  << "attacks " << target << ", causing "
				  << _attack_damage <<" points of damages!" << std::endl;
		_energy_point--;
	}
	else if (_hit_point == STATUS_EXHAUSTION)
		announce("Oh, I am dead....");
	else if (_energy_point == STATUS_EXHAUSTION)
		announce("has not enough energy. failed to attack.");
}

///	@note	This member function will display a message
/// informing that ScavTrap is now in Gatekeeper mode.
void	ScavTrap::guardGate(void)
{
	if (_hit_point > STATUS_EXHAUSTION && _energy_point > STATUS_EXHAUSTION)
	{
		announce("now in Gatekeeper mode!");
		_energy_point--;
	}
	else if (_hit_point == STATUS_EXHAUSTION)
		announce("Oh, I am already dead....");
	else if (_energy_point == STATUS_EXHAUSTION)
		announce("has not enough energy. failed to gatekeeper mode.");
}

/// @brief	private
void	ScavTrap::announce(std::string msg)
{
	std::cout << "[ ScavTrap, "<< _name << " ]: " << msg << std::endl;
}