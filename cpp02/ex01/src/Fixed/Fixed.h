/// @file   Fixed.h
/// @author minakim
/// @date   18-Feb-2024

#ifndef Fixed_H
#define Fixed_H

/// @library
# include <iostream>
# include <math.h>
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
	Fixed &operator=(const Fixed &other);
	
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