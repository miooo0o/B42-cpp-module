/// @file   Animal.cpp
/// @author minakim
/// @date   17-Mar-2024

#include "AAnimal.h"

/// @brief	constructor
AAnimal::AAnimal(void)
	: _type("Animal")
{
	announce("animal: constructor called.");
}

AAnimal::AAnimal(const AAnimal &other)
{
	_type = other.getType();
	announce("animal: copy constructor called.");
}

/// @brief	destructor
AAnimal::~AAnimal(void)
{
	announce("animal: destructor called.");
}

/// @brief	operator
AAnimal	&AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		_type = other.getType();
	return (*this);
}

/// @brief	public
void	AAnimal::announce(std::string const msg) const
{
	std::cout << "[ " << getType() << " ] " << msg << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (_type);
}
