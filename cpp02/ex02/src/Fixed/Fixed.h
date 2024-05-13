/// @file   Fixed.h
/// @author minakim
/// @date   18-Feb-2024

#ifndef Fixed_H
#define Fixed_H

/// @library
# include <iostream>
# include <math.h>
# include <cstdlib>

/// @macro
/// valid
# define INVALID	1
# define VALID		0

/* ************************************************************************** */

/// @class Fixed
class Fixed {
public:
	Fixed(void);
	Fixed(const int val);
	Fixed(const float val);
	Fixed(const Fixed &other);
	~Fixed(void);

	Fixed	&operator=(const Fixed &other);

/// @note	ex02:
/// the 6 comparison operators: >,<,>=,<=,== and !=
	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;

///	the 4 arithmetic operators: +,-,*, and /
	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;
	
///	the 4 increment/decrement
	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);

///	static member function `min`
	static Fixed const	&min(const Fixed &a, const Fixed &b);
	static Fixed		&min(Fixed &a, Fixed &b);

///	static member function `max`
	static Fixed const	&max(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);

	void	setRawBits(int const raw);
	int		getRawBits(void) const;
	float	toFloat( void ) const;
	int		toInt( void ) const;
private:
	int 				_value;
	static const int	_fractional_bits = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &target);
#endif