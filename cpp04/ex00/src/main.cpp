/// @file   main.cpp
/// @author minakim
/// @date   14-Mar-2024

/// @ex00 subject
/// - [X] Start by implementing a simple base class called @class Animal.
/// It has one protected attribute: @protected std::string type;
///	- [X] Implement a Dog @class that **inherits from Animal**.
/// - [X] Implement a Cat @class that **inherits from Animal**.
/// These two **derived classes** must set their type field depending on their name. Then,
/// the Dog’s type will be initialized to "Dog", and the Cat’s type will be initialized to "Cat".
/// The type of the Animal class can be left empty or set to the value of your choice.
/// - [X] Every animal must be able to use the member function: @member makeSound()
/// It will print an appropriate sound (cats don’t bark)
/// To ensure you understood how it works,
/// - [X] implement a WrongCat class that inherits from a WrongAnimal class.
/// If you replace the Animal and the Cat by the wrong ones in the code above,
/// the WrongCat should output the WrongAnimal sound.
/// - [X] Implement and turn in more tests than the ones given above.

/// @include
#include "Cat/Cat.h"
#include "Dog/Dog.h"
#include "WrongCat/WrongCat.h"

int main()
{
	/// @note Animal
	std::cout << "1. animal class"<< std::endl;
	std::cout << std::endl
				<< "------------------------------------------------------------" << std::endl;
	std::cout << "constructor call:" << std::endl
				<< "------------------------------------------------------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl
			  << "------------------------------------------------------------" << std::endl;
	std::cout << "test: getType()" << std::endl
			  << "------------------------------------------------------------" << std::endl;
	std::cout << "I am Dog, and my type is " << dog->getType() << " " << std::endl;
	std::cout << "I am Cat, and my type is " << cat->getType() << " " << std::endl;
	
	std::cout << std::endl
			  << "------------------------------------------------------------" << std::endl;
	std::cout << "test: makeSound()" << std::endl
			  << "------------------------------------------------------------" << std::endl;
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();
	
	std::cout << std::endl
			  << "------------------------------------------------------------" << std::endl;
	std::cout << "destructor call:" << std::endl
			  << "------------------------------------------------------------" << std::endl;
	delete meta;
	delete dog;
	delete cat;
	
	std::cout << std::endl;
	
	/// @note Wrong Animal
	std::cout << "2. wrong animal class"<< std::endl;
	
	std::cout << std::endl
			  << "------------------------------------------------------------" << std::endl;
	std::cout << "constructor call:" << std::endl
			  << "------------------------------------------------------------" << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	
	std::cout << std::endl
			  << "------------------------------------------------------------" << std::endl;
	std::cout << "test: getType()" << std::endl
			  << "------------------------------------------------------------" << std::endl;
	std::cout << "I am Cat, and my type is " << wrong_cat->getType() << " " << std::endl;
	
	std::cout << std::endl
			  << "------------------------------------------------------------" << std::endl;
	std::cout << "test: makeSound()" << std::endl
			  << "------------------------------------------------------------" << std::endl;
	wrong_cat->makeSound();
	wrong_meta->makeSound();
	
	std::cout << std::endl
			  << "------------------------------------------------------------" << std::endl;
	std::cout << "destructor call:" << std::endl
			  << "------------------------------------------------------------" << std::endl;
	delete wrong_meta;
	delete wrong_cat;
	
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}