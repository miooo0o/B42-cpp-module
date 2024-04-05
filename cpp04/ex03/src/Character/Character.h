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
#define SLOT_SIZE	4

/// @struct
struct materiaSlot
{
	AMateria	*materia;
	bool		is_equiped;
};

/// @class Character
class Character {
public:
	Character(void);
	Character(std::string const &name);
	Character(const Character &other);
	~Character(void);
	Character &operator=(const Character &other);
	
	std::string const & getName(void) const;
	void 				equip(AMateria* m);
	void 				unequip(int idx);
	void 				use(int idx, ICharacter& target);
	
private:
	/// materia function
	materiaSlot	init_slot(void);
	materiaSlot	equip_slot(AMateria *m);
	/// @category inventory size limit
	static const int	_slotSize = SLOT_SIZE;
	
	std::string	_name;
	int 		_n_equiped;
	materiaSlot	_slots[_slotSize];
	
};

#endif