/// @file   Fixed.h
/// @author minakim
/// @date   18-Feb-2024

#ifndef Fixed_H
#define Fixed_H

/// @library
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

private:
};

#endif