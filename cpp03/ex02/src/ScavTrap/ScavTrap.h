/// @file   ScavTrap.h
/// @author minakim
/// @date   01-Mar-2024

#ifndef ScavTrap_H
#define ScavTrap_H

/// @library
#include "ClapTrap/ClapTrap.h"

///	@ex01
///	ScavTrap will use the attributes of ClapTrap (update ClapTrap in consequence) and
/// must initialize them to:
/// @var Name, which is passed as parameter to a constructor
/// @var Hit points (100), represent the health of the ClapTrap
/// @var Energy points (50)
/// @var Attack damage (20)
/// @class ScavTrap
class ScavTrap : public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	~ScavTrap(void);
	ScavTrap &operator=(const ScavTrap &other);

	void	attack(const std::string& target);
	void	guardGate(void);

private:
	void	announce(std::string msg);
};

#endif