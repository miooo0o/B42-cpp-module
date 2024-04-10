/// @file   test.cpp
/// @author minakim
/// @date   23-Mar-2024

/// @include
#include "Cat/Cat.h"
#include "Dog/Dog.h"
#include <cstdlib>

int main(void)
{
	try
	{
		/// when I attempting to create an new instance,
		AAnimal* animal = new AAnimal();
		/// clang complain: Allocating an object of abstract class type 'AAnimal'
		delete animal;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}