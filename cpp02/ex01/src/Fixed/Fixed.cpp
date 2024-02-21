/// @file   Fixed.cpp
/// @author minakim
/// @date   18-Feb-2024

#include "Fixed.h"

/// @brief	constructor
Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) : _value(val << _fractional_bits)
{

}

Fixed::Fixed(const float val)
{

}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = other.getRawBits();
}

/// @brief	operator
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_value = other.getRawBits();
	}
	return (*this);
}

/// @brief	destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/// @brief	public
///	@return	that returns the raw value of the fixed-point value.
/// @note	const(the const field following the parameters):
/// 		This function is read-only and does not change the state of the object.
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

/// @brief	that sets the raw value of the fixed-point number.
void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

/// ex01
/// @brief	that converts the fixed-point value to a floating-point value.
float	Fixed::toFloat(void) const
{

}

/// @brief	that converts the fixed-point value to an integer value.
int		Fixed::toInt(void) const
{

}