/// @file   Cat.h
/// @author minakim
/// @date   17-Mar-2024

#ifndef Cat_H
#define Cat_H

/// @library
///	@class
#include "Animal/Animal.h"
#include "Brain/Brain.h"

/// @class Cat
class Cat : public Animal {
public:
	Cat(void);
	Cat(const Cat &other);
	virtual ~Cat(void);
	
	Cat &operator=(const Cat &other);
	
	void	makeSound(void) const;
	Brain	*get_brain(void);

private:
	Brain	*_brain;
};

#endif