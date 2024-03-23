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
	
	/// @note override
	virtual AMateria* clone(void);
	virtual void use(ICharacter& target);
private:
};

#endif