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
	*this = other;
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
	return (new Ice());
}
/// @brief	private
