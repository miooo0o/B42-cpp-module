/// @file   Fixed.cpp
/// @author minakim
/// @date   18-Feb-2024

#include "Fixed.h"

/// @brief	constructor
Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

///	@note	The fractional bits value isinitialized to 8.
///	@brief	shift input value as much the fractional bits.
///	@example
///	[00010111] -> [00010111 00000000]
Fixed::Fixed(const int val) : _value(val << _fractional_bits)
{
	std::cout << "Int constructor called" << std::endl;

}
///	@example
/// Fixed const c( 42.42f );
/// 42.42 * 256 = 10859.52, and rounded by `roundf`, `10859.53` becomes 10860.
/// Here, `10860` becomes the integer part of the fixed-point,
/// and `.52` is truncated, so using `<< _fractional bits` converts 42.42 to an 8-bit integer.
///	@note	(1 << _fractional_bits): This is the same as 2^8. val * 256.
Fixed::Fixed(const float val) : _value(roundf(val * (1 << _fractional_bits)))
{
	std::cout << "Int constructor called" << std::endl;
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
	return (_value);
}

/// @brief	that sets the raw value of the fixed-point number.
void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

/// @brief	that converts the fixed-point value to a floating-point value.
float	Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << _fractional_bits));
}

/// @brief	that converts the fixed-point value to an integer value.
int		Fixed::toInt(void) const
{
	return (getRawBits() >> _fractional_bits);
}

///	@note	overload
/// Operator Overloading refers to defining new semantics for a previously defined operator for
/// a class or user-defined data type that you implement yourself,
/// i.e., giving the operator a user-defined behavior
std::ostream &operator<<(std::ostream &out, const Fixed &target)
{
	out << target.toFloat();
	return (out);
}