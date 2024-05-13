/// @file   WrongAnimal.cpp
/// @author minakim
/// @date   17-Mar-2024

#include "WrongAnimal.h"


/// @brief	constructor
WrongAnimal::WrongAnimal(void)
		: _type("Wrong Animal")
{
	announce("wrong animal: constructor called.");
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	announce("wrong animal: copy constructor called.");
}

/// @brief	destructor
WrongAnimal::~WrongAnimal(void)
{
	announce("wrong animal: destructor called.");
}

/// @brief	operator
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		_type = other.getType();
	return (*this);
}

/// @brief	public
void	WrongAnimal::announce(std::string const msg) const
{
	std::cout << "[ " << getType() << " ] " << msg << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

void	WrongAnimal::makeSound(void) const
{
	announce("purr?");
}
