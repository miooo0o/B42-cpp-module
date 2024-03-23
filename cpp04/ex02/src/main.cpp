/// @file   main.cpp
/// @author minakim
/// @date   18-Mar-2024

/// @ex02
/// Creating Animal objects doesn’t make sense after all. It’s true, they make no sound!
/// To avoid any possible mistakes, the default Animal class should not be instantiable.
/// @done	Fix the Animal class so nobody can instantiate it.
/// 		- Everything should work as before.
/// @done	If you want to, you can update the class name by adding a A prefix to Animal.
/// @done	Write main function

#define CALL_TEST_LINE "c++ -Wall -Werror -Wextra -std=c++98 \
src/test.cpp src/AAnimal/AAnimal.cpp src/Dog/Dog.cpp src/Cat/Cat.cpp \
src/Brain/Brain.cpp -I./include -I./src -o test"

/// @include
#include "Cat/Cat.h"
#include "Dog/Dog.h"
#include <cstdlib> // system

int main(void)
{
	std::cout << "Test 1: attempting to create subclasses (Dog/Cat) "
				 "with abstract class (AAnimal) inheritance..." << std::endl;
	std::cout << "--------------- Test 1 -------------------" << std::endl;
	try
	{
		const Dog	*dog = new Dog();
		const Cat	*cat = new Cat();
		delete dog;
		delete cat;
	}
	catch (std::bad_alloc& e)
	{
		std::cout << "------------------------------------------" << std::endl;
		std::cerr << "error: failed to allocate memory: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	catch (std::exception& e)
	{
		std::cout << "------------------------------------------" << std::endl;
		std::cerr << "error: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "OK[1]: Dog/Cat class are successfully created and deleted" << std::endl << std::endl;
	
	/// @note
	/// test main is at `src/test.cpp`
	/// check `CALL_TEST_LINE` in src/main.cpp
	std::cout << "Test 2: attempting to create an new instance of abstract class (AAnimal)..." << std::endl;
	std::cout << "--------------- Test 2 -------------------" << std::endl;
	int compile_status = system(CALL_TEST_LINE);
	std::cout << "------------------------------------------" << std::endl;

	if (compile_status == EXIT_SUCCESS)
	{
		std::cout << "error: test main compilation successful. "
					 "There may be an issue with the AAnimal class." << std::endl;
		return (EXIT_FAILURE);
	}
	else
		std::cout << "OK[2]: test main compilation failed. "
					 "AAnimal class is abstract as expected." << std::endl << std::endl;
	std::cout << "minakim: `./animal` simple tests completed (2/2). no errors detected." << std::endl;
	return (EXIT_SUCCESS);
}