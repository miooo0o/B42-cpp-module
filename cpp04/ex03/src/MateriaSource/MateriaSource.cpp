/// @file   MateriaSource.cpp
/// @author minakim
/// @date   10-Apr-2024

#include "MateriaSource.h"

/// @brief	constructor
MateriaSource::MateriaSource(void)
    : _n_knows(0)
{
    for (int i = 0; i < _slot_size; i++)
        _materias[i] = nullptr;
}

/// @brief	copy constructor
MateriaSource::MateriaSource(const MateriaSource& other)
{
    *this = other;
}

/// @brief	destructor
MateriaSource::~MateriaSource(void)
{

}

/// @brief	operator
MateriaSource&    MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {

    }
    return *this;
}
/// @brief	public

/**
 * - learnMateria(AMateria*)
 *	    Copies the Materia passed as a parameter and store it in memory
 *		so it can be cloned later. Like the Character, the MateriaSource can know
 *		at most 4 Materias.
 *		They are not necessarily unique.
 */
void    MateriaSource::learnMateria(AMateria *m)
{
    if (!(_n_knows >= 0 && _n_knows <= _slot_size))
        return ;
    for (int i = 0; i < _n_knows; i++)
    {
        if (_materias[i] == nullptr)
        {
            _materias[i] = m;
            _n_knows++;
            return ;
        }
    }
}

bool    is_materia(std::string const& type)
{
    if (type == "cure" || type == "ice")
        return (true);
    return (false);
}

/**
 *	  - createMateria(std::string const &)
 *	     Returns a new Materia.
 *	     The latter is a copy of the Materia previously learned by the MateriaSource
 *	     whose type equals the one passed as parameter.
 *	     Returns 0 if the type is unknown
 */
AMateria*   MateriaSource::createMateria(std::string const& type)
{
    if (!is_materia(type))
        return (nullptr);
}

