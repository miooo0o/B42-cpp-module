/// @file   Animal.cpp
/// @author minakim
/// @date   14-Mar-2024

#include "Animal.h"

/// @brief	constructor
Animal::Animal(void)
	: _type("Animal")
{
	announce("animal: constructor called.");
}

Animal::Animal(const Animal &other)
{
	*this = other;
	announce("animal: copy constructor called.");
	
}

/// @brief	destructor
Animal::~Animal(void)
{
	announce("animal: destructor called.");
}

/// @brief	operator
Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
		_type = other.getType();
	return (*this);
}

/// @brief	public
void	Animal::makeSound(void) const
{
	announce("What does an undefined animal sound like?");
}

void	Animal::announce(std::string const msg) const
{
	std::cout << "[ " << getType() << " ] " << msg << std::endl;
}

std::string	Animal::getType(void) const
{
	return (_type);
}
