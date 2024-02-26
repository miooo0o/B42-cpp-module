/// @file   main.cpp
/// @author minakim
/// @date   18-Feb-2024

# include "Fixed/Fixed.h"

///	@note	My First Class inOrthodox Canonical Form
///	Fixed-point numbers
int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return (EXIT_SUCCESS);
}
