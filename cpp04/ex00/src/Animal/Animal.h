/// @file   Animal.h
/// @author minakim
/// @date   14-Mar-2024

#ifndef Animal_H
#define Animal_H

/// @library
#include <iostream>

/// @class Animal
class Animal {
public:
	Animal(void);
	Animal(const Animal &other);
	/// @todo documentation
	virtual ~Animal(void);

	Animal	&operator=(const Animal &other);
	
	virtual void		makeSound(void) const;
	void				announce(std::string msg) const;
	std::string			getType(void) const;

protected:
	std::string	_type;
};

#endif