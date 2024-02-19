/// @file   Fixed.h
/// @author minakim
/// @date   18-Feb-2024

#ifndef Fixed_H
#define Fixed_H

/// @library
# include <iostream>

/// @macro
/// valid
/* ************************************************************************** */
/// @class Fixed
class Fixed {
public:
	Fixed(void);
	Fixed(const Fixed &other);
	~Fixed(void);
	Fixed &operator=(const Fixed &other);
	
	void	setRawBits(int const raw);
	int		getRawBits(void) const;
private:
	int _value;
	int	_width;
};

#endif