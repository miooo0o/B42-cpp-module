/// @file   DiamondTrap.h
/// @author minakim
/// @date   03-Mar-2024

#ifndef DiamondTrap_H
#define DiamondTrap_H

/// @library
#include "ScavTrap/ScavTrap.h"
#include "FragTrap/FragTrap.h"

///	@ex03
///	The DiamondTrap class will have a name private attribute.
/// Give to this at tribute exactly the same variable’s name
/// (not talking about the robot’s name here)
/// than the one in the ClapTrap base class.
/// @example To be more clear, here are two examples.
/// If ClapTrap’s variable is `name`, give the name `name` to the one of the DiamondTrap.
/// If ClapTrap’s variable is `_name`, give the name `_name` to the one of the DiamondTrap.
/// Its attributes and member functions will be picked from either one of its parent classes
/// @var Name, which is passed as parameter to a constructor
/// @var ClapTrap::name(parameter of the constructor + "_clap_name" suffix)
/// @var Hit points (FragTrap)
/// @var Energy points (ScavTrap)
/// @var Attack damage (FragTrap)
/// @var attack()(Scavtrap)
/// @class DiamondTrap
class DiamondTrap : public ScavTrap, public FragTrap {
public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &other);
	~DiamondTrap(void);
	DiamondTrap &operator=(const DiamondTrap &other);
	
	void	whoAmI(void);
	void	announce(std::string msg);
	void	attack(const std::string& target);
	void	print_status(void);
private:
	std::string	_name;
};

#endif