/// @file   WrongCat.h
/// @author minakim
/// @date   17-Mar-2024

#ifndef WrongCat_H
#define WrongCat_H

/// @include
#include "WrongAnimal/WrongAnimal.h"

/// @class WrongCat
class WrongCat : public WrongAnimal {
public:
	WrongCat(void);
	WrongCat(const WrongCat &other);
	~WrongCat(void);

	WrongCat &operator=(const WrongCat &other);
	
	void	makeSound(void) const;
};

#endif