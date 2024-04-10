/// @file   AAnimal.h
/// @author minakim
/// @date   18-Mar-2024

#ifndef AAnimal_H
#define AAnimal_H

/// @library
#include <iostream>

/// @class AAnimal
class AAnimal {
public:
	AAnimal(void);
	AAnimal(const AAnimal &other);
	virtual ~AAnimal(void);

	AAnimal	&operator=(const AAnimal &other);

	/// @note Pure virtual function:
	virtual void		makeSound(void) const = 0;
	///		A pure virtual function represents a function that must be overridden
	///		in all related derived classes.
	///		If a class contains a pure virtual function, it is referred to as an 'abstract class'.
	///		An abstract class should not be instantiable.
	
	void				announce(std::string msg) const;
	std::string			getType(void) const;

protected:
	std::string	_type;
};

#endif