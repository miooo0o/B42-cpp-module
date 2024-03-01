/// @file   ClapTrap.cpp
/// @author minakim
/// @date   28-Feb-2024

#include "ClapTrap.h"

/// @brief	constructor
ClapTrap::ClapTrap(void)
	: _name("default"), _hit_point(10), _energy_point(10), _attack_damage(0)
{
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

/// @brief	destructor
ClapTrap::~ClapTrap(void)
{
}

/// @brief	operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_attack_damage = other._attack_damage;
		_energy_point = other._energy_point;
		_hit_point = other._hit_point;
	}
	return (*this);
}
/// @brief	public
///	@note
///	When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
/// When ClapTrap repairs itself, it gets <amount> hit points back.
/// Attacking and repairing cost 1 energy point each.
/// Of course, ClapTrap can’t do anything if it has no hit points or energy points left.
void	ClapTrap::attack(const std::string& target)
{
	if (_energy_point > 0 && _hit_point > 0)
	{
		std::cout << "[ ClapTrap "<< _name << "]: "
			  << "attacks " << target << ", causing "
			  << _attack_damage <<" points of damages!" << std::endl;
		_energy_point--;
	}
	else if (_hit_point <= 0)
		announce("Oh, I am dead....");
	else if (_energy_point <= 0)
		announce("has not enough energy.");
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_point > 0)
	{
		std::cout << "[ ClapTrap "<< _name << "]: "
			<< "take "<< amount << " damage" << std::endl;
		_hit_point -= amount;
		return ;
	}
	else
		announce("Oh, I am dead....");
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_point > 0 && _energy_point > 0)
	{
		std::cout << "[ ClapTrap "<< _name << "]: "
			<< "repaired by " << amount << std::endl;
		_hit_point += amount;
		_energy_point--;
	}
	else if (_hit_point <= 0)
		announce("Oh, I am already dead....");
	else if (_energy_point <= 0)
		announce("has not enough energy.");
}

/// @brief	private
void	ClapTrap::announce(std::string msg)
{
	std::cout << "[ ClapTrap "<< _name << "]: " << msg << std::endl;
}