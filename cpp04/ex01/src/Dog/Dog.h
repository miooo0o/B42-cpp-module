/// @file   Dog.h
/// @author minakim
/// @date   17-Mar-2024

#ifndef Dog_H
#define Dog_H

/// @library
///	@class
#include "Animal/Animal.h"
#include "Brain/Brain.h"

/// @class Dog
class Dog : public Animal {
public:
	Dog(void);
	Dog(const Dog &other);
	virtual ~Dog(void);
	
	Dog &operator=(const Dog &other);
	
	void	makeSound(void) const;
	Brain	*get_brain(void);
private:
	Brain	*_brain;
};

#endif