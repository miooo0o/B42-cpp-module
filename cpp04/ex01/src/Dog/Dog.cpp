/// @file   Dog.cpp
/// @author minakim
/// @date   17-Mar-2024

#include "Dog.h"

/// @brief	constructor
Dog::Dog(void)
: _brain(new Brain())
{
	_type = "Dog";
	announce("dog: constructor called.");
}

Dog::Dog(const Dog &other)
{
	_type = other.getType();
	_brain = new Brain(*other._brain);
	announce("dog: copy constructor called.");
}

/// @brief	destructor
Dog::~Dog(void)
{
	delete _brain;
	announce("dog: destructor called.");
}

/// @brief	operator
Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		_type = getType();
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

/// @brief	public
void	Dog::makeSound(void) const
{
	announce("Bark! bark bark bark!");
}

Brain	*Dog::get_brain(void)
{
	return (_brain);
}