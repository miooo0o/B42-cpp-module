/// @file   main.cpp
/// @author minakim
/// @date   23-Mar-2024


/// @done	Complete the definition of the following AMateria class and implement the necessary member functions.
///				- AMateria class
/// @todo	Implement the Materias concrete classes Ice and Cure.
///				- Ice class
///				- Cure class
/// 		Use their name in lower-case ("ice" for Ice, "cure" for Cure) to set their types.
/// 		Of course, their member function clone() will return a new instance of the same type
/// 		(i.e., if you clone an Ice Materia, you will get a new Ice Materia).
/// 		The use (ICharacter&) member function will display:
/// 		• Ice: "* shoots an ice bolt at <name> *"
/// 		• Cure: "* heals <name>’s wounds *"
/// 		<name> is the name of the Character passed as parameter.
///			- tip: While assigning a Materia to another, copying the type doesn’t makesense.
///	@todo	Write the concrete class Character which will implement
///			The Character possesses an inventory of 4 slots, which means 4 Materias at most.
/// 		The inventory is empty at construction.
/// 		They equip the Materias in the first empty slot they find.
/// 		This means, in this order: from slot 0 to slot 3.
/// 		In case they try to adda Materia to a full inventory, or `use/unequip` an un existing Materia,
/// 		don’t do anything(but still, bugs are forbidden).
/// 		The `unequip()` member function must NOT delete the Materia!
///			- tip : Handle the Materias your character left on the floor as you like.
/// 				Save the addresses before calling unequip(), or anything else,
/// 				but don’t forget that you have to avoid memory leaks.
///	@todo	The `use(int, ICharacter&)` member function will have to use the Materia at the slot[idx],
/// 		and pass the target parameter to the `AMateria::use` function.
/// @todo	Your Character must have a constructor taking its name as a parameter.
/// 		Any copy(using copy constructor or copy assignment operator) of a Character must be deep.
/// 		During copy, the Materias of a Character must be deleted before the new ones are added
/// 		to their inventory. Of course, the Materias must be deleted when a Character is destroyed.
///	@todo	Write the concrete class `MateriaSource` which will implement
///			In a nutshell, your `MateriaSource` must be able to learn "templates" of Materias to create them
/// 		when needed. Then, you will be able to generate
/// 		a new Materia using just a string that identifies its type.