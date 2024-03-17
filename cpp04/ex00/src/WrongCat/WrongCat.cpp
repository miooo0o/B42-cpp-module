/// @file   WrongCat.cpp
/// @author minakim
/// @date   17-Mar-2024

#include "WrongCat.h"


/// @brief	constructor
WrongCat::WrongCat(void)
{
	_type = "Wrong Cat";
	announce("wrong cat: constructor called.");
}

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
	announce("wrong cat: copy constructor called.");
}

/// @brief	destructor
WrongCat::~WrongCat(void)
{
	announce("cat: destructor called.");
}

/// @brief	operator
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		_type = getType();
	return *this;
}

/// @brief	public
void	WrongCat::makeSound(void) const
{
	announce("Beep?");
}
