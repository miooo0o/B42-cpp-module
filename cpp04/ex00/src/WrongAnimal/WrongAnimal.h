/// @file   WrongAnimal.h
/// @author minakim
/// @date   17-Mar-2024

#ifndef WrongAnimal_H
#define WrongAnimal_H

/// @library
#include <iostream>

/// @class WrongAnimal
class WrongAnimal {
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &other);
	~WrongAnimal(void);

	WrongAnimal &operator=(const WrongAnimal &other);
	
	std::string	getType(void) const;
	void		announce(std::string msg) const;
	void		makeSound(void) const;
protected:
	std::string	_type;
};

#endif