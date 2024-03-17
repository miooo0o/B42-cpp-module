/// @file   Cat.cpp
/// @author minakim
/// @date   14-Mar-2024

#include "Cat.h"

/// @brief	constructor
Cat::Cat(void)
{
	_type = "Cat";
	announce("cat: constructor called.");
}

Cat::Cat(const Cat &other)
{
	*this = other;
	announce("cat: copy constructor called.");
}

/// @brief	destructor
Cat::~Cat(void)
{
	announce("cat: destructor called.");
}

/// @brief	operator
Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		_type = getType();
	return (*this);
}

/// @brief	public
void	Cat::makeSound(void) const
{
	announce("Meoooooooooooow!");
}

