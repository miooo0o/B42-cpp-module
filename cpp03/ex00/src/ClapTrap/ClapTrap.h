/// @file   ClapTrap.h
/// @author minakim
/// @date   28-Feb-2024

#ifndef ClapTrap_H
#define ClapTrap_H

/// @library
# include <iostream>

class ClapTrap {
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap(void);
	
	ClapTrap &operator=(const ClapTrap &other);

///	@brief	member functions
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:
	std::string		_name;
	unsigned int	_hit_point;
	unsigned int	_energy_point;
	unsigned int	_attack_damage;

	void	announce(std::string msg);
};

#endif