/// @file   main.cpp
/// @author minakim
/// @date   18-Feb-2024

# include <cstdlib>
# include "Fixed/Fixed.h"

///	@note	My First Class inOrthodox Canonical Form
///	Fixed-point numbers
int	main(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return (EXIT_SUCCESS);
}