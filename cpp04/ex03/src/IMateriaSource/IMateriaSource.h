/// @file   IMateriaSource.h
/// @author minakim
/// @date   05-Apr-2024

#ifndef ImateriaSource_H
#define ImateriaSource_H

/// @headerfile
# include "AMateria/AMateria.h"

/// @class IMateriaSource
class IMateriaSource
{
public:
	virtual				~IMateriaSource() {}
	virtual void		learnMateria(AMateria*) = 0;
	virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif