/// @file   FragTrap.cpp
/// @author minakim
/// @date   02-Mar-2024

#include "FragTrap.h"

/// @brief	constructor
FragTrap::FragTrap(void)
{
	_name = "default";
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
	announce("constructor called");
}

FragTrap::FragTrap(std::string name)
{
	_name = name;
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
	announce("constructor called");
}

FragTrap::FragTrap(const FragTrap &other)
{
	*this = other;
	announce("copy constructor called");
}

/// @brief	destructor
FragTrap::~FragTrap(void)
{
	announce("destructor called");
}

/// @brief	operator
FragTrap &FragTrap::operator=(const FragTrap &other)
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
void	FragTrap::attack(const std::string &target)
{
	if (_hit_point > STATUS_EXHAUSTION && _energy_point > STATUS_EXHAUSTION)
	{
		std::cout << "[ FragTrap, "<< _name << " ]: "
				  << "attacks " << target << ", causing "
				  << _attack_damage <<" points of damages!" << std::endl;
		_energy_point--;
	}
	else if (_hit_point == STATUS_EXHAUSTION)
		announce("Oh, I am dead....");
	else if (_energy_point == STATUS_EXHAUSTION)
		announce("has not enough energy. failed to attack.");
}
///	@note
///	This member function displays a positive high fives request on the standard output.
void	FragTrap::highFivesGuys(void)
{
	if (_hit_point > STATUS_EXHAUSTION && _energy_point > STATUS_EXHAUSTION)
	{
		announce("hey, high five guys!");
		_energy_point--;
	}
	else if (_hit_point == STATUS_EXHAUSTION)
		announce("Oh, I am already dead....");
	else if (_energy_point == STATUS_EXHAUSTION)
		announce("has not enough energy. failed to high fives.");
}

/// @brief	private
void	FragTrap::announce(std::string msg)
{
	std::cout << "[ FragTrap, "<< _name << " ]: " << msg << std::endl;
}
