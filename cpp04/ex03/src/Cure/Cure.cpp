/// @file   Cure.cpp
/// @author minakim
/// @date   23-Mar-2024

#include "Cure.h"


/// @brief	constructor
Cure::Cure(void)
	: AMateria("cure")
{
}

Cure::Cure(const Cure &other)
{
	_type = other.getType();
}

/// @brief	destructor
Cure::~Cure(void)
{
}

/// @brief	operator
Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		_type = other.getType();
	}
	return *this;
}

/// @brief	public
AMateria*	Cure::clone(void) const
{
	return (new Cure(*this));
}

void	use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}