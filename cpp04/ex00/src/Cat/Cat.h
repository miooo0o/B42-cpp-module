/// @file   Cat.h
/// @author minakim
/// @date   14-Mar-2024

#ifndef Cat_H
#define Cat_H

/// @library
///	@class
#include "Animal/Animal.h"
/// @macro
/// valid

/// @class Cat
class Cat : public Animal {
public:
	Cat(void);
	Cat(const Cat &other);
	virtual ~Cat(void);
	
	Cat &operator=(const Cat &other);
	
	void	makeSound(void) const;
private:
};

#endif