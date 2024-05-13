/// @file   MateriaSource.h
/// @author minakim
/// @date   10-Apr-2024

#ifndef MateriaSource_H
#define MateriaSource_H

/// @headerfile
#include "IMateriaSource/IMateriaSource.h"

/// @macro
# define MAX_SLOT_SIZE	4

/// @class MateriaSource
class MateriaSource : public IMateriaSource
{
public:
    MateriaSource(void);
    MateriaSource(const MateriaSource& other);
     ~MateriaSource(void);
    MateriaSource& operator = (const MateriaSource& other);

	void		learnMateria(AMateria *m);
	AMateria*	createMateria(std::string const & type);

private:
	static int const	_slot_size = MAX_SLOT_SIZE;
	int 		_n_knows;
	AMateria*	_materias[_slot_size];

};

#endif