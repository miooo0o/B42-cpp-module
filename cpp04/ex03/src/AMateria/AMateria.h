/// @file   AMateria.h
/// @author minakim
/// @date   23-Mar-2024

#ifndef AMateria_H
#define AMateria_H

/// @library
# include <iostream>

/// @include
#include "ICharacter/ICharacter.h"

/// @foward_declarations
class ICharacter;

/// @class AMateria
class AMateria {
public:
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(const AMateria &other);
	~AMateria(void);
	AMateria &operator=(const AMateria &other);
	
	///@return the materia type
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
protected:
	std::string	_type;
};

#endif