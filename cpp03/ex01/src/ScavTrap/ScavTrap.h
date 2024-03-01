/// @file   ScavTrap.h
/// @author minakim
/// @date   01-Mar-2024

#ifndef ScavTrap_H
#define ScavTrap_H

/// @library
#include "ClapTrap/ClapTrap.h"

/// @macro
/// valid

/// @class ScavTrap
class ScavTrap : public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	~ScavTrap(void);
	
	ScavTrap &operator=(const ScavTrap &other);
	void	guardGate(void);

private:
	void	announce(std::string msg);
};

#endif