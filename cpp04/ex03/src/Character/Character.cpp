/// @file   Character.cpp
/// @author minakim
/// @date   05-Apr-2024
///
/// @note   17 Declaring and Initializing Member Data [obsidian]
/// The initializing constructor takes precedence in data initialization.
/// @guide  Let's use direct initialization in the constructor.
#include "Character.h"

/// @brief	constructor
Character::Character(void)
	:_name("no name")
{
	_n_equiped = 0;
}

Character::Character(std::string const &name)
		:_name(name)
{
	_n_equiped = 0;
}

/// @brief	copy constructor
Character::Character(const Character &other)
{
	_name = other._name;
	_n_equiped = other._n_equiped;
	for (int i = 0; i < _slot_size; i++)
	{
		if (_slots[i].is_equipped)
			delete _slots[i].materia;
		_slots[i].materia = other._slots[i].materia->clone();
		_slots[i].is_equipped = other._slots[i].is_equipped;
	}
}

/// @brief	destructor
Character::~Character(void)
{
	for (int i = 0; i < _slot_size; i++)
	{
		if (_slots[i].is_equipped)
			delete _slots[i].materia;
	}
}

/// @brief	operator
Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		_n_equiped = other._n_equiped;
		for (int i = 0; i < _slot_size; i++)
		{
			if (_slots[i].is_equipped)
				delete _slots[i].materia;
			_slots[i].materia = other._slots[i].materia->clone();
			_slots[i].is_equipped = other._slots[i].is_equipped;
		}
	}
	return (*this);
}

/// @brief	public
const std::string &Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < _slot_size; i++)
	{
		if (!_slots[i].is_equipped)
		{
			_slots[i].equip_slot(m);
			_n_equiped++;
			return;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < _slot_size && _slots[idx].is_equipped && _slots[idx].materia)
		_n_equiped--;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < _slot_size && _slots[idx].is_equipped && _slots[idx].materia)
		_slots[idx].materia->use(target);
}

void	MateriaSlot::equip_slot(AMateria *m)
{
	is_equipped = true;
	materia = m;
}