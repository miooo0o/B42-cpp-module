/// @file   ClapTrap.cpp
/// @author minakim
/// @date   28-Feb-2024

#include "ClapTrap.h"

/// @brief	constructor
ClapTrap::ClapTrap(void)
	: _name("default"), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	announce("constructor called");
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	announce("constructor called");
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	announce("copy constructor called");

}

/// @brief	destructor
ClapTrap::~ClapTrap(void)
{
	announce("destructor called");
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
///	@macro	STATUS_EXHAUSTION == 0
/// used for readability due to the use of unsigned int.
void	ClapTrap::attack(const std::string& target)
{
	if (_hit_point > STATUS_EXHAUSTION && _energy_point > STATUS_EXHAUSTION)
	{
		std::cout << "[ ClapTrap, "<< _name << " ]: "
			  << "attacks " << target << ", causing "
			  << _attack_damage <<" points of damages!" << std::endl;
		_energy_point--;
	}
	else if (_hit_point == STATUS_EXHAUSTION)
		announce("Oh, I am dead....");
	else if (_energy_point == STATUS_EXHAUSTION)
		announce("has not enough energy. failed to attack.");
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_point == STATUS_EXHAUSTION)
	{
		announce("Oh, I am dead....");
		return ;
	}
	std::cout << "[ ClapTrap, "<< _name << " ]: "
			  << "take "<< amount << " damage! " << std::flush;
	if (_hit_point <= amount)
	{
		_hit_point = STATUS_EXHAUSTION;
		std::cout << _name << " died in this attack...." << std::endl;
		_name += " the dead";
	}
	else
	{
		_hit_point -= amount;
		std::cout << _name << " still " << _hit_point << " hit points left." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_point > STATUS_EXHAUSTION && _energy_point > STATUS_EXHAUSTION)
	{
		std::cout << "[ ClapTrap, "<< _name << " ]: "
			<< "repaired by " << amount << "! " << std::flush;
		_hit_point += amount;
		_energy_point--;
		std::cout << _name << " has " << _hit_point << " hit points left." << std::endl;
	}
	else if (_hit_point == STATUS_EXHAUSTION)
		announce("Oh, I am already dead....");
	else if (_energy_point == STATUS_EXHAUSTION)
		announce("has not enough energy. failed to repair.");
}

/// @brief	private
void	ClapTrap::announce(std::string msg)
{
	std::cout << "[ ClapTrap, "<< _name << " ]: " << msg << std::endl;
}