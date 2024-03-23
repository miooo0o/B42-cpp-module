/// @file   ICharacter.h
/// @author minakim
/// @date   23-Mar-2024

#ifndef ICharacter_H
#define ICharacter_H

/// @include
#include "AMateria/AMateria.h"

/// @foward_declarations
class AMateria;

/// @class ICharacter
class ICharacter {
public:

	virtual						~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void 				equip(AMateria* m) = 0;
	virtual void 				unequip(int idx) = 0;
	virtual void 				use(int idx, ICharacter& target) = 0;
};

#endif