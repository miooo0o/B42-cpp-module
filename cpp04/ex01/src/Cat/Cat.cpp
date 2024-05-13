/// @file   Cat.cpp
/// @author minakim
/// @date   17-Mar-2024

#include "Cat.h"

/// @brief	constructor
Cat::Cat(void)
	: _brain(new Brain())
{
	_type = "Cat";
	announce("cat: constructor called.");
}

/// shallow copy
/// Cat::Cat(const Cat &other) { *this = other; }
/// deep copy
Cat::Cat(const Cat &other)
{
	_type = other.getType();
	_brain = new Brain(*other._brain);
	announce("cat: copy constructor called.");
}

/// @brief	destructor
Cat::~Cat(void)
{
	delete _brain;
	announce("cat: destructor called.");
}

/// @brief	operator
/// the assignment operator is called on an already existing object
Cat &Cat::operator=(const Cat &other)
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
void	Cat::makeSound(void) const
{
	announce("Meoooooooooooow!");
}

Brain	*Cat::get_brain(void)
{
	return (_brain);
}
