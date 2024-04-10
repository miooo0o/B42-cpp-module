/// @file   Dog.cpp
/// @author minakim
/// @date   14-Mar-2024

#include "Dog.h"

/// @brief	constructor
Dog::Dog(void)
{
	_type = "Dog";
	announce("dog: constructor called.");
}

Dog::Dog(const Dog &other)
{
	*this = other;
	announce("dog: copy constructor called.");
}

/// @brief	destructor
Dog::~Dog(void)
{
	announce("dog: destructor called.");
}

/// @brief	operator
Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		_type = getType();
	return (*this);
}

/// @brief	public
void	Dog::makeSound(void) const
{
	announce("Bark! bark bark bark!");
}
