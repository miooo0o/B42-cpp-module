/// @file   Fixed.cpp
/// @author minakim
/// @date   18-Feb-2024

#include "Fixed.h"

/// @brief	constructor
Fixed::Fixed(void)
	: _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

///	@note	The fractional bits value isinitialized to 8.
///	@brief	shift input value as much the fractional bits.
///	@example
///	[00010111] -> [00010111 00000000]
Fixed::Fixed(const int val)
	: _value(val << _fractional_bits)
{
}
///	@example
/// Fixed const c( 42.42f );
/// 42.42 * 256 = 10859.52, and rounded by `roundf`, `10859.53` becomes 10860.
/// Here, `10860` becomes the integer part of the fixed-point,
/// and `.52` is truncated, so using `<< _fractional bits` converts 42.42 to an 8-bit integer.
///	@note	(1 << _fractional_bits): This is the same as 2^8. so, val * 256.
Fixed::Fixed(const float val)
	: _value(roundf(val * (1 << _fractional_bits)))
{
}

Fixed::Fixed(const Fixed &other)
{
	_value = other.getRawBits();
}

/// @brief	operator
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		_value = other.getRawBits();
	}
	return (*this);
}

/// @brief	destructor
Fixed::~Fixed(void)
{
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

///	@note	member operators
/// 6 comparison operators:>,<,>=,<=,== and !=
bool	Fixed::operator>(const Fixed &other) const
{
	return (getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (getRawBits() ==  other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (getRawBits() !=  other.getRawBits());
}

///	the 4 arithmetic operators: +,-,*, and /
///	@note	initializer list
///	{} is a curly brace (brace),
/// used in C++ to represent an initialization list, starting with C++11.
///	Clang: Avoid repeating the return type from the declaration; use a braced initializer list instead
Fixed	Fixed::operator+(const Fixed &other) const
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return Fixed(toFloat() / other.toFloat());
}

///	the 4 increment/decrement
Fixed&	Fixed::operator++(void)
{
	++_value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	++_value;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	--_value;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	--_value;
	return (tmp);
}

///	@brief	A static member function `min` that takes as parameters two references
/// 1. on fixed-point numbers
///	2. to constant fixed-point numbers
/// @return	a reference to the smallest one
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed const	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

///	@brief	A static member function `max` that takes as parameters two references
/// 1. on fixed-point numbers
///	2. to constant fixed-point numbers
/// @return	a reference to the greatest one
Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed const	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

///	@note	overload
/// Operator Overloading refers to defining new semantics for a previously defined operator for
/// a class or user-defined data type that you implement yourself,
/// i.e., giving the operator a user-defined behavior
std::ostream	&operator<<(std::ostream &out, const Fixed &target)
{
	out << target.toFloat();
	return (out);
}
