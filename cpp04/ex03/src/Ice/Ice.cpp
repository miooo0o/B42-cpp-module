/// @file   Ice.cpp
/// @author minakim
/// @date   23-Mar-2024

#include "Ice.h"


/// @brief	constructor
Ice::Ice(void)
	: AMateria("ice")
{
}

/// @brief	copy constructor
Ice::Ice(const Ice &other)
{
	_type = other.getType();
}

/// @brief	destructor
Ice::~Ice(void)
{
}

/// @brief	operator
Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		_type = other.getType();
	}
	return (*this);
}

/// @brief	public
AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}