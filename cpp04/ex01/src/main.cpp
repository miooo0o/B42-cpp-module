/// @file   main.cpp
/// @author minakim
/// @date   17-Mar-2024

/// @ex01
/// @done Define constructors and destructors for each class to display specific messages.
/// @done Implement a Brain class with an array of 100 std::string called ideas.
/// @done Add a private Brain* attribute to Dog and Cat classes.
/// @done Upon construction, Dog and Cat should create their Brain using new Brain();.
/// @done Upon destruction, Dog and Cat should delete their Brain.
/// @done In the main function:
///       - Create an array of Animal objects.
///       - Fill half of the array with Dog objects and the other half with Cat objects.
///       - Loop over the array and delete every Animal at the end of program execution.
///       - Ensure Dogs and Cats are deleted as Animals.
///       - Check for memory leaks.
/// @done Ensure that a copy of a Dog or a Cat is **not shallow**.
///       - Test that copies are **deep copies**.
/// @note shallow copy
/// Cat::Cat(const Cat &other) { *this = other; }
/// @note deep copy / shallow copy
/// Shallow copy duplicates only the memory addresses pointed to by the object,
/// resulting in copies that share the same memory, leading to mutual dependencies between objects.
/// **deep copy** ensures complete independence between the original object and its copy,
/// mitigating such issues.
///	Cat::Cat(const Cat &other)
///	{
///		_type = other.getType();
///		_brain = new Brain(*other._brain);	<-	allocate memory
/// }
/// @todo downcast (documentation, + obsidian)
/// <dynamic_cast>, <static_cast>
/// @todo move (documentation, + obsidian)

/// @include
#include "Cat/Cat.h"
#include "Dog/Dog.h"

/// @library

Animal	*fill_cat_or_dog(int i)
{
	if (i % 2 == 0)
		return (new Cat());
	return (new Dog());
}

int main(void)
{
	std::cout << std::endl
			  << "------------------------------------------------------------" << std::endl;
	std::cout << "constructor call:" << std::endl
			  << "------------------------------------------------------------" << std::endl;
	// 1. Create an array of Animal objects
	const int	index = 4;
	Animal		*animals[index];
	
	// 2. Fill half of the array with Dog objects and the other half with Cat objects.
	for (int i = 0; i < index; i++)
		animals[i] = fill_cat_or_dog(i);
	
	// 3. set ideas
	dynamic_cast<Cat *>(animals[0])->get_brain()->set_idea(0, "I,    the cat, Baoz.");
	dynamic_cast<Cat *>(animals[2])->get_brain()->set_idea(2, "I,    the cat, Odin.");
	
	dynamic_cast<Dog *>(animals[1])->get_brain()->set_idea(1, "I,    the dog, Noel.");
	dynamic_cast<Dog *>(animals[3])->get_brain()->set_idea(3, "I,    the dog, Lulu.");
	
	// 4. Deep copy `animals` object to `copies` object.
	Animal		*copies[index];
	for (int i = 0; i < index; i++)
	{
		if (typeid(*animals[i]) == typeid(Cat))
			copies[i] = new Cat(*dynamic_cast<Cat *>(animals[i]));
		else if (typeid(*animals[i]) == typeid(Dog))
			copies[i] = new Dog(*dynamic_cast<Dog*>(animals[i]));
	}
	
	// 5. set new idea `copies` object
	dynamic_cast<Cat *>(copies[2])->get_brain()->set_idea(2, "Copy, the cat, Odin.");
	dynamic_cast<Dog *>(copies[1])->get_brain()->set_idea(1, "Copy, the dog, Noel.");
	
	// 6. print original object
	std::cout << std::endl
			  << "------------------------------------------------------------" << std::endl;
	std::cout << "animals (original):" << std::endl
			  << "------------------------------------------------------------" << std::endl;
	for (int i = 0; i < index; i++)
	{
		if (typeid(*animals[i]) == typeid(Cat))
			std::cout << "[ index " << i << " ] "
						<< dynamic_cast<Cat *>(animals[i])->get_brain()->get_idea(i) << std::endl;
		else if (typeid(*animals[i]) == typeid(Dog))
			std::cout << "[ index " << i << " ] "
						<< dynamic_cast<Dog *>(animals[i])->get_brain()->get_idea(i) << std::endl;
	}
	
	// 7. print copies object
	std::cout << std::endl
			  << "------------------------------------------------------------" << std::endl;
	std::cout << "copies (copy):" << std::endl
			  << "------------------------------------------------------------" << std::endl;
	for (int i = 0; i < index; i++)
	{
		if (typeid(*copies[i]) == typeid(Cat))
			std::cout << "[ index " << i << " ] "
					  << dynamic_cast<Cat *>(copies[i])->get_brain()->get_idea(i) << std::endl;
		else if (typeid(*copies[i]) == typeid(Dog))
			std::cout << "[ index " << i << " ] "
					  << dynamic_cast<Dog *>(copies[i])->get_brain()->get_idea(i) << std::endl;
	}
	
	// 8. delete all
	std::cout << std::endl
			  << "------------------------------------------------------------" << std::endl;
	std::cout << "destructor call:" << std::endl
			  << "------------------------------------------------------------" << std::endl;
	for (int i = 0; i < index; i++)
		delete animals[i];
	
	for (int i = 0; i < index; i++)
		delete copies[i];
	
	std::cout << std::endl << "		--- ex01 done!" << std::endl;
	return (EXIT_SUCCESS);
}