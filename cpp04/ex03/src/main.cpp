/**
* @file   main.cpp
 * @author minakim
 * @date   23-Mar-2024
 *
 * @brief  C++04 Exercise 03
 *
 * @details
 * This file contains the implementation for AMateria class and its derived classes Ice and Cure.
 *
 * - AMateria class:
 *   - Use lower-case names ("ice" for Ice, "cure" for Cure) to set their types.
 *   - The clone() member function will return a new instance of the same type.
 *   - The use(ICharacter&) member function will display:
 *     - Ice: "* shoots an ice bolt at <name> *"
 *     - Cure: "* heals <name>'s wounds *"
 *     where <name> is the name of the Character passed as parameter.
 *
 * - Ice class:
 *   - Inherits from AMateria.
 *
 * - Cure class:
 *   - Inherits from AMateria.
 *
 * @done
 * - Complete the definition of the following AMateria class and implement the necessary member functions.
 * - Implement the Materias concrete classes Ice and Cure.
 *
 * @done Write the concrete class Character which will implement:
 *   - The Character possesses an inventory of 4 slots for Materias.
 *   - They equip the Materias in the first empty slot they find.
 *   - The unequip() member function must NOT delete the Materia.
 *   - The use(int, ICharacter&) member function will use the Materia at the given index.
 *   - Your Character must have a constructor taking its name as a parameter.
 *   - Handle deep copies of Character instances correctly.
 *   - Ensure proper memory management for Materias owned by a Character.
 * @done Write the concrete class MateriaSource which will implement:
 *   - MateriaSource must be able to learn "templates" of Materias to create them when needed.
 *   - Generate a new Materia using just a string that identifies its type.
 *	 - learnMateria(AMateria*)
 *		Copies the Materia passed as a parameter and store it in memory
 *		so it can be cloned later. Like the Character, the MateriaSource can know
 *		at most 4 Materias.
 *		They are not necessarily unique.
 *	  - createMateria(std::string const &)
 *	     Returns a new Materia.
 *	     The latter is a copy of the Materia previously learned by the MateriaSource
 *	     whose type equals the one passed as parameter.
 *	     Returns 0 if the type is unknown
 * @tip
 * - While assigning a Materia to another, copying the type doesn't make sense.
 * - Handle the Materias left on the floor as you like to avoid memory leaks.
 * 
 * @todo debugging
 * @todo think more: Is it necessary to add new class?
 */

#include "Project.h"

int	main(void)
{

	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter*	me = new Character("me");

	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	
	return (EXIT_SUCCESS);
}