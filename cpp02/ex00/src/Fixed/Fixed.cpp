/// @file   Fixed.cpp
/// @author minakim
/// @date   18-Feb-2024

#include "Fixed.h"

/// @brief	constructor
Fixed::Fixed(void)
{
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

/// @brief	operator
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
	}
	return *this;
}

/// @brief	destructor
Fixed::~Fixed(void)
{
}

/// @brief	public
/// @brief	private
