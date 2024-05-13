/// @file   ClapTrap.h
/// @author minakim
/// @date   28-Feb-2024

#ifndef ClapTrap_H
#define ClapTrap_H

/// @library
# include <iostream>

/// @macro
# define STATUS_EXHAUSTION	0

/// @ex00
/// It will be called ClapTrap and will have the following private attributes initialized to
/// the values specified in brackets:
/// @var Name: which is passed as parameter to a constructor
/// @var Hit points (10): represent the health of the ClapTrap
/// @var Energy points (10)
/// @var Attack damage (0)
class ClapTrap {
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap(void);
	
	ClapTrap &operator=(const ClapTrap &other);
	
///	@note	`virtual`
///	Where "virtual" is the keyword used to declare a virtual function in C++.
/// Virtual functions are used to implement polymorphism.
/// A virtual function is a member function of a base class that has the ability
/// to be overridden by a derived class.
/// So, if I declare the function virtual in the base class,
/// the derived class can override it to achieve the desired behavior.
///	@brief	member functions
///	@note	member functions attack and announce will still be used in derived classes.
	virtual void	attack(const std::string& target);
	virtual void	announce(std::string msg);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

protected:
	std::string		_name;
	unsigned int	_hit_point;
	unsigned int	_energy_point;
	unsigned int	_attack_damage;
};

#endif