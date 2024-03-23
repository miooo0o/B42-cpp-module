/// @file   Ice.h
/// @author minakim
/// @date   23-Mar-2024

#ifndef Ice_H
#define Ice_H

/// @include
#include "AMateria/AMateria.h"

/// @class Ice
class Ice : public AMateria {
public:
	Ice(void);
	Ice(const Ice &other);
	~Ice(void);
	Ice &operator=(const Ice &other);
	
	virtual AMateria* clone(void);
	virtual void use(ICharacter& target);
private:
};

#endif