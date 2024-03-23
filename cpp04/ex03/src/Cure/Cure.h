/// @file   Cure.h
/// @author minakim
/// @date   23-Mar-2024

#ifndef Cure_H
#define Cure_H

/// @include
#include "AMateria/AMateria.h"

/// @class Cure
class Cure : public AMateria {
public:
	Cure(void);
	Cure(const Cure &other);
	~Cure(void);
	Cure &operator=(const Cure &other);
	
	AMateria* clone(void);
	void use(ICharacter& target);
private:
};

#endif