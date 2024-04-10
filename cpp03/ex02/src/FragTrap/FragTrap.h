/// @file   FragTrap.h
/// @author minakim
/// @date   02-Mar-2024

#ifndef FragTrap_H
#define FragTrap_H

/// @library
#include "ClapTrap/ClapTrap.h"

///	@ex02
///	implement aFragTrapclass that inherits from ClapTrap
/// must initialize them to:
/// @var Name, which is passed as parameter to a constructor
/// @var Hit points (100), represent the health of the ClapTrap
/// @var Energy points (100)
/// @var Attack damage (30)
/// @class FragTrap
class FragTrap : public ClapTrap {
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	~FragTrap(void);
	FragTrap &operator=(const FragTrap &other);
	
	void	attack(const std::string& target);
	void	highFivesGuys(void);

private:
	void	announce(std::string msg);
};

#endif