/// @file   Character.h
/// @author minakim
/// @date   05-Apr-2024

#ifndef Character_H
#define Character_H

/// @headerfile
#include "ICharacter/ICharacter.h"

/// @class
class Amateria;
class Icharacter;

/// @macro
#define MAX_SLOT_SIZE	4

/// @struct
//struct MateriaSlot
//{
//	AMateria*	materia;
//	bool		is_equiped;
//};

class MateriaSlot
{
public:
	MateriaSlot() : materia(NULL), is_equipped(false) {}

	AMateria*	materia;
	bool		is_equipped;

	void		equip_slot(AMateria *m);
};

/// @class Character
class Character : public ICharacter
{
public:
	Character(void);
	Character(std::string const &name);
	Character(const Character &other);
	~Character(void);
	Character &operator=(const Character &other);
	
	std::string const& getName(void) const;
	/// @question	Why don't we need `virtual` before the return type here to achieve Polymorphism?
	///	@answer		class `Character` is the only derived class of class `ICharacter`.
	///             Polymorphism is an important concept in object-oriented programming,
	///             but it is not strictly necessary to use `virtual` for the `equip()` function
	///             in the `Character` class when `Character` is the sole derived class of `ICharacter`.
	///             Since there are no other derived classes to provide alternative implementations
	///             of `equip()`, there is no immediate need for polymorphic behavior in this context.
	void 				equip(AMateria* m);
	void 				unequip(int idx);
	void 				use(int idx, ICharacter& target);

private:
	/// @category slot size limit
	static const int	_slot_size = MAX_SLOT_SIZE;
	
	std::string	_name;
	int 		_n_equiped;
	MateriaSlot	_slots[_slot_size];
	
};

#endif